#include "unittest.h"

#include <iostream>
#include "OpcUaStackCore/Base/DataMemArray.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(DataMemArray_t)

BOOST_AUTO_TEST_CASE(DataMemArray_)
{
	std::cout << "DataMemArray_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataMemArray_constructor)
{
	DataMemArray dataMemArray;
}

BOOST_AUTO_TEST_CASE(DataMemArray_resize)
{
	DataMemArray dataMemArray[7];

	BOOST_REQUIRE(dataMemArray[0].resize(0) == true);
	BOOST_REQUIRE(dataMemArray[0].size() == 0);
	BOOST_REQUIRE(dataMemArray[1].resize(1) == true);
	BOOST_REQUIRE(dataMemArray[1].size() == 1);
	BOOST_REQUIRE(dataMemArray[2].resize(2) == true);
	BOOST_REQUIRE(dataMemArray[2].size() == 2);
	BOOST_REQUIRE(dataMemArray[3].resize(10) == true);
	BOOST_REQUIRE(dataMemArray[3].size() == 10);
	BOOST_REQUIRE(dataMemArray[4].resize(100) == true);
	BOOST_REQUIRE(dataMemArray[4].size() == 100);
	BOOST_REQUIRE(dataMemArray[5].resize(100000) == true);
	BOOST_REQUIRE(dataMemArray[5].size() == 100000);

	dataMemArray[5].log();

	BOOST_REQUIRE(dataMemArray[6].resize(1000000) == false);
	BOOST_REQUIRE(dataMemArray[6].size() == 0);
}

BOOST_AUTO_TEST_CASE(DataMemArray_set)
{
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	BOOST_REQUIRE(dataMemArray.set(10, "0123456789", 10) == false);
	BOOST_REQUIRE(dataMemArray.set(0, "0123456789", 10) == true);
	BOOST_REQUIRE(dataMemArray.set(1, "01234567890123456789", 20) == true);
	BOOST_REQUIRE(dataMemArray.set(3, "01234567890123456789", 20) == true);
	dataMemArray.logFreeSlots();
	dataMemArray.log();
}

BOOST_AUTO_TEST_CASE(DataMemArray_get)
{
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[10];
		memset(mem, idx, 10);
		BOOST_REQUIRE(dataMemArray.set(idx, mem, 10) == true);
	}

	dataMemArray.log();

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[10];
		uint32_t len = 10;
		BOOST_REQUIRE(dataMemArray.get(idx, mem, len) == true);
	}
}

BOOST_AUTO_TEST_CASE(DataMemArray_set_get_string)
{
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		std::string str = "0123456789";
		BOOST_REQUIRE(dataMemArray.set(idx, str) == true);
	}

	dataMemArray.log();

	for (uint32_t idx=0; idx<10; idx++) {
		std::string str;
		BOOST_REQUIRE(dataMemArray.get(idx, str) == true);
		BOOST_REQUIRE(str == "0123456789");
	}
}

BOOST_AUTO_TEST_CASE(DataMemArray_exist)
{
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[100];
		memset(mem, idx, 100);
		BOOST_REQUIRE(dataMemArray.set(idx, mem, 100) == true);
	}

	dataMemArray.log();

	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(dataMemArray.exist(idx) == true);
	}
	BOOST_REQUIRE(dataMemArray.exist(10) == false);
}

BOOST_AUTO_TEST_CASE(DataMemArray_clear)
{
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[100];
		memset(mem, idx, 100);
		BOOST_REQUIRE(dataMemArray.set(idx, mem, 100) == true);
	}

	dataMemArray.clear();
	dataMemArray.log();
}

BOOST_AUTO_TEST_CASE(DataMemArray_setMemBuf)
{
	char* memBuf;
	uint32_t memLen;
	DataMemArray dataMemArray1, dataMemArray2;

	BOOST_REQUIRE(dataMemArray1.resize(10) == true);
	BOOST_REQUIRE(dataMemArray1.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[10];
		memset(mem, idx, 10);
		BOOST_REQUIRE(dataMemArray1.set(idx, mem, 10) == true);
	}

	BOOST_REQUIRE(dataMemArray1.getMemoryBuf(&memBuf, &memLen));
	BOOST_REQUIRE(dataMemArray2.setMemoryBuf(memBuf, memLen));
	dataMemArray2.log();

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[10];
		uint32_t len = 10;
		BOOST_REQUIRE(dataMemArray2.get(idx, mem, len) == true);
	}
}

BOOST_AUTO_TEST_CASE(DataMemArray_unset)
{
	char* memBuf;
	uint32_t memLen;
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		char mem[10];
		memset(mem, idx, 10);
		BOOST_REQUIRE(dataMemArray.set(idx, mem, 10) == true);
	}

	dataMemArray.logSlot();

	// remove last element
	BOOST_REQUIRE(dataMemArray.unset(9) == true);
	dataMemArray.logSlot();

	// remove first element
	BOOST_REQUIRE(dataMemArray.unset(0) == true);
	dataMemArray.logSlot();

	// remove element before
	BOOST_REQUIRE(dataMemArray.unset(8) == true);
	dataMemArray.logSlot();

	// remove element after
	BOOST_REQUIRE(dataMemArray.unset(1) == true);
	dataMemArray.logSlot();

	// remove element in the middle
	BOOST_REQUIRE(dataMemArray.unset(3) == true);
	BOOST_REQUIRE(dataMemArray.unset(5) == true);
	dataMemArray.logSlot();
	BOOST_REQUIRE(dataMemArray.unset(4) == true);
	dataMemArray.logSlot();
	dataMemArray.logFreeSlots();

	BOOST_REQUIRE(dataMemArray.exist(0) == false);
	BOOST_REQUIRE(dataMemArray.exist(1) == false);
	BOOST_REQUIRE(dataMemArray.exist(2) == true);
	BOOST_REQUIRE(dataMemArray.exist(3) == false);
	BOOST_REQUIRE(dataMemArray.exist(4) == false);
	BOOST_REQUIRE(dataMemArray.exist(5) == false);
	BOOST_REQUIRE(dataMemArray.exist(6) == true);
	BOOST_REQUIRE(dataMemArray.exist(7) == true);
	BOOST_REQUIRE(dataMemArray.exist(8) == false);
	BOOST_REQUIRE(dataMemArray.exist(9) == false);

	BOOST_REQUIRE(dataMemArray.unset(2) == true);
	BOOST_REQUIRE(dataMemArray.unset(6) == true);
	BOOST_REQUIRE(dataMemArray.unset(7) == true);
	dataMemArray.logSlot();
}

BOOST_AUTO_TEST_CASE(DataMemArray_padding)
{
	DataMemArray dataMemArray;

	dataMemArray.startMemorySize(1000);
	dataMemArray.expandMemorySize(1000);

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	dataMemArray.logHeader();
	dataMemArray.logSlot();

	char buf[500];
	BOOST_REQUIRE(dataMemArray.set(0, buf, 500) == true);
	dataMemArray.logSlot();

	BOOST_REQUIRE(dataMemArray.set(1, buf, 350) == true);
	dataMemArray.logSlot();

	BOOST_REQUIRE(dataMemArray.unset(0) == true);
	dataMemArray.logSlot();

	BOOST_REQUIRE(dataMemArray.set(2, buf, 485) == true);
	dataMemArray.logSlot();

	BOOST_REQUIRE(dataMemArray.unset(1) == true);
	BOOST_REQUIRE(dataMemArray.unset(2) == true);
	dataMemArray.logSlot();
}

BOOST_AUTO_TEST_SUITE_END()
