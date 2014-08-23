#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/AddNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(AddNodes_)

BOOST_AUTO_TEST_CASE(AddNodes_)
{
	std::cout << "AddNodes_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AddNodes_Request)
{
	ExtensibleParameter ep;
	BOOST_REQUIRE(ep.registerFactoryElement<DataTypeAttributes>((OpcUaUInt32)12345) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<MethodAttributes>((OpcUaUInt32)12346) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<ObjectAttributes>((OpcUaUInt32)12347) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<ObjectTypeAttributes>((OpcUaUInt32)12348) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<ReferenceTypeAttributes>((OpcUaUInt32)12349) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<VariableAttributes>((OpcUaUInt32)12350) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<VariableTypeAttributes>((OpcUaUInt32)12351) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<ViewAttributes>((OpcUaUInt32)12352) == true);
	

	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T120000.000000000");
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
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_AddNodesRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode AddNodesRequest
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	addNodesRequestSPtr = AddNodesRequest::construct();

	addNodesRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	addNodesRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	addNodesRequestSPtr->requestHeader()->time(ptime);
	addNodesRequestSPtr->requestHeader()->requestHandle(1);
	addNodesRequestSPtr->requestHeader()->returnDisagnostics(0);
	addNodesRequestSPtr->requestHeader()->timeoutHint(10000);

	AddNodesItemArray::SPtr addNodesItemArray = AddNodesItemArray::construct();

	// create a AddNodesItem with a referenceTypeId(namespaceIndex=130, nodeId=11) and a ObjectAttributes instance 
	AddNodesItem::SPtr addNodesItemSPtr = AddNodesItem::construct();

	OpcUaNodeId::SPtr objectIdSPtr = OpcUaNodeId::construct();
	objectIdSPtr->namespaceIndex(130);
	objectIdSPtr->nodeId((OpcUaUInt32)11);
	addNodesItemSPtr->referenceTypeId(objectIdSPtr);
	ExtensibleParameter &nodeAttributes = addNodesItemSPtr->nodeAttributes();
	
	nodeAttributes.parameterTypeId().set((OpcUaUInt32)12345);
	ObjectAttributes::SPtr objectAttributes = nodeAttributes.parameter<ObjectAttributes>();
	BOOST_REQUIRE(objectAttributes.get() != NULL);
		
	OpcUaLocalizedText::SPtr opcUaLocalizedText = OpcUaLocalizedText::construct();
	opcUaLocalizedText->text("Mein Haus");
	objectAttributes->displayName(opcUaLocalizedText);
	addNodesItemArray->push_back(addNodesItemSPtr);

	addNodesRequestSPtr->nodesToAdd(addNodesItemArray);
	addNodesRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
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
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_AddNodesRequest_Encoding_DefaultBinary);

	// decode AddNodesRequest
	addNodesRequestSPtr = AddNodesRequest::construct();
	addNodesRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *addNodesRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(addNodesRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(addNodesRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(addNodesRequestSPtr->requestHeader()->requestHandle() == 1);
	BOOST_REQUIRE(addNodesRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(addNodesRequestSPtr->requestHeader()->timeoutHint() == 10000);
	addNodesItemArray = addNodesRequestSPtr->nodesToAdd();
	BOOST_REQUIRE(addNodesItemArray.get() != 0);

	BOOST_REQUIRE(addNodesItemArray->size() == 1);
	BOOST_REQUIRE(addNodesItemArray->get(0, addNodesItemSPtr));
	BOOST_REQUIRE(addNodesItemSPtr.get() != 0);

	BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId().get() != NULL);
	std::cout << "Hier geht schon was schief, referenceTypeId.namespaceIndex=" << addNodesItemSPtr->referenceTypeId()->namespaceIndex() << " !!!" << std::endl;
	BOOST_REQUIRE(addNodesItemSPtr->referenceTypeId()->namespaceIndex() == 130);

	{
		ExtensibleParameter &nodeAttributes = addNodesItemSPtr->nodeAttributes();
		objectAttributes = nodeAttributes.parameter<ObjectAttributes>();
		BOOST_REQUIRE(objectAttributes.get() != NULL);
		BOOST_REQUIRE(objectAttributes->displayName()->text().value() == "Mein Haus");
	}

	
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12345));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12346));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12347));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12348));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12349));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12350));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12351));
	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12352));
}


BOOST_AUTO_TEST_SUITE_END()
