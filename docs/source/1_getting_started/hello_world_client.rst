.. _hello_world_client:

Hello, World of OPC UA! Client part.
====================================

In this document we'll discuss how to create an OPC UA client application by using ASNeG OPC UA Stack.
If you a new at OPC UA technology, it would be better to have a look at :doc:`hello_world_server` example
where we've explained some basic conceptions. 

You can download the source code of the example from :download:`here <hello_world_client.zip>`.

Requirements
-------------

In order to start this tutorial you need to have the following stuff:

1. Windows or Linux machine with the installed stack (see :doc:`installation <installation>` if you don't have it yet.)
2. For our client we need a server. We'll use ASNeG-Demo_.

CMake project
-------------

Our C++ project should have the following structure: 

::

    helloworld_client
     |
     |- CMakeLists.txt
     |- main.cpp


In the CMakeListst.txt we must describe where OPC UA Stack and other dependencies are installed. For that, the stack provides 
CMake helper files which we have to include:

.. code-block:: cmake
  :emphasize-lines: 7-10

   cmake_minimum_required(VERSION 3.5)
   project(helloworld_client)

   set(CMAKE_CXX_STANDARD 14)

   set(OPCUASTACK_VERSION_MAJOR 4)

   include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeBoost.txt)
   include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeOpenSSL.txt)
   include(${OPCUASTACK_INSTALL_PREFIX}/usr/share/cmake/OpcUaStack${OPCUASTACK_VERSION_MAJOR}/CMakeOpcUaStack.txt)

   add_executable(helloworld_client main.cpp)
   

Now, let's build the project:

::

   $ mkdir build
   & cd build
   & cmake -DOPCUASTACK_INSTALL_PREFIX=/path/to/stack ..
   & cmake --build .

If the path to the stack is right, the build will be successful.

Reading OPC UA Variable
-----------------------




.. _ASNeG-Demo: https://github.com/ASNeG/ASNeG-Demo
