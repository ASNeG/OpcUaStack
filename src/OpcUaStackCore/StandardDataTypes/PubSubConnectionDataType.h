/*
    DataTypeClass: PubSubConnectionDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_PubSubConnectionDataType_h__
#define __OpcUaStackCore_PubSubConnectionDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/StandardDataTypes/KeyValuePair.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/StandardDataTypes/WriterGroupDataType.h"
#include "OpcUaStackCore/StandardDataTypes/ReaderGroupDataType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT PubSubConnectionDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<PubSubConnectionDataType> SPtr;
        typedef std::vector<PubSubConnectionDataType::SPtr> Vec;
    
        PubSubConnectionDataType(void);
        PubSubConnectionDataType(const PubSubConnectionDataType& value);
        virtual ~PubSubConnectionDataType(void);
        
        OpcUaString& name(void);
        OpcUaBoolean& enabled(void);
        OpcUaVariant& publisherId(void);
        OpcUaString& transportProfileUri(void);
        OpcUaExtensibleParameter& address(void);
        KeyValuePairArray& connectionProperties(void);
        OpcUaExtensibleParameter& transportSettings(void);
        WriterGroupDataTypeArray& writerGroups(void);
        ReaderGroupDataTypeArray& readerGroups(void);
        
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
        
        void copyTo(PubSubConnectionDataType& value);
        bool operator==(const PubSubConnectionDataType& value);
        bool operator!=(const PubSubConnectionDataType& value);
        PubSubConnectionDataType& operator=(const PubSubConnectionDataType& value);
    
      private:
        OpcUaString name_;
        OpcUaBoolean enabled_;
        OpcUaVariant publisherId_;
        OpcUaString transportProfileUri_;
        OpcUaExtensibleParameter address_;
        KeyValuePairArray connectionProperties_;
        OpcUaExtensibleParameter transportSettings_;
        WriterGroupDataTypeArray writerGroups_;
        ReaderGroupDataTypeArray readerGroups_;
    
    };
    
    class DLLEXPORT PubSubConnectionDataTypeArray
    : public OpcUaArray<PubSubConnectionDataType::SPtr, SPtrTypeCoder<PubSubConnectionDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<PubSubConnectionDataTypeArray> SPtr;
    };

}

#endif
