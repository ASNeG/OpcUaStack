/*
    EnumTypeClass: RedundancySupport

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_RedundancySupport_h__
#define __OpcUaStackCore_RedundancySupport_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT RedundancySupport
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<RedundancySupport> SPtr;
    
        typedef enum {
            EnumNone = 0,
            EnumCold = 1,
            EnumWarm = 2,
            EnumHot = 3,
            EnumTransparent = 4,
            EnumHotAndMirrored = 5,
        } Enum;
    
        RedundancySupport(void);
        RedundancySupport(Enum enumeration);
        RedundancySupport(RedundancySupport& value);
        virtual ~RedundancySupport(void);
        
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
        
        void copyTo(RedundancySupport& value);
        bool operator==(const RedundancySupport& value) const;
        bool operator!=(const RedundancySupport& value) const;
        RedundancySupport& operator=(const RedundancySupport& value);
        RedundancySupport& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT RedundancySupportArray
    : public OpcUaArray<RedundancySupport::SPtr, SPtrTypeCoder<RedundancySupport> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<RedundancySupportArray> SPtr;
    };

}

#endif
