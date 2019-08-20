/*
    DataTypeClass: WriterGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_WriterGroupMessageDataType_h__
#define __OpcUaStackCore_WriterGroupMessageDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT WriterGroupMessageDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<WriterGroupMessageDataType> SPtr;
        typedef std::vector<WriterGroupMessageDataType::SPtr> Vec;
    
        WriterGroupMessageDataType(void);
        WriterGroupMessageDataType(const WriterGroupMessageDataType& value);
        virtual ~WriterGroupMessageDataType(void);
        
        
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
        
        void copyTo(WriterGroupMessageDataType& value);
        bool operator==(const WriterGroupMessageDataType& value);
        bool operator!=(const WriterGroupMessageDataType& value);
        WriterGroupMessageDataType& operator=(const WriterGroupMessageDataType& value);
    
      private:
    
    };
    
    class DLLEXPORT WriterGroupMessageDataTypeArray
    : public OpcUaArray<WriterGroupMessageDataType::SPtr, SPtrTypeCoder<WriterGroupMessageDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<WriterGroupMessageDataTypeArray> SPtr;
    };

}

#endif
