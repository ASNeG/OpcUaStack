/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationServiceTransaction.h"

namespace OpcUaStackServer
{

	class DLLEXPORT GetNamespaceInfo
	{
	  public:
		using SPtr = boost::shared_ptr<GetNamespaceInfo>;

		GetNamespaceInfo(void);
		virtual ~GetNamespaceInfo(void);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

		void newNamespaceUri(const std::string& newNamespaceUri);
		int32_t getNamespaceIndex(const std::string& namespaceUri);

	  private:
		std::string newNamespaceUri_ = "";
		OpcUaStackCore::OpcUaStatusCode resultCode_ = OpcUaStackCore::Success;
		NamespaceInfoResponse::Index2NamespaceMap index2NamespaceMap_;
		NamespaceInfoResponse::Namespace2IndexMap namespace2IndexMap_;
	};

}
#endif
