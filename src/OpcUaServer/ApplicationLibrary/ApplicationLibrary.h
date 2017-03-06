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

#ifndef __OpcUaServer_ApplicationLibrary_h__
#define __OpcUaServer_ApplicationLibrary_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/Application/ApplicationInfo.h"
#include "OpcUaServer/ApplicationLibrary/DynamicLibrary.h"

#include <map>

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServer
{

	class ApplicationLibrary
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ApplicationLibrary> SPtr;
		typedef std::map<std::string, ApplicationLibrary::SPtr> Map;
		typedef void InitFunction(ApplicationIf**);

		ApplicationLibrary(void);
		~ApplicationLibrary(void);

		void applicationInfo(const ApplicationInfo& applicationInfo);
		ApplicationInfo& applicationInfo(void);
		InitFunction* initFunction(void);
		ApplicationIf* applicationIf(void);
		std::string version(void);

		bool startup(void);
		bool shutdown(void);

	  private:
		ApplicationInfo applicationInfo_;
		InitFunction* initFunction_;
		DynamicLibrary dynamicLibrary_;
		ApplicationIf* applicationIf_;
	};

}

#endif
