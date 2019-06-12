/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Json_h__
#define __OpcUaStackCore_Json_h__

#include <boost/property_tree/ptree.hpp>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumberTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Json
	{
	  public:
		static bool toDocumentString(boost::property_tree::ptree& pt, std::string& string);
		static bool toString(boost::property_tree::ptree& pt, std::string& string, bool logEnable = false);
		static bool fromString(const std::string& string, boost::property_tree::ptree& pt, bool logEnable = false);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaBoolean& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaBoolean& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaSByte& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaSByte& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaByte& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaByte& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt16& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt16& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt16& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt16& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt32& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt32& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt32& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt32& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt64& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt64& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt64& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt64& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaFloat& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaFloat& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaDouble& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaDouble& value);
	};

}

#endif
