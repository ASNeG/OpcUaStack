/*
    EnumTypeClass: NodeClass

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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
        static Enum str2Enum(const std::string& enumerationString);
        static std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        static bool exist(const std::string& enumerationString);
        static bool exist(Enum enumeration);
        
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
        
        void copyTo(NodeClass& value);
        bool operator==(const NodeClass& value) const;
        bool operator!=(const NodeClass& value) const;
        NodeClass& operator=(const NodeClass& value);
        NodeClass& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT NodeClassArray
    : public OpcUaArray<NodeClass::SPtr, SPtrTypeCoder<NodeClass> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NodeClassArray> SPtr;
    };

}

#endif
