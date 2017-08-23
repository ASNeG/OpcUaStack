#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaTypeConversion_)

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_)
{
	std::cout << "OpcUaTypeConversion_t" << std::endl;
}

#define SHOULD_NOT_CONVERT(sourceType, targetType) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->set<sourceType>(sourceType()); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_##sourceType, OpcUaBuildInType_##targetType)); \
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_##targetType, value2));         \
} while(0)

#define SHOULD_NOT_CONVERT_PTR(sourceType, targetType) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->variant(constructSPtr<sourceType>()); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_##sourceType, OpcUaBuildInType_##targetType)); \
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_##targetType, value2));         \
} while(0)

#define SHOULD_CONVERT(convType, sourceType, targetType, sourceValue, targetValue) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->set<sourceType>(sourceValue); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL(convType, converter.conversionType(OpcUaBuildInType_##sourceType, OpcUaBuildInType_##targetType)); \
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_##targetType, value2));         \
	BOOST_REQUIRE_EQUAL(targetValue, value2->get<targetType>()); \
} while(0)

#define SHOULD_CONVERT_PTR(convType, sourceType, targetType, sourceValue, targetValue) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->set<sourceType>(sourceValue); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL(convType, converter.conversionType(OpcUaBuildInType_##sourceType, OpcUaBuildInType_##targetType)); \
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_##targetType, value2));         \
	BOOST_REQUIRE_EQUAL(targetType(targetValue), *value2->getSPtr<targetType>()); \
} while(0)

#define SHOULD_CONVERT_2PTR(convType, sourceType, targetType, sourceValue, targetValue) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->variant(sourceValue); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL(convType, converter.conversionType(OpcUaBuildInType_##sourceType, OpcUaBuildInType_##targetType)); \
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_##targetType, value2));         \
	BOOST_REQUIRE_EQUAL(targetValue, *value2->getSPtr<targetType>()); \
} while(0)

#define SHOULD_BE_SAME(type, value) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->set<type>(value); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_##type, OpcUaBuildInType_##type)); \
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_##type, value2));         \
	BOOST_REQUIRE_EQUAL(value, value2->get<type>()); \
} while(0)

#define SHOULD_BE_SAME_PTR(type, value) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	value1->variant(value); \
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_##type, OpcUaBuildInType_##type)); \
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_##type, value2));         \
	BOOST_REQUIRE_EQUAL(*value, *value2->getSPtr<type>()); \
} while(0)

#define SHOULD_HAVE_RANK(type, rank) do {\
	OpcUaTypeConversion converter; \
	BOOST_REQUIRE_EQUAL(rank, converter.precedenceRank(OpcUaBuildInType_##type));\
} while(0)

#define CHECK_MAX(sourceType, targetType, delta) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	value1->set<sourceType>((sourceType)std::numeric_limits<targetType>::max() + delta); \
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_##targetType, value2)); \
} while(0)

#define CHECK_MIN(sourceType, targetType, delta) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	value1->set<sourceType>((sourceType)std::numeric_limits<targetType>::min() - delta); \
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_##targetType, value2)); \
} while(0)

#define CHECK_BAD_VALUE(sourceType, targetType, value) do {\
	OpcUaTypeConversion converter; \
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();\
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();\
															  \
	value1->set<sourceType>(value); \
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_##targetType, value2)); \
} while(0)

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Bool)
{
	SHOULD_HAVE_RANK			(OpcUaBoolean, 11);

	SHOULD_BE_SAME				(OpcUaBoolean, true);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaByte, true, 1);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaDateTime);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaDouble, true, 1.0);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaExpandedNodeId);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaFloat, true, 1.0);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaGuid);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaInt16, true, 1);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaInt32, true, 1);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaInt64, true, 1);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaNodeId);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaSByte, true, 1);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaStatusCode);
	SHOULD_CONVERT_PTR 			('E', OpcUaBoolean, OpcUaString, true, "1");
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaQualifiedName);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaUInt16, true, 1);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaUInt32, true, 1);
	SHOULD_CONVERT				('I', OpcUaBoolean, OpcUaUInt64, true, 1);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Byte)
{
	SHOULD_HAVE_RANK			(OpcUaByte, 10);

	SHOULD_CONVERT				('E', OpcUaByte, OpcUaBoolean, 128, true);
	SHOULD_BE_SAME				(OpcUaByte, 128);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaDateTime);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaDouble, 128, 128.0);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaExpandedNodeId);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaFloat, 128, 128.0f);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaGuid);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaInt16, 128, 128);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaInt32, 128, 128);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaInt64, 128, 128);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaNodeId);

	SHOULD_CONVERT				('I', OpcUaByte, OpcUaSByte, 127, 127);
	CHECK_MAX					(OpcUaByte, OpcUaSByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaStatusCode);
	SHOULD_CONVERT_PTR 			('E', OpcUaByte, OpcUaString, 128, "128");
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaQualifiedName);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaUInt16, 128, 128);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaUInt32, 128, 128);
	SHOULD_CONVERT				('I', OpcUaByte, OpcUaUInt64, 128, 128);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_ByteString)
{
	const std::string guidString = "\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37\x38";
	OpcUaByteString::SPtr bString = constructSPtr<OpcUaByteString>(guidString);

	SHOULD_HAVE_RANK			(OpcUaByteString, 18);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaBoolean);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaByte);
	SHOULD_BE_SAME_PTR			(OpcUaByteString, bString);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaDateTime);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaDouble);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaExpandedNodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaFloat);

	OpcUaGuid guid;
	guid.value("01020304-1112-2122-3132-333435363738");
	SHOULD_CONVERT_2PTR			('E', OpcUaByteString, OpcUaGuid, bString, guid);

	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaInt64);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaNodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaSByte);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaStatusCode);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaString);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaQualifiedName);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaUInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaUInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaUInt64);
	SHOULD_NOT_CONVERT_PTR		(OpcUaByteString, OpcUaXmlElement);

	// byteString -> Guid wrong format
	OpcUaTypeConversion converter;
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>("\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37\x38\x39");
	value1->variant(byteString);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	byteString = constructSPtr<OpcUaByteString>("\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37");
	value1->variant(byteString);
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_DateTime)
{
	OpcUaDateTime dt;
	dt.fromISOString("20020131T100001.123456");

	SHOULD_HAVE_RANK			(OpcUaDateTime, 19);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaBoolean);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaByte);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaByteString);
	SHOULD_BE_SAME				(OpcUaDateTime, dt);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaDouble);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaExpandedNodeId);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaFloat);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaGuid);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaInt16);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaInt32);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaInt64);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaNodeId);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaSByte);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaStatusCode);
	SHOULD_CONVERT_PTR			('E', OpcUaDateTime, OpcUaString, dt, "20020131T100001.123456");
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaQualifiedName);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaUInt16);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaUInt32);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaUInt64);
	SHOULD_NOT_CONVERT			(OpcUaDateTime, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Double)
{
	OpcUaTypeConversion converter;

	OpcUaDouble doubleValue = 24.5;

	SHOULD_HAVE_RANK			(OpcUaDouble, 0);
	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaBoolean, doubleValue, true);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaByte, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaByte, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaDateTime);
	SHOULD_BE_SAME				(OpcUaDouble, doubleValue);
	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaExpandedNodeId);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaFloat, doubleValue, 24.5f);
	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaGuid);
	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaInt16, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaInt16, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaInt16, 1);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaInt32, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaInt32, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaInt32, 1);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaInt64, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaInt64, 10000);
	CHECK_MIN					(OpcUaDouble, OpcUaInt64, 10000);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaSByte, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaSByte, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaSByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaStatusCode);
	SHOULD_CONVERT_PTR			('E', OpcUaDouble, OpcUaString, doubleValue, "24.5");

	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaQualifiedName);
	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaFloat, doubleValue, 24.5f);
	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaGuid);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaUInt16, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaUInt16, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaUInt16, 1);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaUInt32, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaUInt32, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaUInt32, 1);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaUInt64, doubleValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaUInt64, 10000);
	CHECK_MIN					(OpcUaDouble, OpcUaUInt64, 1);
	SHOULD_NOT_CONVERT			(OpcUaDouble, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_OpcUaExpandedNodeId)
{
	OpcUaTypeConversion converter;

	OpcUaExpandedNodeId::SPtr expandedNodeId = constructSPtr<OpcUaExpandedNodeId>();

	expandedNodeId->nodeId<OpcUaUInt32>(1000);
	expandedNodeId->namespaceUri("uri://test.namespace.org");
	expandedNodeId->serverIndex(1);

	SHOULD_HAVE_RANK			(OpcUaExpandedNodeId, 14);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaBoolean);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaByte);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaByteString);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaDateTime);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaDouble);
	SHOULD_BE_SAME_PTR			(OpcUaExpandedNodeId, expandedNodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaFloat);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaGuid);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaInt64);
	SHOULD_CONVERT_2PTR			('E', OpcUaExpandedNodeId, OpcUaNodeId, expandedNodeId, OpcUaNodeId(1000));
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaSByte);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaStatusCode);
	SHOULD_CONVERT_2PTR			('I', OpcUaExpandedNodeId, OpcUaString, expandedNodeId, OpcUaString("svr=1;nsu=uri://test.namespace.org;i=1000"));
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaQualifiedName);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaUInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaUInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaUInt64);
	SHOULD_NOT_CONVERT_PTR		(OpcUaExpandedNodeId, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Float)
{
	OpcUaFloat floatValue = 24.5;

	SHOULD_HAVE_RANK			(OpcUaFloat, 1);
	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaBoolean, floatValue, true);

	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaByte, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaByte, 1);
	CHECK_MIN					(OpcUaFloat, OpcUaByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaDateTime);
	SHOULD_CONVERT				('I',  OpcUaFloat, OpcUaDouble, floatValue, 24.5f);
	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaExpandedNodeId);

	SHOULD_BE_SAME				(OpcUaFloat, floatValue);
	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaGuid);
	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaInt16, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaInt16, 1);
	CHECK_MIN					(OpcUaFloat, OpcUaInt16, 1);

	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaInt32, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaInt32, 1000);
	CHECK_MIN					(OpcUaFloat, OpcUaInt32, 1000);

	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaInt64, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaInt64, 1e12);
	CHECK_MIN					(OpcUaFloat, OpcUaInt64, 1e12);

	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaSByte, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaSByte, 1);
	CHECK_MIN					(OpcUaFloat, OpcUaSByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaStatusCode);
	SHOULD_CONVERT_PTR			('E', OpcUaFloat, OpcUaString, floatValue, "24.5");

	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaQualifiedName);
	SHOULD_BE_SAME				(OpcUaFloat, floatValue);
	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaGuid);

	SHOULD_CONVERT				('E', OpcUaDouble, OpcUaUInt16, floatValue, 25);
	CHECK_MAX					(OpcUaDouble, OpcUaUInt16, 1);
	CHECK_MIN					(OpcUaDouble, OpcUaUInt16, 1);

	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaUInt32, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaUInt32, 1000);
	CHECK_MIN					(OpcUaFloat, OpcUaUInt32, 1);

	SHOULD_CONVERT				('E', OpcUaFloat, OpcUaUInt64, floatValue, 25);
	CHECK_MAX					(OpcUaFloat, OpcUaUInt64, 2e12);
	CHECK_MIN					(OpcUaFloat, OpcUaUInt64, 1);

	SHOULD_NOT_CONVERT			(OpcUaFloat, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Guid)
{
	OpcUaGuid::SPtr guid = constructSPtr<OpcUaGuid>();
	guid->value("01020304-1112-2122-3132-333435363738");
	guid->value();

	SHOULD_HAVE_RANK			(OpcUaGuid, 12);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaBoolean);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaByte);
	SHOULD_CONVERT_2PTR			('E', OpcUaGuid, OpcUaByteString, guid, OpcUaByteString("\x01\x02\x03\x04\x11\x12\x21\x22\x31\x32\x33\x34\x35\x36\x37\x38"));
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaDateTime);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaDouble);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaExpandedNodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaFloat);
	SHOULD_BE_SAME_PTR			(OpcUaGuid, guid);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaInt64);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaNodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaSByte);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaStatusCode);
	SHOULD_CONVERT_2PTR			('E', OpcUaGuid, OpcUaString, guid, OpcUaString(guid->value()));
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaQualifiedName);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaUInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaUInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaUInt64);
	SHOULD_NOT_CONVERT_PTR		(OpcUaGuid, OpcUaXmlElement);

}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Int16)
{
	OpcUaInt16 intVal = 28;

	SHOULD_HAVE_RANK			(OpcUaInt16, 7);

	SHOULD_CONVERT				('E', OpcUaInt16, OpcUaBoolean, intVal, true);

	SHOULD_CONVERT				('E', OpcUaInt16, OpcUaByte, intVal, 28);
	CHECK_MAX					(OpcUaInt16, OpcUaByte, 1);
	CHECK_MIN					(OpcUaInt16, OpcUaByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaDateTime);
	SHOULD_CONVERT				('I', OpcUaInt16, OpcUaDouble, intVal, 28.0);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaExpandedNodeId);
	SHOULD_CONVERT				('I', OpcUaInt16, OpcUaFloat, intVal, 28.0);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaGuid);

	SHOULD_BE_SAME				(OpcUaInt16, intVal);

	SHOULD_CONVERT				('I', OpcUaInt16, OpcUaInt32, intVal, 28);
	SHOULD_CONVERT				('I', OpcUaInt16, OpcUaInt64, intVal, 28);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaNodeId);

	SHOULD_CONVERT				('E', OpcUaInt16, OpcUaSByte, intVal, 28);
	CHECK_MAX					(OpcUaInt16, OpcUaSByte, 1);
	CHECK_MIN					(OpcUaInt16, OpcUaSByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaStatusCode);
	SHOULD_CONVERT_PTR			('E', OpcUaInt16, OpcUaString, intVal, "28");
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaQualifiedName);

	SHOULD_CONVERT				('E', OpcUaInt16, OpcUaUInt16, intVal, 28);
	CHECK_MIN					(OpcUaInt16, OpcUaUInt16, 1);

	SHOULD_CONVERT				('I', OpcUaInt16, OpcUaUInt32, intVal, 28);
	SHOULD_CONVERT				('I', OpcUaInt16, OpcUaUInt64, intVal, 28);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Int32)
{
	OpcUaInt32 intVal = 28;

	SHOULD_HAVE_RANK			(OpcUaInt32, 4);

	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaBoolean, intVal, true);
	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaByte, intVal, 28);
	CHECK_MAX					(OpcUaInt32, OpcUaByte, 1);
	CHECK_MIN					(OpcUaInt32, OpcUaByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaDateTime);
	SHOULD_CONVERT				('I', OpcUaInt32, OpcUaDouble, intVal, 28.0);
	SHOULD_NOT_CONVERT			(OpcUaInt16, OpcUaExpandedNodeId);
	SHOULD_CONVERT				('I', OpcUaInt32, OpcUaFloat, intVal, 28.0);
	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaGuid);

	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaInt16, intVal, 28);
	CHECK_MAX					(OpcUaInt32, OpcUaInt16, 1);
	CHECK_MIN					(OpcUaInt32, OpcUaInt16, 1);

	SHOULD_BE_SAME				(OpcUaInt32, intVal);

	SHOULD_CONVERT				('I', OpcUaInt32, OpcUaInt64, intVal, 28);
	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaNodeId);

	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaSByte, intVal, 28);
	CHECK_MAX					(OpcUaInt32, OpcUaSByte, 1);
	CHECK_MIN					(OpcUaInt32, OpcUaSByte, 1);

	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaStatusCode, 0x80350000, OpcUaStatusCode::BadAttributeIdInvalid);
	CHECK_BAD_VALUE				(OpcUaInt32, OpcUaStatusCode, 0xEFFFFFFF);

	SHOULD_CONVERT_PTR			('E', OpcUaInt32, OpcUaString, intVal, "28");
	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaQualifiedName);

	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaUInt16, intVal, 28);
	CHECK_MAX					(OpcUaInt32, OpcUaUInt16, 1);
	CHECK_MIN					(OpcUaInt32, OpcUaUInt16, 1);

	SHOULD_CONVERT				('E', OpcUaInt32, OpcUaUInt32, intVal, 28);
	CHECK_MIN					(OpcUaInt32, OpcUaUInt32, 1);

	SHOULD_CONVERT				('I', OpcUaInt32, OpcUaUInt64, intVal, 28);
	SHOULD_NOT_CONVERT			(OpcUaInt32, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Int64)
{
	OpcUaInt64 intVal = 28;

	SHOULD_HAVE_RANK			(OpcUaInt64, 2);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaBoolean, intVal, true);
	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaByte, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaByte, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaDateTime);
	SHOULD_CONVERT				('I', OpcUaInt64, OpcUaDouble, intVal, 28.0);
	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaExpandedNodeId);
	SHOULD_CONVERT				('I', OpcUaInt64, OpcUaFloat, intVal, 28.0);
	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaGuid);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaInt16, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaInt16, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaInt16, 1);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaInt32, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaInt32, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaInt32, 1);

	SHOULD_BE_SAME				(OpcUaInt64, intVal);

	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaNodeId);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaSByte, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaSByte, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaSByte, 1);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaStatusCode, 0x80350000, OpcUaStatusCode::BadAttributeIdInvalid);
	CHECK_BAD_VALUE				(OpcUaInt64, OpcUaStatusCode, 0xEFFFFFFF);

	SHOULD_CONVERT_PTR			('E', OpcUaInt64, OpcUaString, intVal, "28");
	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaQualifiedName);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaUInt16, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaUInt16, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaUInt16, 1);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaUInt32, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaUInt32, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaUInt32, 1);

	SHOULD_CONVERT				('E', OpcUaInt64, OpcUaUInt64, intVal, 28);
	CHECK_MAX					(OpcUaInt64, OpcUaUInt32, 1);
	CHECK_MIN					(OpcUaInt64, OpcUaUInt32, 1);

	SHOULD_NOT_CONVERT			(OpcUaInt64, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_NodeId)
{
	OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>(1000, 1);

	SHOULD_HAVE_RANK			(OpcUaNodeId, 15);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaBoolean);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaByte);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaByteString);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaDateTime);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaDouble);

	OpcUaExpandedNodeId expandedNodeId;
	expandedNodeId.nodeId<OpcUaUInt32>(1000);
	expandedNodeId.namespaceIndex(1);

	SHOULD_CONVERT_2PTR			('I', OpcUaNodeId, OpcUaExpandedNodeId, nodeId, expandedNodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaFloat);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaGuid);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaInt64);
	SHOULD_BE_SAME_PTR			(OpcUaNodeId, nodeId);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaSByte);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaStatusCode);
	SHOULD_CONVERT_2PTR			('I', OpcUaNodeId, OpcUaString, nodeId, OpcUaString("ns=1;i=1000"));
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaQualifiedName);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaUInt16);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaUInt32);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaUInt64);
	SHOULD_NOT_CONVERT_PTR		(OpcUaNodeId, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_SByte)
{
	OpcUaSByte sbyte = -46;
	SHOULD_HAVE_RANK			(OpcUaSByte, 9);

	SHOULD_CONVERT				('E', OpcUaSByte, OpcUaBoolean, sbyte, true);

	SHOULD_CONVERT				('E', OpcUaSByte, OpcUaByte, 45, 45);
	CHECK_MIN					(OpcUaSByte, OpcUaByte, 1);

	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaDateTime);
	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaDouble, sbyte, -46.0);
	SHOULD_NOT_CONVERT			(OpcUaByte, OpcUaExpandedNodeId);
	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaFloat, sbyte, -46.0f);
	SHOULD_NOT_CONVERT			(OpcUaBoolean, OpcUaGuid);
	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaInt16, sbyte, -46);
	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaInt32, sbyte, -46);
	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaInt64, sbyte, -46);
	SHOULD_NOT_CONVERT			(OpcUaSByte, OpcUaNodeId);

	SHOULD_BE_SAME				(OpcUaSByte, sbyte);

	SHOULD_NOT_CONVERT			(OpcUaSByte, OpcUaStatusCode);
	SHOULD_CONVERT_PTR 			('E', OpcUaSByte, OpcUaString, sbyte, "-46");
	SHOULD_NOT_CONVERT			(OpcUaSByte, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaSByte, OpcUaQualifiedName);
	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaUInt16, 45, 45);
	CHECK_MIN					(OpcUaSByte, OpcUaUInt16, 1);

	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaUInt32, 45, 45);
	CHECK_MIN					(OpcUaSByte, OpcUaUInt32, 1);

	SHOULD_CONVERT				('I', OpcUaSByte, OpcUaUInt64, 45, 45);
	CHECK_MIN					(OpcUaSByte, OpcUaUInt64, 1);

	SHOULD_NOT_CONVERT			(OpcUaSByte, OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_StatusCode)
{
	OpcUaStatusCode status = OpcUaStatusCode::BadAggregateConfigurationRejected;

	SHOULD_HAVE_RANK			(OpcUaStatusCode, 6);

	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaBoolean);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaByte);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaByteString);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaDateTime);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaExpandedNodeId);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaFloat);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaGuid);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaInt16);

	SHOULD_CONVERT				('I', OpcUaStatusCode, OpcUaInt32, status, 0x80DA0000);
	SHOULD_CONVERT				('I', OpcUaStatusCode, OpcUaInt64, status, 0x80DA0000);

	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaNodeId);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaSByte);

	SHOULD_BE_SAME				(OpcUaStatusCode, status);

	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaString);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaLocalizedText);
	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaQualifiedName);

	SHOULD_CONVERT				('E', OpcUaStatusCode, OpcUaUInt16, status, 0x80DA);
	SHOULD_CONVERT				('I', OpcUaStatusCode, OpcUaUInt32, status, 0x80DA0000);
	SHOULD_CONVERT				('I', OpcUaStatusCode, OpcUaUInt64, status, 0x80DA0000);

	SHOULD_NOT_CONVERT			(OpcUaStatusCode, OpcUaXmlElement);
}

BOOST_AUTO_TEST_SUITE_END()

