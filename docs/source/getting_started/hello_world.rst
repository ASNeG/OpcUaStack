Hello, World of OPC UA!
===========================

.. toctree::
   :maxdepth: 2
   :caption: Hello, World!:


This is the simplest example of an OPC UA application based on ASNeG OPC UA Stack. 
The example will help you to understand the basic OPC UA conceptions and make your first OPC UA server.
Here we are going to make an application outputting a greeting message which will be available from other OPC UA client.

Requirements
---------------------------

In order to start this tutorial you need to have the following stuff:

1. Windows or Linux machine with the installed stack (see :doc:`installation <installation>`  if you don't have one) 
2. A text editor
3. An OPC UA client to test the app. In the tutorial I will use `OPC UA Expert`_.


Creating the application frame
------------------------------

At first we need to create the frame of the future application. It is very easy to do with the stack. 
Just type in your console:

::
    
    $ OpcUaProjectBuilder3 helloworld "My First OPC UA Application" 8888

The builder has created a C++ project in folder **helloworld**, which is ready to be compiled and run as an OPC UA server on 8888 TCP\\IP port.


If you look into the folder you can see quite many files, but don't worry. You don't need to touch most of them. For our goal we need only three:

* **src/helloworld/Config/OpcUaServer.xml** - configuration of the server
* **src/helloworld/Library/Library.cpp** and **Library.h**  - source code of the user application


Information Model
---------------------------

Every OPC UA server application provides its data with *Nodes*, which contain some information. 
To make a string greeting available for OPC UA clients we must to describe it as a node in *Information Model*. Let's do it!


Create a file with name **HelloWorldNodeSet.xml** in directory **src/helloworld/Config** and copy there the following text in XML format:

.. code-block:: xml
  :emphasize-lines: 3,5


    <?xml version="1.0" encoding="utf-8"?>
    <UANodeSet xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:uax="http://opcfoundation.org/UA/2008/02/Types.xsd" xmlns:xsd="http://www.w3.org/2001/XMLSchema" Version="1.02"          LastModified="2013-03-06T05:36:44.0862658Z" xmlns="http://opcfoundation.org/UA/2011/03/UANodeSet.xsd">
        <NamespaceUris>
            <Uri>http://localhost/helloworld/</Uri>
        </NamespaceUris>

        <UAObject NodeId="ns=1;i=1" BrowseName="1:HelloWorldFolder">
            <DisplayName>HelloWorldFolder</DisplayName>
            <Description>The folder of the greeting string</Description>
            <References>
                <Reference ReferenceType="Organizes" IsForward="false">i=85</Reference>
                <Reference ReferenceType="HasTypeDefinition">i=61</Reference>
            </References>
        </UAObject>

        <UAVariable NodeId="ns=1;i=222" BrowseName="1:GreetingString" DataType="i=12">
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
    </UANodeSet>

This file describes the structure of the application:

::

    Root
     |
     |- Objects
         |
         |-HelloWorldFolder
            |
            |- GreetingString (="Hello, World!")

Now we must include our node set to the information model of the application in file **src/helloworld/Config/OpcUaServer.xml**:

.. code-block:: xml
  :emphasize-lines: 3

  <InformationModel>
    <NodeSetFile>@CONF_DIR@/Opc.Ua.NodeSet.xml</NodeSetFile>
    <NodeSetFile>@CONF_DIR@/HelloWorldNodeSet.xml</NodeSetFile>
  </InformationModel>

This might seem quite complicated, but actually you won't need to make your XML node sets manually. You can use our `OPC UA Designer`_ to make this process easier. 
However we do everything ourselves, so that we can learn some basic OPC UA conceptions. If you are already familiar to the protocol, just skip the rest of the section. 


*OPC UA Information* model is split into *namespaces*. Each of them must have its *namespace index*. Index 0 is reserved for the OPC UA standard namespace, where all standard types are described. 
In our application it is stored in **Opc.Ua.NodeSet.xml**. The application can't work without it, so we need to include this file in our configuration. 

In **HelloWorldNodeSet.xml** we've described our own *namespace* by defining *NamespaceUri*:

.. code-block:: xml
    :emphasize-lines: 2

    <NamespaceUris>
        <Uri>http://localhost/helloworld/</Uri>
    </NamespaceUris>

It is not necessary for your task that the URI is really exists, but the stack needs it to give our *namespace* a new *namespace index* which will be 1.

Now we can describe folder **HelloWorldFolder** for our message:

.. code-block:: xml

    <UAObject NodeId="ns=1;i=1" BrowseName="1:HelloWorldFolder">
        <DisplayName>HelloWorldFolder</DisplayName>
        <Description>The folder of the greeting string</Description>
        <References>
            <Reference ReferenceType="Organizes" IsForward="false">i=85</Reference>
            <Reference ReferenceType="HasTypeDefinition">i=61</Reference>
        </References>
    </UAObject>

In the OPC UA everything (objects, variables, types, methods etc.) is *nodes* and every *node* must be identified by a unique *node ID*. Our **HelloWorldFolder** is an *object* with
ID "ns=1;i=1", that means it belongs to *namespace* 1 and has *identifier* 1. The next important OPC UA conception is *references*, they describe relations between *nodes*. In our case folder
**HelloWorldFolder** is placed on folder *Objects*. This relation is described by the following sting:

.. code-block:: xml

    <Reference ReferenceType="Organizes" IsForward="false">i=85</Reference>

The node ID 'i=85' references to standard node *Objects* in namespace 0 with identifier 85. You can found it in **Opc.Ua.NodeSet.xml**. 

In our application **HelloWorldFolder** is just a container for **GreetingString** and it doesn't have any other information. The data is stored in *variables*. And our string is a *variable*:

.. code-block:: xml

    <UAVariable NodeId="ns=1;i=222" BrowseName="1:GreetingString" DataType="i=12">
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

As you can see from the XML snippet, the main difference between *objects* and *variables* is, that the *variables* have values. Variable **GreatingString** has value of type string (ns=0,i=12) with default
value *Ehmm* and placed in on **HelloWorldFolder** (ns=1;i=1)

Now our information model is described and we can see it with an OPC UA client. But we need to compile and launch the application before.

Building and running
---------------------------

In order to make the build process easier ASNeG OPC UA Stack provides scripts for building and installing user applications. 

Hello, World!
---------------------------


Testing with OPC UA Client
---------------------------


References
---------------------------
 
.. _OPC UA Expert: https://www.unified-automation.com/products/development-tools/uaexpert.html
.. _OPC UA Designer: https://github.com/ASNeG/OpcUaDesigner


