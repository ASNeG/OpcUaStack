/*
    DataTypeClass: UadpDataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UadpDataSetReaderMessageDataType_h__
#define __OpcUaStackCore_UadpDataSetReaderMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetReaderMessageDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UadpDataSetReaderMessageDataType
    : public DataSetReaderMessageDataType
    {
      public:
        typedef boost::shared_ptr<UadpDataSetReaderMessageDataType> SPtr;
        typedef std::vector<UadpDataSetReaderMessageDataType::SPtr> Vec;
    
        UadpDataSetReaderMessageDataType(void);
        UadpDataSetReaderMessageDataType(const UadpDataSetReaderMessageDataType& value);
        virtual ~UadpDataSetReaderMessageDataType(void);
        
        OpcUaVersionTime& groupVersion(void);
        OpcUaUInt16& networkMessageNumber(void);
        OpcUaUInt16& dataSetOffset(void);
        OpcUaGuid& dataSetClassId(void);
        OpcUaUadpNetworkMessageContentMask& networkMessageContentMask(void);
        OpcUaUadpDataSetMessageContentMask& dataSetMessageContentMask(void);
        OpcUaDuration& publishingInterval(void);
        OpcUaDuration& receiveOffset(void);
        OpcUaDuration& processingOffset(void);
        
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
        
        void copyTo(UadpDataSetReaderMessageDataType& value);
        bool operator==(const UadpDataSetReaderMessageDataType& value);
        bool operator!=(const UadpDataSetReaderMessageDataType& value);
        UadpDataSetReaderMessageDataType& operator=(const UadpDataSetReaderMessageDataType& value);
    
      private:
        OpcUaVersionTime groupVersion_;
        OpcUaUInt16 networkMessageNumber_;
        OpcUaUInt16 dataSetOffset_;
        OpcUaGuid dataSetClassId_;
        OpcUaUadpNetworkMessageContentMask networkMessageContentMask_;
        OpcUaUadpDataSetMessageContentMask dataSetMessageContentMask_;
        OpcUaDuration publishingInterval_;
        OpcUaDuration receiveOffset_;
        OpcUaDuration processingOffset_;
    
    };
    
    class DLLEXPORT UadpDataSetReaderMessageDataTypeArray
    : public OpcUaArray<UadpDataSetReaderMessageDataType::SPtr, SPtrTypeCoder<UadpDataSetReaderMessageDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UadpDataSetReaderMessageDataTypeArray> SPtr;
    };

}

#endif
