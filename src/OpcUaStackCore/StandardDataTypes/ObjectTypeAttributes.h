/*
    DataTypeClass: ObjectTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ObjectTypeAttributes_h__
#define __OpcUaStackCore_ObjectTypeAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ObjectTypeAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<ObjectTypeAttributes> SPtr;
        typedef std::vector<ObjectTypeAttributes::SPtr> Vec;
    
        ObjectTypeAttributes(void);
        ObjectTypeAttributes(const ObjectTypeAttributes& value);
        virtual ~ObjectTypeAttributes(void);
        
        OpcUaBoolean& isAbstract(void);
        
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
        
        void copyTo(ObjectTypeAttributes& value);
        bool operator==(const ObjectTypeAttributes& value);
        bool operator!=(const ObjectTypeAttributes& value);
        ObjectTypeAttributes& operator=(const ObjectTypeAttributes& value);
    
      private:
        OpcUaBoolean isAbstract_; //!< If TRUE the type is abstract and only subtypes of it appear in the address space.
    
    };
    
    class DLLEXPORT ObjectTypeAttributesArray
    : public OpcUaArray<ObjectTypeAttributes::SPtr, SPtrTypeCoder<ObjectTypeAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ObjectTypeAttributesArray> SPtr;
    };

}

#endif
