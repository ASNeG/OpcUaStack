/*
    DataTypeClass: WriterGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_WriterGroupDataType_h__
#define __OpcUaStackCore_WriterGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/PubSubGroupDataType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetWriterDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT WriterGroupDataType
    : public PubSubGroupDataType
    {
      public:
        typedef boost::shared_ptr<WriterGroupDataType> SPtr;
        typedef std::vector<WriterGroupDataType::SPtr> Vec;
    
        WriterGroupDataType(void);
        WriterGroupDataType(const WriterGroupDataType& value);
        virtual ~WriterGroupDataType(void);
        
        OpcUaUInt16& writerGroupId(void);
        OpcUaDuration& publishingInterval(void);
        OpcUaDuration& keepAliveTime(void);
        OpcUaByte& priority(void);
        OpcUaLocaleIdArray& localeIds(void);
        OpcUaExtensibleParameter& transportSettings(void);
        OpcUaExtensibleParameter& messageSettings(void);
        DataSetWriterDataTypeArray& dataSetWriters(void);
        
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
        
        void copyTo(WriterGroupDataType& value);
        bool operator==(const WriterGroupDataType& value);
        bool operator!=(const WriterGroupDataType& value);
        WriterGroupDataType& operator=(const WriterGroupDataType& value);
    
      private:
        OpcUaUInt16 writerGroupId_;
        OpcUaDuration publishingInterval_;
        OpcUaDuration keepAliveTime_;
        OpcUaByte priority_;
        OpcUaLocaleIdArray localeIds_;
        OpcUaExtensibleParameter transportSettings_;
        OpcUaExtensibleParameter messageSettings_;
        DataSetWriterDataTypeArray dataSetWriters_;
    
    };
    
    class DLLEXPORT WriterGroupDataTypeArray
    : public OpcUaArray<WriterGroupDataType::SPtr, SPtrTypeCoder<WriterGroupDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<WriterGroupDataTypeArray> SPtr;
    };

}

#endif
