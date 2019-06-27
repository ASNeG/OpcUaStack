/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ApplicationUtility/ClientConnection.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ClientConnection::ClientConnection(void)
	: serverUri_("opc.tcp://127.0.0.1:4841")
	, serverUrn_("")
	, discoveryIf_(nullptr)
	, discoveryFindResponseCallback_(boost::bind(&ClientConnection::findResultCallback, this, _1, _2))
	, reconnectTimeout_(5000)
	, sessionName_("OpcUaStackClient-Default")
	, lastDiscoveryTime_()

	, init_(false)
	, state_(S_Disconnected)
	, namespaceElementVec_()

	, ioThread_()
	, slotTimerElement_()
	, serviceSetManager_()
	, sessionService_()
	, attributeService_()

	, namespaceMap_()
	, clientSubscriptionMap_()
	{
		lastDiscoveryTime_ = boost::posix_time::microsec_clock::universal_time() - boost::posix_time::millisec(reconnectTimeout_);
	}

	ClientConnection::~ClientConnection(void)
	{
		serviceSetManager_.deregisterIOThread("GlobalIOThread");
	}

	void
	ClientConnection::serverUri(const std::string& serverUri)
	{
		serverUri_ = serverUri;
	}

	std::string
	ClientConnection::serverUri(void)
	{
		return serverUri_;
	}

	void
	ClientConnection::discoveryIf(DiscoveryClientFindServersIf* discoveryIf, const std::string& serverUrn)
	{
		discoveryIf_ = discoveryIf;
		serverUrn_ = serverUrn;
	}

	void
	ClientConnection::reconnectTimeout(uint32_t reconnectTimeout)
	{
		reconnectTimeout_ = reconnectTimeout;
	}

	uint32_t
	ClientConnection::reconnectTimeout(void)
	{
		return reconnectTimeout_;
	}

	void
	ClientConnection::sessionName(const std::string& sessionName)
	{
		sessionName_ = sessionName;
	}

	std::string
	ClientConnection::sessionName(void)
	{
		return sessionName_;
	}

	bool
	ClientConnection::addClientSubscription(const std::string& id, ClientSubscription::SPtr& clientSubscription)
	{
		init();

		ClientSubscription::Map::iterator it;
		it = clientSubscriptionMap_.find(id);
		if (it != clientSubscriptionMap_.end()) {
			Log(Error, "client subscription already exist in connection")
				.parameter("ServerUri", serverUri_)
				.parameter("SubscriptionId", id);
			return false;
		}

		clientSubscription->serviceSetManager(&serviceSetManager_);
		clientSubscription->sessionService(sessionService_);
		clientSubscriptionMap_.insert(std::make_pair(id, clientSubscription));

		return true;
	}

	void
	ClientConnection::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	IOThread::SPtr&
	ClientConnection::ioThread(void)
	{
		return ioThread_;
	}

	void
	ClientConnection::state(State state)
	{
		state_ = state;
	}

	ClientConnection::State
	ClientConnection::state(void)
	{
		return state_;
	}

	void
	ClientConnection::namespaceElementVec(NamespaceElement::Vec& namespaceElementVec)
	{
		namespaceElementVec_ = namespaceElementVec;
	}

	NamespaceElement::Vec&
	ClientConnection::namespaceElementVec(void)
	{
		return namespaceElementVec_;
	}

	void
	ClientConnection::init(void)
	{
		if (init_) return;
		init_ = true;

		// init service sets
		serviceSetManager_.registerIOThread("GlobalIOThread", ioThread_);

		// create session service
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName("GlobalIOThread");
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(serverUri_);
		sessionServiceConfig.session_->sessionName(sessionName_);
		sessionServiceConfig.session_->reconnectTimeout(reconnectTimeout_);
		serviceSetManager_.sessionService(sessionServiceConfig);
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);

		// create attribute service
		AttributeServiceConfig attributeServiceConfig;
		attributeServiceConfig.ioThreadName("GlobalIOThread");
		attributeServiceConfig.attributeServiceIf_ = this;
		attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
	}

	void
	ClientConnection::connect(void)
	{
		// create session
		state_ = S_Connecting;
		sessionService_->asyncConnect();
	}

	void
	ClientConnection::disconnect(void)
	{
		asyncDisconnect();
	}

	void
	ClientConnection::asyncDisconnect(void)
	{
		// disconnect session
		handleDisconnect();
		sessionService_->asyncDisconnect(true);
	}

	void
	ClientConnection::syncDisconnect(void)
	{
		// disconnect session
		handleDisconnect();
		sessionService_->syncDisconnect(true);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	ClientConnection::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		switch (sessionState)
		{
			case SS_Connect:
				Log(Debug, "session state changed to connect")
				    .parameter("ServerUri", serverUri_);
				readNamespaceArray();
				break;
			case SS_Disconnect:
				Log(Debug, "session state changed to disconnect/close")
					.parameter("ServerUri", serverUri_);
				handleDisconnect();

				if (discoveryIf_ != nullptr) {
			    	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
			    	if ((lastDiscoveryTime_ + boost::posix_time::millisec(reconnectTimeout_)) < now) {
			    		lastDiscoveryTime_ = boost::posix_time::microsec_clock::universal_time();
			    		discoveryIf_->asyncFind(serverUrn_, discoveryFindResponseCallback_);
			    	}
				}

				break;
			case SS_ServerUriError:
				Log(Debug, "session state changed to disconnect/close, because server uri invalid")
					.parameter("ServerUri", serverUri_);

				if (discoveryIf_ != nullptr) {
					boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
			    	if ((lastDiscoveryTime_ + boost::posix_time::millisec(reconnectTimeout_)) < now) {
			    		lastDiscoveryTime_ = boost::posix_time::microsec_clock::universal_time();
			    		discoveryIf_->asyncFind(serverUrn_, discoveryFindResponseCallback_);
			    	}
				}

				break;
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AttributeServiceIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	ClientConnection::attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		handleNamespaceArray(serviceTransactionRead);
	}

	void
	ClientConnection::attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		// nothing to do
	}

	void
	ClientConnection::attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
		// nothing to do
	}

	void
	ClientConnection::attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
		// nothing to do
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// handle namespace array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	ClientConnection::readNamespaceArray(void)
	{
		state_ = S_Connected;
		ServiceTransactionRead::SPtr readTrx = constructSPtr<ServiceTransactionRead>();
		ReadRequest::SPtr req = readTrx->request();
		req->maxAge(0);
		req->timestampsToReturn(2);

		ReadValueId::SPtr readValueId = constructSPtr<ReadValueId>();
		readValueId->nodeId((OpcUaInt16)0, (OpcUaInt32)2255);
		readValueId->attributeId((OpcUaInt32) 13);
		readValueId->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		req->readValueIdArray()->set(readValueId);

		attributeService_->asyncSend(readTrx);
	}

	void
	ClientConnection::handleNamespaceArray(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		ReadRequest::SPtr req = serviceTransactionRead->request();
		ReadResponse::SPtr res = serviceTransactionRead->response();

		// error handling
		OpcUaStatusCode statusCode = serviceTransactionRead->statusCode();
		if (statusCode != Success) {
			Log(Error, "read namespace array transaction error")
				.parameter("ServerUri", serverUri_)
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			state_ = S_Disconnected;
			return;
		}
		if (res->dataValueArray()->size() != 1) {
			Log(Error, "read namespace array response error, because data array size error")
				.parameter("ServerUri", serverUri_);
			state_ = S_Error;
			return;
		}

		// get data value
		OpcUaDataValue::SPtr dataValue;
		res->dataValueArray()->get(0, dataValue);

		if (dataValue->statusCode() != Success) {
			Log(Error, "read namespace array data value error")
				.parameter("ServerUri", serverUri_)
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			state_ = S_Error;
			return;
		}
		OpcUaVariant::SPtr variant = dataValue->variant();

		// get namespace array
		std::map<std::string, uint32_t> namespaceMap;
		std::map<std::string, uint32_t>::iterator it;
		Log(Debug, "read namespace array from server")
		    .parameter("ServerUri", serverUri_);
		for (int32_t idx=0; idx < variant->arrayLength(); idx++) {
			std::string uri = variant->variant()[idx].variantSPtr<OpcUaString>()->value();
			Log(Debug, "")
				.parameter("Uri", uri)
				.parameter("NamespaceIndex", idx);
			namespaceMap.insert(std::make_pair(uri, idx));
		}

		// check number of internal namespaces
		if (namespaceElementVec_.size() == 0) {
			Log(Error, "no internal namespace uri in client configuration available");
			return;
		}

		// create namespace mapping
		namespaceMap_.clear();
		for (uint32_t idx=0; idx<namespaceElementVec_.size(); idx++) {
			uint32_t namespaceIndex = namespaceElementVec_[idx].namespaceIndex_;
			std::string namespaceName = namespaceElementVec_[idx].namespaceName_;

			it = namespaceMap.find(namespaceName);
			if (it == namespaceMap.end()) {
				Log(Error, "namespace name not exist on server")
				    .parameter("ServerUri", serverUri_)
				    .parameter("NamespaceName", namespaceName);
				state_ = S_Error;
				return;
			}

			namespaceMap_.insert(std::make_pair(namespaceIndex, it->second));
		}

		handleConnect();

	}

    void
    ClientConnection::handleConnect(void)
    {
    	state_ = S_Established;

    	ClientSubscription::Map::iterator it;
    	for (it = clientSubscriptionMap_.begin(); it != clientSubscriptionMap_.end(); it++) {
    		ClientSubscription::SPtr clientSubscription = it->second;
    		clientSubscription->open(namespaceMap_);
    	}
    }

    void
    ClientConnection::handleDisconnect(void)
    {
    	if (state_ != S_Established) {
    		state_ = S_Disconnected;
    		return;
    	}

    	state_ = S_Disconnected;

    	ClientSubscription::Map::iterator it;
    	for (it = clientSubscriptionMap_.begin(); it != clientSubscriptionMap_.end(); it++) {
    		ClientSubscription::SPtr clientSubscription = it->second;
    		clientSubscription->error();
    	}
    }

    void
    ClientConnection::findResultCallback(OpcUaStatusCode statusCode, ApplicationDescription::Vec& applicationDescriptionVec)
    {
    	if (statusCode != Success) {
    		return;
    	}

    	std::string endpointUrl = "";
    	ApplicationDescription::Vec::iterator it;
    	for (it = applicationDescriptionVec.begin(); it != applicationDescriptionVec.end(); it++) {

    		ApplicationDescription::SPtr ad = *it;

    		Log(Debug, "discovery result")
    			.parameter("ServerUrn", ad->applicationUri())
    			.parameter("DiscoveryUrls", ad->discoveryUrls());

    		OpcUaStringArray::SPtr discoeryUrls = ad->discoveryUrls();
    		for (uint32_t idx = 0; idx < discoeryUrls->size(); idx++) {
    			OpcUaString::SPtr str;
    			discoeryUrls->get(idx, str);
    			endpointUrl = str->value();
    			break;
    		}
    	}

    	// update endpoint url
    	sessionService_->updateEndpointUrl(endpointUrl);
    	sessionService_->asyncConnect();
    }

}
