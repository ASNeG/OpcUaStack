/*
    DataTypeClass: DataTypeSchemaHeader

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataTypeSchemaHeader_h__
#define __OpcUaStackCore_DataTypeSchemaHeader_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/StructureDescription.h"
#include "OpcUaStackCore/StandardDataTypes/EnumDescription.h"
#include "OpcUaStackCore/StandardDataTypes/SimpleTypeDescription.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataTypeSchemaHeader
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DataTypeSchemaHeader> SPtr;
        typedef std::vector<DataTypeSchemaHeader::SPtr> Vec;
    
        DataTypeSchemaHeader(void);
        DataTypeSchemaHeader(const DataTypeSchemaHeader& value);
        virtual ~DataTypeSchemaHeader(void);
        
        OpcUaStringArray& namespaces(void);
        StructureDescriptionArray& structureDataTypes(void);
        EnumDescriptionArray& enumDataTypes(void);
        SimpleTypeDescriptionArray& simpleDataTypes(void);
        
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
        
        void copyTo(DataTypeSchemaHeader& value);
        bool operator==(const DataTypeSchemaHeader& value);
        bool operator!=(const DataTypeSchemaHeader& value);
        DataTypeSchemaHeader& operator=(const DataTypeSchemaHeader& value);
    
      private:
        OpcUaStringArray namespaces_;
        StructureDescriptionArray structureDataTypes_;
        EnumDescriptionArray enumDataTypes_;
        SimpleTypeDescriptionArray simpleDataTypes_;
    
    };
    
    class DLLEXPORT DataTypeSchemaHeaderArray
    : public OpcUaArray<DataTypeSchemaHeader::SPtr, SPtrTypeCoder<DataTypeSchemaHeader> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataTypeSchemaHeaderArray> SPtr;
    };

}

#endif
