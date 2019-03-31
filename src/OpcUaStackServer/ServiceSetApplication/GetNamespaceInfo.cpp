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

#include "OpcUaStackServer/ServiceSetApplication/GetNamespaceInfo.h"

namespace OpcUaStackServer
{

	GetNamespaceInfo::GetNamespaceInfo(void)
	: resultCode_(Success)
	, index2NamespaceMap_()
	, namespace2IndexMap_()
	{
	}

	GetNamespaceInfo::~GetNamespaceInfo(void)
	{
	}

	bool
	GetNamespaceInfo::query(ApplicationServiceIf* applicationServiceIf)
	{
		// create request
		auto trx = constructSPtr<ServiceTransactionNamespaceInfo>();

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) return false;

	  	// handle response
		index2NamespaceMap_ = trx->response()->index2NamespaceMap();
		namespace2IndexMap_= trx->response()->namespace2IndexMap();

		return true;
	}

	OpcUaStatusCode
	GetNamespaceInfo::resultCode(void)
	{
		return resultCode_;
	}

	int32_t
	GetNamespaceInfo::getNamespaceIndex(const std::string& namespaceUri)
	{
		auto it = namespace2IndexMap_.find(namespaceUri);
		if (it == namespace2IndexMap_.end()) return -1;
		return (int32_t)it->second;
	}

}
