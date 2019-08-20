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
