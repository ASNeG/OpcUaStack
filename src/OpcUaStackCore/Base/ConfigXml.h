/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ConfigXml_h__
#define __OpcUaStackCore_ConfigXml_h__

#include <boost/property_tree/ptree.hpp>
#include <string>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ConfigIf.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ConfigXml
	{
	  public:
		ConfigXml(void);
		~ConfigXml(void);

		bool write(const std::string& configFileName);
		bool write(std::ostream& os);
		bool read(const std::string& configFileName);
		bool read(std::istream& is);
		bool parse(std::istream& is);
		bool parse(const std::string& configFileName, bool writeToConfig = false);
		bool parse(const std::string& configFileName, ConfigIf* configIf);
		std::string errorMessage(void);
		boost::property_tree::ptree& ptree(void);
		void ptree(boost::property_tree::ptree& ptree);
		void writeToConfig(void);
		void writeToConfig(ConfigIf* configIf);

	  private:
		std::string configFileName_;
		boost::property_tree::ptree ptree_;
		std::string errorMessage_;
	};

}

#endif
