# -*- coding: utf-8 -*-
import time
import os
import sys
import datetime
import logging
from opcua import Client
from opcua import ua

def responseCallback(data):
    i = 0
    #print("RESPONSE", datetime.datetime.utcnow())

class OpcUaWriter(object):


    def __init__(self, endpoint, startNodeId, numberOfNodeIds, maxNodesPerRequest, duration):
    
        self.endpoint = endpoint
        self.startNodeId = startNodeId
        self.numberOfNodeIds = numberOfNodeIds
        self.maxNodesPerRequest = maxNodesPerRequest
        self.duration = duration
        self.scriptEnd = datetime.datetime.utcnow() + datetime.timedelta(seconds=duration)

        self.nextSendTime = 0
        self.sendInterval = 0

        self.nodeList1 = []
        self.nodeList2 = []

        # init logging
        logging.basicConfig(level=logging.WARN)

        # open connection
        self.client = Client(self.endpoint)
        self.client.connect()

    def __del__(self):
        # close connection
        self.client.disconnect()


    def createNodeList(self, value):
        nodeList = []
        for idx in range(self.numberOfNodeIds):
            node = ua.WriteValue()
            node.NodeId = ua.NodeId(self.startNodeId + idx, 1)
            node.AttributeId = ua.AttributeIds.Value
            node.Value = ua.DataValue()
            node.Value.Value = ua.Variant(value, ua.VariantType.UInt32)
            node.Value.StatusCode = ua.StatusCode(ua.StatusCodes.Good)
            node.Value.SourceTimestamp = datetime.datetime.utcnow()
            node.Value.ServerTimestamp = datetime.datetime.utcnow()

            if idx % maxNodesPerRequest == 0:
                writeParameters = ua.WriteParameters()
                nodeList.append(writeParameters)
            nodeList[-1].NodesToWrite.append(node)

        return nodeList

    def syncSend(self):
        now = datetime.datetime.utcnow()
        if (now < self.nextSendTime):
            delta = self.nextSendTime - now
            time.sleep(delta.seconds + (delta.microseconds / 1000000))

        self.nextSendTime = self.nextSendTime + datetime.timedelta(seconds=self.sendInterval)


    def write(self, writeParameters):
        request = ua.WriteRequest()
        request.Parameters = writeParameters

        #print("REQUEST", datetime.datetime.utcnow())
        data = self.client.uaclient._uasocket.send_request(request, responseCallback)


    def writeLoop(self): 
        self.sendInterval = 1 / (len(self.nodeList1))
        self.nextSendTime = datetime.datetime.utcnow() 

        count = 0
        while 1:
            print(datetime.datetime.utcnow())
            for writeParameters in self.nodeList1:
                self.syncSend()
                self.write(writeParameters)

            count = count + 1
            if datetime.datetime.utcnow() > self.scriptEnd:
                time.sleep(5)
                print("NumberOfNodes:", count * self.numberOfNodeIds)
                return

            print(datetime.datetime.utcnow())
            for writeParameters in self.nodeList2:
                self.syncSend()
                self.write(writeParameters)

            count = count + 1
            if datetime.datetime.utcnow() > self.scriptEnd:
                time.sleep(5)
                print("NumberOfNodes:", count * self.numberOfNodeIds)
                return

    def run(self):
        self.nodeList1 = self.createNodeList(22)
        self.nodeList2 = self.createNodeList(33)
        self.writeLoop()



# check command line parameter
if len(sys.argv) != 6:
    print("usage: " + sys.argv[0] + " <opcua-endpoint> <start-node-id> <number-of-node-ids> <max-nodes-per-request> <duration>")
    sys.exit()

endpoint = sys.argv[1]
startNodeId = int(sys.argv[2])
numberOfNodeIds = int(sys.argv[3])
maxNodesPerRequest = int(sys.argv[4])
duration = int(sys.argv[5])

writer = OpcUaWriter(endpoint, startNodeId, numberOfNodeIds, maxNodesPerRequest, duration)
writer.run()
sys.exit()

