/*
    DataTypeClass: PublishedDataSetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedDataSetDataType_h__
#define __OpcUaStackCore_PublishedDataSetDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetMetaDataType.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PublishedDataSetDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<PublishedDataSetDataType> SPtr;
        typedef std::vector<PublishedDataSetDataType::SPtr> Vec;
    
        PublishedDataSetDataType(void);
        PublishedDataSetDataType(const PublishedDataSetDataType& value);
        virtual ~PublishedDataSetDataType(void);
        
        OpcUaString& name(void);
        OpcUaStringArray& dataSetFolder(void);
        DataSetMetaDataType& dataSetMetaData(void);
        KeyValuePairArray& extensionFields(void);
        OpcUaExtensibleParameter& dataSetSource(void);
        
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
        
        void copyTo(PublishedDataSetDataType& value);
        bool operator==(const PublishedDataSetDataType& value);
        bool operator!=(const PublishedDataSetDataType& value);
        PublishedDataSetDataType& operator=(const PublishedDataSetDataType& value);
    
      private:
        OpcUaString name_;
        OpcUaStringArray dataSetFolder_;
        DataSetMetaDataType dataSetMetaData_;
        KeyValuePairArray extensionFields_;
        OpcUaExtensibleParameter dataSetSource_;
    
    };
    
    class DLLEXPORT PublishedDataSetDataTypeArray
    : public OpcUaArray<PublishedDataSetDataType::SPtr, SPtrTypeCoder<PublishedDataSetDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PublishedDataSetDataTypeArray> SPtr;
    };

}

#endif
