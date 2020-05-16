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

#ifndef __OpcUaServer_ServerApplication_h__
#define __OpcUaServer_ServerApplication_h__

#include "OpcUaStackServer/Application/ReloadIf.h"
#include "OpcUaServer/Interface/ServerApplicationIf.h"
#include "OpcUaServer/Server/Server.h"

namespace OpcUaServer
{
	class DLLEXPORT ServerApplication
	: public ServerApplicationIf
	, public OpcUaStackServer::ReloadIf
	{
	  public:
		ServerApplication(void);
		~ServerApplication(void);

		virtual void serviceCommandLine(const std::string& configFileName, unsigned int argc, char** argv);
		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool loop(void);
		virtual void stopLoop(void);

		// -- interface RestartIf ---------------------------------------------
		virtual void reload(void);
		// -- interface RestartIf ---------------------------------------------

	  private:
		void processReload(void);

		OpcUaServer::Server server_;
		std::string serviceName_;
		std::string configFileName_;
		bool reload_;
		bool running_;

		boost::mutex mutex_;
		bool stopSignal_;
	};
}

#endif
