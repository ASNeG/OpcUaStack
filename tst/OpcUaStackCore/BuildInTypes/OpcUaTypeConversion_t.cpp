#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaTypeConversion_)

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_)
{
	std::cout << "OpcUaTypeConversion_t" << std::endl;
}

//
// I => implicit
// E => explicit
//

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Boolean
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Boolean_Byte_I)
{
	OpcUaBoolean value1;
	OpcUaByte value2;

	value1 = false;
	value2 = value1;
	BOOST_REQUIRE(value2 == 0);

	value1 = true;
	value2 = value1;
	BOOST_REQUIRE(value2 == 1);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Byte
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Byte_Boolean_E)
{
	OpcUaByte value1;
	OpcUaBoolean value2;

	value1 = 0;
	value2 = value1;
	BOOST_REQUIRE(value2 == false);

	value1 = 1;
	value2 = value1;
	BOOST_REQUIRE(value2 == true);
}

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Bool)
{
	OpcUaTypeConversion converter;
	OpcUaVariant::SPtr value1 = constructSPtr<OpcUaVariant>();
	value1->set<OpcUaBoolean>(true);

	OpcUaVariant::SPtr value2 = constructSPtr<OpcUaVariant>();

	// bool -> bool
	BOOST_REQUIRE_EQUAL('-', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaBoolean));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaBoolean, value2));
	BOOST_REQUIRE(value2->get<OpcUaBoolean>());

	// bool -> byte
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaByte, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaByte>());

	// bool -> byteString
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaByteString));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaByteString, value2));

	// bool -> dateTime
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaDateTime));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaDateTime, value2));

	// bool -> double
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaDouble));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaDouble, value2));
	BOOST_REQUIRE_EQUAL(1.0, value2->get<OpcUaDouble>());

	// bool -> expandedNode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaExpandedNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaExpandedNodeId, value2));

	// bool -> double
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaFloat));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaFloat, value2));
	BOOST_REQUIRE_EQUAL(1.0f, value2->get<OpcUaFloat>());

	// bool -> guid
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaGuid));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaGuid, value2));

	// bool -> int16
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt16, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaInt16>());

	// bool -> int32
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt32, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaInt32>());

	// bool -> int64
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaInt64, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaInt64>());

	// bool -> nodeId
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaNodeId));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaNodeId, value2));

	// bool -> sbyte
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaSByte));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaSByte, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaSByte>());

	// bool -> statusCode
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaStatusCode));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaStatusCode, value2));

	// bool -> string
	BOOST_REQUIRE_EQUAL('E', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaString));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaString, value2));
	BOOST_REQUIRE_EQUAL(OpcUaString("true"), *value2->getSPtr<OpcUaString>());

	// bool -> localizedText
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaLocalizedText));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaLocalizedText, value2));

	// bool -> qualifiedName
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaQualifiedName));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaQualifiedName, value2));

	// bool -> uint16
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaUInt16));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt16, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaUInt16>());

	// bool -> uint32
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaUInt32));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt32, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaUInt32>());

	// bool -> int64
	BOOST_REQUIRE_EQUAL('I', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaUInt64));
	BOOST_REQUIRE(converter.conversion(value1, OpcUaBuildInType_OpcUaUInt64, value2));
	BOOST_REQUIRE_EQUAL(1, value2->get<OpcUaUInt64>());

	// bool -> xmlElement
	BOOST_REQUIRE_EQUAL('X', converter.conversionType(OpcUaBuildInType_OpcUaBoolean, OpcUaBuildInType_OpcUaXmlElement));
	BOOST_REQUIRE(!converter.conversion(value1, OpcUaBuildInType_OpcUaXmlElement, value2));
}

BOOST_AUTO_TEST_SUITE_END()
