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

#ifndef __OpcUaClient_ConfigBase_h__
#define __OpcUaClient_ConfigBase_h__

#include <iostream>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaClient
{

	class DLLEXPORT ConfigBase
	{
	  public:
		ConfigBase(void);
		ConfigBase(ConfigBase& cb, const std::string& additionalElementPrefix);
		~ConfigBase(void);

		void elementPrefix(const std::string& elementPrefix);
		std::string& elementPrefix(void);
		void configFileName(const std::string& configFileName);
		std::string& configFileName(void);

	  private:
		std::string elementPrefix_;
		std::string configFileName_;
	};

}

#endif
