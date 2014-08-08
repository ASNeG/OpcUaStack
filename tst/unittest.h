#include <stdio.h>
#include "os.h"

#define BOOST_TEST_MAIN
#ifdef WIN32

#else 
	#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>