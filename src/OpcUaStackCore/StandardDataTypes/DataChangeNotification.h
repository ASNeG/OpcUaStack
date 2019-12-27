/*
    DataTypeClass: DataChangeNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataChangeNotification_h__
#define __OpcUaStackCore_DataChangeNotification_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NotificationData.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataChangeNotification
    : public NotificationData
    {
      public:
        typedef boost::shared_ptr<DataChangeNotification> SPtr;
        typedef std::vector<DataChangeNotification::SPtr> Vec;
    
        DataChangeNotification(void);
        DataChangeNotification(const DataChangeNotification& value);
        virtual ~DataChangeNotification(void);
        
        MonitoredItemNotificationArray& monitoredItems(void);
        OpcUaDiagnosticInfoArray& diagnosticInfos(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
        void copyTo(DataChangeNotification& value);
        bool operator==(const DataChangeNotification& value);
        bool operator!=(const DataChangeNotification& value);
        DataChangeNotification& operator=(const DataChangeNotification& value);
    
      private:
        MonitoredItemNotificationArray monitoredItems_;
        OpcUaDiagnosticInfoArray diagnosticInfos_;
    
    };
    
    class DLLEXPORT DataChangeNotificationArray
    : public OpcUaArray<DataChangeNotification::SPtr, SPtrTypeCoder<DataChangeNotification> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataChangeNotificationArray> SPtr;
    };

}

#endif
