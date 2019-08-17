/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_EndpointDescriptionConfig_h__
#define __OpcUaStackServer_EndpointDescriptionConfig_h__

#include <string>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescriptionSet.h"

namespace OpcUaStackServer
{

	class DLLEXPORT EndpointDescriptionConfig
	{
	  public:
		static bool endpointDescriptions(
			OpcUaStackCore::EndpointDescriptionSet::SPtr endpointDescriptionSet,
			const std::string& configPrefix, OpcUaStackCore::Config* childConfig,
			const std::string& configurationFileName
		);
		static bool securitySetting(
			OpcUaStackCore::EndpointDescription::SPtr endpointDescription,
			const std::string& configPrefix,
			OpcUaStackCore::Config* config,
			const std::string& configurationFileName,
			OpcUaStackCore::EndpointDescription::Vec& endpointDescriptionVec
		);
		static bool userTokenPolicy(
			OpcUaStackCore::EndpointDescription::SPtr endpointDescription,
			const std::string& configPrefix,
			OpcUaStackCore::Config* config,
			const std::string& configurationFileName
		);
	};

}

#endif
