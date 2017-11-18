#include "unittest.h"

#include <boost/asio.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackPubSub/DataSetMessage/DataDeltaFrameDataSetMessage.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataDeltaFrameDataSetMessage_)

BOOST_AUTO_TEST_CASE(DataDeltaFrameDataSetMessage_)
{
	std::cout << "DataDeltaFrameDataSetMessage_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataDeltaFrameDataSetMessage_encode_decode_variant)
{
	DataDeltaFrameDataSetMessage value1, value2;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	value1.deltaFrameFields()->resize(10);
	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
		variant->setValue(OpcUaNodeId(idx));

		DeltaFrameField::SPtr deltaFrameField = constructSPtr<DeltaFrameField>();
		deltaFrameField->variant(variant);
		deltaFrameField->fieldIndex(idx+10);

		value1.deltaFrameFields()->push_back(deltaFrameField);
	}

	value1.opcUaBinaryEncode(ios);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.deltaFrameFields()->size() == 10);
	for (uint32_t idx=0; idx<10; idx++) {
		DeltaFrameField::SPtr deltaFrameField;
		value2.deltaFrameFields()->get(idx, deltaFrameField);

		OpcUaNodeId nodeId;
		deltaFrameField->variant()->getValue(nodeId);
		BOOST_REQUIRE(nodeId == OpcUaNodeId(idx));
		BOOST_REQUIRE(deltaFrameField->fieldIndex() == (idx+10));
	}

}

BOOST_AUTO_TEST_SUITE_END()
