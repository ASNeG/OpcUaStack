/*
    EnumTypeClass: MessageSecurityMode

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MessageSecurityMode_h__
#define __OpcUaStackCore_MessageSecurityMode_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    /**
     * The type of security to use on a message.
     */
    class DLLEXPORT MessageSecurityMode
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<MessageSecurityMode> SPtr;
    
        typedef enum {
            EnumInvalid = 0,     //!< An invalid mode.
            EnumNone = 1,     //!< No security is used.
            EnumSign = 2,     //!< The message is signed.
            EnumSignAndEncrypt = 3,     //!< The message is signed and encrypted.
        } Enum;
    
        MessageSecurityMode(void);
        MessageSecurityMode(Enum enumeration);
        MessageSecurityMode(MessageSecurityMode& value);
        virtual ~MessageSecurityMode(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
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
        
        void copyTo(MessageSecurityMode& value);
        bool operator==(const MessageSecurityMode& value) const;
        bool operator!=(const MessageSecurityMode& value) const;
        MessageSecurityMode& operator=(const MessageSecurityMode& value);
        MessageSecurityMode& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT MessageSecurityModeArray
    : public OpcUaArray<MessageSecurityMode::SPtr, SPtrTypeCoder<MessageSecurityMode> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MessageSecurityModeArray> SPtr;
    };

}

#endif
