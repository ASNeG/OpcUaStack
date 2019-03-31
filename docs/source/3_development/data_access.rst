.. _data_access:

Data Access
===========

Every OPC UA application is created to provide some data to its clients. In this document
we're going to learn how OPC UA server stores data and provide access to it.
Also we'll show you how you can organize the access data by using ASNeG OPC UA Stack.

Some basic conceptions related to the tutorial were described in :ref:`hello_world`.
It'd be easier to understand the following text if you take a look at this document before.

You can download the source code of the tutorial from
:download:`here <data_access_example.zip>`.

.. _data_access_node_model:

Node Model
-----------

Before to learn how to access to data we need to understand how information is stored
in OPC UA Server. If you are familiar to OPC UA protocol, just skip this
section.

OPC UA application stores its data in :term:`Information Model` as a collection of
:term:`Node`\ s connected to each other with different kinds of relationships. These
relationships are described by :term:`Reference`\ s and each :term:`Node` has a
collection of them.

Except :term:`Reference`\ s :term:`Node`\ s have :term:`Attribute`\ s that store
data and provide it for clients to read and write.

:term:`Node` has :term:`Attribute` *NodeId* to identify itself in :term:`Information Model`.
*NodeId* contains of an identifier and a namespace index. The identifier should be
unique inside of the namespace and can belong to the following types:

* Numeric
* String
* GUID
* Namespace specific format

*NodeId* isn't only one identifier of :term:`Node`. Each :term:`Node` must have
symbolic human-readable :term:`Attribute` *BrowseName* which is used to identifier
the node by its path of *BrowseNames*. *BrowseName* shouldn't be unique for the
whole server but its path must be. Like *NodeId*, *BrowseName* belongs to some
namespace. Usually namespaces of *NodeId* and *BrowseName* are the same, but
the OPC UA Specfication does not demand it.

OK. There are a lot of information here and we need an example to explain
it. In our example :ref:`hello_world` we created a folder for our string message:

.. code-block:: xml

  <UAObject NodeId="ns=2;i=1" BrowseName="2:HelloWorldFolder">
      <DisplayName>HelloWorldFolder</DisplayName>
      <Description>The folder of the greeting string</Description>
      <References>
          <Reference ReferenceType="Organizes" IsForward="false">i=85</Reference>
          <Reference ReferenceType="HasTypeDefinition">i=61</Reference>
      </References>
  </UAObject>

The folder is :term:`Object` and it has *NodeId* with numeric identifier 1 in namsespace 2
and *BrowseName* **HelloWorldFolder** in namsespace 2.

The numeric ID is OK for machines but we (people) prefer to see data structures named with
human-readable symbolic names, so all :term:`Node` have also :term:`Attribute` *DisplayName*.
*DisplayName* of the folder is **HelloWorldFolder** and OPC UA Clients should show
it to users.

Optionally :term:`Node` can have *Description* where we can give some information
about our folder.

We've described :term:`Attribute`\ s of the folder. Let us to see how it relates
to other :term:`Node`\ s in the server. The folder has two :term:`Reference`\ s.

The first one has type *Organizes*  that determines the hierarchy of :term:`Node`\ s
as it should see the users. Flag *IsForward* sets the direction of the reference.
For reference *Organizes* **false** means, our folder is child of :term:`Node` with
*NodeId* **i=85** in namespace 0. It's standard folder *Objects*. You can found it
in file **Opc.Ua.NodeSet.xml**.

The second :term:`Reference` has type *HasTypeDefinition* that means, :term:`Node`
with *NodeId* **i=61** defines the type of the folder. This node is standard type
*FolderType*.

Variable
~~~~~~~~

To store data witch can be read\\written by the client, OPC UA server has a special
node type :term:`Variable`. It has :term:`Attriubte` *Value* where :term:`Variable`
stores a data value of some type.

From our example :ref:`hello_world`:

.. code-block:: xml

    <UAVariable NodeId="ns=2;i=222" BrowseName="1:GreetingString" DataType="i=12">
        <DisplayName>GreetingString</DisplayName>
        <Description>The greeting string</Description>
        <References>
            <Reference ReferenceType="HasTypeDefinition">i=63</Reference>
            <Reference ReferenceType="Organizes" IsForward="false">ns=1;i=1</Reference>
        </References>
        <Value>
            <uax:String>Ehmm</uax:String>
        </Value>
    </UAVariable>

The definition is very similar to :term:`Node` but has additional
attribute *DataType* which has *NodeId* of data value type.

We can create not only scalar variables but arrays as well. Here we're describing
an array of 3 bytes with values [1,2,3]:

.. code-block:: xml

  <UAVariable NodeId="ns=1;i=203" BrowseName="1:ByteArray" DataType="i=3" ValueRank="1" ArrayDimensions="3">
    <DisplayName>ByteArrayValue</DisplayName>
    <Description>Byte array test value</Description>
    <References>
      <Reference ReferenceType="HasTypeDefinition">i=63</Reference>
      <Reference ReferenceType="Organizes" IsForward="false">ns=1;i=2</Reference>
    </References>
  <Value>
      <uax:ListOfByte>
        <uax:Byte>1</uax:Byte>
        <uax:Byte>2</uax:Byte>
        <uax:Byte>3</uax:Byte>
      </uax:ListOfByte>
    </Value>
  </UAVariable>


Creating\\Deleting Node API
~~~~~~~~~~~~~~~~~~~~~~~~~~~

You can create :term:`Node` in :term:`Information Model` by using not only XML
but the stack's API. It cab be useful when your application should create some
:term:`Node` dynamically:

.. TODO: Describe arguments

.. code-block:: cpp

  CreateNodeInstance createNodeInstance(
    "DynamicVariable",                            // name
    NodeClassType_Variable,                       // node class
    OpcUaNodeId(85),                              // parent node id (Objects)
    OpcUaNodeId("Dynamic", 1),                    // node id
    OpcUaLocalizedText("en", "DynamicVariable"),  // display name
    OpcUaQualifiedName("DynamicVariable", 1),     // browse name
    OpcUaNodeId(47),                              // reference type id
    OpcUaNodeId(62)                               // type node id
  );

  if (!createNodeInstance.query(applicationServiceIf_)) {
    std::cout << "createNodeInstance response error" << std::endl;
    return;
  }


Of course sometimes we need to delete :term:`Node`:

.. code-block:: cpp

  DeleteNodeInstance deleteNodeInstance(OpcUaNodeId("Dynamic", 1));

  if (!deleteNodeInstance.query(applicationServiceIf_)) {
    std::cout << "deleteNodeInstance response error" << std::endl;
    return;
  }

Data Value
~~~~~~~~~~

As we already know, :term:`Variable`\ s are used to store data of OPC UA applications
in :term:`Attribute` *Value*. It is not just a value of some type it is structure
which has some additional information:

* *StatusCode* is used to indicate condition of the data. If data is Ok, it should
be *Success*. Otherwise is has some suitable "bad" status from OPC UA specification.
See **Part 4 Services, Table 172 – Common Service Result Codes** for more Information.
* *ServerTimestamp* is time when the value data has been received by *Server*
* *SourceTimestamp* is time applied by source of data and indicates when the
value or *StatusCode* has been changed in the source.

Below you can see a simple example where we initialize *DataValue* and set to
:term:`Variable` which we've created before.

.. code-block:: cpp

  OpcUaDataValue value(OpcUaInt32(500));

  value.statusCode(OpcUaStatusCode::Success);
  value.serverTimestamp(OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
  value.sourceTimestamp(OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));

  GetNodeReference getNodeReference(OpcUaNodeId("Dynamic", 1));
  if (!getNodeReference.query(&this->service())) {
      Log(Error, "response error");
      return false;
  }

  if (getNodeReference.statuses()[0] != Success) {
      Log(Error, "node reference error");
      return false;
  }

  auto ptr = getNodeReference.nodeReferences()[0].lock();
  if (!ptr) {
      Log(Error, "node no longer exist");
      return false;
  }


Callback Model
--------------

Developing your OPC UA application you'll need to know when the client read or write
the data. The stack provides several callbacks to notify the user application about:

* *Client* reads :term:`Attribute`
* *Client* writes a new value into :term:`Attribute`
* *Client* subscribes to changes of :term:`Attribute`
* *Client* unsubscribes from changes of :term:`Attribute`

These callbacks especially useful when the data source of your application is
remote (e.g. PLC, data base etc.) and you need to transport  between the data source
and the client like a gateway.

Read\\Write
~~~~~~~~~~~

The stack can notify a user application if some :term:`Attribute` of a :term:`Node`
has been read or written by the OPC UA client. For that we have to create
handler-methods and register them in the stack as callbacks.

Let's do it in a new application (see :link:`hello_world` if don't know how to
create an application):

.. code-block:: cpp

  void
  Library::startup(void)
  {
    Log(Debug, "Library::startup");

    RegisterForwardNode registerForwardNode;

    registerForwardNode.setReadCallback(boost::bind(&Library::readValue, this, _1));
    registerForwardNode.setWriteCallback(boost::bind(&Library::writeValue, this, _1));
    registerForwardNode.addNode(OpcUaNodeId(203,1));

    if (!registerForwardNode.query(&this->service())) {
      Log(Error, "registerForwardNode response error");
      return false;
    }

    return true;
  }

  void
  Library::readValue(ApplicationReadContext* context)
  {
    Log(Info, "Read data from node")
        .parameter("nodeId", context->nodeId_)
        .parameter("attributeId", context->attributeId_);

    context->statusCode_ = OpcUaStatusCode::Success;

    if (context->attributeId_ == AttributeId::AttributeId_Value) {
      context->dataValue_.copyFrom(sourceValue_);
    }
  }

  void
  Library::writeValue(ApplicationWriteContext* context)
  {
    Log(Info, "Write data to node")
        .parameter("nodeId", context->nodeId_)
        .parameter("attributeId", context->attributeId_);

    context->statusCode_ = OpcUaStatusCode::Success;

    if (context->attributeId_ == AttributeId::AttributeId_Value) {
      context->dataValue_.copyTo(sourceValue_);
    }
  }

This example application has only one :term:`Variable` of type *OpcUaByte* and
registers callbacks for read and write operation with this :term:`Node` by using
class *RegisterForwardNode*. This class can register a lot of other callbacks but for
our purpose we need only two: *ReadCallback* and *WriteCallback* ,

Methods *readValue* and *writeValue* work with *sourceValue* of type *OpcUaDataValue*.
It is some trivial imitation of the case where the real data stored not
in :term:`InformationModel` but in another part of the system and just mapped into
:term:`Variable`\ s of the user application.

Subscription
~~~~~~~~~~~~

Usually the OPC UA Client doesn't read :term:`Attribute`\ s every time when it needs
new data. It subscribes to them by using *Subscription* model. The client creates
a *Subscription* as a buffer where new data values are added when :term:`Attribute`\ s'
states are changed. To specify which :term:`Attribute`\ s must be subscribed and
how often the stack must check them for the new states (value, status or\\and timestamp),
the client creates *MonitoredItems* in *Subscription*. The *MonitoredItems* check
changes of the :term:`Attribute`\ s with specified rate and if the :term:`Attribute`\ s
are changed they store the new value in the buffer of its *Subscription*. To
get the values from the *Subscription* the client calls Service :term:`Publish`.

*Subscription* model in OPC UA might seem to be complicated. Actually the model is even
more complicated than we have described it, because there are a lot of settings,
modes and filters that we have skipped. However it doesn't matter for our purpose, since
it is communication level of the stack and a user application doesn't need to know
about the subscription settings. But if you're interested in learning OPC UA protocol
dipper, you can find references on the corresponded section in OPC UA specification
at the end of this tutorial.

The user application may need to know that the client has subscribed or unsubscribed
to an :term:`Attribute`. For an instance you want to spare network traffic between your
server and data source and update only data that is really needed by the clients.
For this purpose the stack provides two callbacks: *MonitoredItemStartCallback* and
*MonitoredItemStopCallback*.

The following code shows how to use them:

.. code-block:: cpp

  void
  Library::startup(void)
  {
    Log(Debug, "Library::startup");

    RegisterForwardNode registerForwardNode;

    registerForwardNode.setMonitoredItemStartCallback(boost::bind(&Library::startMonitoredItems, this, _1));
    registerForwardNode.setMonitoredItemStopCallback(boost::bind(&Library::stopMonitoredItems, this, _1));
    registerForwardNode.addNode(OpcUaNodeId(203,1));

    if (!registerForwardNode.query(&this->service())) {
      Log(Error, "registerForwardNode response error");
      return false;
    }

    return true;
  }

  void
  Library::startMonitoredItems(ApplicationMonitoredItemStartContext* context)
  {
    Log(Info, "Start monitoring.")
        .parameter("nodeId", context->nodeId_);
  }

  void
  Library::stopMonitoredItems(ApplicationMonitoredItemStopContext* context)
  {
    Log(Info, "Stop monitoring.")
        .parameter("nodeId", context->nodeId_);
  }

Hire we are following the same approach as with the read\\write callbacks and using
*RegisterForwardNode* class to register your method-handlers in the stack which
do nothing but write some log message.


OPC UA Specification
--------------------

* Part 3 Address Space Model, 4.3 Node Model.
* Part 3 Address Space Model, 5 Standard NodeClasses.
* Part 3 Address Space Model, 8.2 NodeId.
* Part 4 Services, Table 172 – Common Service Result Codes
* Part 4 Services, 7.7 DataValue
* Part 4 Services, 5.10 Attribute Service Set
* Part 4 Services, 5.12 MonitoredItem Service Set
* Part 4 Services, 5.13 Subscription Service Set
