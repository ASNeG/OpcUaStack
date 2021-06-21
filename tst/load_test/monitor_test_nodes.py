# -*- coding: utf-8 -*-
import time
import os
import sys
import datetime
import logging
from opcua import Client
from opcua import ua
from opcua import Subscription

class OpcUaMonitor(object):


    def __init__(self, endpoint, startNodeId, numberOfNodeIds, duration):
    
        self.endpoint = endpoint
        self.startNodeId = startNodeId
        self.numberOfNodeIds = numberOfNodeIds
        self.duration = duration
        self.scriptEnd = datetime.datetime.utcnow() + datetime.timedelta(seconds=duration)

        self.nextSendTime = 0
        self.sendInterval = 0

        self.monitoredItemRequestList = []
        self.count = 0

        # init logging
        logging.basicConfig(level=logging.WARN)

        # open connection
        self.client = Client(self.endpoint)
        self.client.connect()

    def __del__(self):
        # close connection
        print("Disconnect")
        self.client.disconnect()


    def datachange_notification(self, node, val, data):
        self.count = self.count + 1
        #print(node, val, data)


    def createSubscription(self):
        self.subscription = self.client.create_subscription(200, self)
        #params = ua.CreateSubscriptionParameters()
        #params.RequestedPublishingInterval = 100
        #params.RequestedLifetimeCount = 10000
        #params.RequestedMaxKeepAliveCount = 3000
        #params.MaxNotificationPerPublish = 10000
        #params.PublishingEnabled = True
        #params.Priority = 0
        #self.subscription = Subscription(self.client, params, self)


    def deleteSubscription(self):
        self.subscription.delete()


    def createMonitoredItemRequestList(self):
        monitoredItemRequestList = []
        for idx in range(self.numberOfNodeIds):
            rv = ua.ReadValueId()
            rv.NodeId = ua.NodeId(self.startNodeId + idx, 1)
            rv.AttributeId = ua.AttributeIds.Value

            mir = ua.MonitoredItemCreateRequest()
            mir.RequestedParameters = ua.MonitoringParameters()
            mir.RequestedParameters.ClientHandle = self.startNodeId + idx
            mir.RequestedParameters.QueueSize = 10
            mir.RequestedParameters.SamplingInterval = 100
            mir.RequestedParameters.DiscardOldest = False
            monitoredItemRequestList.append(mir)
            monitoredItemRequestList[-1].ItemToMonitor = rv

        return monitoredItemRequestList

    
    def createMonitoredItem(self, monotoredItemRequestList):
        for mir in monotoredItemRequestList:
            handle = self.subscription.create_monitored_items([mir])


    def loop(self): 
        while 1:
            now = datetime.datetime.utcnow()
            print(now, self.count)
            self.count = 0
            time.sleep(1)
            if (self.scriptEnd < now):
                return

    def run(self):
        self.createSubscription()
        self.createMonitoredItem(self.createMonitoredItemRequestList())
        self.loop()
        self.deleteSubscription()



# check command line parameter
if len(sys.argv) != 5:
    print("usage: " + sys.argv[0] + " <opcua-endpoint> <start-node-id> <number-of-node-ids> <duration>")
    sys.exit()

endpoint = sys.argv[1]
startNodeId = int(sys.argv[2])
numberOfNodeIds = int(sys.argv[3])
duration = int(sys.argv[4])

monitor = OpcUaMonitor(endpoint, startNodeId, numberOfNodeIds, duration)
monitor.run()
del monitor
sys.exit()

