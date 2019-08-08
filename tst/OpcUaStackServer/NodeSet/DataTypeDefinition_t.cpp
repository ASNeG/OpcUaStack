#include "unittest.h"

#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetDefinitionParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(DataTypeDefinition_)

BOOST_AUTO_TEST_CASE(DataTypeDefinition_)
{
	std::cout << "DataTypeDefinition_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(DataTypeDefinition_encode_decode_structure_description)
{
	ConfigXml configXml, cx1, cx2;
	NodeSetXmlParser nodeSetXmlParser;
	std::vector<boost::property_tree::ptree> ptrees;
	std::vector<boost::property_tree::ptree>::iterator it1;

	// read all definition elements from nodeset
	BOOST_REQUIRE(configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml") == true);
	configXml.find("Definition", ptrees);
	BOOST_REQUIRE(ptrees.size() > 0);

#if 1
	std::set<std::string> elementNames;
	std::set<std::string> attributeNames;
	std::set<std::string>::iterator it2;

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
#endif

	for (it1 = ptrees.begin(); it1 != ptrees.end(); it1++) {
		std::stringstream s1, s2;
		NodeSetDefinitionParser parser;
		StructureDefinitionExpand::SPtr structureDefinition;

		cx1.ptree(*it1);
		BOOST_REQUIRE(cx1.write(s1) == true);
		if (s1.str().find("Value=") != std::string::npos) continue;

		// decode definition element
		BOOST_REQUIRE(parser.decode(*it1, structureDefinition, false) == true);

		// encode definition element
		boost::property_tree::ptree ptree;
		BOOST_REQUIRE(parser.encode(structureDefinition, ptree, false) == true);

		// create string stream from property trees and compare streams
		cx2.ptree(ptree);
		BOOST_REQUIRE(cx2.write(s2) == true);
		if (s1.str() != s2.str()) {
			std::cout << s1.str() << std::endl;
			std::cout << std::endl;
			std::cout << s2.str() << std::endl;
		}
		BOOST_REQUIRE(s1.str() == s2.str());

	}
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_encode_decode_enum_description)
{
	ConfigXml configXml, cx1, cx2;
	NodeSetXmlParser nodeSetXmlParser;
	std::vector<boost::property_tree::ptree> ptrees;
	std::vector<boost::property_tree::ptree>::iterator it1;

	// read all definition elements from nodeset
	BOOST_REQUIRE(configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml") == true);
	configXml.find("Definition", ptrees);
	BOOST_REQUIRE(ptrees.size() > 0);

	for (it1 = ptrees.begin(); it1 != ptrees.end(); it1++) {
		std::stringstream s1, s2;
		NodeSetDefinitionParser parser;
		EnumDefinitionExpand::SPtr enumDefinition;

		cx1.ptree(*it1);
		BOOST_REQUIRE(cx1.write(s1) == true);
		if (s1.str().find("Value=") == std::string::npos) continue;

		// decode definition element
		BOOST_REQUIRE(parser.decode(*it1, enumDefinition, false) == true);

		// encode definition element
		boost::property_tree::ptree ptree;
		BOOST_REQUIRE(parser.encode(enumDefinition, ptree, false) == true);

		// create string stream from property trees and compare streams
		cx2.ptree(ptree);
		BOOST_REQUIRE(cx2.write(s2) == true);
		if (s1.str() != s2.str()) {
			std::cout << s1.str() << std::endl;
			std::cout << std::endl;
			std::cout << s2.str() << std::endl;
		}
		BOOST_REQUIRE(s1.str() == s2.str());

	}
}

BOOST_AUTO_TEST_SUITE_END()


