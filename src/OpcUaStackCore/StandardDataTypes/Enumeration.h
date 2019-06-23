/*
    EnumTypeClass: Enumeration

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_Enumeration_h__
#define __OpcUaStackCore_Enumeration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class Enumeration
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<Enumeration> SPtr;
    
        typedef enum {
        } Enum;
    
        Enumeration(void);
        Enumeration(Enum enumeration);
        Enumeration(Enumeration& value);
        virtual ~Enumeration(void);
        
        int32_t& value(void);
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
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
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
        
      protected:
         bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override { return false; }
         bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override { return false; }

        void copyTo(Enumeration& value);
        bool operator==(const Enumeration& value) const;
        bool operator!=(const Enumeration& value) const;
        Enumeration& operator=(const Enumeration& value);
        Enumeration& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class EnumerationArray
    : public OpcUaArray<Enumeration::SPtr, SPtrTypeCoder<Enumeration> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EnumerationArray> SPtr;
    };

}

#endif
