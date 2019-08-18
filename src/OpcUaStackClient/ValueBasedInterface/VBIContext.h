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

#ifndef __OpcUaStackClient_VBIContext_h__
#define __OpcUaStackClient_VBIContext_h__

#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

namespace OpcUaStackClient
{

	class DLLEXPORT ContextParameter
	{
	  public:
		typedef std::vector<ContextParameter> Vec;

		ContextParameter(void);
		~ContextParameter(void);

		std::string parameter_;
		std::string value_;
	};

	class DLLEXPORT ConnectContext
	{
	  public:
		ConnectContext(void);
		~ConnectContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);

		bool secureChannelLog_;
		std::string endpointUrl_;			//! direct access without get endpoint request.
		std::string discoveryUrl_;			//! use get endpoint request to find endpoint url. If an
											//! endpoint url exists, it will be ignored.
		std::string applicationUri_;		//! needed to detect right certificate, if get endpoint request
											//! is not used
		OpcUaStackCore::MessageSecurityMode::Enum securityMode_;
		OpcUaStackCore::SecurityPolicy::Enum securityPolicy_;
		std::string sessionName_;
		OpcUaStackCore::CryptoManager::SPtr cryptoManager_;

		bool deleteEndpointDescriptionCache_;
	};


	class DLLEXPORT ReadContext
	{
	  public:
		ReadContext(void);
		~ReadContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);

		OpcUaStackCore::OpcUaInt32 attributeId_;
	};

	class DLLEXPORT WriteContext
	{
	  public:
		WriteContext(void);
		~WriteContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);

		OpcUaStackCore::OpcUaInt32 attributeId_;
	};

	class DLLEXPORT HistoryReadContext
	{
	  public:
		HistoryReadContext(void);
		~HistoryReadContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);

		OpcUaStackCore::TimestampsToReturn timestampToReturn_;
		uint32_t maxNumResultValuesPerNode_;
		uint32_t maxNumResultValuesPerRequest_;
	};

	class DLLEXPORT CreateSubscriptionContext
	{
	  public:
		CreateSubscriptionContext(void);
		~CreateSubscriptionContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);

		OpcUaStackCore::OpcUaDouble requestedPublishingInterval_;
		OpcUaStackCore::OpcUaUInt32 requestedLifetimeCount_;
		OpcUaStackCore::OpcUaUInt32 requestedMaxKeepAliveCount_;
		OpcUaStackCore::OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaStackCore::OpcUaBoolean publishingEnabled_;
		OpcUaStackCore::OpcUaByte priority_;
	};

	class DLLEXPORT DeleteSubscriptionContext
	{
	  public:
		DeleteSubscriptionContext(void);
		~DeleteSubscriptionContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);
	};

	class DLLEXPORT CreateMonitoredItemContext
	{
	  public:
		CreateMonitoredItemContext(void);
		~CreateMonitoredItemContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);

		OpcUaStackCore::OpcUaDouble samplingInterval_;
		OpcUaStackCore::OpcUaExtensibleParameter filter_;
		OpcUaStackCore::OpcUaUInt32 queueSize_;
		OpcUaStackCore::OpcUaBoolean discardOldest_;
		OpcUaStackCore::OpcUaUInt32 attributeId_;
	};

	class DLLEXPORT DeleteMonitoredItemContext
	{
	  public:
		DeleteMonitoredItemContext(void);
		~DeleteMonitoredItemContext(void);

		void reset(void);
		bool setContextParameter(ContextParameter::Vec& contextParameterVec);
	};

}

#endif
