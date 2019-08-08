/*
    EnumTypeClass: IdType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_IdType_h__
#define __OpcUaStackCore_IdType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    /**
     * The type of identifier used in a node id.
     */
    class DLLEXPORT IdType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<IdType> SPtr;
    
        typedef enum {
            EnumNumeric = 0,     //!< The identifier is a numeric value. 0 is a null value.
            EnumString = 1,     //!< The identifier is a string value. An empty string is a null value.
            EnumGuid = 2,     //!< The identifier is a 16 byte structure. 16 zero bytes is a null value.
            EnumOpaque = 3,     //!< The identifier is an array of bytes. A zero length array is a null value.
        } Enum;
    
        IdType(void);
        IdType(Enum enumeration);
        IdType(IdType& value);
        virtual ~IdType(void);
        
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
        
        void copyTo(IdType& value);
        bool operator==(const IdType& value) const;
        bool operator!=(const IdType& value) const;
        IdType& operator=(const IdType& value);
        IdType& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT IdTypeArray
    : public OpcUaArray<IdType::SPtr, SPtrTypeCoder<IdType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<IdTypeArray> SPtr;
    };

}

#endif
