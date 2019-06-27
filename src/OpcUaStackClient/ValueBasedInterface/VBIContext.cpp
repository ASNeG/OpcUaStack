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

#include <boost/algorithm/string.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIContext.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Context Parameter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ContextParameter::ContextParameter(void)
	: parameter_("")
	, value_("")
	{
	}

	ContextParameter::~ContextParameter(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ConnectContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ConnectContext::ConnectContext(void)
	: secureChannelLog_(false)
	, endpointUrl_("")
	, discoveryUrl_("")
	, applicationUri_("Unknown")
	, securityMode_(MessageSecurityMode::EnumNone)
	, securityPolicy_(SecurityPolicy::EnumNone)
	, sessionName_("Unknown")
	, cryptoManager_()
	, deleteEndpointDescriptionCache_(false)
	{
	}

	ConnectContext::~ConnectContext(void)
	{
	}

	void
	ConnectContext::reset(void)
	{
		endpointUrl_ = "";
		sessionName_ = "";
		cryptoManager_.reset();
	}

	bool
	ConnectContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		ContextParameter::Vec::iterator it;
		for (it = contextParameterVec.begin(); it != contextParameterVec.end(); it++) {
			if (it->parameter_ == "EndpointUrl") {
				endpointUrl_ = it->value_;
			}
			else if (it->parameter_ == "SessionName") {
				sessionName_ = it->value_;
			}
			else {
				return false;
			}
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ReadContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ReadContext::ReadContext(void)
	: attributeId_(13)
	{
	}

	ReadContext::~ReadContext(void)
	{
	}

	void
	ReadContext::reset(void)
	{
		attributeId_ = 13;
	}

	bool
	ReadContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		ContextParameter::Vec::iterator it;
		for (it = contextParameterVec.begin(); it != contextParameterVec.end(); it++) {
			if (it->parameter_ == "AttributeId") {
				try
				{
					attributeId_ = boost::lexical_cast<int32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "AttributeId")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// WriteContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	WriteContext::WriteContext(void)
	: attributeId_(13)
	{
	}

	WriteContext::~WriteContext(void)
	{
	}

	void
	WriteContext::reset(void)
	{
		attributeId_ = 13;
	}

	bool
	WriteContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		ContextParameter::Vec::iterator it;
		for (it = contextParameterVec.begin(); it != contextParameterVec.end(); it++) {
			if (it->parameter_ == "AttributeId") {
				try
				{
					attributeId_ = boost::lexical_cast<int32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "AttributeId")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// HistoryReadContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	HistoryReadContext::HistoryReadContext(void)
	: timestampToReturn_(TimestampsToReturn_Both)
	, maxNumResultValuesPerNode_(0)
	, maxNumResultValuesPerRequest_(0)
	{
	}

	HistoryReadContext::~HistoryReadContext(void)
	{
	}

	void
	HistoryReadContext::reset(void)
	{
	}

	bool
	HistoryReadContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		for (auto para : contextParameterVec) {
			if (para.parameter_ == "TIMESTAMPSTORETURN") {
				if (para.value_ == "Source") {
					timestampToReturn_ = TimestampsToReturn_Source;
				}
				else if (para.value_ == "Server") {
					timestampToReturn_ = TimestampsToReturn_Server;
				}
				else if (para.value_ == "Both") {
					timestampToReturn_ = TimestampsToReturn_Both;
				}
				else if (para.value_ == "Neither") {
					timestampToReturn_ = TimestampsToReturn_Neither;
				}
				else {
					return false;
				}
			}
			else if (para.parameter_ == "MAXNUMRESULTVALUESPERNODE") {
				try {
					maxNumResultValuesPerNode_ = boost::lexical_cast<uint32_t>(para.value_);
				}
				catch (...)
				{
					return false;
			    }

			}
			else if (para.parameter_ == "MAXNUMRESULTVALUESPERREQUEST") {
				try {
					maxNumResultValuesPerRequest_ = boost::lexical_cast<uint32_t>(para.value_);
				}
				catch (...)
				{
					return false;
			    }

			}
			else {
				return false;
			}
		}
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CreateSubscriptionContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CreateSubscriptionContext::CreateSubscriptionContext(void)
	: requestedPublishingInterval_(100)
	, requestedLifetimeCount_(2400)
	, requestedMaxKeepAliveCount_(10)
	, maxNotificationsPerPublish_(65536)
	, publishingEnabled_(true)
	, priority_(0)
	{
	}

	CreateSubscriptionContext::~CreateSubscriptionContext(void)
	{
	}

	void
	CreateSubscriptionContext::reset(void)
	{
		requestedPublishingInterval_ = 100;
		requestedLifetimeCount_ = 2400;
		requestedMaxKeepAliveCount_ = 10;
		maxNotificationsPerPublish_ = 65536;
		publishingEnabled_ = true;
		priority_ = 0;
	}

	bool
	CreateSubscriptionContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		ContextParameter::Vec::iterator it;
		for (it = contextParameterVec.begin(); it != contextParameterVec.end(); it++) {
			if (it->parameter_ == "RequestedPublishingInterval") {
				try
				{
					requestedPublishingInterval_ = boost::lexical_cast<double>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "RequestedPublishingInterval")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else if (it->parameter_ == "RequestedLifetimeCount") {
				try
				{
					requestedLifetimeCount_ = boost::lexical_cast<uint32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "RequestedLifetimeCount")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else if (it->parameter_ == "RequestedMaxKeepAliveCount") {
				try
				{
					requestedMaxKeepAliveCount_ = boost::lexical_cast<uint32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "RequestedMaxKeepAliveCount")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else if (it->parameter_ == "MaxNotificationsPerPublish") {
				try
				{
					maxNotificationsPerPublish_ = boost::lexical_cast<uint32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "MaxNotificationsPerPublish")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else if (it->parameter_ == "PublishingEnabled") {
				if (boost::to_upper_copy(it->value_) == "TRUE") publishingEnabled_ = true;
				else publishingEnabled_ = false;
			}
			else if (it->parameter_ == "Priority") {
				try
				{
					priority_ = boost::lexical_cast<uint8_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "Priority")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteSubscriptionContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteSubscriptionContext::DeleteSubscriptionContext(void)
	{
	}

	DeleteSubscriptionContext::~DeleteSubscriptionContext(void)
	{
	}

	void
	DeleteSubscriptionContext::reset(void)
	{
	}

	bool
	DeleteSubscriptionContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CreateMonitoredItemContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CreateMonitoredItemContext::CreateMonitoredItemContext(void)
	: samplingInterval_(500)
	, filter_()
	, queueSize_(1)
	, discardOldest_(true)
	, attributeId_(13)
	{
	}

	CreateMonitoredItemContext::~CreateMonitoredItemContext(void)
	{
	}

	void
	CreateMonitoredItemContext::reset(void)
	{
		samplingInterval_ = 500;
		filter_.clear();
		queueSize_ = 1;
		discardOldest_ = true;
		attributeId_ = 13;
	}

	bool
	CreateMonitoredItemContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		ContextParameter::Vec::iterator it;
		for (it = contextParameterVec.begin(); it != contextParameterVec.end(); it++) {
			if (it->parameter_ == "SamplingInterval") {
				try
				{
					samplingInterval_ = boost::lexical_cast<double>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "SamplingInterval")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else if (it->parameter_ == "QueueSize") {
				try
				{
					queueSize_ = boost::lexical_cast<uint32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "QueueSize")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else if (it->parameter_ == "DiscardOldest") {
				if (boost::to_upper_copy(it->value_) == "TRUE") discardOldest_ = true;
				else discardOldest_ = false;
			}
			else if (it->parameter_ == "AttributeId") {
				try
				{
					attributeId_ = boost::lexical_cast<uint32_t>(it->value_);
				} catch (...)
				{
					Log(Error, "parameter value invalid")
						.parameter("Parameter", "AttributeId")
						.parameter("Value", it->value_);
					return false;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteMonitoredItemContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteMonitoredItemContext::DeleteMonitoredItemContext(void)
	{
	}

	DeleteMonitoredItemContext::~DeleteMonitoredItemContext(void)
	{
	}

	void
	DeleteMonitoredItemContext::reset(void)
	{
	}

	bool
	DeleteMonitoredItemContext::setContextParameter(ContextParameter::Vec& contextParameterVec)
	{
		return true;
	}

}
