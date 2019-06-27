/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
	, subscriptionService_()
	, monitoredItemService_()
	, viewService_()

	, sessionChangeCallback_()
	, subscriptionChangeCallback_()
	, dataChangeCallback_()

	, defaultReadContext_()
	, defaultWriteContext_()
	, defaultCreateSubscriptionContext_()
	, defaultDeleteSubscriptionContext_()
	, defaultCreateMonitoredItemContext_()
	, defaultDeleteMonitoredItemContext_()
	{
	}

	VBIClient::~VBIClient(void)
	{
		attributeService_.reset();
		subscriptionService_.reset();
		sessionService_.reset();
		monitoredItemService_.reset();
		viewService_.reset();

		sessionChangeCallback_.reset();
		subscriptionChangeCallback_.reset();
		dataChangeCallback_.reset();

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
	VBIClient::setSessionChangeCallback(Callback& callback)
	{
		sessionChangeCallback_ = callback;
	}

	void
	VBIClient::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		if (sessionChangeCallback_.exist()) {
			sessionChangeCallback_(session, sessionState);
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
		sessionServiceConfig.secureChannelClient_->applicationCertificate(connectContext.applicationCertificate_);
		sessionServiceConfig.secureChannelClient_->cryptoManager(connectContext.cryptoManager_);
		sessionServiceConfig.secureChannelClient_->secureChannelLog(connectContext.secureChannelLog_);
		sessionServiceConfig.session_->sessionName(connectContext.sessionName_);
		sessionServiceConfig.ioThreadName(ioThreadName_);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);
		assert(sessionService_.get() != nullptr);

		// connect to opc ua server
		return sessionService_->syncConnect();
	}

	void
	VBIClient::asyncConnect(ConnectContext& connectContext)
	{
		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(connectContext.endpointUrl_);
		sessionServiceConfig.secureChannelClient_->applicationCertificate(connectContext.applicationCertificate_);
		sessionServiceConfig.secureChannelClient_->cryptoManager(connectContext.cryptoManager_);
		sessionServiceConfig.secureChannelClient_->secureChannelLog(connectContext.secureChannelLog_);
		sessionServiceConfig.session_->sessionName(connectContext.sessionName_);
		sessionServiceConfig.ioThreadName(ioThreadName_);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);
		assert(sessionService_.get() != nullptr);

		// connect to opc ua server
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AttributeService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// read
	// ------------------------------------------------------------------------
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
		ReadValueId::SPtr readValueIdSPtr = constructSPtr<ReadValueId>();
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
		ReadValueId::SPtr readValueIdSPtr = constructSPtr<ReadValueId>();
		readValueIdSPtr->nodeId()->copyFrom(nodeId);
		readValueIdSPtr->attributeId(readContext.attributeId_);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		req->readValueIdArray()->set(readValueIdSPtr);

		attributeService_->asyncSend(trx);
	}


	// ------------------------------------------------------------------------
	// write
	// ------------------------------------------------------------------------
	void
	VBIClient::attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
    	VBITransactionWrite::SPtr trx = boost::static_pointer_cast<VBITransactionWrite>(serviceTransactionWrite);

		if (trx->callback_.exist()) {
			OpcUaNodeId nodeId;

			if (trx->statusCode() != Success) {
				trx->callback_(trx->statusCode(), nodeId);
				return;
			}
			WriteResponse::SPtr res = trx->response();
			if (res->results()->size() != 1) {
				trx->callback_(BadUnexpectedError, nodeId);
				return;
			}

			OpcUaStatusCode statusCode;
			res->results()->get(0, statusCode);

			WriteRequest::SPtr req = trx->request();
			WriteValue::SPtr writeValue;
			req->writeValueArray()->get(0, writeValue);
			writeValue->nodeId()->copyTo(nodeId);

			trx->callback_(statusCode, nodeId);
		}
	}

	WriteContext&
	VBIClient::defaultWriteContext(void)
	{
		return defaultWriteContext_;
	}

	OpcUaStatusCode
	VBIClient::syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue)
	{
		return syncWrite(nodeId, dataValue, defaultWriteContext_);
	}

	OpcUaStatusCode
	VBIClient::syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, WriteContext& writeContext)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeServiceConfig.attributeServiceIf_ = this;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send WriteRequest
		VBITransactionWrite::SPtr trx;
		trx = constructSPtr<VBITransactionWrite>();
		WriteRequest::SPtr req = trx->request();

		WriteValue::SPtr writeValue = constructSPtr<WriteValue>();
		writeValue->nodeId()->copyFrom(nodeId);
		writeValue->attributeId(writeContext.attributeId_);
		writeValue->dataValue().copyFrom(dataValue);
		req->writeValueArray()->resize(1);
		req->writeValueArray()->set(writeValue);

		attributeService_->syncSend(trx);
		if (trx->statusCode() != Success) return trx->statusCode();
		WriteResponse::SPtr res = trx->response();
		if (res->results()->size() != 1) return BadUnexpectedError;

		OpcUaStatusCode statusCode;
		res->results()->get(0, statusCode);
		return statusCode;
	}

	void
	VBIClient::asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback)
	{
		asyncWrite(nodeId, dataValue, callback, defaultWriteContext_);
	}

	void
	VBIClient::asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback, WriteContext& writeContext)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeServiceConfig.attributeServiceIf_ = this;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send WriteRequest
		VBITransactionWrite::SPtr trx;
		trx = constructSPtr<VBITransactionWrite>();
		trx->callback_ = callback;
		WriteRequest::SPtr req = trx->request();

		WriteValue::SPtr writeValue = constructSPtr<WriteValue>();
		writeValue->nodeId()->copyFrom(nodeId);
		writeValue->attributeId(writeContext.attributeId_);
		writeValue->dataValue().copyFrom(dataValue);
		req->writeValueArray()->resize(1);
		req->writeValueArray()->set(writeValue);

		attributeService_->asyncSend(trx);
	}


	// ------------------------------------------------------------------------
	// history read
	// ------------------------------------------------------------------------
	void
	VBIClient::attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
	}
	// FIXME: todo

	// ------------------------------------------------------------------------
	// history update
	// ------------------------------------------------------------------------
	void
	VBIClient::attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
	}
	// FIXME: todo

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SubscriptionService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	void
	VBIClient::subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId)
	{
	    if (subscriptionChangeCallback_.exist()) {
	    	subscriptionChangeCallback_(subscriptionState, subscriptionId);
	    }
	}


	void
	VBIClient::dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem)
	{
		if (dataChangeCallback_.exist()) {
			dataChangeCallback_(monitoredItem->clientHandle(), monitoredItem->dataValue());
		}
	}


	void
	VBIClient::setSubscriptionChangeCallback(Callback& callback)
	{
		subscriptionChangeCallback_ = callback;
	}

	void
	VBIClient::setDataChangeCallback(Callback& callback)
	{
		dataChangeCallback_ = callback;
	}

    // ------------------------------------------------------------------------
    // CreateSubscription
    // ------------------------------------------------------------------------
	void
	VBIClient::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
    	VBITransactionCreateSubscription::SPtr trx = boost::static_pointer_cast<VBITransactionCreateSubscription>(serviceTransactionCreateSubscription);

		if (trx->callback_.exist()) {
			if (trx->statusCode() != Success) {
				trx->callback_(trx->statusCode(), 0);
				return;
			}
			if (trx->responseHeader()->serviceResult() != Success) {
				trx->callback_(trx->responseHeader()->serviceResult(), 0);
				return;
			}

			CreateSubscriptionResponse::SPtr res = trx->response();
			trx->callback_(Success, res->subscriptionId());
		}
	}

	CreateSubscriptionContext&
	VBIClient::defaultCreateSubscriptionContext(void)
	{
		return defaultCreateSubscriptionContext_;
	}

	OpcUaStatusCode
	VBIClient::syncCreateSubscription(uint32_t& subscriptionId)
	{
		return syncCreateSubscription(subscriptionId, defaultCreateSubscriptionContext_);
	}

	OpcUaStatusCode
	VBIClient::syncCreateSubscription(uint32_t& subscriptionId, CreateSubscriptionContext& createSubscriptionContext)
	{
		if (subscriptionService_.get() == nullptr) {
			// create subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionServiceIf_ = this;
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		VBITransactionCreateSubscription::SPtr trx = constructSPtr<VBITransactionCreateSubscription>();
		trx->callback_.reset();
		CreateSubscriptionRequest::SPtr req = trx->request();
		req->requestedPublishingInterval(createSubscriptionContext.requestedPublishingInterval_);
		req->requestedLifetimeCount(createSubscriptionContext.requestedLifetimeCount_);
		req->requestedMaxKeepAliveCount(createSubscriptionContext.requestedMaxKeepAliveCount_);
		req->maxNotificationsPerPublish(createSubscriptionContext.maxNotificationsPerPublish_);
		req->publishingEnabled(createSubscriptionContext.publishingEnabled_);
		req->priority(createSubscriptionContext.priority_);

		ServiceTransactionCreateSubscription::SPtr t = trx;
		subscriptionService_->syncSend(t);
		if (trx->statusCode() != Success) return trx->statusCode();
		if (trx->responseHeader()->serviceResult() != Success) return trx->responseHeader()->serviceResult();
		CreateSubscriptionResponse::SPtr res = trx->response();
		subscriptionId = res->subscriptionId();
		return Success;
	}

	void
	VBIClient::asyncCreateSubscription(Callback& callback)
	{
		asyncCreateSubscription(callback, defaultCreateSubscriptionContext_);
	}

	void
	VBIClient::asyncCreateSubscription(Callback& callback, CreateSubscriptionContext& createSubscriptionContext)
	{
		if (subscriptionService_.get() == nullptr) {
			// create subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionServiceIf_ = this;
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		VBITransactionCreateSubscription::SPtr trx = constructSPtr<VBITransactionCreateSubscription>();
		trx->callback_ = callback;
		CreateSubscriptionRequest::SPtr req = trx->request();
		req->requestedPublishingInterval(createSubscriptionContext.requestedPublishingInterval_);
		req->requestedLifetimeCount(createSubscriptionContext.requestedLifetimeCount_);
		req->requestedMaxKeepAliveCount(createSubscriptionContext.requestedMaxKeepAliveCount_);
		req->maxNotificationsPerPublish(createSubscriptionContext.maxNotificationsPerPublish_);
		req->publishingEnabled(createSubscriptionContext.publishingEnabled_);
		req->priority(createSubscriptionContext.priority_);

		ServiceTransactionCreateSubscription::SPtr t = trx;
		subscriptionService_->asyncSend(t);
	}

	// ------------------------------------------------------------------------
	// ModifySubscription
	// ------------------------------------------------------------------------
	void
	VBIClient::subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
	{
	}
	// FIXME: todo

	// ------------------------------------------------------------------------
	// TransferSubscription
	// ------------------------------------------------------------------------
	void
	VBIClient::subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
	{
	}
	// FIXME: todo

	// ------------------------------------------------------------------------
	// DeleteSubscription
	// ------------------------------------------------------------------------
	void
	VBIClient::subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
	{
    	VBITransactionDeleteSubscription::SPtr trx = boost::static_pointer_cast<VBITransactionDeleteSubscription>(serviceTransactionDeleteSubscriptions);

		if (trx->callback_.exist()) {
			if (trx->statusCode() != Success) {
				trx->callback_(trx->statusCode(), 0);
				return;
			}
			if (trx->responseHeader()->serviceResult() != Success) {
				trx->callback_(trx->responseHeader()->serviceResult(), 0);
				return;
			}

			uint32_t subscriptionId;
			DeleteSubscriptionsRequest::SPtr req = trx->request();
			req->subscriptionIds()->get(0, subscriptionId);


			DeleteSubscriptionsResponse::SPtr res = trx->response();
			if (res->results()->size() != 1) {
				trx->callback_(BadUnexpectedError, subscriptionId);
				return;
			}
			OpcUaStatusCode statusCode;
			res->results()->get(0, statusCode);

			trx->callback_(statusCode, subscriptionId);
		}
	}

	DeleteSubscriptionContext&
	VBIClient::defaultDeleteSubscriptionContext(void)
	{
		return defaultDeleteSubscriptionContext_;
	}

	OpcUaStatusCode
	VBIClient::syncDeleteSubscription(uint32_t subscriptionId)
	{
		return syncDeleteSubscription(subscriptionId, defaultDeleteSubscriptionContext_);
	}

	OpcUaStatusCode
	VBIClient::syncDeleteSubscription(uint32_t subscriptionId, DeleteSubscriptionContext& deleteSubscriptionContext)
	{
		if (subscriptionService_.get() == nullptr) {
			// delete subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionServiceIf_ = this;
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		VBITransactionDeleteSubscription::SPtr trx = constructSPtr<VBITransactionDeleteSubscription>();
		trx->callback_.reset();
		DeleteSubscriptionsRequest::SPtr req = trx->request();
		req->subscriptionIds()->resize(1);
		req->subscriptionIds()->set(0, subscriptionId);

		ServiceTransactionDeleteSubscriptions::SPtr t = trx;
		subscriptionService_->syncSend(t);
		if (trx->statusCode() != Success) return trx->statusCode();
		if (trx->responseHeader()->serviceResult() != Success) return trx->responseHeader()->serviceResult();
		return Success;
	}

	void
	VBIClient::asyncDeleteSubscription(uint32_t subscriptionId, Callback& callback)
	{
		asyncDeleteSubscription(subscriptionId, callback, defaultDeleteSubscriptionContext_);
	}

	void
	VBIClient::asyncDeleteSubscription(uint32_t subscriptionId, Callback& callback, DeleteSubscriptionContext& deleteSubscriptionContext)
	{
		if (subscriptionService_.get() == nullptr) {
			// create subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionServiceIf_ = this;
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		VBITransactionDeleteSubscription::SPtr trx = constructSPtr<VBITransactionDeleteSubscription>();
		trx->callback_ = callback;
		DeleteSubscriptionsRequest::SPtr req = trx->request();
		req->subscriptionIds()->resize(1);
		req->subscriptionIds()->set(0, subscriptionId);

		ServiceTransactionDeleteSubscriptions::SPtr t = trx;
		subscriptionService_->asyncSend(t);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// monitoredItemService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// CreateMonitoredItem
	// ------------------------------------------------------------------------
	void
	VBIClient::monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
	{
	   	VBITransactionCreateMonitoredItem::SPtr trx = boost::static_pointer_cast<VBITransactionCreateMonitoredItem>(serviceTransactionCreateMonitoredItems);

		if (trx->callback_.exist()) {
			OpcUaNodeId nodeId;
			CreateMonitoredItemsRequest::SPtr req = trx->request();
			MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
			req->itemsToCreate()->get(0, monitoredItemCreateRequest);
			monitoredItemCreateRequest->itemToMonitor().nodeId()->copyTo(nodeId);

			if (trx->statusCode() != Success) {
				trx->callback_(trx->statusCode(), nodeId, 0);
				return;
			}
			if (trx->responseHeader()->serviceResult() != Success) {
				trx->callback_(trx->responseHeader()->serviceResult(), nodeId, 0);
				return;
			}

			CreateMonitoredItemsResponse::SPtr res = trx->response();
			if (res->results()->size() != 1) {
				trx->callback_(BadUnexpectedError, nodeId, 0);
				return;
			}

			MonitoredItemCreateResult::SPtr monitoredItemCreateResult;
			res->results()->get(0, monitoredItemCreateResult);
			trx->callback_(Success, nodeId, monitoredItemCreateResult->monitoredItemId());
		}
	}

	CreateMonitoredItemContext&
	VBIClient::defaultCreateMonitoredItemContext(void)
	{
		return defaultCreateMonitoredItemContext_;
	}

	OpcUaStatusCode
	VBIClient::syncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, uint32_t& monitoredItemId)
	{
		return syncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, monitoredItemId, defaultCreateMonitoredItemContext_);
	}

	OpcUaStatusCode
	VBIClient::syncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, uint32_t& monitoredItemId, CreateMonitoredItemContext& createMonitoredItemContext)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemServiceConfig.monitoredItemServiceIf_ = this;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		VBITransactionCreateMonitoredItem::SPtr trx = constructSPtr<VBITransactionCreateMonitoredItem>();
		trx->callback_.reset();
		CreateMonitoredItemsRequest::SPtr req = trx->request();
		req->subscriptionId(subscriptionId);
		req->itemsToCreate()->resize(1);

		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		monitoredItemCreateRequest = constructSPtr<MonitoredItemCreateRequest>();
		monitoredItemCreateRequest->itemToMonitor().nodeId()->copyFrom(nodeId);
		monitoredItemCreateRequest->itemToMonitor().attributeId(createMonitoredItemContext.attributeId_);
		monitoredItemCreateRequest->requestedParameters().clientHandle(clientHandle);
		monitoredItemCreateRequest->requestedParameters().samplingInterval(createMonitoredItemContext.samplingInterval_);
		monitoredItemCreateRequest->requestedParameters().filter(createMonitoredItemContext.filter_);
		monitoredItemCreateRequest->requestedParameters().queueSize(createMonitoredItemContext.queueSize_);
		monitoredItemCreateRequest->requestedParameters().discardOldest(createMonitoredItemContext.discardOldest_);
		req->itemsToCreate()->set(0, monitoredItemCreateRequest);

		ServiceTransactionCreateMonitoredItems::SPtr t = trx;
		monitoredItemService_->syncSend(t);
		if (trx->statusCode() != Success) return trx->statusCode();
		if (trx->responseHeader()->serviceResult() != Success) return trx->responseHeader()->serviceResult();
		CreateMonitoredItemsResponse::SPtr res = trx->response();
		if (res->results()->size() != 1) return BadUnexpectedError;

		MonitoredItemCreateResult::SPtr monitoredItemCreateResult;
		res->results()->get(0, monitoredItemCreateResult);
		monitoredItemId = monitoredItemCreateResult->monitoredItemId();
		return Success;
	}

	void
	VBIClient::asyncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, Callback& callback)
	{
		asyncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, callback, defaultCreateMonitoredItemContext_);
	}

	void
	VBIClient::asyncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, Callback& callback, CreateMonitoredItemContext& createMonitoredItemContext)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemServiceConfig.monitoredItemServiceIf_ = this;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		VBITransactionCreateMonitoredItem::SPtr trx = constructSPtr<VBITransactionCreateMonitoredItem>();
		trx->callback_ = callback;
		CreateMonitoredItemsRequest::SPtr req = trx->request();
		req->subscriptionId(subscriptionId);
		req->itemsToCreate()->resize(1);

		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		monitoredItemCreateRequest = constructSPtr<MonitoredItemCreateRequest>();
		monitoredItemCreateRequest->itemToMonitor().nodeId()->copyFrom(nodeId);
		monitoredItemCreateRequest->itemToMonitor().attributeId(createMonitoredItemContext.attributeId_);
		monitoredItemCreateRequest->requestedParameters().clientHandle(clientHandle);
		monitoredItemCreateRequest->requestedParameters().samplingInterval(createMonitoredItemContext.samplingInterval_);
		monitoredItemCreateRequest->requestedParameters().filter(createMonitoredItemContext.filter_);
		monitoredItemCreateRequest->requestedParameters().queueSize(createMonitoredItemContext.queueSize_);
		monitoredItemCreateRequest->requestedParameters().discardOldest(createMonitoredItemContext.discardOldest_);
		req->itemsToCreate()->set(0, monitoredItemCreateRequest);

		ServiceTransactionCreateMonitoredItems::SPtr t = trx;
		monitoredItemService_->asyncSend(t);
	}

	// ------------------------------------------------------------------------
	// DeleteMonitoredItem
	// ------------------------------------------------------------------------
    void
    VBIClient::monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
    {
	   	VBITransactionDeleteMonitoredItem::SPtr trx = boost::static_pointer_cast<VBITransactionDeleteMonitoredItem>(serviceTransactionDeleteMonitoredItems);

		if (trx->callback_.exist()) {
			uint32_t subscriptionId;
			uint32_t monitoredItemId;
			DeleteMonitoredItemsRequest::SPtr req = trx->request();
			subscriptionId = req->subscriptionId();
			req->monitoredItemIds()->get(0, monitoredItemId);

			if (trx->statusCode() != Success) {
				trx->callback_(trx->statusCode(), subscriptionId, monitoredItemId);
				return;
			}
			if (trx->responseHeader()->serviceResult() != Success) {
				trx->callback_(trx->responseHeader()->serviceResult(), subscriptionId, monitoredItemId);
				return;
			}

			DeleteMonitoredItemsResponse::SPtr res = trx->response();
			if (res->results()->size() != 1) {
				trx->callback_(BadUnexpectedError, subscriptionId, monitoredItemId);
				return;
			}

			OpcUaStatusCode statusCode;
			res->results()->get(0, statusCode);
			trx->callback_(statusCode, subscriptionId, monitoredItemId);
		}
    }

	DeleteMonitoredItemContext&
	VBIClient::defaultDeleteMonitoredItemContext(void)
	{
		return defaultDeleteMonitoredItemContext_;
	}
	OpcUaStatusCode
	VBIClient::syncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId)
	{
		return syncDeleteMonitoredItem(subscriptionId, monitoredItemId, defaultDeleteMonitoredItemContext_);
	}

	OpcUaStatusCode
	VBIClient::syncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, DeleteMonitoredItemContext& deleteMonitoredItemContext)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemServiceConfig.monitoredItemServiceIf_ = this;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		VBITransactionDeleteMonitoredItem::SPtr trx = constructSPtr<VBITransactionDeleteMonitoredItem>();
		trx->callback_.reset();
		DeleteMonitoredItemsRequest::SPtr req = trx->request();
		req->subscriptionId(subscriptionId);
		req->monitoredItemIds()->resize(1);
		req->monitoredItemIds()->set(0, monitoredItemId);

		ServiceTransactionDeleteMonitoredItems::SPtr t = trx;
		monitoredItemService_->syncSend(t);
		if (trx->statusCode() != Success) return trx->statusCode();
		if (trx->responseHeader()->serviceResult() != Success) return trx->responseHeader()->serviceResult();
		DeleteMonitoredItemsResponse::SPtr res = trx->response();
		if (res->results()->size() != 1) return BadUnexpectedError;

		OpcUaStatusCode statusCode;
		res->results()->get(0, statusCode);
		return statusCode;
	}

	void
	VBIClient::asyncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, Callback& callback)
	{
		asyncDeleteMonitoredItem(subscriptionId, monitoredItemId, callback, defaultDeleteMonitoredItemContext_);
	}

	void
	VBIClient::asyncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, Callback& callback, DeleteMonitoredItemContext& deleteMonitoredItemContext)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemServiceConfig.monitoredItemServiceIf_ = this;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		VBITransactionDeleteMonitoredItem::SPtr trx = constructSPtr<VBITransactionDeleteMonitoredItem>();
		trx->callback_ = callback;
		DeleteMonitoredItemsRequest::SPtr req = trx->request();
		req->subscriptionId(subscriptionId);
		req->monitoredItemIds()->resize(1);
		req->monitoredItemIds()->set(0, monitoredItemId);

		ServiceTransactionDeleteMonitoredItems::SPtr t = trx;
		monitoredItemService_->asyncSend(t);
	}

	// ------------------------------------------------------------------------
	// ModifyMonitoredItem
	// ------------------------------------------------------------------------
    void
    VBIClient::monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
    {
    	// FIXME: todo
    }

	// ------------------------------------------------------------------------
	// SetMonitoringMode
	// ------------------------------------------------------------------------
    void
    VBIClient::monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
    {
    	// FIXME: todo
    }

	// ------------------------------------------------------------------------
	// SetTriggering
	// ------------------------------------------------------------------------
    void
    VBIClient::monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
    {
    	// FIXME: todo
    }

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ViewServiceBrowse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// viewServiceBrowseDone
	// ------------------------------------------------------------------------
	OpcUaStatusCode VBIClient::syncViewServiceBrowse(OpcUaNodeId::SPtr& nodeId,
			ReferenceDescriptionArray::SPtr& references)
	{
		if (viewService_ == nullptr)
		{
			// create view service
			viewService_ = serviceSetManager_.viewService(sessionService_);
		}

		ServiceTransactionBrowse::SPtr trx = constructSPtr<ServiceTransactionBrowse>();
		BrowseRequest::SPtr req = trx->request();
		req->nodesToBrowse()->resize(1);

		BrowseDescription::SPtr browseDescription = constructSPtr<BrowseDescription>();
		browseDescription->nodeId(nodeId);
		browseDescription->browseDirection(BrowseDirection_Forward);
		browseDescription->nodeClassMask(0xFFFFFFFF);
		browseDescription->resultMask(0xFFFFFFFF);
		req->nodesToBrowse()->push_back(browseDescription);

		viewService_->syncSend(trx);

		BrowseResponse::SPtr res = trx->response();
		BrowseResultArray::SPtr results = res->results();

		if (results->size() > 0)
		{
			BrowseResult::SPtr browseResult;
			results->get(browseResult);
			references = browseResult->references();
			return browseResult->statusCode();
		}

		return BadUnexpectedError;
	}
}
