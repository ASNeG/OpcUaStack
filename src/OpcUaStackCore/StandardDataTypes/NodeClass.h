/*
    EnumTypeClass: NodeClass

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor:     Kai Huebl (kai@huebl-sgh.de)
    BuildDate: 2018-Oct-25 09:41:46.020329
*/

#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class NodeClass
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NodeClass> SPtr;
    
        typedef enum {
            EnumUnspecified = 0,
            EnumObject = 1,
            EnumVariable = 2,
            EnumMethod = 4,
            EnumObjectType = 8,
            EnumVariableType = 16,
            EnumReferenceType = 32,
            EnumDataType = 64,
            EnumView = 128,
        } Enum;
    
        NodeClass(void);
        NodeClass(Enum enumeration);
        NodeClass(NodeClass& value);
        virtual ~NodeClass(void);
        
        uint32_t& value(void);
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
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(NodeClass& value);
        bool operator==(const NodeClass& value) const;
        bool operator!=(const NodeClass& value) const;
    
      private:
        uint32_t value_;
    
    };

}

#endif
