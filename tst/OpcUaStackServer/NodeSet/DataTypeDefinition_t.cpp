#include "unittest.h"

#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(DataTypeDefinition_)

BOOST_AUTO_TEST_CASE(DataTypeDefinition_)
{
	std::cout << "DataTypeDefinition_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(DataTypeDefinition_decode_description)
{
	ConfigXml configXml;
	NodeSetXmlParser nodeSetXmlParser;
	std::vector<boost::property_tree::ptree> ptrees;
	std::vector<boost::property_tree::ptree>::iterator it1;
	std::set<std::string> elementNames;
	std::set<std::string> attributeNames;
	std::set<std::string>::iterator it2;

	// read all definition elements from nodeset
	BOOST_REQUIRE(configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml") == true);
	configXml.find("Definition", ptrees);
	BOOST_REQUIRE(ptrees.size() > 0);

	// decode all definition elements
	for (it1 = ptrees.begin(); it1 != ptrees.end(); it1++) {
		ConfigXml::createElementNameSet(*it1, elementNames);
		ConfigXml::createAttributeNameSet(*it1, attributeNames);

	}

	std::cout << "element names:" << std::endl;
	for (it2 = elementNames.begin(); it2 != elementNames.end(); it2++) {
		std::cout << *it2 << std::endl;
	}
	std::cout << "attribute names:" << std::endl;
	for (it2 = attributeNames.begin(); it2 != attributeNames.end(); it2++) {
		std::cout << *it2 << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE_END()


