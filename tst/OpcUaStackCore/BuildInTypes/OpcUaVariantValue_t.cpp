#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaVariantValue_)

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_)
{
	std::cout << "OpcUaVariantValue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_uint32_copyTo)
{
	OpcUaVariantValue value1, value2;
	value1.variant((OpcUaUInt32)123);

	value1.copyTo(value2);

	BOOST_REQUIRE(value1.variant<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(value2.variant<OpcUaUInt32>() == 123);

	value2.variant((OpcUaUInt32)456);

	BOOST_REQUIRE(value1.variant<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(value2.variant<OpcUaUInt32>() == 456);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_localizedText_copyTo)
{
	OpcUaLocalizedText::SPtr localizedTextSPtr1 = OpcUaLocalizedText::construct();
	OpcUaLocalizedText::SPtr localizedTextSPtr2;

	localizedTextSPtr1->locale("de");
	localizedTextSPtr1->text("text1");

	OpcUaVariantValue value1, value2;
	value1.variant(localizedTextSPtr1);

	value1.copyTo(value2);

	localizedTextSPtr1 = value1.variantSPtr<OpcUaLocalizedText>();
	localizedTextSPtr2 = value2.variantSPtr<OpcUaLocalizedText>();
	BOOST_REQUIRE(localizedTextSPtr1->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr1->text().value() == "text1");
	BOOST_REQUIRE(localizedTextSPtr2->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr2->text().value() == "text1");

	localizedTextSPtr1->text("text2");

	BOOST_REQUIRE(localizedTextSPtr1->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr1->text().value() == "text2");
	BOOST_REQUIRE(localizedTextSPtr2->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr2->text().value() == "text1");
}

// 

BOOST_AUTO_TEST_SUITE_END()