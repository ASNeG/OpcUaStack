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
#include "OpcUaStackClient/ValueBasedInterface/VBITransaction.h"

namespace OpcUaStackClient
{

	VBIClient::VBIClient(void)
	: serviceSetManager_()
	, ioThreadName_("VBIClient")
	, sessionService_()
	, attributeService_()
	, sessionStateUpdateCallback_()

	, defaultReadContext_()
	, defaultWriteContext_()
	{
	}

	VBIClient::~VBIClient(void)
	{
		attributeService_.reset();
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

	//
	// connect
	//
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


	//
	// disconnect
	//
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

	//
	// read
	//
    void
    VBIClient::attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead)
    {
    	VBITransactionRead::SPtr trx = boost::static_pointer_cast<VBITransactionRead>(serviceTransactionRead);

		if (trx->callback_.exist()) {
			OpcUaNodeId nodeId;
			OpcUaDataValue dataValue;

			if (trx->statusCode() != Success) {
				trx->callback_(trx->statusCode(), nodeId, dataValue);
				return;
			}
			ReadResponse::SPtr res = trx->response();
			if (res->dataValueArray()->size() != 1) {
				trx->callback_(BadUnexpectedError, nodeId, dataValue);
				return;
			}
			OpcUaDataValue::SPtr dataValueSPtr;
			res->dataValueArray()->get(0, dataValueSPtr);
			dataValue.copyFrom(*dataValueSPtr);

			ReadRequest::SPtr req = trx->request();
			ReadValueId::SPtr readValueIdSPtr;
			req->readValueIdArray()->get(0, readValueIdSPtr);
			readValueIdSPtr->nodeId()->copyTo(nodeId);

			trx->callback_(Success, nodeId, dataValue);
		}
    }

	ReadContext&
	VBIClient::defaultReadContext(void)
	{
		return defaultReadContext_;
	}

	OpcUaStatusCode
	VBIClient::syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue)
	{
		return syncRead(nodeId, dataValue, defaultReadContext_);
	}

	OpcUaStatusCode
	VBIClient::syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, ReadContext& readContext)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeServiceConfig.attributeServiceIf_ = this;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send ReadRequest
		VBITransactionRead::SPtr trx;
		trx = constructSPtr<VBITransactionRead>();
		ReadRequest::SPtr req = trx->request();
		ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
		readValueIdSPtr->nodeId()->copyFrom(nodeId);
		readValueIdSPtr->attributeId(readContext.attributeId_);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		req->readValueIdArray()->set(readValueIdSPtr);

		attributeService_->syncSend(trx);

		if (trx->statusCode() != Success) return trx->statusCode();
		ReadResponse::SPtr res = trx->response();
		if (res->dataValueArray()->size() != 1) return BadUnexpectedError;
		OpcUaDataValue::SPtr dataValueSPtr;
		res->dataValueArray()->get(0, dataValueSPtr);
		dataValue.copyFrom(*dataValueSPtr);
		return Success;
	}

	void
	VBIClient::asyncRead(OpcUaNodeId& nodeId, Callback& callback)
	{
		asyncRead(nodeId, callback, defaultReadContext_);
	}

	void
	VBIClient::asyncRead(OpcUaNodeId& nodeId, Callback& callback, ReadContext& readContext)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeServiceConfig.attributeServiceIf_ = this;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send ReadRequest
		VBITransactionRead::SPtr trx = constructSPtr<VBITransactionRead>();
		trx->callback_ = callback;
		ReadRequest::SPtr req = trx->request();
		ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
		readValueIdSPtr->nodeId()->copyFrom(nodeId);
		readValueIdSPtr->attributeId(readContext.attributeId_);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		req->readValueIdArray()->set(readValueIdSPtr);

		attributeService_->asyncSend(trx);
	}


	//
	// write
	//
	void
	VBIClient::attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
	}

	WriteContext&
	VBIClient::defaultWriteContext(void)
	{
		return defaultWriteContext_;
	}

	OpcUaStatusCode
	VBIClient::syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue)
	{
		WriteContext writeContext;
		return syncWrite(nodeId, dataValue, writeContext);
	}

	OpcUaStatusCode
	VBIClient::syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, WriteContext& writeContext)
	{
		return Success;
	}

	void
	VBIClient::asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback)
	{
		WriteContext writeContext;
		asyncWrite(nodeId, dataValue, callback);
	}

	void
	VBIClient::asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback, WriteContext& writeContext)
	{
	}


	//
	// history read
	//
	void
	VBIClient::attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
	}
	// FIXME: todo

	//
	//
	//
	void
	VBIClient::attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
	}
	// FIXME: todo

}
