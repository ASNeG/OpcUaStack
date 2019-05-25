/*
    DataTypeClass: DeleteReferencesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DeleteReferencesItem_h__
#define __OpcUaStackCore_DeleteReferencesItem_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

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
