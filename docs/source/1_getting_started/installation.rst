.. _installation:

Installation
===========================

OpcUaStack provides different ways of installing.

Source Code
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In order to compile and install the stack from the source code, you should meet
the following requirements:

* Compiler with C++17 support (we test only GCC, Clang and Visual Studio)
* CMake >= 3.5
* Boost >= 1.58
* OpenSSL >= 1.0.0


**Linux (Ubuntu or Debian)**

Ubuntu or Debian users can install the requirements by using *apt-get* command:

::

  $ sudo apt-get install libboost-all-dev cmake libssl-dev  build-essential


The next step is the compilation of the source code and its installation. You should run in
the root directory of the sources:

::

  $ sh build.sh -t local


By default, the installation path is $HOME/.ASNeG. You can change it at any moment:

::

  $ sh build.sh -t local -i /path/witch/you/prefer


**Windows (Visual Studio)**

Windows users should install all requirements manually.

In order to compile the project, you should install MSBuild Tools, then run in the environment which
is suitable for your target platform (e.g. Native x86) the following command:

::

  $ build.bat -t local


By default, the installation path is C:\\ASNeG. You can change it by typing:

::

  $ build.bat -t local -i C:\path\witch\you\prefer


**Windows (MinGW)**

The stack can be compiled with MinGW, but there is no build script for it up to now.
You can build the source with cmake typing the following commands:

::
  
  $ mkdir build_mingw
  $ cd build_mingw
  $ cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..\src
  $ set DESTDIR=C:\ASNeG
  $ cmake --build . --target install


DEB Packages
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The stack provides DEB packages, so you can install it into your Ubuntu or Debian.
Download `the last packages`_ and install them by using **dpkg** command

If you need only the runtime to run your application, type:

::

  $ sudo dpkg -i OpcUaStack-x.y.z-x86_64-bin.deb

For development, install *dev* packet too:

::

  $ sudo dpkg -i OpcUaStack-x.y.z-x86_64-dev.deb



Also you can build DEB packets from source by using *build.sh* script:

::

  $ build.sh -t deb

Your packets will be built in *build_deb* directory.


RPM Packages
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Users of RPM Linux distributives can install the stack with RPM packages. The way is the same as for DEB packages.
Download `the last packages`_ and install them by using **rpm** command:

::

  $ sudo rpm -i OpcUaStack-x.y.z-x86_64-bin.rpm
  $ sudo rpm -i OpcUaStack-x.y.z-x86_64-dev.rpm


MSI Packages
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

On Windows, the stack is available for installing with MSI packages. As DEB packets, the MSI packages belong to two kinds.
The package, that ends with *-Bin* suffix, provides the stack and its dependencies (OpenSSL and Boost) and it is suitable to run user applications.
If you are going to develop your own OPC UA user applications, you can use the development package (ending with *-Dev* suffix). This package installs not only the stack and its headers
but the whole Boost and OpenSSL with headers. So you do not need to install something more.


.. _the last packages: https://github.com/ASNeG/OpcUaStack/releases/latest
