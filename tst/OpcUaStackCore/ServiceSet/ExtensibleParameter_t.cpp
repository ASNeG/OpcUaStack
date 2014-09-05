#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/UserNameIdentityToken.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ExtensibleParameter_)

BOOST_AUTO_TEST_CASE(ExtensibleParameter_register_deregister)
{
	std::cout << "ExtensibleParameter_t" << std::endl;

	ExtensibleParameter ep;
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>((OpcUaUInt32)12345) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("0123456789", 10) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("AnonymousIdentityToken") == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);

	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12345));
	BOOST_REQUIRE(ep.deregisterFactoryElement("0123456789", 10) == true);
	BOOST_REQUIRE(ep.deregisterFactoryElement("AnonymousIdentityToken") == true);
	BOOST_REQUIRE(ep.deregisterFactoryElement("12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);
}

BOOST_AUTO_TEST_CASE(ExtensibleParameter_construct)
{
	AnonymousIdentityToken::SPtr anonymousIdentityTokenSPtr;

	ExtensibleParameter ep;
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>((OpcUaUInt32)12345) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("0123456789", 10) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("AnonymousIdentityToken") == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);

	ep.parameterTypeId().set((OpcUaUInt32)12345);
	anonymousIdentityTokenSPtr = ep.parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityTokenSPtr.get() != NULL);

	ep.parameterTypeId().set("0123456789", 10);
	anonymousIdentityTokenSPtr = ep.parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityTokenSPtr.get() != NULL);

	ep.parameterTypeId().set("AnonymousIdentityToken");
	anonymousIdentityTokenSPtr = ep.parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityTokenSPtr.get() != NULL);

	ep.parameterTypeId().set("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	anonymousIdentityTokenSPtr = ep.parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityTokenSPtr.get() != NULL);

	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12345));
	BOOST_REQUIRE(ep.deregisterFactoryElement("0123456789", 10) == true);
	BOOST_REQUIRE(ep.deregisterFactoryElement("AnonymousIdentityToken") == true);
	BOOST_REQUIRE(ep.deregisterFactoryElement("12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);
}

BOOST_AUTO_TEST_CASE(ExtensibleParameter_encode_decode)
{
	uint32_t pos;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	AnonymousIdentityToken::SPtr anonymousIdentityTokenSPtr;

	ExtensibleParameter ep;
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>((OpcUaUInt32)12345) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("0123456789", 10) == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("AnonymousIdentityToken") == true);
	BOOST_REQUIRE(ep.registerFactoryElement<AnonymousIdentityToken>("12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);

	// encode ExtensibleParameter
	ep.parameterTypeId().set((OpcUaUInt32)12345);
	anonymousIdentityTokenSPtr = ep.parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityTokenSPtr.get() != NULL);
	anonymousIdentityTokenSPtr->policyId("OpcUaStack");

	ep.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "01 00 39 30 01 0e 00 00  00 0a 00 00 00 4f 70 63" 
		<< "55 61 53 74 61 63 6b";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	ep.opcUaBinaryDecode(ios);

	// decode ExtensibleParameter
	OpcUaUInt32 nodeId; 
	OpcUaUInt16 namespaceIndex;
	ep.parameterTypeId().get(nodeId, namespaceIndex);
	BOOST_REQUIRE(nodeId == 12345);
	BOOST_REQUIRE(namespaceIndex == 0);
	anonymousIdentityTokenSPtr = ep.parameter<AnonymousIdentityToken>();
	BOOST_REQUIRE(anonymousIdentityTokenSPtr.get() != NULL);
	BOOST_REQUIRE(anonymousIdentityTokenSPtr->policyId() == "OpcUaStack");

	BOOST_REQUIRE(ep.deregisterFactoryElement((OpcUaUInt32)12345));
	BOOST_REQUIRE(ep.deregisterFactoryElement("0123456789", 10) == true);
	BOOST_REQUIRE(ep.deregisterFactoryElement("AnonymousIdentityToken") == true);
	BOOST_REQUIRE(ep.deregisterFactoryElement("12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);
}

BOOST_AUTO_TEST_SUITE_END()