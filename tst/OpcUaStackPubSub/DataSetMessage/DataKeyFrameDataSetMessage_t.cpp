#include "unittest.h"

#include <boost/asio.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackPubSub/DataSetMessage/DataKeyFrameDataSetMessage.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataKeyFrameDataSetMessage_)

BOOST_AUTO_TEST_CASE(DataKeyFrameDataSetMessage_)
{
	std::cout << "DataKeyFrameDataSetMessage_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataKeyFrameDataSetMessage_encode_decode_variant)
{
	DataKeyFrameDataSetMessage value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.dataSetFields()->resize(10);
	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
		variant->setValue(OpcUaNodeId(idx));

		DataSetField::SPtr dataSetField = constructSPtr<DataSetField>();
		dataSetField->variant(variant);

		value1.dataSetFields()->push_back(dataSetField);
	}

	value1.opcUaBinaryEncode(ios);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.dataSetFields()->size() == 10);
	for (uint32_t idx=0; idx<10; idx++) {
		DataSetField::SPtr dataSetField;
		value2.dataSetFields()->get(idx, dataSetField);

		OpcUaNodeId nodeId;
		dataSetField->variant()->getValue(nodeId);
		BOOST_REQUIRE(nodeId == OpcUaNodeId(idx));
	}

}

BOOST_AUTO_TEST_SUITE_END()
