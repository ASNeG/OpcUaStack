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

#ifndef __OpcUaServer_DynamicLibrary_h__
#define __OpcUaServer_DynamicLibrary_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaServer
{

	class Lib;
	class DLLEXPORT DynamicLibrary
	{
	  public:

		DynamicLibrary(void);
		~DynamicLibrary(void);

		bool isOpen(void);
		bool open(const std::string& moduleName);
		bool close(void);

		bool get(const std::string& functionName, void **ptr);

	  private:
		std::string moduleName_;
		Lib* lib_;
	};

}

#endif
