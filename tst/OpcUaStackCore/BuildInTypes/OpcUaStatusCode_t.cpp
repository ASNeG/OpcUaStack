#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaStatusCode_)

BOOST_AUTO_TEST_CASE(OpcUaStatusCode_)
{
	std::cout << "OpcUaStatusCode_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaStatusCode_encode_decode)
{
	OpcUaInt32 tmp;
	std::stringstream ss;
	OpcUaStatusCode value1, value2;

	value1 = BadUnexpectedError;
	
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, tmp); value2 = (OpcUaStatusCode)tmp;

	BOOST_REQUIRE(value2 == BadUnexpectedError);
}

BOOST_AUTO_TEST_SUITE_END()
