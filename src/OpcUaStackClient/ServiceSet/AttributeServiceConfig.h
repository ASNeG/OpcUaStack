/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_AttributeServiceConfig_h__
#define __OpcUaStackClient_AttributeServiceConfig_h__

#include "OpcUaStackClient/ServiceSet/ServiceConfigBase.h"

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeServiceConfig
	: public ServiceConfigBase
	{
	  public:
		typedef boost::shared_ptr<AttributeServiceConfig> SPtr;

		AttributeServiceConfig(void);
		~AttributeServiceConfig(void);

		std::string attributeServiceName_ = "AttributeService";
	};

}

#endif
