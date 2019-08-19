/*
    DataTypeClass: UadpDataSetWriterMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UadpDataSetWriterMessageDataType_h__
#define __OpcUaStackCore_UadpDataSetWriterMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetWriterMessageDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UadpDataSetWriterMessageDataType
    : public DataSetWriterMessageDataType
    {
      public:
        typedef boost::shared_ptr<UadpDataSetWriterMessageDataType> SPtr;
        typedef std::vector<UadpDataSetWriterMessageDataType::SPtr> Vec;
    
        UadpDataSetWriterMessageDataType(void);
        UadpDataSetWriterMessageDataType(const UadpDataSetWriterMessageDataType& value);
        virtual ~UadpDataSetWriterMessageDataType(void);
        
        OpcUaUadpDataSetMessageContentMask& dataSetMessageContentMask(void);
        OpcUaUInt16& configuredSize(void);
        OpcUaUInt16& networkMessageNumber(void);
        OpcUaUInt16& dataSetOffset(void);
        
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
        
        void copyTo(UadpDataSetWriterMessageDataType& value);
        bool operator==(const UadpDataSetWriterMessageDataType& value);
        bool operator!=(const UadpDataSetWriterMessageDataType& value);
        UadpDataSetWriterMessageDataType& operator=(const UadpDataSetWriterMessageDataType& value);
    
      private:
        OpcUaUadpDataSetMessageContentMask dataSetMessageContentMask_;
        OpcUaUInt16 configuredSize_;
        OpcUaUInt16 networkMessageNumber_;
        OpcUaUInt16 dataSetOffset_;
    
    };
    
    class DLLEXPORT UadpDataSetWriterMessageDataTypeArray
    : public OpcUaArray<UadpDataSetWriterMessageDataType::SPtr, SPtrTypeCoder<UadpDataSetWriterMessageDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UadpDataSetWriterMessageDataTypeArray> SPtr;
    };

}

#endif
