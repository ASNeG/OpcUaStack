/*
    EnumTypeClass: NodeAttributesMask

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor:     Kai Huebl (kai@huebl-sgh.de)
    BuildDate: 2018-Oct-25 09:41:46.022527
*/

#ifndef __OpcUaStackCore_NodeAttributesMask_h__
#define __OpcUaStackCore_NodeAttributesMask_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class NodeAttributesMask
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<NodeAttributesMask> SPtr;
    
        typedef enum {
            EnumNone = 0,
            EnumAccessLevel = 1,
            EnumArrayDimensions = 2,
            EnumBrowseName = 4,
            EnumContainsNoLoops = 8,
            EnumDataType = 16,
            EnumDescription = 32,
            EnumDisplayName = 64,
            EnumEventNotifier = 128,
            EnumExecutable = 256,
            EnumHistorizing = 512,
            EnumInverseName = 1024,
            EnumIsAbstract = 2048,
            EnumMinimumSamplingInterval = 4096,
            EnumNodeClass = 8192,
            EnumNodeId = 16384,
            EnumSymmetric = 32768,
            EnumUserAccessLevel = 65536,
            EnumUserExecutable = 131072,
            EnumUserWriteMask = 262144,
            EnumValueRank = 524288,
            EnumWriteMask = 1048576,
            EnumValue = 2097152,
            EnumDataTypeDefinition = 4194304,
            EnumRolePermissions = 8388608,
            EnumAccessRestrictions = 16777216,
            EnumAll = 33554431,
            EnumBaseNode = 26501220,
            EnumObject = 26501348,
            EnumObjectType = 26503268,
            EnumVariable = 26571383,
            EnumVariableType = 28600438,
            EnumMethod = 26632548,
            EnumReferenceType = 26537060,
            EnumView = 26501356,
        } Enum;
    
        NodeAttributesMask(void);
        NodeAttributesMask(Enum enumeration);
        NodeAttributesMask(NodeAttributesMask& value);
        virtual ~NodeAttributesMask(void);
        
        uint32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(NodeAttributesMask& value);
        bool operator==(const NodeAttributesMask& value) const;
        bool operator!=(const NodeAttributesMask& value) const;
    
      private:
        uint32_t value_;
    
    };

}

#endif
