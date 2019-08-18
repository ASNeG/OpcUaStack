#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaExtensionObject_)

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_)
{
	std::cout << "OpcUaExtensionObject_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_body_no)
{
	std::stringstream ss;
	OpcUaExtensionObject value1, value2;

	BOOST_REQUIRE(value1.style() == OpcUaExtensionObject::S_None);

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.style() == OpcUaExtensionObject::S_None);
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_register)
{
	std::stringstream ss;
	OpcUaExtensionObject value1, value2;

	OpcUaExtensionObject eo;
	eo.registerFactoryElement<StatusResult>(OpcUaId_StatusResult_Encoding_DefaultBinary);
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_reset)
{
	OpcUaExtensionObject value;
	BOOST_REQUIRE(value.style() == OpcUaExtensionObject::S_None);

	OpcUaByteString::SPtr byteString;
	byteString = boost::make_shared<OpcUaByteString>();
	value.byteString(byteString);
	BOOST_REQUIRE(value.style() == OpcUaExtensionObject::S_ByteString);
	value.reset();

	StatusResult::SPtr statusResult;
	statusResult = value.parameter<StatusResult>(OpcUaId_StatusResult_Encoding_DefaultBinary);
	statusResult->statusCode().enumeration((OpcUaStatusCode)3494);
	BOOST_REQUIRE(value.style() == OpcUaExtensionObject::S_Type);
	value.reset();

	BOOST_REQUIRE(value.style() == OpcUaExtensionObject::S_None);
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_body_type)
{
	std::stringstream ss;
	OpcUaExtensionObject value1, value2;
	StatusResult::SPtr statusResult1, statusResult2;

	statusResult1 = value1.parameter<StatusResult>(OpcUaId_StatusResult_Encoding_DefaultBinary);
	statusResult1->statusCode().enumeration((OpcUaStatusCode)3494);
	BOOST_REQUIRE(value1.style() == OpcUaExtensionObject::S_Type);

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.style() == OpcUaExtensionObject::S_Type);
	BOOST_REQUIRE(value2.typeId().nodeId<OpcUaUInt32>() == OpcUaId_StatusResult_Encoding_DefaultBinary);
	statusResult2 = value2.parameter<StatusResult>();
	BOOST_REQUIRE(statusResult2.get() != nullptr);
	BOOST_REQUIRE(statusResult1->statusCode().enumeration() == 3494);
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_body_byteString)
{
	std::stringstream ss;
	OpcUaExtensionObject value1, value2;
	OpcUaByteString::SPtr byteString1, byteString2;

	byteString1 = boost::make_shared<OpcUaByteString>();
	byteString1->value(std::string("Dies ist ein ByteString"));
	value1.typeId(1234);
	value1.byteString(byteString1);
	BOOST_REQUIRE(value1.style() == OpcUaExtensionObject::S_ByteString);

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.style() == OpcUaExtensionObject::S_ByteString);
	BOOST_REQUIRE(value2.typeId().nodeId<OpcUaUInt32>() == 1234);
	byteString2 = value2.byteString();
	BOOST_REQUIRE(byteString2.get() != nullptr);
	BOOST_REQUIRE(byteString2->toHexString() == "44696573206973742065696E2042797465537472696E67");
}

BOOST_AUTO_TEST_SUITE_END()
