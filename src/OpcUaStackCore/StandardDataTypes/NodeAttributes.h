/*
    DataTypeClass: NodeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
