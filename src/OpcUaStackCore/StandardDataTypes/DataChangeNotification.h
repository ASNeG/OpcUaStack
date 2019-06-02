/*
    DataTypeClass: DataChangeNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataChangeNotification_h__
#define __OpcUaStackCore_DataChangeNotification_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
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
