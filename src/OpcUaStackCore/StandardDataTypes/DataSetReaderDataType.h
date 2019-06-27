/*
    DataTypeClass: DataSetReaderDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataSetReaderDataType_h__
#define __OpcUaStackCore_DataSetReaderDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetMetaDataType.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataSetReaderDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DataSetReaderDataType> SPtr;
        typedef std::vector<DataSetReaderDataType::SPtr> Vec;
    
        DataSetReaderDataType(void);
        DataSetReaderDataType(const DataSetReaderDataType& value);
        virtual ~DataSetReaderDataType(void);
        
        OpcUaString& name(void);
        OpcUaBoolean& enabled(void);
        OpcUaVariant& publisherId(void);
        OpcUaUInt16& writerGroupId(void);
        OpcUaUInt16& dataSetWriterId(void);
        DataSetMetaDataType& dataSetMetaData(void);
        OpcUaDataSetFieldContentMask& dataSetFieldContentMask(void);
        OpcUaDuration& messageReceiveTimeout(void);
        MessageSecurityMode& securityMode(void);
        OpcUaString& securityGroupId(void);
        EndpointDescriptionArray& securityKeyServices(void);
        KeyValuePairArray& dataSetReaderProperties(void);
        OpcUaExtensibleParameter& transportSettings(void);
        OpcUaExtensibleParameter& messageSettings(void);
        OpcUaExtensibleParameter& subscribedDataSet(void);
        
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
        
        void copyTo(DataSetReaderDataType& value);
        bool operator==(const DataSetReaderDataType& value);
        bool operator!=(const DataSetReaderDataType& value);
        DataSetReaderDataType& operator=(const DataSetReaderDataType& value);
    
      private:
        OpcUaString name_;
        OpcUaBoolean enabled_;
        OpcUaVariant publisherId_;
        OpcUaUInt16 writerGroupId_;
        OpcUaUInt16 dataSetWriterId_;
        DataSetMetaDataType dataSetMetaData_;
        OpcUaDataSetFieldContentMask dataSetFieldContentMask_;
        OpcUaDuration messageReceiveTimeout_;
        MessageSecurityMode securityMode_;
        OpcUaString securityGroupId_;
        EndpointDescriptionArray securityKeyServices_;
        KeyValuePairArray dataSetReaderProperties_;
        OpcUaExtensibleParameter transportSettings_;
        OpcUaExtensibleParameter messageSettings_;
        OpcUaExtensibleParameter subscribedDataSet_;
    
    };
    
    class DLLEXPORT DataSetReaderDataTypeArray
    : public OpcUaArray<DataSetReaderDataType::SPtr, SPtrTypeCoder<DataSetReaderDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataSetReaderDataTypeArray> SPtr;
    };

}

#endif
