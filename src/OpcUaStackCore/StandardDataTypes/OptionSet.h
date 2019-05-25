/*
    DataTypeClass: OptionSet

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_OptionSet_h__
#define __OpcUaStackCore_OptionSet_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT OptionSet
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<OptionSet> SPtr;
        typedef std::vector<OptionSet::SPtr> Vec;
    
        OptionSet(void);
        OptionSet(const OptionSet& value);
        virtual ~OptionSet(void);
        
        OpcUaByteString& value(void);
        OpcUaByteString& validBits(void);
        
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
        
        void copyTo(OptionSet& value);
        bool operator==(const OptionSet& value);
        bool operator!=(const OptionSet& value);
        OptionSet& operator=(const OptionSet& value);
    
      private:
        OpcUaByteString value_; //!< Array of bytes representing the bits in the option set.
        OpcUaByteString validBits_; //!< Array of bytes with same size as value representing the valid bits in the value parameter.
    
    };
    
    class DLLEXPORT OptionSetArray
    : public OpcUaArray<OptionSet::SPtr, SPtrTypeCoder<OptionSet> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<OptionSetArray> SPtr;
    };

}

#endif
