/*
    EnumTypeClass: NodeAttributesMask

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_NodeAttributesMask_h__
#define __OpcUaStackCore_NodeAttributesMask_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    /**
     * The bits used to specify default attributes for a new node.
     */
    class DLLEXPORT NodeAttributesMask
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NodeAttributesMask> SPtr;
    
        typedef enum {
            EnumNone = 0,     //!< No attribuites provided.
            EnumAccessLevel = 1,     //!< The access level attribute is specified.
            EnumArrayDimensions = 2,     //!< The array dimensions attribute is specified.
            EnumBrowseName = 4,     //!< The browse name attribute is specified.
            EnumContainsNoLoops = 8,     //!< The contains no loops attribute is specified.
            EnumDataType = 16,     //!< The data type attribute is specified.
            EnumDescription = 32,     //!< The description attribute is specified.
            EnumDisplayName = 64,     //!< The display name attribute is specified.
            EnumEventNotifier = 128,     //!< The event notifier attribute is specified.
            EnumExecutable = 256,     //!< The executable attribute is specified.
            EnumHistorizing = 512,     //!< The historizing attribute is specified.
            EnumInverseName = 1024,     //!< The inverse name attribute is specified.
            EnumIsAbstract = 2048,     //!< The is abstract attribute is specified.
            EnumMinimumSamplingInterval = 4096,     //!< The minimum sampling interval attribute is specified.
            EnumNodeClass = 8192,     //!< The node class attribute is specified.
            EnumNodeId = 16384,     //!< The node id attribute is specified.
            EnumSymmetric = 32768,     //!< The symmetric attribute is specified.
            EnumUserAccessLevel = 65536,     //!< The user access level attribute is specified.
            EnumUserExecutable = 131072,     //!< The user executable attribute is specified.
            EnumUserWriteMask = 262144,     //!< The user write mask attribute is specified.
            EnumValueRank = 524288,     //!< The value rank attribute is specified.
            EnumWriteMask = 1048576,     //!< The write mask attribute is specified.
            EnumValue = 2097152,     //!< The value attribute is specified.
            EnumDataTypeDefinition = 4194304,     //!< The write mask attribute is specified.
            EnumRolePermissions = 8388608,     //!< The write mask attribute is specified.
            EnumAccessRestrictions = 16777216,     //!< The write mask attribute is specified.
            EnumAll = 33554431,     //!< All attributes are specified.
            EnumBaseNode = 26501220,     //!< All base attributes are specified.
            EnumObject = 26501348,     //!< All object attributes are specified.
            EnumObjectType = 26503268,     //!< All object type attributes are specified.
            EnumVariable = 26571383,     //!< All variable attributes are specified.
            EnumVariableType = 28600438,     //!< All variable type attributes are specified.
            EnumMethod = 26632548,     //!< All method attributes are specified.
            EnumReferenceType = 26537060,     //!< All reference type attributes are specified.
            EnumView = 26501356,     //!< All view attributes are specified.
        } Enum;
    
        NodeAttributesMask(void);
        NodeAttributesMask(Enum enumeration);
        NodeAttributesMask(NodeAttributesMask& value);
        virtual ~NodeAttributesMask(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        static Enum str2Enum(const std::string& enumerationString);
        static std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        static bool exist(const std::string& enumerationString);
        static bool exist(Enum enumeration);
        
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
        
        void copyTo(NodeAttributesMask& value);
        bool operator==(const NodeAttributesMask& value) const;
        bool operator!=(const NodeAttributesMask& value) const;
        NodeAttributesMask& operator=(const NodeAttributesMask& value);
        NodeAttributesMask& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT NodeAttributesMaskArray
    : public OpcUaArray<NodeAttributesMask::SPtr, SPtrTypeCoder<NodeAttributesMask> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<NodeAttributesMaskArray> SPtr;
    };

}

#endif
