/*
    DataTypeClass: PublishedDataSetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PublishedDataSetDataType_h__
#define __OpcUaStackCore_PublishedDataSetDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
