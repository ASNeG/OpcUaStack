/*
    DataTypeClass: RolePermissionType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RolePermissionType_h__
#define __OpcUaStackCore_RolePermissionType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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
