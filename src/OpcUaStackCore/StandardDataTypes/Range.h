/*
    DataTypeClass: Range

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_Range_h__
#define __OpcUaStackCore_Range_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT Range
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<Range> SPtr;
        typedef std::vector<Range::SPtr> Vec;
    
        Range(void);
        Range(const Range& value);
        virtual ~Range(void);
        
        OpcUaDouble& low(void);
        OpcUaDouble& high(void);
        
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
        
        void copyTo(Range& value);
        bool operator==(const Range& value);
        bool operator!=(const Range& value);
        Range& operator=(const Range& value);
    
      private:
        OpcUaDouble low_;
        OpcUaDouble high_;
    
    };
    
    class DLLEXPORT RangeArray
    : public OpcUaArray<Range::SPtr, SPtrTypeCoder<Range> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RangeArray> SPtr;
    };

}

#endif
