#include "unittest.h"
#include "OpcUaStackCore/Base/Callback.h"
#include <boost/function.hpp>

using namespace OpcUaStackCore;

class Callback_Test {
  public:
	Callback_Test(void);
	void run(void);
	void run(int p1);
	int run2(int p1);
	int run3(int p1, int p2);
	int run4(int p1, int p2, int p3);
	int run5(int p1, int p2, int p3, int p4);
	int run6(int p1, int p2, int p3, int p4, int p5);

	uint32_t run_;
	uint32_t run1_;
	uint32_t run2_;
	uint32_t run3_;
	uint32_t run4_;
	uint32_t run5_;
	uint32_t run6_;
};

Callback_Test::Callback_Test(void)
: run_(0)
, run1_(0)
, run2_(0)
, run3_(0)
, run4_(0)
, run5_(0)
, run6_(0)
{
}

void
Callback_Test::run(void)
{
    run_++;
}

void
Callback_Test::run(int p1)
{
	std::cout << "P1=" << p1 << std::endl;
	run1_++;
}

int
Callback_Test::run2(int p1)
{
	std::cout << "P1=" << p1 << std::endl;
	run2_++;
	return p1;
}

int
Callback_Test::run3(int p1, int p2)
{
	std::cout << "P1=" << p1
			  << " P2=" << p2
			  << std::endl;
	run3_++;
	return p1;
}

int
Callback_Test::run4(int p1, int p2, int p3)
{
	std::cout << "P1=" << p1
			  << " P2=" << p2
			  << " P3=" << p3
			  << std::endl;
	run4_++;
	return p1;
}

int
Callback_Test::run5(int p1, int p2, int p3, int p4)
{
	std::cout << "P1=" << p1
			  << " P2=" << p2
			  << " P3=" << p3
			  << " P4=" << p4
			  << std::endl;
	run5_++;
	return p1;
}

int
Callback_Test::run6(int p1, int p2, int p3, int p4, int p5)
{
	std::cout << "P1=" << p1
			  << " P2=" << p2
			  << " P3=" << p3
			  << " P4=" << p4
			  << " P5=" << p5
			  << std::endl;
	run6_++;
	return p1;
}

class CallbackCallback_Test
{
  public:
    void callback0(Callback& callback) {
    	callback();
    }
    void callback1(Callback& callback, uint32_t a1) {
    	callback(a1);
    }
};

BOOST_AUTO_TEST_SUITE(Callback_t)

BOOST_AUTO_TEST_CASE(Callback_)
{
	std::cout << "Callback_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Callback_bind_without_parameter)
{
	Callback_Test callback_Test;
	boost::function<void()> f = boost::bind(&Callback_Test::run,&callback_Test);
    f();
    BOOST_REQUIRE(callback_Test.run_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_bind_with_parameter)
{
	Callback_Test callback_Test;
    boost::function<void(int)> f = boost::bind(&Callback_Test::run,&callback_Test);
    f(1);
	BOOST_REQUIRE(callback_Test.run_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_assign)
{
	Callback_Test callback_Test;
    Callback callback1(boost::bind(&Callback_Test::run,&callback_Test));
    Callback callback2;

    callback2 = callback1;
    callback2();

	BOOST_REQUIRE(callback_Test.run_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_reset)
{
	Callback_Test callback_Test;
    Callback callback;

    callback.reset(boost::bind(&Callback_Test::run,&callback_Test));
    callback();

    BOOST_REQUIRE(callback_Test.run_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_without_parameter)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run,&callback_Test));
    callback();
    BOOST_REQUIRE(callback_Test.run_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_parameter)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run,&callback_Test,_1));
    callback(123);
    BOOST_REQUIRE(callback_Test.run1_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_parameter_redirect)
{
	CallbackCallback_Test callbackCallback_test;
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run,&callback_Test,_1));
    callbackCallback_test.callback1(callback,123);
    BOOST_REQUIRE(callback_Test.run1_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_parameter_and_return_code)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run2,&callback_Test,_1));
    callback(123);
    BOOST_REQUIRE(callback_Test.run2_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_2_parameter_and_return_code)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run3,&callback_Test,_1,_2));
    callback(123,234);
    BOOST_REQUIRE(callback_Test.run3_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_3_parameter_and_return_code)
{
    Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run4,&callback_Test,_1,_2,_3));
    callback(123,456,789);
    BOOST_REQUIRE(callback_Test.run4_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_4_parameter_and_return_code)
{
    Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run5,&callback_Test,_1,_2,_3,_4));
    callback(123,456,789,123);
    BOOST_REQUIRE(callback_Test.run5_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_0_parameter_1_value)
{
    Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run2,&callback_Test,123));
    callback();
    BOOST_REQUIRE(callback_Test.run2_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_0_parameter_2_value)
{
    Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run3,&callback_Test,123, 234));
    callback();
    BOOST_REQUIRE(callback_Test.run3_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_0_parameter_3_value)
{
    Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run4,&callback_Test,123, 234, 567));
    callback();
    BOOST_REQUIRE(callback_Test.run4_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_0_parameter_4_value)
{
    Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run5,&callback_Test,123,234,567,890));
    callback();
    BOOST_REQUIRE(callback_Test.run5_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_1_parameter_1_value)
{
   Callback_Test callback_Test;
   Callback callback(boost::bind(&Callback_Test::run3,&callback_Test,123,_1));
   callback(999);
   BOOST_REQUIRE(callback_Test.run3_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_1_parameter_2_value)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run4,&callback_Test,123,234,_1));
    callback(999);
    BOOST_REQUIRE(callback_Test.run4_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_1_parameter_3_value)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run5,&callback_Test,123,234,567,_1));
    callback(999);
    BOOST_REQUIRE(callback_Test.run5_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_2_parameter_1_value)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run4,&callback_Test,123,_1,_2));
    callback(111,222);
    BOOST_REQUIRE(callback_Test.run4_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_2_parameter_2_value)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run5,&callback_Test,123,345,_1,_2));
    callback(111,222);
    BOOST_REQUIRE(callback_Test.run5_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_2_parameter_3_value)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run6,&callback_Test,123,345,678,_1,_2));
    callback(111,222);
    BOOST_REQUIRE(callback_Test.run6_ == 1);
}

BOOST_AUTO_TEST_CASE(Callback_callback_with_3_parameter_1_value)
{
	Callback_Test callback_Test;
    Callback callback(boost::bind(&Callback_Test::run5,&callback_Test,123,_1,_2,_3));
    callback(111,222,333);
    BOOST_REQUIRE(callback_Test.run5_ == 1);
}

BOOST_AUTO_TEST_SUITE_END()
