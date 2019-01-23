.. _glossary:

OPC UA Glossary
========

.. glossary::

  Address Space
    collection of information that an OPC UA Server makes visible to its Clients

  Communication Stack
    layered set of software modules between the application and the hardware that provides various
    functions to encode, encrypt and format a Message for sending, and to decode, decrypt and unpack
    a Message that was received

  Endpoint
    physical address available on a network that allows Clients to access one
    or more :term:`Service`\ s provided by a Server

  Discovery
    mechanism which allows OPC UA Clients to find OPC UA Servers on the network

  DiscoveryUrl
    a URL for a network :term:`Endpoint` that provides the information required
    to connect to a Server

  Information Model
    organizational framework that defines, characterizes and relates information
    resources of a given system or set of systems.

  Method
    callable software function that is a component of an :term:`Object`

  Node
    fundamental component of an :term:`Address Space`

  Object
    :term:`Node` that represents a physical or abstract element of a system

  ObjectType
    :term:`Node` that represents the type definition for an :term:`Object`

  Reference
    explicit relationship (a named pointer) from one :term:`Node` to another

  Secure Channel
    a long-term logical connection between a single client and a single server on
    :term:`Communication Stack`'s level

  Service
    client-callable operation in an OPC UA Server

  Session
    a long-term logical connection between a single client and a single server
    on OPC UA application level

  Variable
    :term:`Node` that contains a value
