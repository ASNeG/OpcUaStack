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

#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

namespace OpcUaStackClient
{

	VBIClient::VBIClient(void)
	: serviceSetManager_()
	, ioThreadName_("VBIClient")
	, sessionService_()
	, sessionStateUpdateCallback_()
	{
	}

	VBIClient::~VBIClient(void)
	{
		sessionService_.reset();
		sessionStateUpdateCallback_.reset();
	}

	void
	VBIClient::ioThreadName(const std::string& ioThreadName)
	{
		ioThreadName_ = ioThreadName;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	VBIClient::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		if (sessionStateUpdateCallback_.exist()) {
			sessionStateUpdateCallback_(session, sessionState);
		}
	}

	OpcUaStatusCode
	VBIClient::syncConnect(ConnectContext& connectContext)
	{
		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(connectContext.endpointUrl_);
		sessionServiceConfig.session_->sessionName(connectContext.sessionName_);
		sessionServiceConfig.ioThreadName(ioThreadName_);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);
		assert(sessionService_.get() != nullptr);

		// connect to opc ua server
		sessionStateUpdateCallback_.reset();
		return sessionService_->syncConnect();
	}

	void
	VBIClient::asyncConnect(Callback& callback, ConnectContext& connectContext)
	{
		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(connectContext.endpointUrl_);
		sessionServiceConfig.session_->sessionName(connectContext.sessionName_);

		// create session
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);
		assert(sessionService_.get() != nullptr);

		// connect session
		sessionStateUpdateCallback_ = callback;
		sessionService_->asyncConnect();
	}

	OpcUaStatusCode
	VBIClient::syncDisconnect(void)
	{
		// connect session
		return sessionService_->syncDisconnect();
	}

	void
	VBIClient::asyncDisconnect(void)
	{
		sessionService_->asyncDisconnect();
	}

	void
	VBIClient::asyncDisconnect(Callback& callback)
	{
		// disconnect session
		sessionStateUpdateCallback_ = callback;
		sessionService_->asyncDisconnect();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AttributeService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	VBIClient::syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue)
	{
		return Success;
	}

	void
	VBIClient::asyncRead(OpcUaNodeId& nodeId, Callback& callback)
	{
	}

	OpcUaStatusCode
	VBIClient::syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue)
	{
		return Success;
	}

	void
	VBIClient::asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback)
	{
	}

}
