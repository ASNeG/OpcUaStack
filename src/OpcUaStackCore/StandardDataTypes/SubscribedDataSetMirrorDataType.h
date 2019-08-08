/*
    DataTypeClass: SubscribedDataSetMirrorDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SubscribedDataSetMirrorDataType_h__
#define __OpcUaStackCore_SubscribedDataSetMirrorDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/SubscribedDataSetDataType.h"
#include "OpcUaStackCore/StandardDataTypes/RolePermissionType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SubscribedDataSetMirrorDataType
    : public SubscribedDataSetDataType
    {
      public:
        typedef boost::shared_ptr<SubscribedDataSetMirrorDataType> SPtr;
        typedef std::vector<SubscribedDataSetMirrorDataType::SPtr> Vec;
    
        SubscribedDataSetMirrorDataType(void);
        SubscribedDataSetMirrorDataType(const SubscribedDataSetMirrorDataType& value);
        virtual ~SubscribedDataSetMirrorDataType(void);
        
        OpcUaString& parentNodeName(void);
        RolePermissionTypeArray& rolePermissions(void);
        
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
        
        void copyTo(SubscribedDataSetMirrorDataType& value);
        bool operator==(const SubscribedDataSetMirrorDataType& value);
        bool operator!=(const SubscribedDataSetMirrorDataType& value);
        SubscribedDataSetMirrorDataType& operator=(const SubscribedDataSetMirrorDataType& value);
    
      private:
        OpcUaString parentNodeName_;
        RolePermissionTypeArray rolePermissions_;
    
    };
    
    class DLLEXPORT SubscribedDataSetMirrorDataTypeArray
    : public OpcUaArray<SubscribedDataSetMirrorDataType::SPtr, SPtrTypeCoder<SubscribedDataSetMirrorDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SubscribedDataSetMirrorDataTypeArray> SPtr;
    };

}

#endif
