/*
    DataTypeClass: WriterGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_WriterGroupDataType_h__
#define __OpcUaStackCore_WriterGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
