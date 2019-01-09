Application Service Interface
==================================
.. toctree::
   :maxdepth: 2
   :caption: Application Service Interface:

Most OPC UA applications should be able to do the following operations:

1. Figure out the namespace index by its URI
2. Handle different types of events (reading, writing variables, start node monitoring and etc.)
3. Fire OPC UA events
4. Create and delete variables

For these operations the ASNeG OPC UA Stack provides a special interface. We call it *Application Service Interface*. 
Here we're going to describe this interface in details.


GetNamespaceInfo
--------------------------------

RegisterForwardNode
--------------------------------

RegisterForwardMethod
--------------------------------

RegisterForwardGlobal
--------------------------------

FireEvent
--------------------------------

BrowsePathToNodeId
--------------------------------

DeleteNodeInstance
--------------------------------

CreateNodeInstance
--------------------------------


