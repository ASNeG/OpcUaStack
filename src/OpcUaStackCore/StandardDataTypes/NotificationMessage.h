/*
    DataTypeClass: NotificationMessage

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NotificationMessage_h__
#define __OpcUaStackCore_NotificationMessage_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NotificationMessage
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NotificationMessage> SPtr;
        typedef std::vector<NotificationMessage::SPtr> Vec;
    
        NotificationMessage(void);
        NotificationMessage(const NotificationMessage& value);
        virtual ~NotificationMessage(void);
        
        OpcUaCounter& sequenceNumber(void);
        OpcUaUtcTime& publishTime(void);
        OpcUaExtensibleParameterArray& notificationData(void);
        
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
        
        void copyTo(NotificationMessage& value);
        bool operator==(const NotificationMessage& value);
        bool operator!=(const NotificationMessage& value);
        NotificationMessage& operator=(const NotificationMessage& value);
    
      private:
        OpcUaCounter sequenceNumber_;
        OpcUaUtcTime publishTime_;
        OpcUaExtensibleParameterArray notificationData_;
    
    };
    
    class DLLEXPORT NotificationMessageArray
    : public OpcUaArray<NotificationMessage::SPtr, SPtrTypeCoder<NotificationMessage> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NotificationMessageArray> SPtr;
    };

}

#endif
