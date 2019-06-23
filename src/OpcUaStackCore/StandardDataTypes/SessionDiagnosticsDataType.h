/*
    DataTypeClass: SessionDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SessionDiagnosticsDataType_h__
#define __OpcUaStackCore_SessionDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"
#include "OpcUaStackCore/StandardDataTypes/ServiceCounterDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SessionDiagnosticsDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SessionDiagnosticsDataType> SPtr;
        typedef std::vector<SessionDiagnosticsDataType::SPtr> Vec;
    
        SessionDiagnosticsDataType(void);
        SessionDiagnosticsDataType(const SessionDiagnosticsDataType& value);
        virtual ~SessionDiagnosticsDataType(void);
        
        OpcUaNodeId& sessionId(void);
        OpcUaString& sessionName(void);
        ApplicationDescription& clientDescription(void);
        OpcUaString& serverUri(void);
        OpcUaString& endpointUrl(void);
        OpcUaLocaleIdArray& localeIds(void);
        OpcUaDuration& actualSessionTimeout(void);
        OpcUaUInt32& maxResponseMessageSize(void);
        OpcUaUtcTime& clientConnectionTime(void);
        OpcUaUtcTime& clientLastContactTime(void);
        OpcUaUInt32& currentSubscriptionsCount(void);
        OpcUaUInt32& currentMonitoredItemsCount(void);
        OpcUaUInt32& currentPublishRequestsInQueue(void);
        ServiceCounterDataType& totalRequestCount(void);
        OpcUaUInt32& unauthorizedRequestCount(void);
        ServiceCounterDataType& readCount(void);
        ServiceCounterDataType& historyReadCount(void);
        ServiceCounterDataType& writeCount(void);
        ServiceCounterDataType& historyUpdateCount(void);
        ServiceCounterDataType& callCount(void);
        ServiceCounterDataType& createMonitoredItemsCount(void);
        ServiceCounterDataType& modifyMonitoredItemsCount(void);
        ServiceCounterDataType& setMonitoringModeCount(void);
        ServiceCounterDataType& setTriggeringCount(void);
        ServiceCounterDataType& deleteMonitoredItemsCount(void);
        ServiceCounterDataType& createSubscriptionCount(void);
        ServiceCounterDataType& modifySubscriptionCount(void);
        ServiceCounterDataType& setPublishingModeCount(void);
        ServiceCounterDataType& publishCount(void);
        ServiceCounterDataType& republishCount(void);
        ServiceCounterDataType& transferSubscriptionsCount(void);
        ServiceCounterDataType& deleteSubscriptionsCount(void);
        ServiceCounterDataType& addNodesCount(void);
        ServiceCounterDataType& addReferencesCount(void);
        ServiceCounterDataType& deleteNodesCount(void);
        ServiceCounterDataType& deleteReferencesCount(void);
        ServiceCounterDataType& browseCount(void);
        ServiceCounterDataType& browseNextCount(void);
        ServiceCounterDataType& translateBrowsePathsToNodeIdsCount(void);
        ServiceCounterDataType& queryFirstCount(void);
        ServiceCounterDataType& queryNextCount(void);
        ServiceCounterDataType& registerNodesCount(void);
        ServiceCounterDataType& unregisterNodesCount(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(SessionDiagnosticsDataType& value);
        bool operator==(const SessionDiagnosticsDataType& value);
        bool operator!=(const SessionDiagnosticsDataType& value);
        SessionDiagnosticsDataType& operator=(const SessionDiagnosticsDataType& value);
    
      private:
        OpcUaNodeId sessionId_;
        OpcUaString sessionName_;
        ApplicationDescription clientDescription_;
        OpcUaString serverUri_;
        OpcUaString endpointUrl_;
        OpcUaLocaleIdArray localeIds_;
        OpcUaDuration actualSessionTimeout_;
        OpcUaUInt32 maxResponseMessageSize_;
        OpcUaUtcTime clientConnectionTime_;
        OpcUaUtcTime clientLastContactTime_;
        OpcUaUInt32 currentSubscriptionsCount_;
        OpcUaUInt32 currentMonitoredItemsCount_;
        OpcUaUInt32 currentPublishRequestsInQueue_;
        ServiceCounterDataType totalRequestCount_;
        OpcUaUInt32 unauthorizedRequestCount_;
        ServiceCounterDataType readCount_;
        ServiceCounterDataType historyReadCount_;
        ServiceCounterDataType writeCount_;
        ServiceCounterDataType historyUpdateCount_;
        ServiceCounterDataType callCount_;
        ServiceCounterDataType createMonitoredItemsCount_;
        ServiceCounterDataType modifyMonitoredItemsCount_;
        ServiceCounterDataType setMonitoringModeCount_;
        ServiceCounterDataType setTriggeringCount_;
        ServiceCounterDataType deleteMonitoredItemsCount_;
        ServiceCounterDataType createSubscriptionCount_;
        ServiceCounterDataType modifySubscriptionCount_;
        ServiceCounterDataType setPublishingModeCount_;
        ServiceCounterDataType publishCount_;
        ServiceCounterDataType republishCount_;
        ServiceCounterDataType transferSubscriptionsCount_;
        ServiceCounterDataType deleteSubscriptionsCount_;
        ServiceCounterDataType addNodesCount_;
        ServiceCounterDataType addReferencesCount_;
        ServiceCounterDataType deleteNodesCount_;
        ServiceCounterDataType deleteReferencesCount_;
        ServiceCounterDataType browseCount_;
        ServiceCounterDataType browseNextCount_;
        ServiceCounterDataType translateBrowsePathsToNodeIdsCount_;
        ServiceCounterDataType queryFirstCount_;
        ServiceCounterDataType queryNextCount_;
        ServiceCounterDataType registerNodesCount_;
        ServiceCounterDataType unregisterNodesCount_;
    
    };
    
    class DLLEXPORT SessionDiagnosticsDataTypeArray
    : public OpcUaArray<SessionDiagnosticsDataType::SPtr, SPtrTypeCoder<SessionDiagnosticsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SessionDiagnosticsDataTypeArray> SPtr;
    };

}

#endif
