ASNeG OPC UA Stack
==============================

.. image:: http://jenkins.asneg.de:8080/job/OpcUaStack/job/Release4/badge/icon
    :target: http://jenkins.asneg.de:8080/job/OpcUaStack/job/Release4/
.. image:: https://img.shields.io/github/downloads/ASNeG/OpcUaStack/total.svg
    :alt: Github All Releases
    :target: https://github.com/ASNeG/OpcUaStack
.. image:: https://asneg-invate-form.herokuapp.com/badge.svg
    :alt: Slack Community
    :target: https://asneg-invate-form.herokuapp.com


About
------------------------------

ASNeG OPC UA Stack is an open source framework for development and distribution of OPC UA client\\server applications.
It provides SDK to write your applications in C++ and an infrastructure to run and distribute them.

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
* Auto-generating a user application frame
* Support Docker
* Support DEB and RPM package types to distribute user applications on Linux
* Support MSI package type to distribute user applications on Windows

In the development stage:

* Code generator to create C++ classes representing OPC UA types, objects and events from XML (Nodesets)
* Multi-thread model (currently all application modules run in only one thread)
* PubSub (Part 14) implementation

The information about the coverage of OPC UA specification you can find
`here <https://opcuastack.readthedocs.io/en/latest/1_getting_started/overview.html#opc-ua-specification-coverage>`_

Installing
------------------------------

See `here <https://opcuastack.rtfd.io/en/latest/1_getting_started/installation.html>`_.


Usage
------------------------------

In order to create a user application OPC UA Stack provides a project builder:

::

  $ OpcUaProjectBuilder3 MyProject ProjectDescription 9012

The builder creates a template of OPC UA application project in directory MyProject. The template is
ready to be compiled and installed. Below there is an example for local installation (DEB installation is also possible):

::

  $ cd MyPorject
  $ sh build.sh local

The user application is installed in directory $HOME/.ASNeG or C:\ASNeG by default. And you can run it by using OPC UA Server:

::

  $ OpcUaServer3 $HOME/install/etc/OpcUaStack/MyProject/OpcUaServer.xml

The server reads the setting from file **OpcUaServer.xml** and runs the user application.
Now the application is available via OPC UA protocol on port 9012.

For more information about how to write your own OPC UA client server application see example_ and ASNeG-Demo_.


References
------------------------------

* `Home Page`_
* `Slack Community`_
* Documentation_
* ASNeG-Demo_
* `OPC UA Specifications`_
* ASNeG-Demo_

.. _example: https://opcuastack.readthedocs.io/en/latest/1_getting_started/hello_world.html
.. _Documentation: http://opcuastack.rtfd.io/
.. _Home Page: https://asneg.github.io/projects/opcuastack
.. _OPC UA Specifications: https://opcfoundation.org/developer-tools/specifications-unified-architecture
.. _ASNeG-Demo: https://github.com/ASNeG/ASNeG-Demo
.. _Slack Community: https://asneg-invate-form.herokuapp.com
