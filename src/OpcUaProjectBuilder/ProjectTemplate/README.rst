ProjectName
========================================================

Installation
--------------------------------------------------------

In order to install ProjectName in your machine type the following command:

**On Linux** 

::
    $ sh build.sh -t local
	 
	
**On Windows**

::
    $ build.bat local


Docker
--------------------------------------------------------

You can use Docker to run ProjectName:

::
    $ docker build -t ProjectName:latest .
    $ docker run -d -p ProjectPort:ProjectPort ProjectName:latest
