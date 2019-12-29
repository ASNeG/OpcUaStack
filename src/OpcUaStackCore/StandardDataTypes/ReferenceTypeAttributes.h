/*
    DataTypeClass: ReferenceTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReferenceTypeAttributes_h__
#define __OpcUaStackCore_ReferenceTypeAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
