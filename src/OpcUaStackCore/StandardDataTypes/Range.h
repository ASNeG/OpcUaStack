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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"

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
