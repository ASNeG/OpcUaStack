/*
    DataTypeClass: AddNodesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AddNodesItem_h__
#define __OpcUaStackCore_AddNodesItem_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AddNodesItem
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<AddNodesItem> SPtr;
        typedef std::vector<AddNodesItem::SPtr> Vec;
    
        AddNodesItem(void);
        AddNodesItem(const AddNodesItem& value);
        virtual ~AddNodesItem(void);
        
        OpcUaExpandedNodeId& parentNodeId(void);
        OpcUaNodeId& referenceTypeId(void);
        OpcUaExpandedNodeId& requestedNewNodeId(void);
        OpcUaQualifiedName& browseName(void);
        NodeClass& nodeClass(void);
        OpcUaExtensibleParameter& nodeAttributes(void);
        OpcUaExpandedNodeId& typeDefinition(void);
        
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
        
        void copyTo(AddNodesItem& value);
        bool operator==(const AddNodesItem& value);
        bool operator!=(const AddNodesItem& value);
        AddNodesItem& operator=(const AddNodesItem& value);
    
      private:
        OpcUaExpandedNodeId parentNodeId_; //!< The node id for the parent node.
        OpcUaNodeId referenceTypeId_; //!< The type of reference from the parent to the new node.
        OpcUaExpandedNodeId requestedNewNodeId_; //!< The node id requested by the client. If null the server must provide one.
        OpcUaQualifiedName browseName_; //!< The browse name for the new node.
        NodeClass nodeClass_; //!< The class of the new node.
        OpcUaExtensibleParameter nodeAttributes_; //!< The default attributes for the new node.
        OpcUaExpandedNodeId typeDefinition_; //!< The type definition for the new node.
    
    };
    
    class DLLEXPORT AddNodesItemArray
    : public OpcUaArray<AddNodesItem::SPtr, SPtrTypeCoder<AddNodesItem> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AddNodesItemArray> SPtr;
    };

}

#endif
