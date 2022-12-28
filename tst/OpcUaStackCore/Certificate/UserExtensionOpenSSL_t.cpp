#include "OpcUaStackCore/Certificate/UserExtensionOpenSSL.h"

#include "unittest.h"

BOOST_AUTO_TEST_SUITE(UserExtensionOpenSSL_)

BOOST_AUTO_TEST_CASE(UserExtensionOpenSSL_)
{
	std::cout << "UserExtensionOpenSSL_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(UserExtensionOpenSSL__encode_decode)
{
	std::string value;
	OpcUaStackCore::UserExtensionOpenSSL ue1, ue2;

	// encode extension
	BOOST_REQUIRE(ue1.setEntry("N1", "V1") == true);
	BOOST_REQUIRE(ue1.setEntry("N2", "V2") == true);
	BOOST_REQUIRE(ue1.setEntry("N3", "V3") == true);
	BOOST_REQUIRE(ue1.encodeExtention() == true);

	// copy extension
	ue2.setExtension(ue1.getExtension());
	ue1.setExtension(NULL);

	// decode extension
	BOOST_REQUIRE(ue2.decodeExtention() == true);
	BOOST_REQUIRE(ue2.getEntry("N1", value) == true);
	BOOST_REQUIRE(value == "V1");
	BOOST_REQUIRE(ue2.getEntry("N2", value) == true);
	BOOST_REQUIRE(value == "V2");
	BOOST_REQUIRE(ue2.getEntry("N3", value) == true);
	BOOST_REQUIRE(value == "V3");
}

BOOST_AUTO_TEST_SUITE_END()
