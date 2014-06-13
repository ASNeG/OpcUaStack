#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaXmlElement.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaXmlElement_)

BOOST_AUTO_TEST_CASE(OpcUaXmlElement_)
{
	std::cout << "OpcUaXmlElement_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaXmlElement_null)
{
	std::stringstream ss;
	OpcUaXmlElement value1, value2;

	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
}

BOOST_AUTO_TEST_SUITE_END()