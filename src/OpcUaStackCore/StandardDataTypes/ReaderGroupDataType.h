/*
    DataTypeClass: ReaderGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReaderGroupDataType_h__
#define __OpcUaStackCore_ReaderGroupDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
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
