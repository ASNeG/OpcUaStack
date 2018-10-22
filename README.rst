OpcUaStack
==============================

.. image:: https://travis-ci.org/ASNeG/OpcUaStack.svg?branch=master
    :target: https://travis-ci.org/ASNeG/OpcUaStack

.. image:: https://img.shields.io/github/downloads/ASNeG/OpcUaStack/total.svg?style=social   :alt: Github All Releases   :target: https://github.com/ASNeG/OpcUaStack


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

* SDK for Client\\Server application
* Application Server to run OPC UA application as dynamic libraries
* Settings and OPC UA information model in XML format
* Support DEB package type to distribute user applications on Linux

In the development stage:

* Code generator to create C++ classes representing OPC UA types, objects and events from XML (Nodesets)
* Multi-thread model (currently all application modules run in only one thread)
* Support RPM package type to distribute user applications on Linux
* Support MSI package type to distribute user applications on Windows

Installation
------------------------------

OpcUaStack provides different ways of installing.

Source Code
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In order to compile and install the stack from the source code, you should meet
the following requirements:

* Compiler with C++11 support
* CMake >= 2.8.9
* Boost >= 1.54
* OpenSSL >= 1.0.0


**Linux (Ubuntu or Debian)**

Ubuntu or Debian users can install the requirements by using *apt-get* command:

::

  $ sudo apt-get install apt-get install libboost-all-dev cmake libssl-dev  build-essential


The next step is the compilation of the source code and its installation. You should run in 
the root directory of the sources:

::

  $ sh build.sh -t local 


By default the installation path is $HOME/.ASNeG. You can change it at any moment:

::

  $ sh build.sh -t local -i /path/witch/you/prefer


**Windows**

Winidows users should install all requirements manually. 

In order to compile the project, you should install MSBuild Tools 2015, then run in the environment which
is suitable for your target platform (e.g. Native x86) the following command:

::

  $ build.bat local


By default the installation path is C:\\install. You can change it by typing:

::
  
  $ cd local_build
  $ set DESTDIR=C:\path\witch\you\prefer
  $ MSBuild INSTALL.vcxproj



DEB Packets
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The stack provides DEB packets, so you can install it into your Ubuntu or Debian.
Download `the last packages`_ and install them by using **dpkg** command

If you need only the runtime to run your application, type:

::

  $ sudo dpkg -i OpcUaStack-x.y.z-x86_64-bin.deb

For development, install *dev* packet too:

::

  $ sudo dpkg -i OpcUaStack-x.y.z-x86_64-dev.deb


.. _the last packages: https://github.com/ASNeG/OpcUaStack/releases/latest

Also you can build DEB packets from source by using *build.sh* script:

::

  $ build.sh -t deb

Your packets will be built in *build_deb* directory.

Usage 
------------------------------

In order to create a user application OpcUa Stack provides a project builder:

::

  $ OpcUaProjectBuilder3 MyProject ProjectDescription 9012

The builder creates a template of OPC UA application project in directory MyProject. The template is 
ready to be compiled and installed. Below there is an example for local installation (DEB installation is also possible):

::

  $ cd MyPorject
  $ sh build.sh local

The user application is installed in directory $HOME/install by default. And you can run it by using OPC UA Server:

::
  
  $ OpcUaServer3 $HOME/install/etc/OpcUaStack/MyProject/OpcUaServer.xml

The server reads the setting from file **OpcUaServer.xml** and run the user application. 
Now the application is available via OPC UA protocol on port 9012.
  
For more information about how to write your own OPC UA client server application see ASNeG-Demo_.


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

+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
|      Service Set       | Function                   | Information  |  OPC UA Interface  | Value Based Interface |
|                        |                            | Model        |                    |                       |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
|                        |                            |              |  Sync    |  Async  | Sync    | Async       |
+========================+============================+==============+==========+=========+=========+=============+
| Discover               | Find Server                |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Get Endpoints              | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Register Server            |              |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Secure                 | Open Secure Channel        | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Close Secure Channel       | |done|       |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Session                | Create Session             | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Activate Session           | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Close Session              | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Cancel Session             |              |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Node Management        | Add Nodes                  |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Add References             |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Delete Nodes               |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Delete References          |              |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| View                   | Browse                     | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Browse Next                | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Translate Browse Paths     |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Register Nodes             |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Unregister Nodes           |              |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Query                  | Query First                |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Query Next                 |              |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Attribute              | Read                       |  |done|      |  |done|  |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | History Read               | |done|       |  |done|  |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Write                      | |done|       |  |done|  |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | History Update             |              |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Method                 | Call                       | |done|       |  |done|  |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Monitored Item         | Create Monitored Items     | |done|       |  |done|  |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Modify Monitored Items     |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Set Monitoring Mode        |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Set Triggering             |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Delete Monitored Items     | |done|       | |done|   |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Subscription           | Create Subscription        | |done|       |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Modify Subscription        |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Publish/Set                | |done|       |  |done|  |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Republish                  |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Transfer Subscription      |              |          |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Delete Subscription        | |done|       |          |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+
| Alarms & Events        | Alarms                     | |done|       |  |done|  |         |         |             |
+                        +----------------------------+--------------+----------+---------+---------+-------------+
|                        | Events                     | |done|       |  |done|  |         |         |             |
+------------------------+----------------------------+--------------+----------+---------+---------+-------------+

Columns:

* *Information Model* - Interface of the OPC UA information model of the OPC UA Server
* *OPC UA Interface* - OPC UA Applications are deployed to the OPC UA Server in form of libraries. The OPC UA Interface contains the full OPC UA functionality. 
  To use the interface OPC UA skills are necessary.
* *Value Based Interface* - OPC UA Applications are deployed to the OPC UA Server in form of libraries. The value based Interface contains the limited OPC UA functionality. 
  To use the interface OPC UA skills are not necessary.

**Security:**

+------------------------+----------------------------+----------+----------+
|                        | Type                       | Client   |  Server  |
+========================+============================+==========+==========+
| Security Mode          | None                       | |done|   | |done|   |
+                        +----------------------------+----------+----------+
|                        | Sign                       |          | |done|   |
+                        +----------------------------+----------+----------+
|                        | Sign and Encrypt           |          | |done|   | 
+------------------------+----------------------------+----------+----------+
| Security Policy        | None                       | |done|   | |done|   |
+                        +----------------------------+----------+----------+
|                        | Basic128Rsa15              |          | |done|   |
+                        +----------------------------+----------+----------+
|                        | Basic256                   |          | |done|   |
+                        +----------------------------+----------+----------+
|                        | Basic256Sha256             |          | |done|   | 
+------------------------+----------------------------+----------+----------+
| User Authentication    | Anonymous                  | |done|   | |done|   |
+ Policy                 +----------------------------+----------+----------+
|                        | Username                   |          | |done|   |
+                        +----------------------------+----------+----------+
|                        | IssuedToken                |          | |done|   |
+                        +----------------------------+----------+----------+
|                        | Certificate                |          | |done|   | 
+------------------------+----------------------------+----------+----------+

References
------------------------------

* `OPC UA Specifications`_
* `ASNeG Home Page`_ (in German)
* ASNeG-Demo_ 

.. _OPC UA Specifications: https://opcfoundation.org/developer-tools/specifications-unified-architecture
.. _ASNeG Home Page: http://asneg.de/
.. _ASNeG-Demo: https://github.com/ASNeG/ASNeG-Demo
