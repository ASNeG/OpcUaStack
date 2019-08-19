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
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual void opcUaBinaryEncode(std::ostream& os) const override;
        virtual void opcUaBinaryDecode(std::istream& is) override;
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
