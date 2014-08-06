#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(EndpointDescription_)

BOOST_AUTO_TEST_CASE(EndpointDescription_)
{
	std::cout << "EndpointDescription_t" << std::endl;

	EndpointDescription::SPtr endpointDescriptionSPtr;

	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode EndpointDescription
	endpointDescriptionSPtr = EndpointDescription::construct();
	endpointDescriptionSPtr->applicationDescription(ApplicationDescription::construct());
	endpointDescriptionSPtr->applicationDescription()->discoveryUrls(OpcUaStringArray::construct());
	
	endpointDescriptionSPtr->endpointUrl("opt.tcp://localhost:481/0.0.0.0");
	endpointDescriptionSPtr->applicationDescription()->applicationUri("urn:localhost:compyny:Unittest");
	endpointDescriptionSPtr->applicationDescription()->productUri("urn:company:Unittest");
	endpointDescriptionSPtr->applicationDescription()->applicationName().text("company Unittest");
	endpointDescriptionSPtr->applicationDescription()->applicationType(ApplicationType_Server);
	endpointDescriptionSPtr->applicationDescription()->discoveryUrls()->resize(1);
	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->applicationDescription()->discoveryUrls()->set(0, opcUaStringSPtr);
	endpointDescriptionSPtr->serverCertificate((OpcUaByte*)"0123456789", 10);
	endpointDescriptionSPtr->messageSecurityMode(MessageSecurityMode_None);
	endpointDescriptionSPtr->securityPolicyUri("http://opcfoundation.org/UA/SecurityPolicy#None");


#if 0
		UserTokenPolicyArray::SPtr userIdentityTokens_;
		OpcUaString transportProfileUri_;
		OpcUaByte securityLevel_;
#endif
}

BOOST_AUTO_TEST_SUITE_END()