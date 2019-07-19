ProjectName
===========

ProjectName is an OPC UA application based on `ASNeG OPC UA Stack`_.


Requirements
------------

* ANSeG OPC UA Stack >= 4.0.0
* CMake
* C++ compiler with C++11 support



Installing
----------

Before install ProjectName you must install `ASNeG OPC UA Stack`_. 
See `this tutorial <https://opcuastack.readthedocs.io/en/latest/1_getting_started/installation.html>`_ 
for more information. Then type the following command:

**On Linux** 

::

  $ sh build.sh -t local -i ~/.ASNeG
	 
	
**On Windows**

::

  $ build.bat -t local -i C:\\ASNeG


Usage
-----

Having installed ProjectName locally, you can run it by using the following command:

**On Linux**

::
  
  $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${HOME}/.ASNeG/usr/lib
  $ OpcUaServer4 ~/.ASNeG/etc/OpcUaStack/ProjectName/OpcUaServer.xml

**On Windows**

::

  $ set PATH=%PATH%;C:\ASNeG\lib
  $ OpcUaServer4 CONSOLE C:\ASNeG\etc\OpcUaStack\ProjectName\OpcUaServer.xml


Also you can use Docker without installing any dependencies:

::

  $ docker build -t ProjectName:latest .
  $ docker run -d -p ProjectPort:ProjectPort ProjectName:latest


Documentaion
------------

ProjectName uses `Sphinx`_ to generate its documentation and it is ready for hosting on `RTD`_.
You can build the documentation locally. For that you should `install Sphinx <http://www.sphinx-doc.org/en/master/usage/installation.html>`_
on your machine with Pyhton and `Doxygen <http://www.doxygen.nl/manual/install.html>`_ .Then run the following command from the root directory of the project:

::

  $ cd docs
  $ pip install -r requirements.txt
  $ make html

The generated HTML files you can find in **build/html** directory.


References
----------

* `ASNeG OPC UA Stack`_
* `Hello World Example`_ with ASNeG OPC UA Stack
* `Sphinx`_ Documentation Generator


.. _`ASNeG OPC UA Stack`: https://asneg.github.io/projects/opcuastack
.. _`Hello World Example`: https://opcuastack.readthedocs.io/en/latest/1_getting_started/hello_world.html
.. _`Sphinx`: http://www.sphinx-doc.org/en/master/
.. _`RTD`: https://readthedocs.org/
