/*
    DataTypeClass: DeleteNodesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DeleteNodesItem_h__
#define __OpcUaStackCore_DeleteNodesItem_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DeleteNodesItem
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DeleteNodesItem> SPtr;
        typedef std::vector<DeleteNodesItem::SPtr> Vec;
    
        DeleteNodesItem(void);
        DeleteNodesItem(const DeleteNodesItem& value);
        virtual ~DeleteNodesItem(void);
        
        OpcUaNodeId& nodeId(void);
        OpcUaBoolean& deleteTargetReferences(void);
        
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
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(DeleteNodesItem& value);
        bool operator==(const DeleteNodesItem& value);
        bool operator!=(const DeleteNodesItem& value);
        DeleteNodesItem& operator=(const DeleteNodesItem& value);
    
      private:
        OpcUaNodeId nodeId_; //!< The id of the node to delete.
        OpcUaBoolean deleteTargetReferences_; //!< If TRUE all references to the are deleted as well.
    
    };
    
    class DLLEXPORT DeleteNodesItemArray
    : public OpcUaArray<DeleteNodesItem::SPtr, SPtrTypeCoder<DeleteNodesItem> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DeleteNodesItemArray> SPtr;
    };

}

#endif
