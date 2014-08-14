#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ExtensibleParameter_)

BOOST_AUTO_TEST_CASE(ExtensibleParameter_Factory)
{
	ExtensibleParameter ep;


}

BOOST_AUTO_TEST_CASE(ExtensibleParameter_)
{
	std::cout << "ExtensibleParameter_t" << std::endl;

#if 0
	uint32_t pos;
	OpcUaByte* opcUaByte;
	OpcUaInt32 opcUaByteLen;
	UserTokenPolicy::SPtr userTokenPolicySPtr;
	ExtensibleParameter::SPtr ExtensibleParameterSPtr;

	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode ExtensibleParameter
	ExtensibleParameterSPtr = ExtensibleParameter::construct();
	
	ExtensibleParameterSPtr->endpointUrl("opt.tcp://localhost:481/0.0.0.0");
	ExtensibleParameterSPtr->applicationDescription()->applicationUri("urn:localhost:compyny:Unittest");
	ExtensibleParameterSPtr->applicationDescription()->productUri("urn:company:Unittest");
	ExtensibleParameterSPtr->applicationDescription()->applicationName().text("company Unittest");
	ExtensibleParameterSPtr->applicationDescription()->applicationType(ApplicationType_Server);
	ExtensibleParameterSPtr->applicationDescription()->discoveryUrls()->resize(1);
	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	ExtensibleParameterSPtr->applicationDescription()->discoveryUrls()->set(0, opcUaStringSPtr);
	ExtensibleParameterSPtr->serverCertificate((OpcUaByte*)"0123456789", 10);
	ExtensibleParameterSPtr->messageSecurityMode(MessageSecurityMode_None);
	ExtensibleParameterSPtr->securityPolicyUri("http://opcfoundation.org/UA/SecurityPolicy#None");

	ExtensibleParameterSPtr->userIdentityTokens()->resize(1);
	userTokenPolicySPtr = UserTokenPolicy::construct();
	userTokenPolicySPtr->policyId("OpcUaStack");
	userTokenPolicySPtr->tokenType(UserIdentityTokenType_Anonymous);
	ExtensibleParameterSPtr->userIdentityTokens()->push_back(userTokenPolicySPtr);

	ExtensibleParameterSPtr->transportProfileUri("http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	ExtensibleParameterSPtr->securityLevel(0);

	ExtensibleParameterSPtr->opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "1f 00 00 00 6f 70 74 2e  74 63 70 3a 2f 2f 6c 6f"
		<< "63 61 6c 68 6f 73 74 3a  34 38 31 2f 30 2e 30 2e"
		<< "30 2e 30 1e 00 00 00 75  72 6e 3a 6c 6f 63 61 6c"
		<< "68 6f 73 74 3a 63 6f 6d  70 79 6e 79 3a 55 6e 69"
		<< "74 74 65 73 74 14 00 00  00 75 72 6e 3a 63 6f 6d"
		<< "70 61 6e 79 3a 55 6e 69  74 74 65 73 74 02 10 00"
		<< "00 00 63 6f 6d 70 61 6e  79 20 55 6e 69 74 74 65"
		<< "73 74 00 00 00 00 ff ff  ff ff ff ff ff ff 01 00"
		<< "00 00 20 00 00 00 6f 70  74 2e 74 63 70 3a 2f 2f"
		<< "6c 6f 63 61 6c 68 6f 73  74 3a 34 38 34 31 2f 30"
		<< "2e 30 2e 30 2e 30 0a 00  00 00 30 31 32 33 34 35"
		<< "36 37 38 39 00 00 00 00  2f 00 00 00 68 74 74 70"
		<< "3a 2f 2f 6f 70 63 66 6f  75 6e 64 61 74 69 6f 6e"
		<< "2e 6f 72 67 2f 55 41 2f  53 65 63 75 72 69 74 79"
		<< "50 6f 6c 69 63 79 23 4e  6f 6e 65 01 00 00 00 0a"
		<< "00 00 00 4f 70 63 55 61  53 74 61 63 6b 00 00 00"
		<< "00 ff ff ff ff ff ff ff  ff ff ff ff ff 41 00 00"
		<< "00 68 74 74 70 3a 2f 2f  6f 70 63 66 6f 75 6e 64"
		<< "61 74 69 6f 6e 2e 6f 72  67 2f 55 41 2d 50 72 6f"
		<< "66 69 6c 65 2f 54 72 61  6e 73 70 6f 72 74 2f 75"
		<< "61 74 63 70 2d 75 61 73  63 2d 75 61 62 69 6e 61"
		<< "72 79 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode ExtensibleParameter
	ExtensibleParameterSPtr = ExtensibleParameter::construct();
	ExtensibleParameterSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(ExtensibleParameterSPtr->endpointUrl() == "opt.tcp://localhost:481/0.0.0.0");
	BOOST_REQUIRE(ExtensibleParameterSPtr->applicationDescription()->applicationUri() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(ExtensibleParameterSPtr->applicationDescription()->productUri() == "urn:company:Unittest");
	BOOST_REQUIRE(ExtensibleParameterSPtr->applicationDescription()->applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(ExtensibleParameterSPtr->applicationDescription()->applicationType() == ApplicationType_Server);
	BOOST_REQUIRE(ExtensibleParameterSPtr->applicationDescription()->discoveryUrls()->size() == 1);
	ExtensibleParameterSPtr->applicationDescription()->discoveryUrls()->get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");

	ExtensibleParameterSPtr->serverCertificate(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	BOOST_REQUIRE(ExtensibleParameterSPtr->messageSecurityMode() == MessageSecurityMode_None);
	BOOST_REQUIRE(ExtensibleParameterSPtr->securityPolicyUri() == "http://opcfoundation.org/UA/SecurityPolicy#None");

	BOOST_REQUIRE(ExtensibleParameterSPtr->userIdentityTokens()->size() == 1);
	ExtensibleParameterSPtr->userIdentityTokens()->get(0, userTokenPolicySPtr);
	BOOST_REQUIRE(userTokenPolicySPtr->policyId() == "OpcUaStack");
	BOOST_REQUIRE(userTokenPolicySPtr->tokenType() == UserIdentityTokenType_Anonymous);
	
	BOOST_REQUIRE(ExtensibleParameterSPtr->transportProfileUri() == "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	BOOST_REQUIRE(ExtensibleParameterSPtr->securityLevel() == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()