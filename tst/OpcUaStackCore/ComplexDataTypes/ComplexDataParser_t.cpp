#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataTypeParser_t)

BOOST_AUTO_TEST_CASE(ComplexDataTypeParser_parse)
{
	ComplexDataTypeParser parser;

	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);
}

BOOST_AUTO_TEST_SUITE_END()
