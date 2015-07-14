#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/Subscription.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	Subscription::Subscription(IOService& ioService)
	: requestedPublishingInterval_(100)
	, requestedLifetimeCount_(50)
	, requestedMaxKeepAliveCount_(50)
	, maxNotificationsPerPublish_(10000)
	, publishingEnabled_(true)
	, priority_(1)
	, state_(S_Closed)
	, subscriptionService_()
	, reconnect_(true)
	{
		subscriptionService_.subscriptionServiceIf(this);
	}

	Subscription::~Subscription(void)
	{
	}

	void
	Subscription::componentSession(Component* componentSession)
	{
		subscriptionService_.componentSession(componentSession);
	}

	void
	Subscription::subscriptionIf(SubscriptionIf* subscriptionIf)
	{
		subscriptionIf_ = subscriptionIf;
	}

	void
	Subscription::open(void)
	{
		// The subscription must be in the state S_Closed
		if (state_ != S_Closed) {
			Log(Error, "cannot open subscription, because subscription is not closed");
			return;
		}

		// create create subscription request
		ServiceTransactionCreateSubscription::SPtr trx = ServiceTransactionCreateSubscription::construct();
		CreateSubscriptionRequest::SPtr req = trx->request();
		req->requestedPublishingInterval(requestedPublishingInterval_);
		req->requestedLifetimeCount(requestedLifetimeCount_);
		req->requestedMaxKeepAliveCount(requestedMaxKeepAliveCount_);
		req->maxNotificationsPerPublish(maxNotificationsPerPublish_);
		req->publishingEnabled(publishingEnabled_);
		req->priority(priority_);

		// send subscription request
		state_ = S_Connecting;
		subscriptionService_.sendAsync(trx);
	}

	void
	Subscription::close(void)
	{
		// The subscription must not be in the state S_Closed
		if (state_ != S_Closed) {
			Log(Error, "cannot close subscription, because subscription is already closed");
			return;
		}


#if 0
		S_Connecting,
			S_Connected,
			S_Closing,
			S_Reconnecting
#endif
	}

    void
    Subscription::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
    {
		// The subscription must be in the state S_Connecting
		if (state_ != S_Connecting) {
			Log(Error, "received create subscription response in invalid state")
				.parameter("State", state_);
			state_ = S_Closed;
			return;
		}

		// check result code
		OpcUaStatusCode statusCode = serviceTransactionCreateSubscription->responseHeader()->serviceResult();
		if ( statusCode != Success) {
			Log(Error, "received invalid status code in create subscription response")
				.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
			state_ = S_Closed;
			return;
		}

		// save parameter and send notify to application
		CreateSubscriptionResponse::SPtr res = serviceTransactionCreateSubscription->response();
		subscriptionId_ = res->subscriptionId();
		revisedPublishingInterval_ = res->revisedPublishingInterval();
		revisedLifetimeCount_ = res->revisedLifetimeCount();
		revisedMaxKeepAliveCount_ = res->revisedMaxKeepAliveCount();

		state_ = S_Connected;
		if (subscriptionIf_) subscriptionIf_->subscriptionStateChange(S_Open);
    }

    void
    Subscription::subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
    {
    }

    void
    Subscription::subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
    {
	}

    void
    Subscription::subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
    {
    }

}
