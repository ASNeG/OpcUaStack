/*
    EnumTypeClass: NodeClass

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    /**
     * A mask specifying the class of the node.
     */
    class DLLEXPORT NodeClass
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NodeClass> SPtr;
    
        typedef enum {
            EnumUnspecified = 0,     //!< No classes are selected.
            EnumObject = 1,     //!< The node is an object.
            EnumVariable = 2,     //!< The node is a variable.
            EnumMethod = 4,     //!< The node is a method.
            EnumObjectType = 8,     //!< The node is an object type.
            EnumVariableType = 16,     //!< The node is an variable type.
            EnumReferenceType = 32,     //!< The node is a reference type.
            EnumDataType = 64,     //!< The node is a data type.
            EnumView = 128,     //!< The node is a view.
        } Enum;
    
        NodeClass(void);
        NodeClass(Enum enumeration);
        NodeClass(NodeClass& value);
        virtual ~NodeClass(void);
        
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
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(NodeClass& value);
        bool operator==(const NodeClass& value) const;
        bool operator!=(const NodeClass& value) const;
        NodeClass& operator=(const NodeClass& value);
        NodeClass& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class NodeClassArray
    : public OpcUaArray<NodeClass::SPtr, SPtrTypeCoder<NodeClass> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NodeClassArray> SPtr;
    };

}

#endif
