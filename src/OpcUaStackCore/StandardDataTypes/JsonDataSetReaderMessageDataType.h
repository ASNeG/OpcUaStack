/*
    DataTypeClass: JsonDataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_JsonDataSetReaderMessageDataType_h__
#define __OpcUaStackCore_JsonDataSetReaderMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetReaderMessageDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT JsonDataSetReaderMessageDataType
    : public DataSetReaderMessageDataType
    {
      public:
        typedef boost::shared_ptr<JsonDataSetReaderMessageDataType> SPtr;
        typedef std::vector<JsonDataSetReaderMessageDataType::SPtr> Vec;
    
        JsonDataSetReaderMessageDataType(void);
        JsonDataSetReaderMessageDataType(const JsonDataSetReaderMessageDataType& value);
        virtual ~JsonDataSetReaderMessageDataType(void);
        
        OpcUaJsonNetworkMessageContentMask& networkMessageContentMask(void);
        OpcUaJsonDataSetMessageContentMask& dataSetMessageContentMask(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(JsonDataSetReaderMessageDataType& value);
        bool operator==(const JsonDataSetReaderMessageDataType& value);
        bool operator!=(const JsonDataSetReaderMessageDataType& value);
        JsonDataSetReaderMessageDataType& operator=(const JsonDataSetReaderMessageDataType& value);
    
      private:
        OpcUaJsonNetworkMessageContentMask networkMessageContentMask_;
        OpcUaJsonDataSetMessageContentMask dataSetMessageContentMask_;
    
    };
    
    class DLLEXPORT JsonDataSetReaderMessageDataTypeArray
    : public OpcUaArray<JsonDataSetReaderMessageDataType::SPtr, SPtrTypeCoder<JsonDataSetReaderMessageDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<JsonDataSetReaderMessageDataTypeArray> SPtr;
    };

}

#endif
