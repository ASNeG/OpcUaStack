/*
    DataTypeClass: ObjectAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ObjectAttributes_h__
#define __OpcUaStackCore_ObjectAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ObjectAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<ObjectAttributes> SPtr;
        typedef std::vector<ObjectAttributes::SPtr> Vec;
    
        ObjectAttributes(void);
        ObjectAttributes(const ObjectAttributes& value);
        virtual ~ObjectAttributes(void);
        
        OpcUaByte& eventNotifier(void);
        
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
        
        void copyTo(ObjectAttributes& value);
        bool operator==(const ObjectAttributes& value);
        bool operator!=(const ObjectAttributes& value);
        ObjectAttributes& operator=(const ObjectAttributes& value);
    
      private:
        OpcUaByte eventNotifier_; //!< A mask indicating what events are produced by the object.
    
    };
    
    class DLLEXPORT ObjectAttributesArray
    : public OpcUaArray<ObjectAttributes::SPtr, SPtrTypeCoder<ObjectAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ObjectAttributesArray> SPtr;
    };

}

#endif
