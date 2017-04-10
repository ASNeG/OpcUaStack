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

#ifndef __OpcUaStackServer_PTreeBuildInTypes_h__
#define __OpcUaStackServer_PTreeBuildInTypes_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT PTreeBuildInTypes
	{
	  public:
		PTreeBuildInTypes(void);
		~PTreeBuildInTypes(void);

		static bool encode(boost::property_tree::ptree& ptree, OpcUaBoolean& value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaByte& value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaSByte& value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaDateTime& value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaString::SPtr value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr value, const std::string& tag);
		static bool encode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr value, const std::string& tag);

		static bool decode(boost::property_tree::ptree& ptree, OpcUaBoolean& destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaByte& destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaSByte& destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaDateTime& destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaString::SPtr destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr destValue, const std::string& tag);
		static bool decode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr destValue, const std::string& tag);

	};


}

#endif
