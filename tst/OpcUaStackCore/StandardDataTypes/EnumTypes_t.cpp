#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(EnumTypes_)

BOOST_AUTO_TEST_CASE(EnumTypes_)
{
	std::cout << "EnumTypes_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(EnumTypes_construct_destruct)
{
	NodeClass nodeClass1;
	NodeClass nodeClass2(NodeClass::EnumMethod);
	NodeClass nodeClass3(nodeClass2);

	BOOST_REQUIRE(nodeClass2 == nodeClass3);
	BOOST_REQUIRE(nodeClass1.value() == NodeClass::EnumUnspecified);
	BOOST_REQUIRE(nodeClass2.value() == NodeClass::EnumMethod);
	BOOST_REQUIRE(nodeClass3.value() == NodeClass::EnumMethod);
}

BOOST_AUTO_TEST_CASE(EnumTypes_setter_getter)
{
	NodeClass nodeClass;

	nodeClass.enumeration(NodeClass::EnumDataType);
	BOOST_REQUIRE(nodeClass.enumeration() == NodeClass::EnumDataType);
	BOOST_REQUIRE(nodeClass.enum2Str() == "DataType");
	BOOST_REQUIRE(nodeClass.toString() == "DataType");
}

BOOST_AUTO_TEST_CASE(EnumTypes_mapping)
{
	NodeClass nodeClass;

	BOOST_REQUIRE(nodeClass.enum2Str(NodeClass::EnumObject) == "Object");
	BOOST_REQUIRE(nodeClass.str2Enum("Object") == NodeClass::EnumObject);
}

BOOST_AUTO_TEST_CASE(EnumTypes_exist)
{
	NodeClass nodeClass;

	BOOST_REQUIRE(nodeClass.exist(NodeClass::EnumObject) == true);
	BOOST_REQUIRE(nodeClass.exist("Object") == true);
	BOOST_REQUIRE(nodeClass.exist("UNKNOWN") == false);
}

BOOST_AUTO_TEST_CASE(EnumTypes_factory)
{
	NodeClass nodeClass;
	ExtensionObjectBase::SPtr extensionObjectBase;

	extensionObjectBase = nodeClass.factory();
	BOOST_REQUIRE(extensionObjectBase.get() != nullptr);
	BOOST_REQUIRE(dynamic_cast<NodeClass*>(extensionObjectBase.get()) != nullptr);
	BOOST_REQUIRE(dynamic_cast<OpcUaLocalizedText*>(extensionObjectBase.get()) == nullptr);
}

BOOST_AUTO_TEST_CASE(EnumTypes_binary_encode_decode)
{
	NodeClass nodeClass;
	ExtensionObjectBase::SPtr eO1, eO2;

	eO1 = nodeClass.factory();
	BOOST_REQUIRE(eO1.get() != nullptr);
	eO2 = nodeClass.factory();
	BOOST_REQUIRE(eO2.get() != nullptr);

	// encode
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	eO1->opcUaBinaryEncode(ios);

	// decode
	eO2->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(*eO1 == *eO2);

}

BOOST_AUTO_TEST_CASE(EnumTypes_xml_encode_decode)
{
	Xmlns xmlns;
	NodeClass nodeClass;
	ExtensionObjectBase::SPtr eO1, eO2;

	eO1 = nodeClass.factory();
	BOOST_REQUIRE(eO1.get() != nullptr);
	eO2 = nodeClass.factory();
	BOOST_REQUIRE(eO2.get() != nullptr);

	// encode
	boost::property_tree::ptree ptree;
	eO1->xmlEncode(ptree, xmlns);

	// decode
	eO2->xmlDecode(ptree, xmlns);
	BOOST_REQUIRE(*eO1 == *eO2);

}

BOOST_AUTO_TEST_CASE(EnumTypes_xml_copyTo)
{
	Xmlns xmlns;
	NodeClass nodeClass;
	ExtensionObjectBase::SPtr eO1, eO2;

	eO1 = nodeClass.factory();
	BOOST_REQUIRE(eO1.get() != nullptr);
	eO2 = nodeClass.factory();
	BOOST_REQUIRE(eO2.get() != nullptr);

	// copy Top
	eO1->copyTo(*eO2);
	BOOST_REQUIRE(*eO1 == *eO2);

}

BOOST_AUTO_TEST_SUITE_END()

