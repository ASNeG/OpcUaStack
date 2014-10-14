#include "unittest.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"

using namespace OpcUaStackCore;

#define ARRAY_NUMBER(handle) (handle >> 8)
#define SLOT_NUMBER(handle) (handle & 0x00FF)

BOOST_AUTO_TEST_SUITE(SlotTimer_t)

BOOST_AUTO_TEST_CASE(SlotTimer_)
{
	std::cout << "SlotTimer_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_array1)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<255; idx++) {
		slotTimerElement = SlotTimerElement::construct();
		slotTimerElement->tick(idx);
		slotTimer.insert(slotTimerElement);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == idx);
		BOOST_REQUIRE(slotTimer.count() == idx+1);
	}
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_array2)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=260; idx<270; idx++) {
		slotTimerElement = SlotTimerElement::construct();
		slotTimerElement->tick(idx);
		slotTimer.insert(slotTimerElement);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);
	}
	BOOST_REQUIRE(slotTimer.count() == 10);
}

BOOST_AUTO_TEST_CASE(SlotTimer_remove_array1)
{
	SlotTimerElement::SPtr slotTimerElement[255];
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<255; idx++) {
		slotTimerElement[idx] = SlotTimerElement::construct();
		slotTimerElement[idx]->tick(idx);
		slotTimer.insert(slotTimerElement[idx]);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement[idx]->handle()) == 0);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement[idx]->handle()) == idx);
		BOOST_REQUIRE(slotTimer.count() == idx+1);
	}

	for (uint32_t idx=0; idx<255; idx++) {
		slotTimer.remove(slotTimerElement[idx]);
	}

	BOOST_REQUIRE(slotTimer.count() == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_remove_array2)
{
	SlotTimerElement::SPtr slotTimerElement[10];
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimerElement[idx] = SlotTimerElement::construct();
		slotTimerElement[idx]->tick(idx+260);
		slotTimer.insert(slotTimerElement[idx]);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement[idx]->handle()) == 1);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement[idx]->handle()) == 0);
	}
	BOOST_REQUIRE(slotTimer.count() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimer.remove(slotTimerElement[idx]);
	}
	BOOST_REQUIRE(slotTimer.count() == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_same_tick)
{
	SlotTimerElement::SPtr slotTimerElement[10];
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimerElement[idx] = SlotTimerElement::construct();
		slotTimerElement[idx]->tick(0);
		slotTimer.insert(slotTimerElement[idx]);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement[idx]->handle()) == 0);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement[idx]->handle()) == 0);
	}
	BOOST_REQUIRE(slotTimer.count() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimer.remove(slotTimerElement[idx]);
	}
	BOOST_REQUIRE(slotTimer.count() == 0);
}


BOOST_AUTO_TEST_SUITE_END()
