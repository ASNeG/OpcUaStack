/*
    DataTypeClass: UABinaryFileDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UABinaryFileDataType_h__
#define __OpcUaStackCore_UABinaryFileDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeSchemaHeader.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UABinaryFileDataType
    : public DataTypeSchemaHeader
    {
      public:
        typedef boost::shared_ptr<UABinaryFileDataType> SPtr;
        typedef std::vector<UABinaryFileDataType::SPtr> Vec;
    
        UABinaryFileDataType(void);
        UABinaryFileDataType(const UABinaryFileDataType& value);
        virtual ~UABinaryFileDataType(void);
        
        OpcUaString& schemaLocation(void);
        KeyValuePairArray& fileHeader(void);
        OpcUaVariant& body(void);
        
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
        
        void copyTo(UABinaryFileDataType& value);
        bool operator==(const UABinaryFileDataType& value);
        bool operator!=(const UABinaryFileDataType& value);
        UABinaryFileDataType& operator=(const UABinaryFileDataType& value);
    
      private:
        OpcUaString schemaLocation_;
        KeyValuePairArray fileHeader_;
        OpcUaVariant body_;
    
    };
    
    class DLLEXPORT UABinaryFileDataTypeArray
    : public OpcUaArray<UABinaryFileDataType::SPtr, SPtrTypeCoder<UABinaryFileDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UABinaryFileDataTypeArray> SPtr;
    };

}

#endif
