# -*- coding: utf-8 -*-
import time
import os
import sys
import logging
from opcua import Client
from opcua import ua

endpoint = "opc.tcp://127.0.0.1:8889"

# check command line parameter
if len(sys.argv) != 5:
    print("usage: " + sys.argv[0] + " <opcua-endpoint> <start-node-id> <number-of-node-ids> <number-of-nodes-per-packet>")
    sys.exit()

endpoint = sys.argv[1]
startNodeId = int(sys.argv[2])
numberOfNodeIds = int(sys.argv[3])
numberOfNodesPerPacket = int(sys.argv[4])

class OpcUaCreateNodes(object):


    def __init__(self, endpoint, startNodeId, numberOfNodeIds, numberOfNodesPerPacket):
    
        self.endpoint = endpoint
        self.startNodeId = startNodeId
        self.numberOfNodeIds = numberOfNodeIds
        self.numberOfNodesPerPacket = numberOfNodesPerPacket

        self.nodeList = []

        # init logging
        logging.basicConfig(level=logging.WARN)

        # open connection
        self.client = Client(self.endpoint)
        self.client.connect()

    def __del__(self):
        # close connection
        self.client.disconnect()

    def createNodeList(self):
        for idx in range(numberOfNodeIds):
            node = ua.AddNodesItem()
            node.RequestedNewNodeId = ua.NodeId(startNodeId + idx, 1)
            node.BrowseName = ua.QualifiedName("TestNode", 1)
            node.NodeClass = ua.NodeClass.Variable
            node.ParentNodeId = ua.NodeId(ua.ObjectIds.ObjectsFolder, 0)
            node.ReferenceTypeId = ua.NodeId(ua.ObjectIds.HasComponent, 0)
            node.TypeDefinition = ua.NodeId(ua.ObjectIds.BaseVariableType, 0)
            attrs = ua.VariableAttributes()
            attrs.DisplayName = ua.LocalizedText("Variable" + str(startNodeId + idx))
            attrs.DataType = ua.NodeId(ua.ObjectIds.UInt32)
            attrs.Value = ua.Variant(1, ua.VariantType.UInt32)
            attrs.ValueRank = -1
            node.NodeAttributes = attrs

            if idx % numberOfNodesPerPacket == 0:
                self.nodeList.append([node])
            else:
                self.nodeList[-1].append(node)

    def createOpcUaNodes(self):
        for nodeList in self.nodeList:
            print(".", end="")
            self.client.uaclient.add_nodes(nodeList)


    def run(self):
        self.createNodeList()
        self.createOpcUaNodes()
        print("done")

createNodes = OpcUaCreateNodes(endpoint, startNodeId, numberOfNodeIds, numberOfNodesPerPacket)
createNodes.run()
sys.exit()
