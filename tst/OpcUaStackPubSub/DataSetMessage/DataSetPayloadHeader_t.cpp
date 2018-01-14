#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayloadHeader.h"

using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataSetPayloadHeader_)

BOOST_AUTO_TEST_CASE(DataSetPayloadHeader_)
{
	std::cout << "DataSetPayloadHeader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataSetPayloadHeader_encode_decode)
{
	std::stringstream ss;
	OpcUaUInt16 val;
	DataSetPayloadHeader value1, value2;

	value1.dataSetArrayEnabled(true);
	value1.dataSetWriterIds()->resize(5);
	value1.dataSetWriterIds()->push_back(1);
	value1.dataSetWriterIds()->push_back(2);
	value1.dataSetWriterIds()->push_back(3);
	value1.dataSetWriterIds()->push_back(4);
	value1.dataSetWriterIds()->push_back(5);
	value1.opcUaBinaryEncode(ss);

	value2.dataSetArrayEnabled(true);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.dataSetWriterIds()->size() == 5);
	value2.dataSetWriterIds()->get(0, val);
	BOOST_REQUIRE(val == 1);
	value2.dataSetWriterIds()->get(1, val);
	BOOST_REQUIRE(val == 2);
	value2.dataSetWriterIds()->get(2, val);
	BOOST_REQUIRE(val == 3);
	value2.dataSetWriterIds()->get(3, val);
	BOOST_REQUIRE(val == 4);
	value2.dataSetWriterIds()->get(4, val);
	BOOST_REQUIRE(val == 5);

}

BOOST_AUTO_TEST_SUITE_END()
