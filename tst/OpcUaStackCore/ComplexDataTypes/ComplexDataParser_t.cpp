#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataTypeParser_t)

BOOST_AUTO_TEST_CASE(ComplexDataTypeParser_parse)
{
	ComplexDataType::SPtr type;
	ComplexDataTypeParser parser;

	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);

	type = parser.complexDataType("BaseEventType");
	BOOST_REQUIRE(type.get() != nullptr);
	BOOST_REQUIRE(type->name() == "BaseEventType");

	// FIXME: todo
	std::cout << "...." << type->binaryTypeId().toString() << std::endl;
	//BOOST_REQUIRE(type->binaryTypeId() == OpcUaNodeId("i=2041"));

	BOOST_REQUIRE(type->index2Name(0) == "EventId");
	//BOOST_REQUIRE(type->ComplexDataType())

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
}

BOOST_AUTO_TEST_SUITE_END()
