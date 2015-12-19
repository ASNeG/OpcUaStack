#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "unittest.h"
#include "OpcUaStackCore/Base/Pool.h"

using namespace OpcUaStackCore;

class PoolTest
{
  public:
	typedef boost::shared_ptr<PoolTest> SPtr;

	PoolTest(void) {}
	PoolTest(const std::string& string) {}
	~PoolTest(void) {}

	char buffer[1000];
};


#define NUMBER_TESTS 1000000

BOOST_AUTO_TEST_SUITE(Pool_t)

BOOST_AUTO_TEST_CASE(Pool_)
{
	std::cout << "Pool_t" << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// pointer
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(Pool_allocate_memory)
{
	BOOST_REQUIRE(true);

	PoolTest* poolTest[100000];
	boost::posix_time::ptime start;
	boost::posix_time::ptime stop;
	boost::posix_time::time_duration td;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS; idx++)  {
		poolTest[0] = new PoolTest();
		delete poolTest[0];
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate Memory 000001: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/1000; idx++)  {
		for (uint32_t j = 0; j<1000; j++) poolTest[j] = new PoolTest();
		for (uint32_t j = 0; j<1000; j++) delete poolTest[j];
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate Memory 001000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/10000; idx++)  {
		for (uint32_t j = 0; j<10000; j++) poolTest[j] = new PoolTest();
		for (uint32_t j = 0; j<10000; j++) delete poolTest[j];
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate Memory 010000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/100000; idx++)  {
		for (uint32_t j = 0; j<100000; j++) poolTest[j] = new PoolTest();
		for (uint32_t j = 0; j<100000; j++) delete poolTest[j];
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate Memory 100000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	BOOST_REQUIRE(true);
}

BOOST_AUTO_TEST_CASE(Pool_allocate_sptr_memory)
{
	BOOST_REQUIRE(true);

	PoolTest::SPtr poolTest[100000];
	boost::posix_time::ptime start;
	boost::posix_time::ptime stop;
	boost::posix_time::time_duration td;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS; idx++)  {
		poolTest[0].reset(new PoolTest());
		poolTest[0].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory 000001: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/1000; idx++)  {
		for (uint32_t j=0; j<1000; j++) poolTest[j].reset(new PoolTest());
		for (uint32_t j=0; j<1000; j++) poolTest[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory 001000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/10000; idx++)  {
		for (uint32_t j=0; j<10000; j++) poolTest[j].reset(new PoolTest());
		for (uint32_t j=0; j<10000; j++) poolTest[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory 010000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/100000; idx++)  {
		for (uint32_t j=0; j<100000; j++) poolTest[j].reset(new PoolTest());
		for (uint32_t j=0; j<100000; j++) poolTest[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory 100000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	BOOST_REQUIRE(true);
}

BOOST_AUTO_TEST_CASE(Pool_allocate_sptr_memory_copy)
{
	BOOST_REQUIRE(true);

	PoolTest::SPtr poolTest0[100000];
	PoolTest::SPtr poolTest1[100000];
	boost::posix_time::ptime start;
	boost::posix_time::ptime stop;
	boost::posix_time::time_duration td;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS; idx++)  {
		poolTest0[0].reset(new PoolTest());
		poolTest1[0] = poolTest0[0];
		poolTest0[0].reset();
		poolTest1[0].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory copy 000001: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/1000; idx++)  {
		for (uint32_t j=0; j<1000; j++) poolTest0[j].reset(new PoolTest());
		for (uint32_t j=0; j<1000; j++) poolTest1[j] = poolTest0[j];
		for (uint32_t j=0; j<1000; j++) poolTest0[j].reset();
		for (uint32_t j=0; j<1000; j++) poolTest1[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory copy 001000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/10000; idx++)  {
		for (uint32_t j=0; j<10000; j++) poolTest0[j].reset(new PoolTest());
		for (uint32_t j=0; j<10000; j++) poolTest1[j] = poolTest0[j];
		for (uint32_t j=0; j<10000; j++) poolTest0[j].reset();
		for (uint32_t j=0; j<10000; j++) poolTest1[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory copy 010000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/100000; idx++)  {
		for (uint32_t j=0; j<100000; j++) poolTest0[j].reset(new PoolTest());
		for (uint32_t j=0; j<100000; j++) poolTest1[j] = poolTest0[j];
		for (uint32_t j=0; j<100000; j++) poolTest0[j].reset();
		for (uint32_t j=0; j<100000; j++) poolTest1[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Allocate sptr Memory copy 100000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	BOOST_REQUIRE(true);
}

BOOST_AUTO_TEST_CASE(Pool_pool_memory)
{
	BOOST_REQUIRE(true);

	Pool<PoolTest> pool;
	PoolTest* poolTest[100000];
	boost::posix_time::ptime start;
	boost::posix_time::ptime stop;
	boost::posix_time::time_duration td;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS; idx++)  {
		poolTest[0] = pool.construct();
		pool.destroy(poolTest[0]);
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool Memory 000001: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/1000; idx++)  {
		for (uint32_t j = 0; j<1000; j++) poolTest[j] = pool.construct();
		for (uint32_t j = 0; j<1000; j++) pool.destroy(poolTest[j]);
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool Memory 001000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/10000; idx++)  {
		for (uint32_t j = 0; j<10000; j++) poolTest[j] = pool.construct();
		for (uint32_t j = 0; j<10000; j++) pool.destroy(poolTest[j]);
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool Memory 010000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;


	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/100000; idx++)  {
		for (uint32_t j = 0; j<100000; j++) poolTest[j] = pool.construct();
		for (uint32_t j = 0; j<100000; j++) pool.destroy(poolTest[j]);
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool Memory 100000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	BOOST_REQUIRE(true);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// smart pointer
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(Pool_allocate_sptr_pool_memory)
{
	BOOST_REQUIRE(true);

	Pool<PoolTest,true,100000,100000> pool;
	PoolTest::SPtr poolTest[100000];
	boost::posix_time::ptime start;
	boost::posix_time::ptime stop;
	boost::posix_time::time_duration td;

	BOOST_REQUIRE(true);
	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS; idx++)  {
		//std::cout << idx << std::endl;
		poolTest[0] = pool.constructSPtr();
		poolTest[0].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory 000001: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;
	BOOST_REQUIRE(true);
	while (pool.garbageCollector());

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/1000; idx++)  {
		for (uint32_t j=0; j<1000; j++) poolTest[j] = pool.constructSPtr();
		for (uint32_t j=0; j<1000; j++) poolTest[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory 001000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;
	while (pool.garbageCollector());

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/10000; idx++)  {
		for (uint32_t j=0; j<10000; j++) poolTest[j] = pool.constructSPtr();
		for (uint32_t j=0; j<10000; j++) poolTest[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory 010000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;
	while (pool.garbageCollector());

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/100000; idx++)  {
		for (uint32_t j=0; j<100000; j++) poolTest[j] = pool.constructSPtr();
		for (uint32_t j=0; j<100000; j++) poolTest[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory 100000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;
	while (pool.garbageCollector());

	BOOST_REQUIRE(true);
}

BOOST_AUTO_TEST_CASE(Pool_allocate_sptr_pool_memory_copy)
{
	BOOST_REQUIRE(true);

	Pool<PoolTest,true,100000,100000> pool;
	PoolTest::SPtr poolTest0[100000];
	PoolTest::SPtr poolTest1[100000];
	boost::posix_time::ptime start;
	boost::posix_time::ptime stop;
	boost::posix_time::time_duration td;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS; idx++)  {
		poolTest0[0] = pool.constructSPtr();
		poolTest1[0] = poolTest0[0];
		poolTest0[0].reset();
		poolTest1[0].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory copy 000001: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/1000; idx++)  {
		for (uint32_t j=0; j<1000; j++) poolTest0[j] = pool.constructSPtr();
		for (uint32_t j=0; j<1000; j++) poolTest1[j] = poolTest0[j];
		for (uint32_t j=0; j<1000; j++) poolTest0[j].reset();
		for (uint32_t j=0; j<1000; j++) poolTest1[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory copy 001000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/10000; idx++)  {
		for (uint32_t j=0; j<10000; j++) poolTest0[j] = pool.constructSPtr();
		for (uint32_t j=0; j<10000; j++) poolTest1[j] = poolTest0[j];
		for (uint32_t j=0; j<10000; j++) poolTest0[j].reset();
		for (uint32_t j=0; j<10000; j++) poolTest1[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory copy 010000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	start = boost::posix_time::microsec_clock::local_time();
	for (uint32_t idx=0; idx<NUMBER_TESTS/100000; idx++)  {
		for (uint32_t j=0; j<100000; j++) poolTest0[j] = pool.constructSPtr();
		for (uint32_t j=0; j<100000; j++) poolTest1[j] = poolTest0[j];
		for (uint32_t j=0; j<100000; j++) poolTest0[j].reset();
		for (uint32_t j=0; j<100000; j++) poolTest1[j].reset();
	}
	stop = boost::posix_time::microsec_clock::local_time();
	td = stop - start;
	std::cout << "Pool sptr Memory copy 100000: " << NUMBER_TESTS << " " << td.total_milliseconds() << "ms" << std::endl;

	BOOST_REQUIRE(true);
}

BOOST_AUTO_TEST_SUITE_END()

