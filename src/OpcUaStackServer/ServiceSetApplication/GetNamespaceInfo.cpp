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

#include "OpcUaStackServer/ServiceSetApplication/GetNamespaceInfo.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	GetNamespaceInfo::GetNamespaceInfo(void)
	{
	}

	GetNamespaceInfo::~GetNamespaceInfo(void)
	{
	}

	bool
	GetNamespaceInfo::query(ApplicationServiceIf* applicationServiceIf)
	{
		// create request
		auto trx = boost::make_shared<ServiceTransactionNamespaceInfo>();
		auto req = trx->request();
		auto res = trx->response();

		// set request parameter
		req->newNamespaceUri(newNamespaceUri_);

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) return false;

	  	// handle response
		index2NamespaceMap_ = res->index2NamespaceMap();
		namespace2IndexMap_= res->namespace2IndexMap();

		return true;
	}

	OpcUaStatusCode
	GetNamespaceInfo::resultCode(void)
	{
		return resultCode_;
	}

	void
	GetNamespaceInfo::newNamespaceUri(const std::string& newNamespaceUri)
	{
		newNamespaceUri_ = newNamespaceUri;
	}

	int32_t
	GetNamespaceInfo::getNamespaceIndex(const std::string& namespaceUri)
	{
		auto it = namespace2IndexMap_.find(namespaceUri);
		if (it == namespace2IndexMap_.end()) return -1;
		return (int32_t)it->second;
	}

}
