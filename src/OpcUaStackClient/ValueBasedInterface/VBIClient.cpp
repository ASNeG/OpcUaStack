/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBITransaction.h"
#include "OpcUaStackClient/ValueBasedInterface/HistoryRead.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

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

	, dataChangeHandler_()
	, subscriptionChangeHandler_()
	, sessionChangeHandler_()

	, defaultReadContext_()
	, defaultWriteContext_()
	, defaultHistoryReadContext_()
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
	VBIClient::setSessionChangeHandler(SessionChangeHandler sessionChangeHandler)
	{
		sessionChangeHandler_ = sessionChangeHandler;
	}

	//
	// connect
	//
	OpcUaStatusCode
	VBIClient::syncConnect(ConnectContext& connectContext)
	{
		sessionService_.reset();

		auto sessionServiceChangeHandler = [this](SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionChangeHandler_) {
				sessionChangeHandler_(session, sessionState);
				return;
			}
		};

		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionServiceChangeHandler;
		sessionServiceConfig.secureChannelClient_->endpointUrl(connectContext.endpointUrl_);
		sessionServiceConfig.secureChannelClient_->applicationUri(connectContext.applicationUri_);
		sessionServiceConfig.secureChannelClient_->securityMode(connectContext.securityMode_);
		sessionServiceConfig.secureChannelClient_->securityPolicy(connectContext.securityPolicy_);
		sessionServiceConfig.secureChannelClient_->cryptoManager(connectContext.cryptoManager_);
		sessionServiceConfig.secureChannelClient_->secureChannelLog(connectContext.secureChannelLog_);
		sessionServiceConfig.session_->sessionName(connectContext.sessionName_);
		sessionServiceConfig.ioThreadName(ioThreadName_);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);
		assert(sessionService_.get() != nullptr);

		if (connectContext.deleteEndpointDescriptionCache_) {
			Log(Debug, "clear endpoint description cache");
			deleteEndpointDescriptionCache();
		}

		// connect to opc ua server
		return sessionService_->syncConnect();
	}

	void
	VBIClient::asyncConnect(ConnectContext& connectContext)
	{
		sessionService_.reset();

		auto sessionServiceChangeHandler = [this](SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionChangeHandler_) {
				sessionChangeHandler_(session, sessionState);
				return;
			}
		};

		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionServiceChangeHandler;
		sessionServiceConfig.secureChannelClient_->endpointUrl(connectContext.endpointUrl_);
		sessionServiceConfig.secureChannelClient_->discoveryUrl(connectContext.discoveryUrl_);
		sessionServiceConfig.secureChannelClient_->applicationUri(connectContext.applicationUri_);
		sessionServiceConfig.secureChannelClient_->securityMode(connectContext.securityMode_);
		sessionServiceConfig.secureChannelClient_->securityPolicy(connectContext.securityPolicy_);
		sessionServiceConfig.secureChannelClient_->cryptoManager(connectContext.cryptoManager_);
		sessionServiceConfig.secureChannelClient_->secureChannelLog(connectContext.secureChannelLog_);
		sessionServiceConfig.session_->sessionName(connectContext.sessionName_);
		sessionServiceConfig.ioThreadName(ioThreadName_);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);
		assert(sessionService_.get() != nullptr);

		if (connectContext.deleteEndpointDescriptionCache_) {
			Log(Debug, "clear endpoint description cache");
			deleteEndpointDescriptionCache();
		}

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

	void
	VBIClient::deleteEndpointDescriptionCache(void)
	{
		sessionService_->getEndpointDescriptionCache().clear();
	}

	EndpointDescriptionCache&
	VBIClient::getEndpointDescriptionCache(void)
	{
		return sessionService_->getEndpointDescriptionCache();
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
    VBIClient::attributeServiceReadResponse(
    	ServiceTransactionRead::SPtr serviceTransactionRead
	)
    {
    	auto trx = boost::static_pointer_cast<VBITransactionRead>(serviceTransactionRead);
    	if (!trx->VBIResultHandler_) {
    		return;
    	}

		OpcUaNodeId nodeId;
		OpcUaDataValue dataValue;

		if (trx->statusCode() != Success) {
			trx->VBIResultHandler_(trx->statusCode(), nodeId, dataValue);
			return;
		}

		auto res = trx->response();
		if (res->dataValueArray()->size() != 1) {
			trx->VBIResultHandler_(BadUnexpectedError, nodeId, dataValue);
			return;
		}
		OpcUaDataValue::SPtr dataValueSPtr;
		res->dataValueArray()->get(0, dataValueSPtr);
		dataValue.copyFrom(*dataValueSPtr);

		auto req = trx->request();
		ReadValueId::SPtr readValueIdSPtr;
		req->readValueIdArray()->get(0, readValueIdSPtr);
		readValueIdSPtr->nodeId()->copyTo(nodeId);

		trx->VBIResultHandler_(Success, nodeId, dataValue);
    }

	ReadContext&
	VBIClient::defaultReadContext(void)
	{
		return defaultReadContext_;
	}

	OpcUaStatusCode
	VBIClient::syncRead(
		OpcUaNodeId& nodeId,
		OpcUaDataValue& dataValue
	)
	{
		return syncRead(nodeId, dataValue, defaultReadContext_);
	}

	OpcUaStatusCode
	VBIClient::syncRead(
		OpcUaNodeId& nodeId,
		OpcUaDataValue& dataValue,
		ReadContext& readContext
	)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send ReadRequest
		auto trx = boost::make_shared<VBITransactionRead>();
		auto req = trx->request();
		auto readValueIdSPtr = boost::make_shared<ReadValueId>();
		readValueIdSPtr->nodeId()->copyFrom(nodeId);
		readValueIdSPtr->attributeId(readContext.attributeId_);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		req->readValueIdArray()->set(readValueIdSPtr);

		attributeService_->syncSend(trx);

		if (trx->statusCode() != Success) return trx->statusCode();
		auto res = trx->response();
		if (res->dataValueArray()->size() != 1) return BadUnexpectedError;
		OpcUaDataValue::SPtr dataValueSPtr;
		res->dataValueArray()->get(0, dataValueSPtr);
		dataValue.copyFrom(*dataValueSPtr);
		return Success;
	}

	void
	VBIClient::asyncRead(
		OpcUaNodeId& nodeId,
		const VBITransactionRead::VBIResultHandler& resultHandler
	)
	{
		asyncRead(nodeId, resultHandler, defaultReadContext_);
	}

	void
	VBIClient::asyncRead(
		OpcUaNodeId& nodeId,
		const VBITransactionRead::VBIResultHandler& resultHandler,
		ReadContext& readContext
	)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send ReadRequest
		auto trx = boost::make_shared<VBITransactionRead>();
		auto req = trx->request();
		auto readValueIdSPtr = boost::make_shared<ReadValueId>();
		trx->VBIResultHandler_ = resultHandler;
		readValueIdSPtr->nodeId()->copyFrom(nodeId);
		readValueIdSPtr->attributeId(readContext.attributeId_);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		req->readValueIdArray()->set(readValueIdSPtr);

		trx->resultHandler(
			[this](ServiceTransactionRead::SPtr& trx) {
				attributeServiceReadResponse(trx);
			}
		);
		attributeService_->asyncSend(trx);
	}


	// ------------------------------------------------------------------------
	// write
	// ------------------------------------------------------------------------
	void
	VBIClient::attributeServiceWriteResponse(
		ServiceTransactionWrite::SPtr serviceTransactionWrite
	)
	{
    	auto trx = boost::static_pointer_cast<VBITransactionWrite>(serviceTransactionWrite);
    	if (!trx->VBIResultHandler_) {
    		return;
    	}

		OpcUaNodeId nodeId;

		if (trx->statusCode() != Success) {
			trx->VBIResultHandler_(trx->statusCode(), nodeId);
			return;
		}
		auto res = trx->response();
		if (res->results()->size() != 1) {
			trx->VBIResultHandler_(BadUnexpectedError, nodeId);
			return;
		}

		OpcUaStatusCode statusCode;
		res->results()->get(0, statusCode);

		auto req = trx->request();
		WriteValue::SPtr writeValue;
		req->writeValueArray()->get(0, writeValue);
		writeValue->nodeId()->copyTo(nodeId);

		trx->VBIResultHandler_(statusCode, nodeId);
	}

	WriteContext&
	VBIClient::defaultWriteContext(void)
	{
		return defaultWriteContext_;
	}

	OpcUaStatusCode
	VBIClient::syncWrite(
		OpcUaNodeId& nodeId,
		OpcUaDataValue& dataValue
	)
	{
		return syncWrite(nodeId, dataValue, defaultWriteContext_);
	}

	OpcUaStatusCode
	VBIClient::syncWrite(
		OpcUaNodeId& nodeId,
		OpcUaDataValue& dataValue,
		WriteContext& writeContext
	)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send WriteRequest
		auto trx = boost::make_shared<VBITransactionWrite>();
		auto req = trx->request();

		auto writeValue = boost::make_shared<WriteValue>();
		writeValue->nodeId()->copyFrom(nodeId);
		writeValue->attributeId(writeContext.attributeId_);
		writeValue->dataValue().copyFrom(dataValue);
		req->writeValueArray()->resize(1);
		req->writeValueArray()->set(writeValue);

		attributeService_->syncSend(trx);
		if (trx->statusCode() != Success) return trx->statusCode();
		auto res = trx->response();
		if (res->results()->size() != 1) return BadUnexpectedError;

		OpcUaStatusCode statusCode;
		res->results()->get(0, statusCode);
		return statusCode;
	}

	void
	VBIClient::asyncWrite(
		OpcUaNodeId& nodeId,
		OpcUaDataValue& dataValue,
		const VBITransactionWrite::VBIResultHandler& resultHandler
	)
	{
		asyncWrite(nodeId, dataValue, resultHandler, defaultWriteContext_);
	}

	void
	VBIClient::asyncWrite(
		OpcUaNodeId& nodeId,
		OpcUaDataValue& dataValue,
		const VBITransactionWrite::VBIResultHandler& resultHandler,
		WriteContext& writeContext
	)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		// create and send WriteRequest
		auto trx = boost::make_shared<VBITransactionWrite>();
		trx->VBIResultHandler_ = resultHandler;
		auto req = trx->request();

		auto writeValue = boost::make_shared<WriteValue>();
		writeValue->nodeId()->copyFrom(nodeId);
		writeValue->attributeId(writeContext.attributeId_);
		writeValue->dataValue().copyFrom(dataValue);
		req->writeValueArray()->resize(1);
		req->writeValueArray()->set(writeValue);

		trx->resultHandler(
			[this](ServiceTransactionWrite::SPtr& trx) {
				attributeServiceWriteResponse(trx);
			}
		);
		attributeService_->asyncSend(trx);
	}


	// ------------------------------------------------------------------------
	// history read
	// ------------------------------------------------------------------------
	void
	VBIClient::attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
	}

	HistoryReadContext&
	VBIClient::defaultHistoryReadContext(void)
	{
		return defaultHistoryReadContext_;
	}

	OpcUaStatusCode
	VBIClient::syncHistoryRead(
		const OpcUaNodeId& nodeId,
		boost::posix_time::ptime startTime,
		boost::posix_time::ptime endTime,
		std::vector<OpcUaDataValue::SPtr>& dataValueVec
	)
	{
		return syncHistoryRead(nodeId, startTime, endTime, defaultHistoryReadContext_, dataValueVec);
	}

	OpcUaStatusCode
	VBIClient::syncHistoryRead(
		const OpcUaNodeId& nodeId,
		boost::posix_time::ptime startTime,
		boost::posix_time::ptime endTime,
		HistoryReadContext& historyReadContext,
		std::vector<OpcUaDataValue::SPtr>& dataValueVec
	)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		HistoryRead historyRead;
		historyRead.attributeService(attributeService_);
		historyRead.maxNumResultValuesPerRequest(historyReadContext.maxNumResultValuesPerRequest_);
		historyRead.maxNumResultValuesPerNode(historyReadContext.maxNumResultValuesPerNode_);

		return historyRead.syncHistoryRead(
			nodeId,
			startTime,
			endTime,
			dataValueVec
		);
	}

	void
	VBIClient::asyncHistoryRead(
		const OpcUaNodeId& nodeId,
		boost::posix_time::ptime startTime,
		boost::posix_time::ptime endTime,
		const VBITransactionHistoryRead::VBIResultHandler& resultHandler
	)
	{
		return asyncHistoryRead(nodeId, startTime, endTime, resultHandler, defaultHistoryReadContext_);
	}

	void
	VBIClient::asyncHistoryRead(
		const OpcUaNodeId& nodeId,
		boost::posix_time::ptime startTime,
		boost::posix_time::ptime endTime,
		const VBITransactionHistoryRead::VBIResultHandler& resultHandler,
		HistoryReadContext& historyReadContext
	)
	{
		if (attributeService_.get() == nullptr) {
			// create attribute service
			AttributeServiceConfig attributeServiceConfig;
			attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
			assert(attributeService_.get() != nullptr);
		}

		auto historyRead = boost::make_shared<HistoryRead>();
		historyRead->attributeService(attributeService_);
		historyRead->maxNumResultValuesPerRequest(historyReadContext.maxNumResultValuesPerRequest_);
		historyRead->maxNumResultValuesPerNode(historyReadContext.maxNumResultValuesPerNode_);

		historyRead->asyncHistoryRead(
			nodeId,
			startTime,
			endTime,
			[this, resultHandler](OpcUaStatusCode statusCode, std::vector<OpcUaDataValue::SPtr>& dataValueVec) {
				resultHandler(statusCode, dataValueVec);
			}
		);
	}

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
	    if (subscriptionChangeHandler_) {
	    	subscriptionChangeHandler_(subscriptionState, subscriptionId);
	    }
	}


	void
	VBIClient::dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem)
	{
		if (dataChangeHandler_) {
			dataChangeHandler_(monitoredItem->clientHandle(), monitoredItem->value());
		}
	}


	void
	VBIClient::setSubscriptionChangeHandler(const SubscriptionChangeHandler& subscriptionChangeHandler)
	{
		subscriptionChangeHandler_ = subscriptionChangeHandler;
	}

	void
	VBIClient::setDataChangeHandler(const DataChangeHandler& dataChangeHandler)
	{
		dataChangeHandler_ = dataChangeHandler;
	}

    // ------------------------------------------------------------------------
    // CreateSubscription
    // ------------------------------------------------------------------------
	void
	VBIClient::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
    	auto trx = boost::static_pointer_cast<VBITransactionCreateSubscription>(serviceTransactionCreateSubscription);
    	if (!trx->VBIResultHandler_) {
    		return;
    	}

    	if (trx->statusCode() != Success) {
    		trx->VBIResultHandler_(trx->statusCode(), 0);
    		return;
    	}
    	if (trx->responseHeader()->serviceResult() != Success) {
    		trx->VBIResultHandler_(trx->responseHeader()->serviceResult(), 0);
    		return;
    	}

    	CreateSubscriptionResponse::SPtr res = trx->response();
    	trx->VBIResultHandler_(Success, res->subscriptionId());


	}

	CreateSubscriptionContext&
	VBIClient::defaultCreateSubscriptionContext(void)
	{
		return defaultCreateSubscriptionContext_;
	}

	OpcUaStatusCode
	VBIClient::syncCreateSubscription(
		uint32_t& subscriptionId
	)
	{
		return syncCreateSubscription(subscriptionId, defaultCreateSubscriptionContext_);
	}

	OpcUaStatusCode
	VBIClient::syncCreateSubscription(
		uint32_t& subscriptionId,
		CreateSubscriptionContext& createSubscriptionContext
	)
	{
		if (subscriptionService_.get() == nullptr) {
			// create subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
				[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
					subscriptionStateUpdate(subscriptionState, subscriptionId);
				};
			subscriptionServiceConfig.dataChangeNotificationHandler_ =
				[this](const MonitoredItemNotification::SPtr& monitoredItem) {
					dataChangeNotification(monitoredItem);
				};
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionCreateSubscription>();
		auto req = trx->request();
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
		auto res = trx->response();
		subscriptionId = res->subscriptionId();
		return Success;
	}

	void
	VBIClient::asyncCreateSubscription(
		const VBITransactionCreateSubscription::VBIResultHandler& resultHandler
	)
	{
		asyncCreateSubscription(resultHandler, defaultCreateSubscriptionContext_);
	}

	void
	VBIClient::asyncCreateSubscription(
		const VBITransactionCreateSubscription::VBIResultHandler& resultHandler,
		CreateSubscriptionContext& createSubscriptionContext
	)
	{
		if (subscriptionService_.get() == nullptr) {
			// create subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
				[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
					subscriptionStateUpdate(subscriptionState, subscriptionId);
				};
			subscriptionServiceConfig.dataChangeNotificationHandler_ =
				[this](const MonitoredItemNotification::SPtr& monitoredItem) {
					dataChangeNotification(monitoredItem);
				};
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionCreateSubscription>();
		trx->VBIResultHandler_ = resultHandler;
		auto req = trx->request();
		req->requestedPublishingInterval(createSubscriptionContext.requestedPublishingInterval_);
		req->requestedLifetimeCount(createSubscriptionContext.requestedLifetimeCount_);
		req->requestedMaxKeepAliveCount(createSubscriptionContext.requestedMaxKeepAliveCount_);
		req->maxNotificationsPerPublish(createSubscriptionContext.maxNotificationsPerPublish_);
		req->publishingEnabled(createSubscriptionContext.publishingEnabled_);
		req->priority(createSubscriptionContext.priority_);

		trx->resultHandler(
			[this](ServiceTransactionCreateSubscription::SPtr& trx) {
			subscriptionServiceCreateSubscriptionResponse(trx);
			}
		);
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
    	auto trx = boost::static_pointer_cast<VBITransactionDeleteSubscription>(serviceTransactionDeleteSubscriptions);
    	if (!trx->VBIResultHandler_) {
    		return;
    	}

		if (trx->statusCode() != Success) {
			trx->VBIResultHandler_(trx->statusCode(), 0);
			return;
		}
		if (trx->responseHeader()->serviceResult() != Success) {
			trx->VBIResultHandler_(trx->responseHeader()->serviceResult(), 0);
			return;
		}

		uint32_t subscriptionId;
		auto req = trx->request();
		req->subscriptionIds()->get(0, subscriptionId);


		auto res = trx->response();
		if (res->results()->size() != 1) {
			trx->VBIResultHandler_(BadUnexpectedError, subscriptionId);
			return;
		}
		OpcUaStatusCode statusCode;
		res->results()->get(0, statusCode);

		trx->VBIResultHandler_(statusCode, subscriptionId);
	}

	DeleteSubscriptionContext&
	VBIClient::defaultDeleteSubscriptionContext(void)
	{
		return defaultDeleteSubscriptionContext_;
	}

	OpcUaStatusCode
	VBIClient::syncDeleteSubscription(
		uint32_t subscriptionId
	)
	{
		return syncDeleteSubscription(subscriptionId, defaultDeleteSubscriptionContext_);
	}

	OpcUaStatusCode
	VBIClient::syncDeleteSubscription(
		uint32_t subscriptionId,
		DeleteSubscriptionContext& deleteSubscriptionContext
	)
	{
		if (subscriptionService_.get() == nullptr) {
			// delete subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
				[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
					subscriptionStateUpdate(subscriptionState, subscriptionId);
				};
			subscriptionServiceConfig.dataChangeNotificationHandler_ =
				[this](const MonitoredItemNotification::SPtr& monitoredItem) {
					dataChangeNotification(monitoredItem);
				};
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionDeleteSubscription>();
		auto req = trx->request();
		req->subscriptionIds()->resize(1);
		req->subscriptionIds()->set(0, subscriptionId);

		ServiceTransactionDeleteSubscriptions::SPtr t = trx;
		subscriptionService_->syncSend(t);
		if (trx->statusCode() != Success) return trx->statusCode();
		if (trx->responseHeader()->serviceResult() != Success) return trx->responseHeader()->serviceResult();
		return Success;
	}

	void
	VBIClient::asyncDeleteSubscription(
		uint32_t subscriptionId,
		const VBITransactionDeleteSubscription::VBIResultHandler& resultHandler
	)
	{
		asyncDeleteSubscription(subscriptionId, resultHandler, defaultDeleteSubscriptionContext_);
	}

	void
	VBIClient::asyncDeleteSubscription(
		uint32_t subscriptionId,
		const VBITransactionDeleteSubscription::VBIResultHandler& resultHandler,
		DeleteSubscriptionContext& deleteSubscriptionContext)
	{
		if (subscriptionService_.get() == nullptr) {
			// create subscription service
			SubscriptionServiceConfig subscriptionServiceConfig;
			subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
				[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
					subscriptionStateUpdate(subscriptionState, subscriptionId);
				};
			subscriptionServiceConfig.dataChangeNotificationHandler_ =
				[this](const MonitoredItemNotification::SPtr& monitoredItem) {
					dataChangeNotification(monitoredItem);
				};
			subscriptionService_ = serviceSetManager_.subscriptionService(sessionService_, subscriptionServiceConfig);
			assert(subscriptionService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionDeleteSubscription>();
		trx->VBIResultHandler_ = resultHandler;
		auto req = trx->request();
		req->subscriptionIds()->resize(1);
		req->subscriptionIds()->set(0, subscriptionId);

		trx->resultHandler(
			[this](ServiceTransactionDeleteSubscriptions::SPtr& trx) {
				subscriptionServiceDeleteSubscriptionsResponse(trx);
			}
		);
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
	VBIClient::monitoredItemServiceCreateMonitoredItemsResponse(
		ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems
	)
	{
	   	auto trx = boost::static_pointer_cast<VBITransactionCreateMonitoredItem>(serviceTransactionCreateMonitoredItems);
	   	if (!trx->VBIResultHandler_) {
	   		return;
	   	}

		OpcUaNodeId nodeId;
		auto req = trx->request();
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		req->itemsToCreate()->get(0, monitoredItemCreateRequest);
		monitoredItemCreateRequest->itemToMonitor().nodeId()->copyTo(nodeId);

		if (trx->statusCode() != Success) {
			trx->VBIResultHandler_(trx->statusCode(), nodeId, 0);
			return;
		}
		if (trx->responseHeader()->serviceResult() != Success) {
			trx->VBIResultHandler_(trx->responseHeader()->serviceResult(), nodeId, 0);
			return;
		}

		auto res = trx->response();
		if (res->results()->size() != 1) {
			trx->VBIResultHandler_(BadUnexpectedError, nodeId, 0);
			return;
		}

		MonitoredItemCreateResult::SPtr monitoredItemCreateResult;
		res->results()->get(0, monitoredItemCreateResult);
		trx->VBIResultHandler_(Success, nodeId, monitoredItemCreateResult->monitoredItemId());
	}

	CreateMonitoredItemContext&
	VBIClient::defaultCreateMonitoredItemContext(void)
	{
		return defaultCreateMonitoredItemContext_;
	}

	OpcUaStatusCode
	VBIClient::syncCreateMonitoredItem(
		OpcUaNodeId& nodeId,
		uint32_t subscriptionId,
		uint32_t clientHandle,
		uint32_t& monitoredItemId
	)
	{
		return syncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, monitoredItemId, defaultCreateMonitoredItemContext_);
	}

	OpcUaStatusCode
	VBIClient::syncCreateMonitoredItem(
		OpcUaNodeId& nodeId,
		uint32_t subscriptionId,
		uint32_t clientHandle,
		uint32_t& monitoredItemId,
		CreateMonitoredItemContext& createMonitoredItemContext
	)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionCreateMonitoredItem>();
		CreateMonitoredItemsRequest::SPtr req = trx->request();
		req->subscriptionId(subscriptionId);
		req->itemsToCreate()->resize(1);

		auto monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();
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
	VBIClient::asyncCreateMonitoredItem(
		OpcUaNodeId& nodeId,
		uint32_t subscriptionId,
		uint32_t clientHandle,
		const VBITransactionCreateMonitoredItem::VBIResultHandler& resultHandler
	)
	{
		asyncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, resultHandler, defaultCreateMonitoredItemContext_);
	}

	void
	VBIClient::asyncCreateMonitoredItem(
		OpcUaNodeId& nodeId,
		uint32_t subscriptionId,
		uint32_t clientHandle,
		const VBITransactionCreateMonitoredItem::VBIResultHandler& resultHandler,
		CreateMonitoredItemContext& createMonitoredItemContext
	)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionCreateMonitoredItem>();
		trx->VBIResultHandler_ = resultHandler;
		CreateMonitoredItemsRequest::SPtr req = trx->request();
		req->subscriptionId(subscriptionId);
		req->itemsToCreate()->resize(1);

		auto monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();
		monitoredItemCreateRequest->itemToMonitor().nodeId()->copyFrom(nodeId);
		monitoredItemCreateRequest->itemToMonitor().attributeId(createMonitoredItemContext.attributeId_);
		monitoredItemCreateRequest->requestedParameters().clientHandle(clientHandle);
		monitoredItemCreateRequest->requestedParameters().samplingInterval(createMonitoredItemContext.samplingInterval_);
		monitoredItemCreateRequest->requestedParameters().filter(createMonitoredItemContext.filter_);
		monitoredItemCreateRequest->requestedParameters().queueSize(createMonitoredItemContext.queueSize_);
		monitoredItemCreateRequest->requestedParameters().discardOldest(createMonitoredItemContext.discardOldest_);
		req->itemsToCreate()->set(0, monitoredItemCreateRequest);

		trx->resultHandler(
			[this](ServiceTransactionCreateMonitoredItems::SPtr& trx) {
				monitoredItemServiceCreateMonitoredItemsResponse(trx);
			}
		);
		ServiceTransactionCreateMonitoredItems::SPtr t = trx;
		monitoredItemService_->asyncSend(t);
	}

	// ------------------------------------------------------------------------
	// DeleteMonitoredItem
	// ------------------------------------------------------------------------
    void
    VBIClient::monitoredItemServiceDeleteMonitoredItemsResponse(
    	ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems
	)
    {
	   	auto trx = boost::static_pointer_cast<VBITransactionDeleteMonitoredItem>(serviceTransactionDeleteMonitoredItems);
	   	if (!trx->VBIResultHandler_) {
	   		return;
	   	}

		uint32_t subscriptionId;
		uint32_t monitoredItemId;
		auto req = trx->request();
		subscriptionId = req->subscriptionId();
		req->monitoredItemIds()->get(0, monitoredItemId);

		if (trx->statusCode() != Success) {
			trx->VBIResultHandler_(trx->statusCode(), subscriptionId, monitoredItemId);
			return;
		}
		if (trx->responseHeader()->serviceResult() != Success) {
			trx->VBIResultHandler_(trx->responseHeader()->serviceResult(), subscriptionId, monitoredItemId);
			return;
		}

		auto res = trx->response();
		if (res->results()->size() != 1) {
			trx->VBIResultHandler_(BadUnexpectedError, subscriptionId, monitoredItemId);
			return;
		}

		OpcUaStatusCode statusCode;
		res->results()->get(0, statusCode);
		trx->VBIResultHandler_(statusCode, subscriptionId, monitoredItemId);
    }

	DeleteMonitoredItemContext&
	VBIClient::defaultDeleteMonitoredItemContext(void)
	{
		return defaultDeleteMonitoredItemContext_;
	}
	OpcUaStatusCode
	VBIClient::syncDeleteMonitoredItem(
		uint32_t subscriptionId,
		uint32_t monitoredItemId
	)
	{
		return syncDeleteMonitoredItem(subscriptionId, monitoredItemId, defaultDeleteMonitoredItemContext_);
	}

	OpcUaStatusCode
	VBIClient::syncDeleteMonitoredItem(
		uint32_t subscriptionId,
		uint32_t monitoredItemId,
		DeleteMonitoredItemContext&
		deleteMonitoredItemContext
	)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionDeleteMonitoredItem>();
		auto req = trx->request();
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
	VBIClient::asyncDeleteMonitoredItem(
		uint32_t subscriptionId,
		uint32_t monitoredItemId,
		const VBITransactionDeleteMonitoredItem::VBIResultHandler& resultHandler
	)
	{
		asyncDeleteMonitoredItem(subscriptionId, monitoredItemId, resultHandler, defaultDeleteMonitoredItemContext_);
	}

	void
	VBIClient::asyncDeleteMonitoredItem(
		uint32_t subscriptionId,
		uint32_t monitoredItemId,
		const VBITransactionDeleteMonitoredItem::VBIResultHandler& resultHandler,
		DeleteMonitoredItemContext& deleteMonitoredItemContext
	)
	{
		if (monitoredItemService_.get() == nullptr) {
			// monitoredItem service
			MonitoredItemServiceConfig monitoredItemServiceConfig;
			monitoredItemService_ = serviceSetManager_.monitoredItemService(sessionService_, monitoredItemServiceConfig);
			assert(monitoredItemService_.get() != nullptr);
		}

		auto trx = boost::make_shared<VBITransactionDeleteMonitoredItem>();
		trx->VBIResultHandler_ = resultHandler;
		auto req = trx->request();
		req->subscriptionId(subscriptionId);
		req->monitoredItemIds()->resize(1);
		req->monitoredItemIds()->set(0, monitoredItemId);

		trx->resultHandler(
			[this](ServiceTransactionDeleteMonitoredItems::SPtr& trx) {
				monitoredItemServiceDeleteMonitoredItemsResponse(trx);
			}
		);
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

		ServiceTransactionBrowse::SPtr trx = boost::make_shared<ServiceTransactionBrowse>();
		BrowseRequest::SPtr req = trx->request();
		req->nodesToBrowse()->resize(1);

		BrowseDescription::SPtr browseDescription = boost::make_shared<BrowseDescription>();
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
