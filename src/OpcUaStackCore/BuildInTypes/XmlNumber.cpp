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

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/lexical_cast.hpp>

#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{


	bool
	XmlNumber::xmlEncode(boost::property_tree::ptree& pt, OpcUaBoolean& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		boost::to_upper(sourceValue);
		if (sourceValue == "TRUE") value = true;
		else value = false;
		return true;
	}

	bool
	XmlNumber::xmlDecode(boost::property_tree::ptree& pt, OpcUaBoolean& value)
	{
		std::string sourceValue = pt.get_value<std::string>();
		try {
			value = (OpcUaByte)boost::lexical_cast<OpcUaUInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& e) {
			return false;
		}
		return true;
	}

}
