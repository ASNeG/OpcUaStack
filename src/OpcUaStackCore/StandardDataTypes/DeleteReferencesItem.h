/*
    DataTypeClass: DeleteReferencesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DeleteReferencesItem_h__
#define __OpcUaStackCore_DeleteReferencesItem_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DeleteReferencesItem
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DeleteReferencesItem> SPtr;
        typedef std::vector<DeleteReferencesItem::SPtr> Vec;
    
        DeleteReferencesItem(void);
        DeleteReferencesItem(const DeleteReferencesItem& value);
        virtual ~DeleteReferencesItem(void);
        
        OpcUaNodeId& sourceNodeId(void);
        OpcUaNodeId& referenceTypeId(void);
        OpcUaBoolean& isForward(void);
        OpcUaExpandedNodeId& targetNodeId(void);
        OpcUaBoolean& deleteBidirectional(void);
        
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
        
        void copyTo(DeleteReferencesItem& value);
        bool operator==(const DeleteReferencesItem& value);
        bool operator!=(const DeleteReferencesItem& value);
        DeleteReferencesItem& operator=(const DeleteReferencesItem& value);
    
      private:
        OpcUaNodeId sourceNodeId_; //!< The source of the reference to delete.
        OpcUaNodeId referenceTypeId_; //!< The type of reference to delete.
        OpcUaBoolean isForward_; //!< If TRUE the a forward reference is deleted.
        OpcUaExpandedNodeId targetNodeId_; //!< The target of the reference to delete.
        OpcUaBoolean deleteBidirectional_; //!< If TRUE the reference is deleted in both directions.
    
    };
    
    class DLLEXPORT DeleteReferencesItemArray
    : public OpcUaArray<DeleteReferencesItem::SPtr, SPtrTypeCoder<DeleteReferencesItem> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DeleteReferencesItemArray> SPtr;
    };

}

#endif
