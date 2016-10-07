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

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
}

BOOST_AUTO_TEST_SUITE_END()
