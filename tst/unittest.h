#ifndef __OPCUA_UNITTEST__
#define __OPCUA_UNITTEST__

#include <stdio.h>
#include "os.h"

#define REAL_SERVER 1
#define REAL_SERVER_URI "opt.tcp://192.168.122.99:48010"

//#define BOOST_TEST_MAIN
#ifdef WIN32

#else 
	#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>

#endif
