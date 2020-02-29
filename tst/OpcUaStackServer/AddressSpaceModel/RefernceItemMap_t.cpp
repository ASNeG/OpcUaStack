#include "unittest.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;


struct ReferenceItemMapFixture {
	ReferenceItemMapFixture(void)
    : map()
    , refId1(0)
    , refId2(1)
    , refId3(2)
    , refId4(3)
    {
    	BOOST_TEST_MESSAGE("ReferenceItemMapFixture");
    	map.add(ReferenceType::ReferenceType_Organizes, true, refId1);
    	map.add(ReferenceType::ReferenceType_Organizes, true, refId2);
    	map.add(ReferenceType::ReferenceType_Organizes, true, refId3);

    	map.add(ReferenceType::ReferenceType_HasComponent, true, refId4);
    }

    ~ReferenceItemMapFixture(void)
    {
    	BOOST_TEST_MESSAGE("~ReferenceItemMapFixture");
    }

    ReferenceItemMap map;
	OpcUaNodeId refId1;
	OpcUaNodeId refId2;
	OpcUaNodeId refId3;
	OpcUaNodeId refId4;
};


BOOST_AUTO_TEST_SUITE(RefernceItemMap_)

BOOST_AUTO_TEST_CASE(RefernceItemMap_)
{
	std::cout << "RefernceItemMap_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(RefernceItemMap_equal_range, ReferenceItemMapFixture)
{
	BOOST_REQUIRE(map.size() == 4);

	auto it = map.equal_range(OpcUaNodeId(OpcUaId_Organizes));

	BOOST_REQUIRE(it.first != it.second);
	BOOST_REQUIRE(refId1 == it.first->second->nodeId_);

	++it.first;
	BOOST_REQUIRE(refId2 == it.first->second->nodeId_);

	++it.first;
	BOOST_REQUIRE(refId3 == it.first->second->nodeId_);

	++it.first;
	BOOST_REQUIRE(it.first == it.second);
}

BOOST_FIXTURE_TEST_CASE(RefernceItemMap_iterator, ReferenceItemMapFixture)
{
	auto it = map.begin();

	BOOST_REQUIRE_EQUAL(4, map.size());
	BOOST_REQUIRE(refId1 == (*it)->nodeId_);

	++it;
	BOOST_REQUIRE(refId2 == (*it)->nodeId_);

	++it;
	BOOST_REQUIRE(refId3 == (*it)->nodeId_);

	++it;
	BOOST_REQUIRE(refId4 == (*it)->nodeId_);

	++it;
	BOOST_REQUIRE(map.end() == it);
}

BOOST_FIXTURE_TEST_CASE(RefernceItemMap_add_item,ReferenceItemMapFixture)
{
	ReferenceItemMap map;
	OpcUaNodeId id(1);

	BOOST_REQUIRE(map.add(ReferenceType::ReferenceType_Organizes, true, id));
	auto referenceItem = *(map.begin());

	BOOST_REQUIRE(referenceItem);
	BOOST_REQUIRE(referenceItem->isForward_);
	BOOST_REQUIRE(id == referenceItem->nodeId_);
	BOOST_REQUIRE(OpcUaNodeId(OpcUaId_Organizes) == referenceItem->typeId_);
}


BOOST_FIXTURE_TEST_CASE(RefernceItemMap_remove_item, ReferenceItemMapFixture)
{
	auto it = map.begin();

	BOOST_REQUIRE(map.size() == 4);
	BOOST_REQUIRE(map.erase(it));

	BOOST_REQUIRE(map.size() == 3);
	BOOST_REQUIRE(map.erase(it));

	BOOST_REQUIRE(map.size() == 2);
	BOOST_REQUIRE(map.erase(it));

	BOOST_REQUIRE_EQUAL(1, map.size());
	auto itr = map.equal_range(OpcUaNodeId(OpcUaId_Organizes));

	BOOST_REQUIRE(itr.first == itr.second);

	auto referenceItem = *(map.begin());
	BOOST_REQUIRE(refId4 == referenceItem->nodeId_);
}

BOOST_AUTO_TEST_SUITE_END()
