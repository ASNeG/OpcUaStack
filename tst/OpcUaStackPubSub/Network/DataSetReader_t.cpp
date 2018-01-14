#include "unittest.h"

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"
#include "OpcUaStackPubSub/DataSet/DataSetReader.h"


using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;



BOOST_AUTO_TEST_SUITE(DataSetReader_)

BOOST_AUTO_TEST_CASE(DataSetReader_)
{
	std::cout << "DataSetReader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataSetReader_timeoutExpired)
{
	DataSetReader reader;

	reader.messageReceiveTimeout(100);

	BOOST_REQUIRE(reader.checkTimeout(100));
	BOOST_REQUIRE(reader.checkTimeout(100) == false);
}

BOOST_AUTO_TEST_CASE(DataSetReader_timeoutReset)
{
	DataSetReader reader;

	reader.messageReceiveTimeout(100);

	BOOST_REQUIRE(reader.checkTimeout(100));
	reader.receiveDataSetMessage(nullptr);

	BOOST_REQUIRE(reader.checkTimeout(100));
}



BOOST_AUTO_TEST_SUITE_END()


