Release 3.7.0
------------------------------------------------------------

**Features**:

* refactoring application service interface #65, by @huebl
* add simple getter to password of UserNameIdentityToken #108, by @flipback 

**Bugs**:

* fix user changing during activated session #105, by @huebl

Release 3.6.1 (2018-12-28)
------------------------------------------------------------

**Bugs**:

* fix compilation on Winodws #71, by @flipback

Release 3.6.0 (2018-12-26)
------------------------------------------------------------

**Features**:

* add *OpcUaStackServer::GetNodeReference* to simplify access to nodes in application #59, by @huebl
* add additional constructors for *OpcUaStack::DataValue* class is cumbersome #60, by @huebl
* add options for *build.bat* to set install path, stack location and VS version #33, by @flipback
* implement MSI distribution for the stack and user applications #14, by @flipback
* implement RPM distribution for the stack and user applications #13, by @flipback

**Bugs**:
 
* fix crash during shutdown #10, by @huebl
* fix runing client tests on CI server #45, by @flipback
* fix too specific params of *build.bat* #16, by @flipback
* fix OpenSSL-1.1 compatibility in test compilation #46, by @flipback
* fix type conversion of refernces on the same value #67, by @flipback
* fix comparison in *OpcUaStackCore::ComparisonFilterNode* #67, by @flipback

**Documentation**:

* init Shinx documentations and add 'Hello, World' example #61, by @flipback


Release 3.5.2 (2018-12-18)
------------------------------------------------------------

**Bugs**:

* fix error "Unexpected SequenceNumber" #57, by @huebl


Release 3.5.1 (2018-11-11)
-----------------------------------------------------------

**Bugs**:

* fix OpcUaStackCore/Client/Server tests #31, by @huebl
* fix missing certificate in OPC UA Client #40, by @huebl
* fix unstable OPC UA Client test #41, by @huebl


Release 3.5.0 (2018-10-27)
------------------------------------------------------------

**Features**:

* add options for *build.sh* to set install path, stack location and job count #28, by @flipback

**Bugs**:

* fix strict versions of dependencies in DEB packet #15, by @flipback
* fix building DEB packet of a user application #19, by @flipback


Release 3.4.1 (2018-10-22)
-------------------------------------------------------------

**Bugs**:

* fix condition check in server start #30, by @antlad


Release 3.4.0 (2018-10-16)
-------------------------------------------------------------

**Features**:
* add Docker support #17, by @flipback


