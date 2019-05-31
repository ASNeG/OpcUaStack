/*
    DataTypeClass: EventNotificationList

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EventNotificationList_h__
#define __OpcUaStackCore_EventNotificationList_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/NotificationData.h"
#include "OpcUaStackCore/StandardDataTypes/EventFieldList.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EventNotificationList
    : public NotificationData
    {
      public:
        typedef boost::shared_ptr<EventNotificationList> SPtr;
        typedef std::vector<EventNotificationList::SPtr> Vec;
    
        EventNotificationList(void);
        EventNotificationList(const EventNotificationList& value);
        virtual ~EventNotificationList(void);
        
        EventFieldListArray& events(void);
        
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
        
        void copyTo(EventNotificationList& value);
        bool operator==(const EventNotificationList& value);
        bool operator!=(const EventNotificationList& value);
        EventNotificationList& operator=(const EventNotificationList& value);
    
      private:
        EventFieldListArray events_;
    
    };
    
    class DLLEXPORT EventNotificationListArray
    : public OpcUaArray<EventNotificationList::SPtr, SPtrTypeCoder<EventNotificationList> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EventNotificationListArray> SPtr;
    };

}

#endif
