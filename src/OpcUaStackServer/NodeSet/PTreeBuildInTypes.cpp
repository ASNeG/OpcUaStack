/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/lexical_cast.hpp>
#include "OpcUaStackServer/NodeSet/PTreeBuildInTypes.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	PTreeBuildInTypes::PTreeBuildInTypes(void)
	{
	}

	PTreeBuildInTypes::~PTreeBuildInTypes(void)
	{
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaBoolean& value, const std::string& tag)
	{
		if (value) {
			ptree.put(tag, "true");
		}
		else {
			ptree.put(tag, "false");
		}
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaByte& value, const std::string& tag)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		ptree.put(tag, ss.str());
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaSByte& value, const std::string& tag)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		ptree.put(tag, ss.str());
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaDateTime& value, const std::string& tag)
	{
		ptree.put(tag, value.toISOString());
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaString::SPtr value, const std::string& tag)
	{
		ptree.put(tag, value->value());
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr value, const std::string& tag)
	{
		OpcUaByte *data;
		OpcUaInt32 dataLen;
		value->value(&data, &dataLen);
		if (dataLen < 0) {
			ptree.put(tag, std::string(""));
			return true;
		}
		std::string byteString((char*)data, dataLen);
		ptree.put(tag, byteString);
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr value, const std::string& tag)
	{
		std::string text = value->text().value();
		ptree.put(tag + std::string(".") + std::string("Text"), text);

		std::string locale = value->locale().value();
		ptree.put(tag + std::string(".") + std::string("Locale"), locale);
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr value, const std::string& tag)
	{
		std::string guidString = *value;
		std::string localTag = tag + std::string(".") + std::string("String");
		ptree.put(localTag, guidString);
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr value, const std::string& tag)
	{
		if (value->namespaceIndex() != 0 ) {
			std::stringstream ss;
			ss << value->namespaceIndex();;
			std::string localTag = tag + std::string(".") + std::string("NamespaceIndex");
			ptree.put(localTag, ss.str());
		}

		std::string localTag = tag + std::string(".") + std::string("Name");
		//ptree.put(localTag, value->name().value());
		return true;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr value, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::encode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr value, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaBoolean& destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaByte& destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaSByte& destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaDateTime& destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaString::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

	bool
	PTreeBuildInTypes::decode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr destValue, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}



}
