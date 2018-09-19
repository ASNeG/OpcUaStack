OpcUaStack
==============================

About
------------------------------

OpcUaStack is an open source implementation of OPC UA protocol written in C++. It provides SDK to create your own OPC UA application from scratch and 
an OPC UA framework as well, which makes creating and running OPC UA applications easier. 

The stack contains the following parts:

* **OpcUaStackClient** is a client library, which can be used to implement a client OPC UA application in C++.
* **OpcUaStackServer** is a server library, which can be used to implement a server OPC UA application in C++.
* **OPC UA Application Server** provides a server environment to run user OPC UA client\\server applications as dynamic libraries.
* **OPC UA Project Generator** helps to create and distribute a new user application for Application Server.

All parts of the stack are cross-platform and support Linux and Windows operation systems.

Features
------------------------------

* SDK for Client\\Server applicaion
* Application Server to run OPC UA application as dynamic libraries
* Settings and OPC UA information model in XML format
* Support DEB package type to distribute user applications on Linux

In the development stage:

* Code generator to create C++ classes representing OPC UA types, objects and events from XML
* Multi-thread model (currently all application modules run in only one thread)
* Support RPM package type to distribute user applications on Linux
* Support MSI package type to distribute user applications on Windows


OPC UA Specification Coverage
------------------------------

.. |done| unicode:: U+2713 .. DONE

Client Library:
``````````````````````````````

+------------------------+----------------------------+---------+---------+---------+-------------+
|      Service Set       | Function                   | OPC UA Interface  | Value Based Interface |
+------------------------+----------------------------+---------+---------+---------+-------------+
|                        |                            | Sync    |  Async  | Sync    | Async       |
+========================+============================+=========+=========+=========+=============+
| Discover               | Find Server                |         |         |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Get Endpoints              | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Register Server            | |done|  | |done|  |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+





Installation
------------------------------

Exmaples
------------------------------


References
------------------------------
