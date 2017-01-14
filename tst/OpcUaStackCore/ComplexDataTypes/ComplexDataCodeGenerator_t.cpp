#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataCodeGenerator.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataCodeGenerator_t)

BOOST_AUTO_TEST_CASE(ComplexDataCodeGenerator_CodeGenerator)
{
	ComplexDataType::SPtr type;
	ComplexDataTypeParser parser;

	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);

}

BOOST_AUTO_TEST_SUITE_END()
