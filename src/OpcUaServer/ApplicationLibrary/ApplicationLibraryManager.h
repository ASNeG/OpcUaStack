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

#ifndef __OpcUaServer_ApplicationLibraryManager_h__
#define __OpcUaServer_ApplicationLibraryManager_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaServer/ApplicationLibrary/ApplicationLibrary.h"

namespace OpcUaServer
{

	class DLLEXPORT ApplicationLibraryManager
	{
	  public:
		ApplicationLibraryManager(void);
		~ApplicationLibraryManager(void);

		bool startup(void);
		bool shutdown(void);

		void config(OpcUaStackCore::Config& config);
		OpcUaStackCore::Config& config(void);
		ApplicationLibrary::Map& applicationLibraryMap(void);

	  private:
		OpcUaStackCore::Config* config_;
		ApplicationLibrary::Map applicationLibraryMap_;
	};

}

#endif
