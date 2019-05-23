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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
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
