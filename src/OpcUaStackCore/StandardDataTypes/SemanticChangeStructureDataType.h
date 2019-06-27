/*
    DataTypeClass: SemanticChangeStructureDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SemanticChangeStructureDataType_h__
#define __OpcUaStackCore_SemanticChangeStructureDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SemanticChangeStructureDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SemanticChangeStructureDataType> SPtr;
        typedef std::vector<SemanticChangeStructureDataType::SPtr> Vec;
    
        SemanticChangeStructureDataType(void);
        SemanticChangeStructureDataType(const SemanticChangeStructureDataType& value);
        virtual ~SemanticChangeStructureDataType(void);
        
        OpcUaNodeId& affected(void);
        OpcUaNodeId& affectedType(void);
        
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
        
        void copyTo(SemanticChangeStructureDataType& value);
        bool operator==(const SemanticChangeStructureDataType& value);
        bool operator!=(const SemanticChangeStructureDataType& value);
        SemanticChangeStructureDataType& operator=(const SemanticChangeStructureDataType& value);
    
      private:
        OpcUaNodeId affected_;
        OpcUaNodeId affectedType_;
    
    };
    
    class DLLEXPORT SemanticChangeStructureDataTypeArray
    : public OpcUaArray<SemanticChangeStructureDataType::SPtr, SPtrTypeCoder<SemanticChangeStructureDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SemanticChangeStructureDataTypeArray> SPtr;
    };

}

#endif
