#ifndef __OPCUA_UNITTEST__
#define __OPCUA_UNITTEST__

#include <stdio.h>
#include "os.h"

//#define REAL_SERVER_URI "opt.tcp://127.0.0.1:8889"
//#define REAL_SERVER_URI "opt.tcp://192.168.0.142:48010"
//#define REAL_SERVER_URI "opt.tcp://192.168.129.1:48010"
//#define REAL_SESSION_NAME "urn:127.0.0.1:ASNeG.de:ASNeG-Client
#define REAL_SESSION_NAME "urn:127.0.0.1:Company:Company-Client"

//#define BOOST_TEST_MAIN
#ifdef WIN32

#else 
	#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include <iostream>

#endif
