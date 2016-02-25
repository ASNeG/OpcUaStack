/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ApplicationInfo_h__
#define __OpcUaStackServer_ApplicationInfo_h__

#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationInfo
	{
	  public:
		ApplicationInfo(void);
		virtual ~ApplicationInfo(void);

		void applicationName(const std::string& applicationName);
		std::string& applicationName(void);
		void libraryName(const std::string& libraryName);
		std::string& libraryName(void);
		void configFileName(const std::string& configFileName);
		std::string& configFileName(void);

	  private:
		std::string applicationName_;
		std::string libraryName_;
		std::string configFileName_;
	};

}

#endif
