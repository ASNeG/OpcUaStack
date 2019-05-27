/*
    DataTypeClass: RolePermissionType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RolePermissionType_h__
#define __OpcUaStackCore_RolePermissionType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RolePermissionType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<RolePermissionType> SPtr;
        typedef std::vector<RolePermissionType::SPtr> Vec;
    
        RolePermissionType(void);
        RolePermissionType(const RolePermissionType& value);
        virtual ~RolePermissionType(void);
        
        OpcUaNodeId& roleId(void);
        OpcUaPermissionType& permissions(void);
        
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
        
        void copyTo(RolePermissionType& value);
        bool operator==(const RolePermissionType& value);
        bool operator!=(const RolePermissionType& value);
        RolePermissionType& operator=(const RolePermissionType& value);
    
      private:
        OpcUaNodeId roleId_;
        OpcUaPermissionType permissions_;
    
    };
    
    class DLLEXPORT RolePermissionTypeArray
    : public OpcUaArray<RolePermissionType::SPtr, SPtrTypeCoder<RolePermissionType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RolePermissionTypeArray> SPtr;
    };

}

#endif
