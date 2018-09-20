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

**Client Library:**


+------------------------+----------------------------+---------+---------+---------+-------------+
|      Service Set       | Function                   | OPC UA Interface  | Value Based Interface |
+------------------------+----------------------------+---------+---------+---------+-------------+
|                        |                            | Sync    |  Async  | Sync    | Async       |
+========================+============================+=========+=========+=========+=============+
| Discover               | Find Server                |         |         |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Get Endpoints              | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Register Server            |         |         |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Secure                 | Open Secure Channel        | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Close Secure Channel       | |done|  | |done|  | |done|  | |done|      |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Session                | Create Session             | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Activate Session           | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Close Session              | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Cancel Session             | |done|  | |done|  |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Node Management        | Add Nodes                  | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Add References             | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Delete Nodes               | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Delete References          | |done|  | |done|  |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| View                   | Browse                     | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Browse Next                | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Translate Browse Paths     | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Register Nodes             |         |         |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Unregister Nodes           |         |         |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Query                  | Query First                | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Query Next                 | |done|  | |done|  |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Attribute              | Read                       | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | History Read               | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Write                      | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | History Update             | |done|  | |done|  |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Method                 | Call                       | |done|  | |done|  |         |             |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Monitored Item         | Create Monitored Items     | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Modify Monitored Items     | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Set Monitoring Mode        | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Set Triggering             | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Delete Monitored Items     | |done|  | |done|  | |done|  | |done|      |
+------------------------+----------------------------+---------+---------+---------+-------------+
| Subscription           | Create Subscription        | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Modify Subscription        | |done|  | |done|  |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Publish/Set                | |done|  | |done|  | |done|  | |done|      |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Republish                  |         |         |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Transfer Subscription      |         |         |         |             |
+                        +----------------------------+---------+---------+---------+-------------+
|                        | Delete Subscription        | |done|  | |done|  | |done|  | |done|      |
+------------------------+----------------------------+---------+---------+---------+-------------+



Columns:

* *OPC UA Interface* contains the OPC UA interface with full functionality. To use the interface OPC UA skills are necessary
* *Value Based Interface* contains a value based interface with limited functionality. To use the interface OPC UA skills are not necessary



**Server Library:**



Installation
------------------------------

Exmaples
------------------------------


References
------------------------------
