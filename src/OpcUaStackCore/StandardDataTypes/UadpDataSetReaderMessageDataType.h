/*
    DataTypeClass: UadpDataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UadpDataSetReaderMessageDataType_h__
#define __OpcUaStackCore_UadpDataSetReaderMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
