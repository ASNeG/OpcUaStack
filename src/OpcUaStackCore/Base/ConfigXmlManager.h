/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ConfigXmlManager_h__
#define __OpcUaStackCore_ConfigXmlManager_h__

#include <string>
#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ConfigXmlManager
	{
	  public:
		ConfigXmlManager(void);
		~ConfigXmlManager(void);

		bool registerConfiguration(const std::string& configurationFileName, Config::SPtr& config);
		bool deregisterConfiguration(const std::string& configurationFileName);
		bool existConfiguration(const std::string& configurationFileName);
		std::string& errorMessage(void);

	  private:
		Config::Map configMap_;
		std::string errorMessage_;
	};

}

#endif
