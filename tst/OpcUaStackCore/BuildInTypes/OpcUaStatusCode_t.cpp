#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
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
	std::stringstream ss;
	OpcUaStatusCode value1, value2;

	value1 = OpcUaStatusCode::x;
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2 == OpcUaStatusCode::x);
}

BOOST_AUTO_TEST_SUITE_END()