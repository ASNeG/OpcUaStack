/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_JsonNumber_h__
#define __OpcUaStackCore_JsonNumber_h__

#include <boost/property_tree/ptree.hpp>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumberTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT JsonNumber
	{
	  public:
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaBoolean value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaByte value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaSByte value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt16 value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaInt16 value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt32 value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaInt32 value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt64 value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaInt64 value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaFloat value, const std::string& element);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaDouble value, const std::string& element);

		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaBoolean value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaByte value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaSByte value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt16 value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaInt16 value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt32 value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaInt32 value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaUInt64 value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaInt64 value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaFloat value);
		static bool jsonEncode(boost::property_tree::ptree& pt, OpcUaDouble value);

		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaBoolean& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaByte& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaSByte& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt16& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt16& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt32& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt32& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt64& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt64& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaFloat& value, const std::string& element);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaDouble& value, const std::string& element);

		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaBoolean& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaByte& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaSByte& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt16& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt16& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt32& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt32& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaUInt64& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaInt64& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaFloat& value);
		static bool jsonDecode(const boost::property_tree::ptree& pt, OpcUaDouble& value);

	};

}

#endif
