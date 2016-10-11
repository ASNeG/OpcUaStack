#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/UserTokenPolicy.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(UserTokenPolicy_)

BOOST_AUTO_TEST_CASE(UserTokenPolicy_)
{
	uint32_t pos;
	std::cout << "UserTokenPolicy_t" << std::endl;

	UserTokenPolicy::SPtr userTokenPolicySPtr;

	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode UserTokenPolicy
	userTokenPolicySPtr = constructSPtr<UserTokenPolicy>();
	userTokenPolicySPtr->policyId("OpcUaStack");
	userTokenPolicySPtr->tokenType(UserIdentityTokenType_Anonymous);
	userTokenPolicySPtr->opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "0a 00 00 00 4f 70 63 55  61 53 74 61 63 6b 00 00"
		<< "00 00 ff ff ff ff ff ff  ff ff ff ff ff ff";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode UserTokenPolicy
	userTokenPolicySPtr = constructSPtr<UserTokenPolicy>();
	userTokenPolicySPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(userTokenPolicySPtr->policyId() == "OpcUaStack");
	BOOST_REQUIRE(userTokenPolicySPtr->tokenType() == UserIdentityTokenType_Anonymous);
}

BOOST_AUTO_TEST_SUITE_END()
