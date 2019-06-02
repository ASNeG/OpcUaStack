/*
    DataTypeClass: JsonDataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_JsonDataSetReaderMessageDataType_h__
#define __OpcUaStackCore_JsonDataSetReaderMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
