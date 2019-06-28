/*
    DataTypeClass: NodeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NodeAttributes_h__
#define __OpcUaStackCore_NodeAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT NodeAttributes
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NodeAttributes> SPtr;
        typedef std::vector<NodeAttributes::SPtr> Vec;
    
        NodeAttributes(void);
        NodeAttributes(const NodeAttributes& value);
        virtual ~NodeAttributes(void);
        
        OpcUaUInt32& specifiedAttributes(void);
        OpcUaLocalizedText& displayName(void);
        OpcUaLocalizedText& description(void);
        OpcUaUInt32& writeMask(void);
        OpcUaUInt32& userWriteMask(void);
        
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
        
        void copyTo(NodeAttributes& value);
        bool operator==(const NodeAttributes& value);
        bool operator!=(const NodeAttributes& value);
        NodeAttributes& operator=(const NodeAttributes& value);
    
      private:
        OpcUaUInt32 specifiedAttributes_; //!< A mask indicating which attributes have been provided.
        OpcUaLocalizedText displayName_; //!< A human readable name for the node.
        OpcUaLocalizedText description_; //!< A description for the node.
        OpcUaUInt32 writeMask_; //!< A mask which specifies which attributes are writable.
        OpcUaUInt32 userWriteMask_; //!< A mask which specifies which attributes are writable by the current user.
    
    };
    
    class DLLEXPORT NodeAttributesArray
    : public OpcUaArray<NodeAttributes::SPtr, SPtrTypeCoder<NodeAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NodeAttributesArray> SPtr;
    };

}

#endif
