/*
    DataTypeClass: MonitoredItemNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MonitoredItemNotification_h__
#define __OpcUaStackCore_MonitoredItemNotification_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT MonitoredItemNotification
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<MonitoredItemNotification> SPtr;
        typedef std::vector<MonitoredItemNotification::SPtr> Vec;
    
        MonitoredItemNotification(void);
        MonitoredItemNotification(const MonitoredItemNotification& value);
        virtual ~MonitoredItemNotification(void);
        
        OpcUaIntegerId& clientHandle(void);
        OpcUaDataValue& value(void);
        
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
        
        void copyTo(MonitoredItemNotification& value);
        bool operator==(const MonitoredItemNotification& value);
        bool operator!=(const MonitoredItemNotification& value);
        MonitoredItemNotification& operator=(const MonitoredItemNotification& value);
    
      private:
        OpcUaIntegerId clientHandle_;
        OpcUaDataValue value_;
    
    };
    
    class DLLEXPORT MonitoredItemNotificationArray
    : public OpcUaArray<MonitoredItemNotification::SPtr, SPtrTypeCoder<MonitoredItemNotification> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MonitoredItemNotificationArray> SPtr;
    };

}

#endif
