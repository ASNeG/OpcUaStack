#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataCodeGenerator.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataCodeGenerator_t)

BOOST_AUTO_TEST_CASE(ComplexDataCodeGenerator_CodeGenerator)
{
	// parse configuration
	ComplexDataTypeParser parser;
	parser.mergeSuperType(false);
	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);

	// get type
	ComplexDataType::SPtr type;
	type = parser.complexDataType("MyComplexType1");
	BOOST_REQUIRE(type.get() != nullptr);

	// run code generator
	ComplexDataCodeGenerator generator;
	generator.classTemplateFileHeader("../tst/data/OpcUaComplexDataType.h.tmpl");
	generator.classTemplateFileSource("../tst/data/OpcUaComplexDataType.cpp.tmpl");
	BOOST_REQUIRE(generator.generate(*type) == true);

	std::cout << "============================" << std::endl;
	std::cout << generator.contentHeader() << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << generator.contentSource() << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
