#include "unittest.h"

#include <boost/asio.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayload.h"
#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataSetPayload_)

BOOST_AUTO_TEST_CASE(DataSetPayload_)
{
	std::cout << "DataSetPayload_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataSetPayload_encode_decode)
{
	uint32_t pos;
	DataSetPayload value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.dataSetMessages()->resize(2);
	value1.dataSetMessages()->push_back(constructSPtr<KeepAliveMessage>());
	value1.dataSetMessages()->push_back(constructSPtr<KeepAliveMessage>());
	value1.dataSetMessageHeaders()->resize(2);
	value1.dataSetMessageHeaders()->push_back(constructSPtr<DataSetMessageHeader>());
	value1.dataSetMessageHeaders()->push_back(constructSPtr<DataSetMessageHeader>());

	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "01 00 01 00 00 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	value2.opcUaBinaryDecode(ios);
}

BOOST_AUTO_TEST_SUITE_END()
