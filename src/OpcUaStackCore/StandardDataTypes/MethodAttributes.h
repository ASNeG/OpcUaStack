/*
    DataTypeClass: MethodAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MethodAttributes_h__
#define __OpcUaStackCore_MethodAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT MethodAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<MethodAttributes> SPtr;
        typedef std::vector<MethodAttributes::SPtr> Vec;
    
        MethodAttributes(void);
        MethodAttributes(const MethodAttributes& value);
        virtual ~MethodAttributes(void);
        
        OpcUaBoolean& executable(void);
        OpcUaBoolean& userExecutable(void);
        
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
        
        void copyTo(MethodAttributes& value);
        bool operator==(const MethodAttributes& value);
        bool operator!=(const MethodAttributes& value);
        MethodAttributes& operator=(const MethodAttributes& value);
    
      private:
        OpcUaBoolean executable_; //!< If TRUE the method can be called.
        OpcUaBoolean userExecutable_; //!< If TRUE the method can be called by the current user.
    
    };
    
    class DLLEXPORT MethodAttributesArray
    : public OpcUaArray<MethodAttributes::SPtr, SPtrTypeCoder<MethodAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<MethodAttributesArray> SPtr;
    };

}

#endif
