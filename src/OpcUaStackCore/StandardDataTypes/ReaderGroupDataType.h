/*
    DataTypeClass: ReaderGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReaderGroupDataType_h__
#define __OpcUaStackCore_ReaderGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/PubSubGroupDataType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/StandardDataTypes/DataSetReaderDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReaderGroupDataType
    : public PubSubGroupDataType
    {
      public:
        typedef boost::shared_ptr<ReaderGroupDataType> SPtr;
        typedef std::vector<ReaderGroupDataType::SPtr> Vec;
    
        ReaderGroupDataType(void);
        ReaderGroupDataType(const ReaderGroupDataType& value);
        virtual ~ReaderGroupDataType(void);
        
        OpcUaExtensibleParameter& transportSettings(void);
        OpcUaExtensibleParameter& messageSettings(void);
        DataSetReaderDataTypeArray& dataSetReaders(void);
        
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
        
        void copyTo(ReaderGroupDataType& value);
        bool operator==(const ReaderGroupDataType& value);
        bool operator!=(const ReaderGroupDataType& value);
        ReaderGroupDataType& operator=(const ReaderGroupDataType& value);
    
      private:
        OpcUaExtensibleParameter transportSettings_;
        OpcUaExtensibleParameter messageSettings_;
        DataSetReaderDataTypeArray dataSetReaders_;
    
    };
    
    class DLLEXPORT ReaderGroupDataTypeArray
    : public OpcUaArray<ReaderGroupDataType::SPtr, SPtrTypeCoder<ReaderGroupDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReaderGroupDataTypeArray> SPtr;
    };

}

#endif
