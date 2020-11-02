  Release 4.0.0
------------------------------------------------------------

**Features**:

* Add asynchronously call request #446, by @huebl
* Add asynchronously write request #447, by @huebl
* Add asynchronously read request #448, by @huebl
* Add usage of certificate chains in opc ua stack #401, by @huebl
* Add new thread and communication concept #339, by @huebl 
* Add configuration file to opc ua client application #301, by @huebl
* Replace slot timer callback function by timeoutfunction #285, by @huebl
* Added historical access vbi interface #155, by @huebl
* Remove class Pool and PoolBase #118, @huebl
* Use get endpoint request in opc ua client #112, by @huebl
* Implemented client security #5, by @huebl
* Server accepted unknown certificates #96, by @huebl
* Security implementation complicated #95, by @huebl
* Implement object type code generator #27, by @huebl
* Implement variable type code generator #26, by @huebl
* Integrate JSON encoder/decoder #39, by @huebl
* Rework OpcUaStackCore #47, by @huebl
* Implement data type code generator #8, by @huebl
* Implement enum type code generator #29, by @huebl
* Processing of type information not possible #22, by @huebl
* read and write values from xml nodeset #37, by @huebl
* add JSON mapping into OPC UA services #189 #191 #192 #193 #195 #196, by @huebl, @flipback

**Bugs**:

* fix compiltation for boost 1.70 and higher #428, by @flipback
* fix reconnect timer crash in session service #302, by @huebl
* Add isNull and setNull function to class OpcUaNodeId #278, @huebl
* Add Generator directory to cmake file #272, @huebl
* Add type generator library #270, @huebl
* Copy alias map in Config to childs #268, @huebl
* Init createAt field in open secure channel response #259, @huebl
* Reconnect after timeout if no entry found in endpoint cache #220, by @huebl
* Remove duplicate registration of extension objects #219, by @huebl
* Added server namespace 1 #92, by @huebl
* OPC UA server chrashes at startup #99, by @huebl
* Ignore optional placeholder element in code generator #78, by @huebl
* Double entry of CTRL C leads to crash #74, by @huebl
* Error occured during create a new opc ua application server #84, by @huebl
* Class OpcUaDataValue does not have an "<" operator #54, by @huebl
* Extensible Parameter us used incorrectly #36, by @huebl

**Documentation**:

* add *Overview* document #184, by @flipback
* add *Project Roadmap* section #246, by @flipback

Release 3.8.1
------------------------------------------------------------

**Bugs**:

* fix libssl-dev dependency for dev DEB package #314, by @flipback
* fix defaul endpoint URL #310, by @flipback

**Documentation**

* improve documentation #241 #264 #318, by @flipback 

Release 3.8.0 (2019-10-14)
------------------------------------------------------------

**Features**:

* add policy id to session config #168, by @huebl
* add option -j to build.bat to build on several CPUs on Windows #243, by @flipback
* add MinGW support #289, by @flipback

**Bugs**:

* fix initializing createAt field in open secure channel response #259, @huebl
* fix dependence of start\\stop item monitoring on callbacks #133, by @flipback
* fix overwriting result status in HistoryRead service #182, by @flipback

**Other**:

* integrate CI under Jenkins #234, by @flipback

Release 3.7.0 (2019-04-01)
------------------------------------------------------------


**Features**:

* refactoring application service interface #65, by @huebl
* add simple getter to password of UserNameIdentityToken #108, by @flipback
* improve performance of Information Model #120, by @flipback

**Bugs**:

* fix changing user in the same OPC UA session #105, by @huebl
* allow relative install path #130, by @huebl
* fix socket leak in discovery client #126, by @huebl
* fix calling stop monitored item callback #132, by @flipback
* fix crash  server during restart #109, by @huebl
* fix processing of create\delete node requests #158, by @huebl

**Documentation**:

* fix apt-get command in installation guide  #128, by @flipback
* add app build command for local stack #129, by @flipback
* add tutorials *Discovery Proccess*, *Data Access* and *Access Control* #82, by @flipback

Release 3.6.2 (2019-02-01)
------------------------------------------------------------

**Bugs**:

* fix filter in monitored item #101, by @TYZzzzzzz

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
