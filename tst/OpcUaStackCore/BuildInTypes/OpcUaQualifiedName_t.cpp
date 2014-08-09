#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaQualifiedName_)

BOOST_AUTO_TEST_CASE(OpcUaQualifiedName_)
{
	std::cout << "OpcUaQualifiedName_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaQualifiedName_encode_decode)
{
	std::stringstream ss;
	OpcUaQualifiedName value1, value2;

	value1 = "ABC";			// name
	value1 = 12;			// namespaceIndex
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.name().value() == "ABC");
	BOOST_REQUIRE(value2.namespaceIndex() == 12);
}

BOOST_AUTO_TEST_SUITE_END()