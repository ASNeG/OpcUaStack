.. _discovery_process:

Discovery Process
==================

This document describes how you can make your OPC UA application visible for OPC
UA clients on the network with  ASNeG OPC UA Stack.

Overview
---------

In order to allow OPC UA clients to find OPC UA servers in the network OPC UA
protocol specifies some special :term:`Discovery` mechanisms. The stack
supports two of them:

1. Simple Discovery with :term:`DiscoveryUrl`
2. Local Discovery Server

Below we'll explain how both mechanisms work and how you can use them by using
the stack.

Simple Discovery
----------------

The simple discovery is only possible when the client knows :term:`DiscoveryUrl`
of the server. In this case the client requests the :term:`Endpoint`\ s of the
server directly by calling *GetEndpoints* :term:`Service`. The server returns
its available :term:`Endpoint`\ s and the client can start communicating through
one of them:

::

   Client                           Server
  ========                     ================
     |                           |          |
     |      GetEndpoints()       |          |
     I-------------------------->I          |
     I                           I          |
     I  EndPointsDescriptions()  I          |
     I<--------------------------I          |
     |                           |          |
     |                           |          |
     I  CreateSecurityChannel()  |          |
     I------------------------------------->I
     I                           |          I
     |                           |          |
                              Discovery  Session
                              Endpoint   Endpoint

As a developer you needn't to code this behavior. The stack do all automatically.
That you need, it is only to describe the :term:`Endpoint`\ s of your application
in configuration file **OpcUaServer.xml**:

.. code-block:: xml

  <Endpoints>
    <EndpointDescription>
      <EndpointUrl>opc.tcp://0.0.0.0:8888</EndpointUrl>
      <ApplicationUri>urn:0.0.0.0:ASNeG:helloworld</ApplicationUri>
      <ProductUri>urn:ASNeG:helloworld</ProductUri>
      <ApplicationName>helloworld</ApplicationName>
      <DiscoveryUrl>opc.tcp://0.0.0.0:8888</DiscoveryUrl>

      <SecuritySetting>
        <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#None</SecurityPolicyUri>
        <MessageSecurityMode>None</MessageSecurityMode>
      </SecuritySetting>
      <SecuritySetting>
        <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15</SecurityPolicyUri>
        <MessageSecurityMode>SignAndEncrypt</MessageSecurityMode>
      </SecuritySetting>

      <UserTokenPolicy>
        <PolicyId>OpcUaStack1</PolicyId>
        <TokenType>Anonymous</TokenType>
        <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#None</SecurityPolicyUri>
      </UserTokenPolicy>
      <UserTokenPolicy>
        <PolicyId>OpcUaStack2</PolicyId>
        <TokenType>Username</TokenType>
        <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#Basic256</SecurityPolicyUri>
      </UserTokenPolicy>
      <UserTokenPolicy>
        <PolicyId>OpcUaStack3</PolicyId>
        <TokenType>IssuedToken</TokenType>
        <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#Basic256</SecurityPolicyUri>
      </UserTokenPolicy>
      <UserTokenPolicy>
        <PolicyId>OpcUaStack3</PolicyId>
        <TokenType>Certificate</TokenType>
        <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#Basic256</SecurityPolicyUri>
      </UserTokenPolicy>
      <TransportProfileUri>http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary</TransportProfileUri>
      <SecurityLevel>0</SecurityLevel>
    </EndpointDescription>
  </Endpoints>

As you can see the :term:`Endpoint` provides the client information about
application identification, communication and security policy so that the client
can connect to the application via TCP\\IP and open a :term:`Secure Channel`\ .
You can learn more about OPC UA security in section :ref:`Security`.


Local Discovery Server
----------------------

The local discovery server provides the list of the registered servers to the client.
If an OPC UA Server needs to be discovered by the clients, it should register itself
on the discovery server by using RegiserServer() or RegisterServer2() :term:`Service`\ s

In order to connect to the registered server, the client calls FindRegister()
:term:`Service` on the discovery server to get the list of the servers. So that
the client needn't to know any :term:`DiscoverUrl`\ s of servers excepting the
discovery server.

::

   Client                  Discover Server                 Server
  ========                =================           ================
     |                           |                      |          |
     |                           |    RegisterServer()  |          |
     |                           I<---------------------I          |
     |                           |                      |          |
     |      FindServers()        |                      |          |
     I-------------------------->I                      |          |
     I                           I                      |          |
     I  ApplicationDescription[] I                      |          |
     I<--------------------------I                      |          |
     |                           |                      |          |
     |                                                  |          |
     |                                                  |          |
     |                                                  |          |
     |                     GetEndpoints()               |          |
     I------------------------------------------------->I          |
     I                                                  I          |
     I                EndPointsDescriptions()           I          |
     I<-------------------------------------------------I          |
     |                                                  |          |
     |                                                  |          |
     I                CreateSecureChannel()             |          |
     I------------------------------------------------------------>I
     I                                                  |          I
     |                                                  |          |
                                                      Discovery  Session
                                                      Endpoint   Endpoint

If you use ASNeG OPC UA Stack you don't need to code the behavior described above.
You should just configure the local discovery server in configuration file **OpcUaServer.xml**:

.. code-block:: xml

  <DiscoveryServer>
    <DiscoveryUrl>opc.tcp://localhost:4840</DiscoveryUrl>
    <RegisterInterval>40000</RegisterInterval>
  </DiscoveryServer>

References
--------------------

* :ref:`Security section <security>`
* `ASNeG OPC UA Discovery Server <https://github.com/ASNeG/OpcUaDiscoveryServer>`_


OPC UA Specification
--------------------

* Part 4 Services, 5.4 Discovery Service Set.
* Part 12 Discovery, 4 The Discovery Process.
