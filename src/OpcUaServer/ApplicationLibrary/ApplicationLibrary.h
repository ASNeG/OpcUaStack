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

#ifndef __OpcUaServer_ApplicationLibrary_h__
#define __OpcUaServer_ApplicationLibrary_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/Application/ApplicationInfo.h"
#include "OpcUaServer/ApplicationLibrary/DynamicLibrary.h"

#include <map>

namespace OpcUaServer
{

	class DLLEXPORT ApplicationLibrary
	: public  OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<ApplicationLibrary> SPtr;
		typedef std::map<std::string, ApplicationLibrary::SPtr> Map;
		typedef void InitFunction(OpcUaStackServer::ApplicationIf**);

		ApplicationLibrary(void);
		~ApplicationLibrary(void);

		void applicationInfo(const OpcUaStackServer::ApplicationInfo& applicationInfo);
		OpcUaStackServer::ApplicationInfo& applicationInfo(void);
		InitFunction* initFunction(void);
		OpcUaStackServer::ApplicationIf* applicationIf(void);
		std::string version(void);
		std::string gitCommit(void);
		std::string gitBranch(void);

		bool startup(void);
		bool shutdown(void);

	  private:
		OpcUaStackServer::ApplicationInfo applicationInfo_;
		InitFunction* initFunction_;
		DynamicLibrary dynamicLibrary_;
		OpcUaStackServer::ApplicationIf* applicationIf_;
	};

}

#endif
