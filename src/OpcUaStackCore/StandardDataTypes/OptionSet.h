/*
    DataTypeClass: OptionSet

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_OptionSet_h__
#define __OpcUaStackCore_OptionSet_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

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
