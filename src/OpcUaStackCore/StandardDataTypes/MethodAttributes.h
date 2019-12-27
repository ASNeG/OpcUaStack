/*
    DataTypeClass: MethodAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_MethodAttributes_h__
#define __OpcUaStackCore_MethodAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
