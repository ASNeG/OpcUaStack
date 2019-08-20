#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/AddNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/AddNodesResponse.h"
#include "OpcUaStackCore/ServiceSet/AttributesDescription.h"
#include "OpcUaStackCore/StandardDataTypes/ReferenceTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/MethodAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ViewAttributes.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(AddNodes_)

BOOST_AUTO_TEST_CASE(AddNodes_)
{
	std::cout << "AddNodes_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AddNodes_init)
{
	Core core;
	core.init();
}

BOOST_AUTO_TEST_CASE(AddNodes_Request)
{
	RequestHeader::SPtr requestHeader = boost::make_shared<RequestHeader>();
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	AddNodesRequest::SPtr addNodesRequestSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode channel id
	OpcUaUInt32 channelId;
	channelId = 153451225;
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaNumber::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_AddNodesRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode AddNodesRequest
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	addNodesRequestSPtr = boost::make_shared<AddNodesRequest>();

	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(1);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(10000);


	addNodesRequestSPtr->nodesToAdd()->resize(8);

	// add DataTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumDataType);

		DataTypeAttributes::SPtr dataTypeAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_DataTypeAttributes_Encoding_DefaultBinary);
		dataTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<DataTypeAttributes>();
		BOOST_REQUIRE(dataTypeAttributes.get() != nullptr);
		dataTypeAttributes->displayName().set("de", "Computer");
		dataTypeAttributes->description().set("de", "Hilfsmittel fuer die Programmerstellung");
		dataTypeAttributes->isAbstract() = false;
		dataTypeAttributes->writeMask() = WriteableAttribute_DataType;
		dataTypeAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(0, addNodesItemSPtr);
	}

	// add ObjectAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumObject);

		ObjectAttributes::SPtr objectAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_ObjectAttributes_Encoding_DefaultBinary);
		objectAttributes = addNodesItemSPtr->nodeAttributes().parameter<ObjectAttributes>();
		BOOST_REQUIRE(objectAttributes.get() != NULL);
		objectAttributes->displayName().set("de", "Mein Haus");
		objectAttributes->displayName().text();
		objectAttributes->description().set("de", "Mein Auto");
		objectAttributes->eventNotifier() = EventNotifierAttribute_SubscribeToEvents;
		objectAttributes->writeMask() = WriteableAttribute_WriteMask;
		objectAttributes->userWriteMask() = WriteableAttribute_WriteMask;

		addNodesRequestSPtr->nodesToAdd()->set(1, addNodesItemSPtr);
	}

	// add MethodAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumMethod);

		MethodAttributes::SPtr methodAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_MethodAttributes_Encoding_DefaultBinary);
		methodAttributes = addNodesItemSPtr->nodeAttributes().parameter<MethodAttributes>();
		BOOST_REQUIRE(methodAttributes.get() != NULL);
		methodAttributes->displayName().set("de", "kaufen");
		methodAttributes->description().set("de", "Der Erwerb einer Lizenz oder dem Besitz an einem Gegenstand");
		methodAttributes->executable() = true;
		methodAttributes->userExecutable() = false;
		methodAttributes->writeMask() = WriteableAttribute_DataType;
		methodAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(2, addNodesItemSPtr);
	}
		
	// add ObjectTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumObjectType);

		ObjectTypeAttributes::SPtr objectTypeAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_ObjectTypeAttributes_Encoding_DefaultBinary);
		objectTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<ObjectTypeAttributes>();
		BOOST_REQUIRE(objectTypeAttributes.get() != NULL);
		objectTypeAttributes->displayName().set("de", "Reservierung");
		objectTypeAttributes->description().set("de", "Beschreibt den Anspruch auf eine Leistung");
		objectTypeAttributes->isAbstract() = false;
		objectTypeAttributes->writeMask() = WriteableAttribute_DataType;
		objectTypeAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(3, addNodesItemSPtr);
	}

		
	// add ReferenceTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumReferenceType);

		ReferenceTypeAttributes::SPtr referenceTypeAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_ReferenceTypeAttributes_Encoding_DefaultBinary);
		referenceTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<ReferenceTypeAttributes>();
		BOOST_REQUIRE(referenceTypeAttributes.get() != NULL);
		referenceTypeAttributes->displayName().set("de", "ReservationsRef");
		referenceTypeAttributes->description().set("de", "Verweis auf Sitzplatzreservierungen");
		referenceTypeAttributes->isAbstract() = true;
		referenceTypeAttributes->symmetric() = false;
		referenceTypeAttributes->inverseName().set("de", "SeatRef");
		referenceTypeAttributes->writeMask() = WriteableAttribute_DataType;
		referenceTypeAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(4, addNodesItemSPtr);
	}
			
	// add ViewAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumView);

		ViewAttributes::SPtr viewAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_ViewAttributes_Encoding_DefaultBinary);
		viewAttributes = addNodesItemSPtr->nodeAttributes().parameter<ViewAttributes>();
		BOOST_REQUIRE(viewAttributes.get() != NULL);
		viewAttributes->displayName().set("de", "reservationsAtStation");
		viewAttributes->description().set("de", "Ausgabe der Sitzplatzreservierungen");
		viewAttributes->containsNoLoops() = true;
		viewAttributes->eventNotifier() = EventNotifierAttribute_SubscribeToEvents;
		viewAttributes->writeMask() = WriteableAttribute_DataType;
		viewAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(5, addNodesItemSPtr);
	}


	// add VariableAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumVariable);

		VariableAttributes::SPtr variableAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_VariableAttributes_Encoding_DefaultBinary);
		variableAttributes = addNodesItemSPtr->nodeAttributes().parameter<VariableAttributes>();
		BOOST_REQUIRE(variableAttributes.get() != NULL);
		variableAttributes->displayName().set("de", "resInfo");
		variableAttributes->description().set("de", "Reservierungsart");

		boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
		OpcUaDateTime dateTime;
		dateTime.dateTime(ptime1);
		variableAttributes->value().variant((OpcUaUInt16)1234);
		variableAttributes->dataType().set(12, 130);
		variableAttributes->valueRank() = 10;
		variableAttributes->arrayDimensions().resize(1);
		variableAttributes->arrayDimensions().set(0, 12);
		variableAttributes->accessLevel()  = 2;
		variableAttributes->userAccessLevel()  = 3;
		variableAttributes->minimumSamplingInterval() = 100;
		variableAttributes->historizing() =  false;
		variableAttributes->writeMask() = WriteableAttribute_DataType;
		variableAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(6, addNodesItemSPtr);
	}

	// add VariableTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr = boost::make_shared<AddNodesItem>();
		addNodesItemSPtr->parentNodeId().set(12,130);
		addNodesItemSPtr->referenceTypeId().set(11, 130);
		addNodesItemSPtr->requestedNewNodeId().set(13,130);
		addNodesItemSPtr->typeDefinition().set(14, 130);
		addNodesItemSPtr->browseName().name("browsename");
		addNodesItemSPtr->nodeClass().enumeration(NodeClass::EnumVariableType);

		VariableTypeAttributes::SPtr variableTypeAttributes;
		addNodesItemSPtr->nodeAttributes().parameterTypeId().set((OpcUaUInt32)OpcUaId_VariableTypeAttributes_Encoding_DefaultBinary);
		variableTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<VariableTypeAttributes>();
		BOOST_REQUIRE(variableTypeAttributes.get() != NULL);
		variableTypeAttributes->displayName().set("de", "resInfo");
		variableTypeAttributes->description().set("de", "Reservierungsart12345");

		boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
		OpcUaDateTime dateTime;
		dateTime.dateTime(ptime1);
		variableTypeAttributes->value().variant((OpcUaUInt16)1234);
		variableTypeAttributes->dataType().set(12, 130);
		variableTypeAttributes->valueRank() = 10;
		variableTypeAttributes->arrayDimensions().resize(1);
		variableTypeAttributes->arrayDimensions().set(0, 12);
		variableTypeAttributes->isAbstract() = false;
		variableTypeAttributes->writeMask()  = WriteableAttribute_DataType;
		variableTypeAttributes->userWriteMask() = WriteableAttribute_DataType;

		addNodesRequestSPtr->nodesToAdd()->set(7, addNodesItemSPtr);
	}

	requestHeader->opcUaBinaryEncode(ios1);
	addNodesRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	/*
	std::stringstream ss;
	ss	<< "4d 53 47 46 13 01 00 00  d9 7a 25 09 01 00 00 00"
		<< "34 00 00 00 02 00 00 00  01 00 cd 01 04 01 00 12"
		<< "34 56 78 9a bc de f0 12  34 56 78 9a bc de f0 00"
		<< "00 00 00 00 00 00 00 01  00 00 00 00 00 00 00 ff"
		<< "ff ff ff 10 27 00 00 00  00 00 1e 00 00 00 75 72"
		<< "6e 3a 6c 6f 63 61 6c 68  6f 73 74 3a 63 6f 6d 70"
		<< "79 6e 79 3a 55 6e 69 74  74 65 73 74 14 00 00 00"
		<< "75 72 6e 3a 63 6f 6d 70  61 6e 79 3a 55 6e 69 74"
		<< "74 65 73 74 02 10 00 00  00 63 6f 6d 70 61 6e 79"
		<< "20 55 6e 69 74 74 65 73  74 01 00 00 00 ff ff ff"
		<< "ff ff ff ff ff 00 00 00  00 ff ff ff ff 18 00 00"
		<< "00 6f 70 63 2e 74 63 70  3a 2f 2f 6c 6f 63 61 6c"
		<< "68 6f 73 74 3a 34 38 34  31 1e 00 00 00 75 72 6e"
		<< "3a 6c 6f 63 61 6c 68 6f  73 74 3a 63 6f 6d 70 61"
		<< "6e 79 3a 55 6e 69 74 74  65 73 74 0a 00 00 00 30"
		<< "31 32 33 34 35 36 37 38  39 0a 00 00 00 30 31 32"
		<< "33 34 35 36 37 38 39 00  00 00 00 80 4f 32 41 00"
		<< "00 00 00";
		BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);
    */

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_AddNodesRequest_Encoding_DefaultBinary);

	// decode AddNodesRequest
	addNodesRequestSPtr = boost::make_shared<AddNodesRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	addNodesRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 1);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 10000);

	BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd().get() != 0);
	BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->size() == 8);

	// verify DataTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(0, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumDataType);

		DataTypeAttributes::SPtr dataTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<DataTypeAttributes>();
		BOOST_REQUIRE(dataTypeAttributes.get() != NULL);
		BOOST_REQUIRE(dataTypeAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(dataTypeAttributes->displayName().text().value() == "Computer");
		BOOST_REQUIRE(dataTypeAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(dataTypeAttributes->description().text().value() == "Hilfsmittel fuer die Programmerstellung");
		BOOST_REQUIRE(dataTypeAttributes->isAbstract() == false);
		BOOST_REQUIRE(dataTypeAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(dataTypeAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	// verify ObjectAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(1, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumObject);

		ObjectAttributes::SPtr objectAttributes = addNodesItemSPtr->nodeAttributes().parameter<ObjectAttributes>();
		BOOST_REQUIRE(objectAttributes.get() != NULL);
		BOOST_REQUIRE(objectAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(objectAttributes->displayName().text().value() == "Mein Haus");
		BOOST_REQUIRE(objectAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(objectAttributes->description().text().value() == "Mein Auto");
	}

	
	// verify MethodAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(2, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumMethod);

		MethodAttributes::SPtr methodAttributes = addNodesItemSPtr->nodeAttributes().parameter<MethodAttributes>();
		BOOST_REQUIRE(methodAttributes.get() != NULL);
		BOOST_REQUIRE(methodAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(methodAttributes->displayName().text().value() == "kaufen");
		BOOST_REQUIRE(methodAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(methodAttributes->description().text().value() == "Der Erwerb einer Lizenz oder dem Besitz an einem Gegenstand");
		BOOST_REQUIRE(methodAttributes->executable() == true);
		BOOST_REQUIRE(methodAttributes->userExecutable() == false);
		BOOST_REQUIRE(methodAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(methodAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	// verify ObjectTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(3, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumObjectType);

		ObjectTypeAttributes::SPtr objectTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<ObjectTypeAttributes>();
		BOOST_REQUIRE(objectTypeAttributes.get() != NULL);
		BOOST_REQUIRE(objectTypeAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(objectTypeAttributes->displayName().text().value() == "Reservierung");
		BOOST_REQUIRE(objectTypeAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(objectTypeAttributes->description().text().value() == "Beschreibt den Anspruch auf eine Leistung");
		BOOST_REQUIRE(objectTypeAttributes->isAbstract() == false);
		BOOST_REQUIRE(objectTypeAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(objectTypeAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	
	// verify ReferenceTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(4, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumReferenceType);

		ReferenceTypeAttributes::SPtr referenceTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<ReferenceTypeAttributes>();
		BOOST_REQUIRE(referenceTypeAttributes.get() != NULL);
		BOOST_REQUIRE(referenceTypeAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(referenceTypeAttributes->displayName().text().value() == "ReservationsRef");
		BOOST_REQUIRE(referenceTypeAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(referenceTypeAttributes->description().text().value() == "Verweis auf Sitzplatzreservierungen");
		BOOST_REQUIRE(referenceTypeAttributes->isAbstract() == true);
		BOOST_REQUIRE(referenceTypeAttributes->symmetric() == false);
		BOOST_REQUIRE(referenceTypeAttributes->inverseName().locale().value() == "de");
		BOOST_REQUIRE(referenceTypeAttributes->inverseName().text().value() == "SeatRef");
		BOOST_REQUIRE(referenceTypeAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(referenceTypeAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	
	// verify ViewAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(5, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumView);

		ViewAttributes::SPtr viewAttributes = addNodesItemSPtr->nodeAttributes().parameter<ViewAttributes>();
		BOOST_REQUIRE(viewAttributes.get() != NULL);
		BOOST_REQUIRE(viewAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(viewAttributes->displayName().text().value() == "reservationsAtStation");
		BOOST_REQUIRE(viewAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(viewAttributes->description().text().value() == "Ausgabe der Sitzplatzreservierungen");
		BOOST_REQUIRE(viewAttributes->containsNoLoops() == true);
		BOOST_REQUIRE(viewAttributes->eventNotifier() == EventNotifierAttribute_SubscribeToEvents);
		BOOST_REQUIRE(viewAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(viewAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	// verify VariableAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(6, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumVariable);

		VariableAttributes::SPtr variableAttributes = addNodesItemSPtr->nodeAttributes().parameter<VariableAttributes>();
		BOOST_REQUIRE(variableAttributes.get() != NULL);
		BOOST_REQUIRE(variableAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(variableAttributes->displayName().text().value() == "resInfo");
		BOOST_REQUIRE(variableAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(variableAttributes->description().text().value() == "Reservierungsart");
		BOOST_REQUIRE(variableAttributes->value().variant<OpcUaUInt16>() == 1234);

		BOOST_REQUIRE(variableAttributes->dataType().namespaceIndex() == 130);
		BOOST_REQUIRE(variableAttributes->dataType().nodeId<OpcUaUInt32>() == 12);

		BOOST_REQUIRE(variableAttributes->valueRank() == 10);
		BOOST_REQUIRE(variableAttributes->arrayDimensions().size() == 1);
		OpcUaUInt32 arrayDimension;
		variableAttributes->arrayDimensions().get(0, arrayDimension);
		BOOST_REQUIRE(arrayDimension == 12);

		BOOST_REQUIRE(variableAttributes->accessLevel() == 2);
		BOOST_REQUIRE(variableAttributes->userAccessLevel() == 3);
		BOOST_REQUIRE(variableAttributes->minimumSamplingInterval() == 100);
		BOOST_REQUIRE(variableAttributes->historizing() == false);
		BOOST_REQUIRE(variableAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(variableAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	// verify VariableTypeAttributes node
	{
		AddNodesItem::SPtr addNodesItemSPtr;
		BOOST_REQUIRE(addNodesRequestSPtr->nodesToAdd()->get(7, addNodesItemSPtr));
		BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->parentNodeId().nodeId<OpcUaUInt32>() == 12);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addNodesItemSPtr->nodeClass().enumeration() == NodeClass::EnumVariableType);

		BOOST_REQUIRE(addNodesItemSPtr->nodeAttributes().parameterTypeId().namespaceIndex() == 0);
		BOOST_REQUIRE(addNodesItemSPtr->nodeAttributes().parameterTypeId().nodeId<OpcUaUInt32>() == OpcUaId_VariableTypeAttributes_Encoding_DefaultBinary);
		VariableTypeAttributes::SPtr variableTypeAttributes = addNodesItemSPtr->nodeAttributes().parameter<VariableTypeAttributes>();
		BOOST_REQUIRE(variableTypeAttributes.get() != NULL);
		BOOST_REQUIRE(variableTypeAttributes->displayName().locale().value() == "de");
		BOOST_REQUIRE(variableTypeAttributes->displayName().text().value() == "resInfo");
		BOOST_REQUIRE(variableTypeAttributes->description().locale().value() == "de");
		BOOST_REQUIRE(variableTypeAttributes->description().text().value() == "Reservierungsart12345");
		BOOST_REQUIRE(variableTypeAttributes->value().variant<OpcUaUInt16>() == 1234);

		BOOST_REQUIRE(variableTypeAttributes->dataType().namespaceIndex() == 130);
		BOOST_REQUIRE(variableTypeAttributes->dataType().nodeId<OpcUaUInt32>() == 12);

		BOOST_REQUIRE(variableTypeAttributes->valueRank() == 10);
		BOOST_REQUIRE(variableTypeAttributes->arrayDimensions().size() == 1);
		OpcUaUInt32 arrayDimension;
		variableTypeAttributes->arrayDimensions().get(0, arrayDimension);
		BOOST_REQUIRE(arrayDimension == 12);
		BOOST_REQUIRE(variableTypeAttributes->isAbstract() == false);
		BOOST_REQUIRE(variableTypeAttributes->writeMask() == WriteableAttribute_DataType);
		BOOST_REQUIRE(variableTypeAttributes->userWriteMask() == WriteableAttribute_DataType);
	}

	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12345));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12346));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12347));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12348));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12349));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12350));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12351));
	//BOOST_REQUIRE(eo.deregisterFactoryElement((OpcUaUInt32)12352));
}


BOOST_AUTO_TEST_CASE(AddNodes_Response)
{
	ResponseHeader::SPtr responseHeader = boost::make_shared<ResponseHeader>();
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	AddNodesResponse::SPtr addNodesResponseSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode channel id
	OpcUaUInt32 channelId;
	channelId = 153451225;
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaNumber::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(53);
	sequenceHeaderSPtr->requestId(3);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_AddNodesResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode AddNodesResponseResponse
	addNodesResponseSPtr = boost::make_shared<AddNodesResponse>();

	responseHeader->time(ptime);
	responseHeader->requestHandle(1);
	responseHeader->serviceResult(Success);

	AddNodesResultArray::SPtr addNodesResultArraySPtr = boost::make_shared<AddNodesResultArray>();
	addNodesResultArraySPtr->resize(1);
	{
		AddNodesResult::SPtr addNodesResultSPtr = boost::make_shared<AddNodesResult>();
		addNodesResultSPtr->statusCode(Success);
		OpcUaNodeId::SPtr addedNodeIdSPtr = boost::make_shared<OpcUaNodeId>();
		addedNodeIdSPtr->set(11, 130);
		addNodesResultSPtr->addedNodeId(addedNodeIdSPtr);
		addNodesResultArraySPtr->set(0, addNodesResultSPtr);		
	}

	addNodesResponseSPtr->results(addNodesResultArraySPtr);

	responseHeader->opcUaBinaryEncode(ios1);
	addNodesResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	/*
	std::stringstream ss;
	ss	<< "4d 53 47 46 40 00 00 00  d9 7a 25 09 01 00 00 00"
		<< "35 00 00 00 03 00 00 00  01 00 d6 01 00 00 00 00"
		<< "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
		<< "00 00 00 00 ff ff ff ff  00 00 00 00 00 00 00 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);
	*/

	
	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 53);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 3);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_AddNodesResponse_Encoding_DefaultBinary);

	//decode AddNodesResponse
	addNodesResponseSPtr = boost::make_shared<AddNodesResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	addNodesResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 1);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);
	BOOST_REQUIRE(addNodesResponseSPtr->results()->size() == 1);
	BOOST_REQUIRE(addNodesResponseSPtr->diagnosticInfos()->size() == 0);

	{
		AddNodesResult::SPtr addNodesResultSPtr;
		BOOST_REQUIRE(addNodesResponseSPtr->results()->get(0, addNodesResultSPtr));
		BOOST_REQUIRE(addNodesResultSPtr.get() != 0);
		BOOST_REQUIRE(addNodesResultSPtr->statusCode() == Success);
		BOOST_REQUIRE(addNodesResultSPtr->addedNodeId()->namespaceIndex() == 130);
		BOOST_REQUIRE(addNodesResultSPtr->addedNodeId()->nodeId<OpcUaUInt32>() == 11);
	}

}

BOOST_AUTO_TEST_SUITE_END()
