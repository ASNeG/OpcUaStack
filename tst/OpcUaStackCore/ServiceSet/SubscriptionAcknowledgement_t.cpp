#include "unittest.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SubscriptionAcknowledgement_)

BOOST_AUTO_TEST_CASE(SubscriptionAcknowledgement_)
{
	std::cout << "SubscriptionAcknowledgement_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SubscriptionAcknowledgement_encode_decode)
{
	std::stringstream ss;
	
	SubscriptionAcknowledgement value1, value2;

	value1.subscriptionId(123);
	value1.sequenceNumber(321);

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.subscriptionId() == 123);
	BOOST_REQUIRE(value2.sequenceNumber() == 321);
}

BOOST_AUTO_TEST_SUITE_END()