#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/array.hpp>
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(BuildInTypes_t)


BOOST_AUTO_TEST_CASE(BuildInTypes_OpcUaExpandedNodeId)
{
	boost::array<char,1000000> array;
	std::stringstream ss;
	ss.rdbuf()->pubsetbuf(array.data(), array.size());

	OpcUaExpandedNodeId OpcUaExpandedNodeId1, OpcUaExpandedNodeId2;

	// two byte representation
	OpcUaExpandedNodeId1.namespaceIndex(0);
	OpcUaExpandedNodeId1.nodeId((OpcUaUInt32)1);
	opcUaBinaryEncode(ss, OpcUaExpandedNodeId1);
	opcUaBinaryDecode(ss, OpcUaExpandedNodeId2);
	BOOST_REQUIRE(OpcUaExpandedNodeId2.namespaceIndex() == 0);
	BOOST_REQUIRE(OpcUaExpandedNodeId2.nodeIdType() == OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32);
	BOOST_REQUIRE(OpcUaExpandedNodeId2.nodeId<OpcUaUInt32>() == 1);
}


BOOST_AUTO_TEST_SUITE_END()