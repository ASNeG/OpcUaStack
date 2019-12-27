/*
    DataTypeClass: ModelChangeStructureDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ModelChangeStructureDataType_h__
#define __OpcUaStackCore_ModelChangeStructureDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ModelChangeStructureDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ModelChangeStructureDataType> SPtr;
        typedef std::vector<ModelChangeStructureDataType::SPtr> Vec;
    
        ModelChangeStructureDataType(void);
        ModelChangeStructureDataType(const ModelChangeStructureDataType& value);
        virtual ~ModelChangeStructureDataType(void);
        
        OpcUaNodeId& affected(void);
        OpcUaNodeId& affectedType(void);
        OpcUaByte& verb(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(ModelChangeStructureDataType& value);
        bool operator==(const ModelChangeStructureDataType& value);
        bool operator!=(const ModelChangeStructureDataType& value);
        ModelChangeStructureDataType& operator=(const ModelChangeStructureDataType& value);
    
      private:
        OpcUaNodeId affected_;
        OpcUaNodeId affectedType_;
        OpcUaByte verb_;
    
    };
    
    class DLLEXPORT ModelChangeStructureDataTypeArray
    : public OpcUaArray<ModelChangeStructureDataType::SPtr, SPtrTypeCoder<ModelChangeStructureDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ModelChangeStructureDataTypeArray> SPtr;
    };

}

#endif
