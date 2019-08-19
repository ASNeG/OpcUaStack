/*
    DataTypeClass: ConfigurationVersionDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ConfigurationVersionDataType_h__
#define __OpcUaStackCore_ConfigurationVersionDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ConfigurationVersionDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ConfigurationVersionDataType> SPtr;
        typedef std::vector<ConfigurationVersionDataType::SPtr> Vec;
    
        ConfigurationVersionDataType(void);
        ConfigurationVersionDataType(const ConfigurationVersionDataType& value);
        virtual ~ConfigurationVersionDataType(void);
        
        OpcUaVersionTime& majorVersion(void);
        OpcUaVersionTime& minorVersion(void);
        
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
        
        void copyTo(ConfigurationVersionDataType& value);
        bool operator==(const ConfigurationVersionDataType& value);
        bool operator!=(const ConfigurationVersionDataType& value);
        ConfigurationVersionDataType& operator=(const ConfigurationVersionDataType& value);
    
      private:
        OpcUaVersionTime majorVersion_;
        OpcUaVersionTime minorVersion_;
    
    };
    
    class DLLEXPORT ConfigurationVersionDataTypeArray
    : public OpcUaArray<ConfigurationVersionDataType::SPtr, SPtrTypeCoder<ConfigurationVersionDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ConfigurationVersionDataTypeArray> SPtr;
    };

}

#endif
