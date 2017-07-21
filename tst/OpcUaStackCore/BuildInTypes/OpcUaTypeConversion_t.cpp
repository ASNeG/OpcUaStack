#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaTypeConversion_)

BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_)
{
	std::cout << "OpcUaTypeConversion_t" << std::endl;
}

//
// I => implicit
// E => explicit
//

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Boolean
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Boolean_Byte_I)
{
	OpcUaBoolean value1;
	OpcUaByte value2;

	value1 = false;
	value2 = value1;
	BOOST_REQUIRE(value2 == 0);

	value1 = true;
	value2 = value1;
	BOOST_REQUIRE(value2 == 1);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Byte
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(OpcUaTypeConversion_Byte_Boolean_E)
{
	OpcUaByte value1;
	OpcUaBoolean value2;

	value1 = 0;
	value2 = value1;
	BOOST_REQUIRE(value2 == false);

	value1 = 1;
	value2 = value1;
	BOOST_REQUIRE(value2 == true);
}

BOOST_AUTO_TEST_SUITE_END()
