/*
    EnumTypeClass: ApplicationType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ApplicationType_h__
#define __OpcUaStackCore_ApplicationType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    /**
     * The types of applications.
     */
    class DLLEXPORT ApplicationType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ApplicationType> SPtr;
    
        typedef enum {
            EnumServer = 0,     //!< The application is a server.
            EnumClient = 1,     //!< The application is a client.
            EnumClientAndServer = 2,     //!< The application is a client and a server.
            EnumDiscoveryServer = 3,     //!< The application is a discovery server.
        } Enum;
    
        ApplicationType(void);
        ApplicationType(Enum enumeration);
        ApplicationType(ApplicationType& value);
        virtual ~ApplicationType(void);
        
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
        
        void copyTo(ApplicationType& value);
        bool operator==(const ApplicationType& value) const;
        bool operator!=(const ApplicationType& value) const;
        ApplicationType& operator=(const ApplicationType& value);
        ApplicationType& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT ApplicationTypeArray
    : public OpcUaArray<ApplicationType::SPtr, SPtrTypeCoder<ApplicationType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ApplicationTypeArray> SPtr;
    };

}

#endif
