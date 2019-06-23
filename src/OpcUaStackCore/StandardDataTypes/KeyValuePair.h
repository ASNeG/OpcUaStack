/*
    DataTypeClass: KeyValuePair

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_KeyValuePair_h__
#define __OpcUaStackCore_KeyValuePair_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT KeyValuePair
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<KeyValuePair> SPtr;
        typedef std::vector<KeyValuePair::SPtr> Vec;
    
        KeyValuePair(void);
        KeyValuePair(const KeyValuePair& value);
        virtual ~KeyValuePair(void);
        
        OpcUaQualifiedName& key(void);
        OpcUaVariant& value(void);
        
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
        
        void copyTo(KeyValuePair& value);
        bool operator==(const KeyValuePair& value);
        bool operator!=(const KeyValuePair& value);
        KeyValuePair& operator=(const KeyValuePair& value);
    
      private:
        OpcUaQualifiedName key_;
        OpcUaVariant value_;
    
    };
    
    class DLLEXPORT KeyValuePairArray
    : public OpcUaArray<KeyValuePair::SPtr, SPtrTypeCoder<KeyValuePair> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<KeyValuePairArray> SPtr;
    };

}

#endif
