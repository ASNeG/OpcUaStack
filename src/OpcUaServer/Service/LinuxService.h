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

#ifndef __OpcUaServer_LinuxService_h__
#define __OpcUaServer_LinuxService_h__

#include "OpcUaServer/Interface/ServerLoopIf.h"

namespace OpcUaServer
{

	class DLLEXPORT LinuxService
	{
	  public:
		static LinuxService* instance_;
		static LinuxService* instance(void);

		LinuxService(void);
		virtual ~LinuxService(void);

		void usage(void);
		void main(unsigned int argc, char** argv);

		void serverLoopIf(ServerLoopIf* serverLoopIf);
		void stop(void);

	  private:
		ServerLoopIf* serverLoopIf_;
	};

}

#endif
