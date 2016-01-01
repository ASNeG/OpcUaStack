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

#ifndef __OpcUaStackClient_NamespaceArray_h__
#define __OpcUaStackClient_NamespaceArray_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/SessionOld.h"

namespace OpcUaStackClient
{

	class DLLEXPORT NamespaceArray
	{
	  public:
		NamespaceArray(void);
		NamespaceArray(SessionOld::SPtr session);
		~NamespaceArray(void);

		void session(SessionOld::SPtr session);
		bool readSync(IOThread* ioThread);
		std::vector<std::string>& namespaceVec(void);

	  private:
		SessionOld::SPtr session_;
		std::vector<std::string> namespaceVec_;
	};

}

#endif
