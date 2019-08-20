/*
    DataTypeClass: DataTypeDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataTypeDescription_h__
#define __OpcUaStackCore_DataTypeDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataTypeDescription
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DataTypeDescription> SPtr;
        typedef std::vector<DataTypeDescription::SPtr> Vec;
    
        DataTypeDescription(void);
        DataTypeDescription(const DataTypeDescription& value);
        virtual ~DataTypeDescription(void);
        
        OpcUaNodeId& dataTypeId(void);
        OpcUaQualifiedName& name(void);
        
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
        
        void copyTo(DataTypeDescription& value);
        bool operator==(const DataTypeDescription& value);
        bool operator!=(const DataTypeDescription& value);
        DataTypeDescription& operator=(const DataTypeDescription& value);
    
      private:
        OpcUaNodeId dataTypeId_;
        OpcUaQualifiedName name_;
    
    };
    
    class DLLEXPORT DataTypeDescriptionArray
    : public OpcUaArray<DataTypeDescription::SPtr, SPtrTypeCoder<DataTypeDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataTypeDescriptionArray> SPtr;
    };

}

#endif
