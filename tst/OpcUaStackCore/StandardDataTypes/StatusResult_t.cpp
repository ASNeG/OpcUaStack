#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(StatusResult_)

BOOST_AUTO_TEST_CASE(StatusResult_)
{
	std::cout << "StatusResult_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(StatusResult_encode_decode)
{
	StatusResult value1;
	StatusResult value2;

	value1.statusCode().enumeration((OpcUaStatusCode)1);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.statusCode().enumeration() == (OpcUaStatusCode)1);
}

BOOST_AUTO_TEST_CASE(StatusResult_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_StatusResult_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<StatusResult>()->statusCode().enumeration((OpcUaStatusCode)1);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<StatusResult>()->statusCode().enumeration() == (OpcUaStatusCode)1);
}

BOOST_AUTO_TEST_CASE(StatusResult_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_StatusResult_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<StatusResult>()->statusCode().enumeration((OpcUaStatusCode)1);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<StatusResult>()->statusCode().enumeration() == (OpcUaStatusCode)1);
}


BOOST_AUTO_TEST_SUITE_END()


