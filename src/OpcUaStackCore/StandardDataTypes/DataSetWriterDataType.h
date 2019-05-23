/*
    DataTypeClass: DataSetWriterDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataSetWriterDataType_h__
#define __OpcUaStackCore_DataSetWriterDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataSetWriterDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DataSetWriterDataType> SPtr;
        typedef std::vector<DataSetWriterDataType::SPtr> Vec;
    
        DataSetWriterDataType(void);
        DataSetWriterDataType(const DataSetWriterDataType& value);
        virtual ~DataSetWriterDataType(void);
        
        OpcUaString& name(void);
        OpcUaBoolean& enabled(void);
        OpcUaUInt16& dataSetWriterId(void);
        OpcUaDataSetFieldContentMask& dataSetFieldContentMask(void);
        OpcUaUInt32& keyFrameCount(void);
        OpcUaString& dataSetName(void);
        KeyValuePairArray& dataSetWriterProperties(void);
        OpcUaExtensibleParameter& transportSettings(void);
        OpcUaExtensibleParameter& messageSettings(void);
        
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
        
        void copyTo(DataSetWriterDataType& value);
        bool operator==(const DataSetWriterDataType& value);
        bool operator!=(const DataSetWriterDataType& value);
        DataSetWriterDataType& operator=(const DataSetWriterDataType& value);
    
      private:
        OpcUaString name_;
        OpcUaBoolean enabled_;
        OpcUaUInt16 dataSetWriterId_;
        OpcUaDataSetFieldContentMask dataSetFieldContentMask_;
        OpcUaUInt32 keyFrameCount_;
        OpcUaString dataSetName_;
        KeyValuePairArray dataSetWriterProperties_;
        OpcUaExtensibleParameter transportSettings_;
        OpcUaExtensibleParameter messageSettings_;
    
    };
    
    class DLLEXPORT DataSetWriterDataTypeArray
    : public OpcUaArray<DataSetWriterDataType::SPtr, SPtrTypeCoder<DataSetWriterDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataSetWriterDataTypeArray> SPtr;
    };

}

#endif
