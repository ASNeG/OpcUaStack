/*
    DataTypeClass: AddReferencesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AddReferencesItem_h__
#define __OpcUaStackCore_AddReferencesItem_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AddReferencesItem
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<AddReferencesItem> SPtr;
        typedef std::vector<AddReferencesItem::SPtr> Vec;
    
        AddReferencesItem(void);
        AddReferencesItem(const AddReferencesItem& value);
        virtual ~AddReferencesItem(void);
        
        OpcUaNodeId& sourceNodeId(void);
        OpcUaNodeId& referenceTypeId(void);
        OpcUaBoolean& isForward(void);
        OpcUaString& targetServerUri(void);
        OpcUaExpandedNodeId& targetNodeId(void);
        NodeClass& targetNodeClass(void);
        
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
        
        void copyTo(AddReferencesItem& value);
        bool operator==(const AddReferencesItem& value);
        bool operator!=(const AddReferencesItem& value);
        AddReferencesItem& operator=(const AddReferencesItem& value);
    
      private:
        OpcUaNodeId sourceNodeId_; //!< The source of the reference.
        OpcUaNodeId referenceTypeId_; //!< The type of reference.
        OpcUaBoolean isForward_; //!< If TRUE the reference is a forward reference.
        OpcUaString targetServerUri_; //!< The URI of the server containing the target (if in another server).
        OpcUaExpandedNodeId targetNodeId_; //!< The target of the reference.
        NodeClass targetNodeClass_; //!< The node class of the target (if known).
    
    };
    
    class DLLEXPORT AddReferencesItemArray
    : public OpcUaArray<AddReferencesItem::SPtr, SPtrTypeCoder<AddReferencesItem> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AddReferencesItemArray> SPtr;
    };

}

#endif
