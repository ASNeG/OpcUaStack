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

BOOST_AUTO_TEST_SUITE_END()
