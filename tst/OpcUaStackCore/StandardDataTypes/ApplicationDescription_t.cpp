#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ApplicationDescription_)

BOOST_AUTO_TEST_CASE(ApplicationDescription_)
{
	uint32_t pos;
	std::cout << "ApplicationDescription_t" << std::endl;

	OpcUaString::SPtr opcUaStringSPtr;
	ApplicationDescription::SPtr applicationDescriptionSPtr;

	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode ApplicationDescription
	applicationDescriptionSPtr = boost::make_shared<ApplicationDescription>();
	applicationDescriptionSPtr->applicationUri().value("urn:localhost:compyny:Unittest");
	applicationDescriptionSPtr->productUri().value("urn:company:Unittest");
	applicationDescriptionSPtr->applicationName().text("company Unittest");
	applicationDescriptionSPtr->applicationType().enumeration(ApplicationType::EnumServer);
	applicationDescriptionSPtr->discoveryUrls().resize(1);
	opcUaStringSPtr = boost::make_shared<OpcUaString>();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	applicationDescriptionSPtr->discoveryUrls().set(0, opcUaStringSPtr);
	applicationDescriptionSPtr->opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "1e 00 00 00 75 72 6e 3a  6c 6f 63 61 6c 68 6f 73"
		<< "74 3a 63 6f 6d 70 79 6e  79 3a 55 6e 69 74 74 65"
		<< "73 74 14 00 00 00 75 72  6e 3a 63 6f 6d 70 61 6e"
		<< "79 3a 55 6e 69 74 74 65  73 74 02 10 00 00 00 63"
		<< "6f 6d 70 61 6e 79 20 55  6e 69 74 74 65 73 74 00"
		<< "00 00 00 ff ff ff ff ff  ff ff ff 01 00 00 00 20"
		<< "00 00 00 6f 70 74 2e 74  63 70 3a 2f 2f 6c 6f 63"
		<< "61 6c 68 6f 73 74 3a 34  38 34 31 2f 30 2e 30 2e"
		<< "30 2e 30";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode ApplicationDescription
	applicationDescriptionSPtr = boost::make_shared<ApplicationDescription>();
	applicationDescriptionSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(applicationDescriptionSPtr->applicationUri().value() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(applicationDescriptionSPtr->productUri().value() == "urn:company:Unittest");
	BOOST_REQUIRE(applicationDescriptionSPtr->applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(applicationDescriptionSPtr->applicationType().enumeration() == ApplicationType::EnumServer);
	applicationDescriptionSPtr->discoveryUrls().get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");

}

BOOST_AUTO_TEST_SUITE_END()
