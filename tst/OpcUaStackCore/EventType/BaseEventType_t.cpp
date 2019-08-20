#include "unittest.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(BaseEventType_)

BOOST_AUTO_TEST_CASE(BaseEventType_)
{
	std::cout << "BaseEventType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(BaseEventType_construct_destruct)
{
	BaseEventType baseEventType;
}

BOOST_AUTO_TEST_CASE(BaseEventType_setter_error)
{
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	// invalid type
	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaString("String"));
	BOOST_REQUIRE(baseEventType.eventId(value) == false);
}

BOOST_AUTO_TEST_CASE(BaseEventType_setter_ok)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaByteString("ByteString"));
	BOOST_REQUIRE(baseEventType.eventId(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaNodeId(1));
	BOOST_REQUIRE(baseEventType.eventType(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaString("String"));
	BOOST_REQUIRE(baseEventType.sourceName(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaDateTime(now));
	BOOST_REQUIRE(baseEventType.localTime(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaLocalizedText("de", "text"));
	BOOST_REQUIRE(baseEventType.message(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaDateTime(now));
	BOOST_REQUIRE(baseEventType.receiveTime(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue((OpcUaUInt16)1);
	BOOST_REQUIRE(baseEventType.severity(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaNodeId(2));
	BOOST_REQUIRE(baseEventType.sourceNode(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaDateTime(now));
	BOOST_REQUIRE(baseEventType.time(value) == true);
}

BOOST_AUTO_TEST_CASE(BaseEventType_getter_ok)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaByteString("ByteString"));
	BOOST_REQUIRE(baseEventType.eventId(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaNodeId(1));
	BOOST_REQUIRE(baseEventType.eventType(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaString("String"));
	BOOST_REQUIRE(baseEventType.sourceName(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaDateTime(now));
	BOOST_REQUIRE(baseEventType.localTime(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaLocalizedText("de", "text"));
	BOOST_REQUIRE(baseEventType.message(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaDateTime(now));
	BOOST_REQUIRE(baseEventType.receiveTime(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue((OpcUaUInt16)1);
	BOOST_REQUIRE(baseEventType.severity(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaNodeId(2));
	BOOST_REQUIRE(baseEventType.sourceNode(value) == true);

	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaDateTime(now));
	BOOST_REQUIRE(baseEventType.time(value) == true);

	//
	// getter
	//
	value = baseEventType.eventId();
	OpcUaByteString eventId;
	BOOST_REQUIRE(value->getValue(eventId) == true);
	BOOST_REQUIRE(eventId == OpcUaByteString("ByteString"));

	value = baseEventType.eventType();
	OpcUaNodeId eventType;
	BOOST_REQUIRE(value->getValue(eventType) == true);
	BOOST_REQUIRE(eventType == OpcUaNodeId(1));

	value = baseEventType.sourceName();
	OpcUaString sourceName;
	BOOST_REQUIRE(value->getValue(sourceName) == true);
	BOOST_REQUIRE(sourceName == OpcUaString("String"));

	value = baseEventType.localTime();
	OpcUaDateTime localTime;
	BOOST_REQUIRE(value->getValue(localTime) == true);
	BOOST_REQUIRE(localTime == OpcUaDateTime(now));

	value = baseEventType.message();
	OpcUaLocalizedText message;
	BOOST_REQUIRE(value->getValue(message) == true);
	BOOST_REQUIRE(message == OpcUaLocalizedText("de", "text"));

	value = baseEventType.receiveTime();
	OpcUaDateTime receiveTime;
	BOOST_REQUIRE(value->getValue(receiveTime) == true);
	BOOST_REQUIRE(receiveTime == OpcUaDateTime(now));

	value = baseEventType.severity();
	OpcUaUInt16 severity;
	BOOST_REQUIRE(value->getValue(severity) == true);
	BOOST_REQUIRE(severity == (OpcUaUInt16)1);

	value = baseEventType.sourceNode();
	OpcUaNodeId sourceNode;
	BOOST_REQUIRE(value->getValue(sourceNode) == true);
	BOOST_REQUIRE(sourceNode == OpcUaNodeId(2));

	value = baseEventType.time();
	OpcUaDateTime time;
	BOOST_REQUIRE(value->getValue(time) == true);
	BOOST_REQUIRE(time == OpcUaDateTime(now));
}

BOOST_AUTO_TEST_CASE(BaseEventType_namespace_index)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	//
	// map namespace uri to namespace index
	//
	EventBase* eventBase = &baseEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("");
	eventBase->namespaceArray(&namespaceVec);

	OpcUaNodeId typeNodeId;
	baseEventType.eventType()->getValue(typeNodeId);
	BOOST_REQUIRE(typeNodeId == OpcUaNodeId((OpcUaUInt32)2041));
}

BOOST_AUTO_TEST_CASE(BaseEventType_broeseNameList_empty)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	//
	// map namespace uri to namespace index
	//
	EventBase* eventBase = &baseEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("");
	eventBase->namespaceArray(&namespaceVec);

	OpcUaNodeId typeNodeId;
	baseEventType.eventType()->getValue(typeNodeId);
	BOOST_REQUIRE(typeNodeId == OpcUaNodeId((OpcUaUInt32)2041));

	// get event type
	OpcUaNodeId eventType("Unknown");
	bool eventFound = false;
	std::list<OpcUaQualifiedName::SPtr> browseNameList;
	OpcUaVariant::SPtr variant;
	//BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::BadBrowseNameListEmpty);
	//BOOST_REQUIRE(variant.get() == nullptr);
}

BOOST_AUTO_TEST_CASE(BaseEventType_typeId_unknwon)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	//
	// map namespace uri to namespace index
	//
	EventBase* eventBase = &baseEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("");
	eventBase->namespaceArray(&namespaceVec);

	OpcUaNodeId typeNodeId;
	baseEventType.eventType()->getValue(typeNodeId);
	BOOST_REQUIRE(typeNodeId == OpcUaNodeId((OpcUaUInt32)2041));

	// get event type
	OpcUaNodeId eventType("Unknown");
	bool eventFound = false;
	std::list<OpcUaQualifiedName::SPtr> browseNameList;
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Unknown"));
	bool error = false;
	OpcUaVariant::SPtr variant;
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::BadEventTypeNotExist);
	BOOST_REQUIRE(variant.get() == nullptr);
}

BOOST_AUTO_TEST_CASE(BaseEventType_browsName_unknwon)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	//
	// map namespace uri to namespace index
	//
	EventBase* eventBase = &baseEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("");
	eventBase->namespaceArray(&namespaceVec);

	OpcUaNodeId typeNodeId;
	baseEventType.eventType()->getValue(typeNodeId);
	BOOST_REQUIRE(typeNodeId == OpcUaNodeId((OpcUaUInt32)2041));

	// get event type
	OpcUaNodeId eventType((OpcUaUInt32)2041);
	bool eventFound = false;
	std::list<OpcUaQualifiedName::SPtr> browseNameList;
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Unknown"));
	bool error = false;
	OpcUaVariant::SPtr variant;
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::BadValueNotExist);
	BOOST_REQUIRE(variant.get() == nullptr);
}

BOOST_AUTO_TEST_CASE(BaseEventType_variant_not_exist)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	//
	// map namespace uri to namespace index
	//
	EventBase* eventBase = &baseEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("");
	eventBase->namespaceArray(&namespaceVec);

	OpcUaNodeId typeNodeId;
	baseEventType.eventType()->getValue(typeNodeId);
	BOOST_REQUIRE(typeNodeId == OpcUaNodeId((OpcUaUInt32)2041));

	// get event type
	OpcUaNodeId eventType((OpcUaUInt32)2041);
	bool eventFound = false;
	std::list<OpcUaQualifiedName::SPtr> browseNameList;
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("EventId"));
	bool error = false;
	OpcUaVariant::SPtr variant;
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::BadValueNotExist);
	BOOST_REQUIRE(variant.get() == nullptr);
}

BOOST_AUTO_TEST_CASE(BaseEventType_variant_success)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaVariant::SPtr value;
	BaseEventType baseEventType;

	//
	// set event id
	//
	value = boost::make_shared<OpcUaVariant>();
	value->setValue(OpcUaByteString("ByteString"));
	BOOST_REQUIRE(baseEventType.eventId(value) == true);

	//
	// map namespace uri to namespace index
	//
	EventBase* eventBase = &baseEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("");
	eventBase->namespaceArray(&namespaceVec);

	OpcUaNodeId typeNodeId;
	baseEventType.eventType()->getValue(typeNodeId);
	BOOST_REQUIRE(typeNodeId == OpcUaNodeId((OpcUaUInt32)2041));

	//
	// get event type
	//
	OpcUaNodeId eventType((OpcUaUInt32)2041);
	bool eventFound = false;
	std::list<OpcUaQualifiedName::SPtr> browseNameList;
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("EventId"));
	bool error = false;
	OpcUaVariant::SPtr variant;
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::Success);
	BOOST_REQUIRE(variant.get() != nullptr);
	OpcUaByteString byteString;
	BOOST_REQUIRE(variant->getValue(byteString) == true);
	BOOST_REQUIRE(byteString == OpcUaByteString("ByteString"));
}


BOOST_AUTO_TEST_SUITE_END()
