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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

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
