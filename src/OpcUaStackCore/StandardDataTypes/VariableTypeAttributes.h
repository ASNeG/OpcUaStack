/*
    DataTypeClass: VariableTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_VariableTypeAttributes_h__
#define __OpcUaStackCore_VariableTypeAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT VariableTypeAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<VariableTypeAttributes> SPtr;
        typedef std::vector<VariableTypeAttributes::SPtr> Vec;
    
        VariableTypeAttributes(void);
        VariableTypeAttributes(const VariableTypeAttributes& value);
        virtual ~VariableTypeAttributes(void);
        
        OpcUaVariant& value(void);
        OpcUaNodeId& dataType(void);
        OpcUaInt32& valueRank(void);
        OpcUaUInt32Array& arrayDimensions(void);
        OpcUaBoolean& isAbstract(void);
        
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
        
        void copyTo(VariableTypeAttributes& value);
        bool operator==(const VariableTypeAttributes& value);
        bool operator!=(const VariableTypeAttributes& value);
        VariableTypeAttributes& operator=(const VariableTypeAttributes& value);
    
      private:
        OpcUaVariant value_; //!< The default value when creating new instances.
        OpcUaNodeId dataType_; //!< The data type of the value.
        OpcUaInt32 valueRank_; //!< Whether the value is an array type and the rank of the array if it is.
        OpcUaUInt32Array arrayDimensions_; //!< The number of dimensions if the value is an array type and one or more dimensions have a fixed length.
        OpcUaBoolean isAbstract_; //!< If TRUE the type is abstract and only subtypes of it appear in the address space.
    
    };
    
    class DLLEXPORT VariableTypeAttributesArray
    : public OpcUaArray<VariableTypeAttributes::SPtr, SPtrTypeCoder<VariableTypeAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<VariableTypeAttributesArray> SPtr;
    };

}

#endif
