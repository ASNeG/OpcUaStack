/*
    DataTypeClass: SimpleTypeDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SimpleTypeDescription_h__
#define __OpcUaStackCore_SimpleTypeDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDescription.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SimpleTypeDescription
    : public DataTypeDescription
    {
      public:
        typedef boost::shared_ptr<SimpleTypeDescription> SPtr;
        typedef std::vector<SimpleTypeDescription::SPtr> Vec;
    
        SimpleTypeDescription(void);
        SimpleTypeDescription(const SimpleTypeDescription& value);
        virtual ~SimpleTypeDescription(void);
        
        OpcUaNodeId& baseDataType(void);
        OpcUaByte& builtInType(void);
        
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
        
        void copyTo(SimpleTypeDescription& value);
        bool operator==(const SimpleTypeDescription& value);
        bool operator!=(const SimpleTypeDescription& value);
        SimpleTypeDescription& operator=(const SimpleTypeDescription& value);
    
      private:
        OpcUaNodeId baseDataType_;
        OpcUaByte builtInType_;
    
    };
    
    class DLLEXPORT SimpleTypeDescriptionArray
    : public OpcUaArray<SimpleTypeDescription::SPtr, SPtrTypeCoder<SimpleTypeDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SimpleTypeDescriptionArray> SPtr;
    };

}

#endif
