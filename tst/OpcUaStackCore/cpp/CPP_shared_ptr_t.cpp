#include "unittest.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

BOOST_AUTO_TEST_SUITE(CPP_shared_ptr_t)

uint32_t baseClassConstruct = 0;
uint32_t baseClassDestruct = 0;
uint32_t derivedClassContruct = 0;
uint32_t derivedClassDestruct = 0;

class BaseClass
: public boost::enable_shared_from_this<BaseClass>
{
  public:

	using SPtr = boost::shared_ptr<BaseClass>;

	BaseClass(void)
	{
		baseClassConstruct++;
	}

	virtual ~BaseClass(void)
	{
		baseClassDestruct++;
	}

	void activate(void)
	{
		own_ = shared_from_this();
	}

	void deactivate(void)
	{
		own_ = nullptr;
	}

  private:
	SPtr own_;
};

class DerivedClass
: public BaseClass
{
  public:

	using SPtr = boost::shared_ptr<DerivedClass>;

	DerivedClass(void)
	{
		derivedClassContruct++;
	}

	~DerivedClass(void)
	{
		derivedClassDestruct++;
	}
};

BOOST_AUTO_TEST_CASE(SharedPtr_)
{
	std::cout << "CPP_shared_ptr_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SharedPtr_construct_destruct)
{
	baseClassConstruct = 0;
	baseClassDestruct = 0;
	derivedClassContruct = 0;
	derivedClassDestruct = 0;

	DerivedClass::SPtr ptr = boost::make_shared<DerivedClass>();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 0);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 0);

	ptr.reset();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 1);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 1);
}

BOOST_AUTO_TEST_CASE(SharedPtr_own_ptr1)
{
	baseClassConstruct = 0;
	baseClassDestruct = 0;
	derivedClassContruct = 0;
	derivedClassDestruct = 0;

	DerivedClass::SPtr sptr = boost::make_shared<DerivedClass>();
	DerivedClass* ptr = sptr.get();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 0);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 0);

	sptr->activate();
	sptr.reset();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 0);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 0);

	ptr->deactivate();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 1);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 1);
}

BOOST_AUTO_TEST_CASE(SharedPtr_own_ptr2)
{
	baseClassConstruct = 0;
	baseClassDestruct = 0;
	derivedClassContruct = 0;
	derivedClassDestruct = 0;

	DerivedClass::SPtr sptr = boost::make_shared<DerivedClass>();
	DerivedClass* ptr = sptr.get();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 0);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 0);

	sptr->activate();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 0);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 0);

	ptr->deactivate();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 0);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 0);

	sptr.reset();
	BOOST_REQUIRE(baseClassConstruct == 1);
	BOOST_REQUIRE(baseClassDestruct == 1);
	BOOST_REQUIRE(derivedClassContruct == 1);
	BOOST_REQUIRE(derivedClassDestruct == 1);
}

BOOST_AUTO_TEST_SUITE_END()
