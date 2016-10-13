/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include "OpcUaServerApplicationDemo/DemoLibrary/Function.h"

namespace OpcUaServerApplicationDemo
{

	Function::Function(void)
	: ioThread_(nullptr)
	, applicationServiceIf_(nullptr)
	, applicationInfo_(nullptr)
	, namespaceIndex_(0)
	, baseNodeClassWMap_()
	, methodCallback_(boost::bind(&Function::method, this, _1))
	{
	}

	Function::~Function(void)
	{
	}

	bool
	Function::startup(
		IOThread& ioThread,
		ApplicationServiceIf& applicationServiceIf,
		ApplicationInfo* applicationInfo
	)
	{
		Log(Debug, "Function::startup");

		ioThread_ = &ioThread;
		applicationServiceIf_ = &applicationServiceIf;
		applicationInfo_ = applicationInfo;

		// read namespace array from opc ua server
		if (!getNamespaceInfo()) {
			return false;
		}

		// register function callbacks
		if (!registerCallbacks()) {
			return false;
		}

		return true;
	}

	bool
	Function::shutdown(void)
	{
		Log(Debug, "Function::shutdown");

		return true;
	}

	bool
	Function::getNamespaceInfo(void)
	{
		Log(Debug, "get namespace info");

		ServiceTransactionNamespaceInfo::SPtr trx = constructSPtr<ServiceTransactionNamespaceInfo>();
		NamespaceInfoRequest::SPtr req = trx->request();
		NamespaceInfoResponse::SPtr res = trx->response();

		applicationServiceIf_->sendSync(trx);
		if (trx->statusCode() != Success) {
			Log(Error, "NamespaceInfoResponse error")
			    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
			return false;
		}

		NamespaceInfoResponse::Index2NamespaceMap::iterator it;
		for (
		    it = res->index2NamespaceMap().begin();
			it != res->index2NamespaceMap().end();
			it++
		)
		{
			if (it->second == "http://ASNeG.de/Function/") {
				namespaceIndex_ = it->first;
				return true;
			}
 		}

		Log(Error, "namespace not found in configuration")
	        .parameter("NamespaceUri", "http://ASNeG.de/Function/");

		func1_.set(std::string("func1"), namespaceIndex_);
		func2_.set(std::string("func2"), namespaceIndex_);
		func3_.set(std::string("func3"), namespaceIndex_);
		funcMult_.set(std::string("funcMult"), namespaceIndex_);

		return false;
	}

	bool
	Function::registerCallbacks(void)
	{
		Log(Debug, "register method callbacks");

	  	ServiceTransactionRegisterForward::SPtr trx = constructSPtr<ServiceTransactionRegisterForward>();
	  	RegisterForwardRequest::SPtr req = trx->request();
	  	RegisterForwardResponse::SPtr res = trx->response();

	  	req->forwardInfoSync()->methodService().setCallback(methodCallback_);
	  	req->nodesToRegister()->resize(1);

	  	OpcUaNodeId::SPtr nodeId;

	  	// add func1
	  	nodeId = constructSPtr<OpcUaNodeId>();
	  	nodeId->set(std::string("Function"), namespaceIndex_);
	  	req->nodesToRegister()->push_back(nodeId);

	  	applicationServiceIf_->sendSync(trx);
	  	if (trx->statusCode() != Success) {
	  		std::cout << "response error" << std::endl;
	  		return false;
	  	}

	  	for (uint32_t pos = 0; pos < res->statusCodeArray()->size(); pos++) {
	  		OpcUaStatusCode statusCode;
	  		res->statusCodeArray()->get(pos, statusCode);
	  		if (statusCode != Success) {
	  			std::cout << "register value error" << std::endl;
	  			return false;
	  		}
	  	}

		return true;
	}

	void
	Function::method(ApplicationMethodContext* applicationMethodContext)
	{
		Log(Debug, "method call")
			.parameter("ObjectNodeId", applicationMethodContext->objectNodeId_)
			.parameter("MethodNodeId", applicationMethodContext->methodNodeId_);

		// method func1
		if (applicationMethodContext->methodNodeId_ == func1_) {
			applicationMethodContext->statusCode_ = Success;
		}

		// method func2
		else if (applicationMethodContext->methodNodeId_ == func2_) {
			if (applicationMethodContext->inputArguments_->size() != 0) {
				Log(Debug, "input arguments")
				    .parameter("Arguments", applicationMethodContext->inputArguments_);
			}
			applicationMethodContext->statusCode_ = Success;
		}

		// method func3
		else if (applicationMethodContext->methodNodeId_ == func3_) {
			if (applicationMethodContext->inputArguments_->size() != 0) {
				Log(Debug, "input arguments")
				    .parameter("Arguments", applicationMethodContext->inputArguments_);
			}
			applicationMethodContext->statusCode_ = Success;
		}

		// method funcMult
		else if (applicationMethodContext->methodNodeId_ == funcMult_) {
			if (applicationMethodContext->inputArguments_->size() != 0) {
				Log(Debug, "input arguments")
				    .parameter("Arguments", applicationMethodContext->inputArguments_);
			}
			applicationMethodContext->statusCode_ = Success;
		}

		else {
			applicationMethodContext->statusCode_ = BadNotSupported;
		}

	}

}
