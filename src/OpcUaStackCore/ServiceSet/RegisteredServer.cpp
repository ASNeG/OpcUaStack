/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/RegisteredServer.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisteredServer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisteredServer::RegisteredServer(void)
	: Object()
	, serverUri_()
	, productUri_()
	, serverNameArraySPtr_(constructSPtr<OpcUaLocalizedTextArray>())
	, serverType_()
	, gatewayServerUri_()
	, discoveryUrlArraySPtr_(constructSPtr<OpcUaStringArray>())
	, semaphoreFilePath_()
	, isOnline_()
	{
	}

	RegisteredServer::~RegisteredServer(void)
	{
	}

	void 
	RegisteredServer::serverUri(const OpcUaString& serverUri)
	{
		serverUri_ = serverUri;
	}
	
	void 
	RegisteredServer::serverUri(const std::string& serverUri)
	{
		serverUri_.value(serverUri);
	}
	
	OpcUaString& 
	RegisteredServer::serverUri(void)
	{
		return serverUri_;
	}
	
	void 
	RegisteredServer::productUri(const OpcUaString& productUri)
	{
		productUri_ = productUri;
	}
	
	void 
	RegisteredServer::productUri(const std::string& productUri)
	{
		productUri_.value(productUri);
	}
	
	OpcUaString& 
	RegisteredServer::productUri(void)
	{
		return productUri_;
	}
	
	void 
	RegisteredServer::serverNames(const OpcUaLocalizedTextArray::SPtr& serverNames)
	{
		serverNameArraySPtr_ = serverNames;
	}
	
	OpcUaLocalizedTextArray::SPtr
	RegisteredServer::serverNames(void) const
	{
		return serverNameArraySPtr_;
	}
	
	void 
	RegisteredServer::serverType(const ApplicationType serverType)
	{
		serverType_ = serverType;
	}
	
	ApplicationType 
	RegisteredServer::serverType(void)
	{
		return serverType_;
	}
	
	void 
	RegisteredServer::gatewayServerUri(const OpcUaString& gatewayServerUri)
	{
		gatewayServerUri_ = gatewayServerUri;
	}
	
	void 
	RegisteredServer::gatewayServerUri(const std::string& gatewayServerUri)
	{
		gatewayServerUri_.value(gatewayServerUri);
	}
	
	OpcUaString& 
	RegisteredServer::gatewayServerUri(void)
	{
		return gatewayServerUri_;
	}

	void 
	RegisteredServer::discoveryUrls(const OpcUaStringArray::SPtr discoveryUrls)
	{
		discoveryUrlArraySPtr_ = discoveryUrls;
	}
	
	OpcUaStringArray::SPtr 
	RegisteredServer::discoveryUrls(void) const
	{
		return discoveryUrlArraySPtr_;
	}
	
	void 
	RegisteredServer::semaphoreFilePath(const OpcUaString& semaphoreFilePath)
	{
		semaphoreFilePath_ = semaphoreFilePath;
	}
	
	void 
	RegisteredServer::semaphoreFilePath(const std::string& semaphoreFilePath)
	{
		semaphoreFilePath_.value(semaphoreFilePath);
	}
	
	OpcUaString& 
	RegisteredServer::semaphoreFilePath(void)
	{
		return semaphoreFilePath_;
	}
	
	void 
	RegisteredServer::isOnline(const OpcUaBoolean& isOnline)
	{
		isOnline_ = isOnline;
	}
	
	OpcUaBoolean 
	RegisteredServer::isOnline(void)
	{
		return isOnline_;
	}

	void 
	RegisteredServer::opcUaBinaryEncode(std::ostream& os) const
	{
		serverUri_.opcUaBinaryEncode(os);
		productUri_.opcUaBinaryEncode(os);
		serverNameArraySPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)serverType_);
		gatewayServerUri_.opcUaBinaryEncode(os);
		discoveryUrlArraySPtr_->opcUaBinaryEncode(os);
		semaphoreFilePath_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isOnline_);
	}
	
	void 
	RegisteredServer::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		serverUri_.opcUaBinaryDecode(is);
		productUri_.opcUaBinaryDecode(is);
		serverNameArraySPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		serverType_ = (ApplicationType)tmp;
		gatewayServerUri_.opcUaBinaryDecode(is);
		discoveryUrlArraySPtr_->opcUaBinaryDecode(is);
		semaphoreFilePath_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isOnline_);
	}

	void
	RegisteredServer::copyTo(RegisteredServer& registeredServer)
	{
		serverUri_.copyTo(registeredServer.serverUri());
		productUri_.copyTo(registeredServer.productUri());
		gatewayServerUri_.copyTo(registeredServer.gatewayServerUri());
		semaphoreFilePath_.copyTo(registeredServer.semaphoreFilePath());
		registeredServer.serverType_ = serverType_;
		registeredServer.isOnline_ = isOnline_;
		discoveryUrlArraySPtr_->copyTo(*registeredServer.discoveryUrls());
		serverNameArraySPtr_->copyTo(*registeredServer.serverNames());
	}

}
