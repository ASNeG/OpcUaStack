/*
    DataTypeClass: ReferenceTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReferenceTypeAttributes_h__
#define __OpcUaStackCore_ReferenceTypeAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReferenceTypeAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<ReferenceTypeAttributes> SPtr;
        typedef std::vector<ReferenceTypeAttributes::SPtr> Vec;
    
        ReferenceTypeAttributes(void);
        ReferenceTypeAttributes(const ReferenceTypeAttributes& value);
        virtual ~ReferenceTypeAttributes(void);
        
        OpcUaBoolean& isAbstract(void);
        OpcUaBoolean& symmetric(void);
        OpcUaLocalizedText& inverseName(void);
        
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
        
        void copyTo(ReferenceTypeAttributes& value);
        bool operator==(const ReferenceTypeAttributes& value);
        bool operator!=(const ReferenceTypeAttributes& value);
        ReferenceTypeAttributes& operator=(const ReferenceTypeAttributes& value);
    
      private:
        OpcUaBoolean isAbstract_; //!< If TRUE the type is abstract and only subtypes of it appear in the address space.
        OpcUaBoolean symmetric_; //!< If TRUE the reference type has the same semantics in both directions.
        OpcUaLocalizedText inverseName_; //!< The display name for the reference when following it from target to source.
    
    };
    
    class DLLEXPORT ReferenceTypeAttributesArray
    : public OpcUaArray<ReferenceTypeAttributes::SPtr, SPtrTypeCoder<ReferenceTypeAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReferenceTypeAttributesArray> SPtr;
    };

}

#endif
