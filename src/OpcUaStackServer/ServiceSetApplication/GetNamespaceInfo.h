/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_GetNamespaceInfo_h__
#define __OpcUaStackServer_GetNamespaceInfo_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT GetNamespaceInfo
	{
	  public:
		typedef boost::shared_ptr<GetNamespaceInfo> SPtr;

		GetNamespaceInfo(void);
		virtual ~GetNamespaceInfo(void);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStatusCode resultCode(void);

		int32_t getNamespaceIndex(const std::string& namespaceUri);

	  private:
		OpcUaStatusCode resultCode_;
		NamespaceInfoResponse::Index2NamespaceMap index2NamespaceMap_;
		NamespaceInfoResponse::Namespace2IndexMap namespace2IndexMap_;
	};

}
#endif
