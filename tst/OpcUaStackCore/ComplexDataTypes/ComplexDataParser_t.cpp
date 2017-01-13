#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataTypeParser_t)

BOOST_AUTO_TEST_CASE(ComplexDataTypeParser_parse)
{
	ComplexDataType::SPtr type;
	ComplexDataTypeParser parser;

	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);

	// BaseEventType
	type = parser.complexDataType("BaseEventType");
	BOOST_REQUIRE(type.get() != nullptr);
	BOOST_REQUIRE(type->name() == "BaseEventType");

	BOOST_REQUIRE(type->index2Name(0) == "EventId");
	BOOST_REQUIRE(type->complexDataTypeItem(0)->itemType() == OpcUaBuildInType_OpcUaByteString);
	BOOST_REQUIRE(type->complexDataTypeItem(0)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(1) == "EventType");
	BOOST_REQUIRE(type->complexDataTypeItem(1)->itemType() == OpcUaBuildInType_OpcUaNodeId);
	BOOST_REQUIRE(type->complexDataTypeItem(1)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(6) == "Message");
	BOOST_REQUIRE(type->complexDataTypeItem(6)->itemType() == OpcUaBuildInType_OpcUaLocalizedText);
	BOOST_REQUIRE(type->complexDataTypeItem(6)->mandatory() == true);
}


#if 0
	<ComplexDataType TypeName="BaseEventType" TypeBinaryNodeId="i=2041">
	    <Variable Name="EventId" 	 Type="ByteString" 		 ModellingRule="M"></Variable>
	    <Variable Name="EventType" 	 Type="NodeId" 			 ModellingRule="M"></Variable>
	    <Variable Name="SourceNode"  Type="NodeId"	 		 ModellingRule="M"></Variable>
	    <Variable Name="SourceName"  Type="String" 			 ModellingRule="M"></Variable>
	    <Variable Name="Time" 		 Type="DateTime" 		 ModellingRule="M"></Variable>
	    <Variable Name="ReceiveTime" Type="DateTime" 		 ModellingRule="M"></Variable>
	  <!--  <Variable Name="LocalTime" 	 Type="TimeZoneDataType" ModellingRule="O"></Variable> -->
	    <Variable Name="Message" 	 Type="LocalizedText" 	 ModellingRule="M"></Variable>
	    <Variable Name="Severity" 	 Type="UInt16" 			 ModellingRule="M"></Variable>
	</ComplexDataType>

	<ComplexDataType TypeName="AuditEventType" HasSupertype="BaseEventType" TypeBinaryNodeId="i=2052">
	    <Variable Name="ActionTimeStamp" 	Type="DateTime" ModellingRule="M"></Variable>
	    <Variable Name="Status" 	 	    Type="Boolean" 	ModellingRule="M"></Variable>
	    <Variable Name="ServerId" 	 	    Type="String" 	ModellingRule="M"></Variable>
	    <Variable Name="ClientAuditEntryId" Type="String" 	ModellingRule="M"></Variable>
	    <Variable Name="ClientUserId" 	    Type="String" 	ModellingRule="M"></Variable>
	</ComplexDataType>
#endif

BOOST_AUTO_TEST_SUITE_END()
