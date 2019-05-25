/*
    DataTypeClass: PublishedDataItemsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedDataItemsDataType_h__
#define __OpcUaStackCore_PublishedDataItemsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
