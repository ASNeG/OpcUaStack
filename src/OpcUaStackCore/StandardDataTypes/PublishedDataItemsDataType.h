/*
    DataTypeClass: PublishedDataItemsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedDataItemsDataType_h__
#define __OpcUaStackCore_PublishedDataItemsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/PublishedDataSetSourceDataType.h"
#include "OpcUaStackCore/StandardDataTypes/PublishedVariableDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PublishedDataItemsDataType
    : public PublishedDataSetSourceDataType
    {
      public:
        typedef boost::shared_ptr<PublishedDataItemsDataType> SPtr;
        typedef std::vector<PublishedDataItemsDataType::SPtr> Vec;
    
        PublishedDataItemsDataType(void);
        PublishedDataItemsDataType(const PublishedDataItemsDataType& value);
        virtual ~PublishedDataItemsDataType(void);
        
        PublishedVariableDataTypeArray& publishedData(void);
        
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
        
        void copyTo(PublishedDataItemsDataType& value);
        bool operator==(const PublishedDataItemsDataType& value);
        bool operator!=(const PublishedDataItemsDataType& value);
        PublishedDataItemsDataType& operator=(const PublishedDataItemsDataType& value);
    
      private:
        PublishedVariableDataTypeArray publishedData_;
    
    };
    
    class DLLEXPORT PublishedDataItemsDataTypeArray
    : public OpcUaArray<PublishedDataItemsDataType::SPtr, SPtrTypeCoder<PublishedDataItemsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PublishedDataItemsDataTypeArray> SPtr;
    };

}

#endif
