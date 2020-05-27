/*
    EnumTypeClass: SessionState

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionState_h__
#define __OpcUaStackServer_SessionState_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT SessionState
    : public OpcUaStackCore::Object
    , public OpcUaStackCore::ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SessionState> SPtr;
    
        typedef enum {
            EnumCreate = 0,
            EnumActive = 1,
            EnumClose = 2,
        } Enum;
    
        SessionState(void);
        SessionState(Enum enumeration);
        SessionState(SessionState& value);
        virtual ~SessionState(void);
        
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
        virtual OpcUaStackCore::ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaStackCore::OpcUaNodeId typeId(void) override;
        virtual OpcUaStackCore::OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaStackCore::OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaStackCore::OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) override;
        virtual void copyTo(OpcUaStackCore::ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(OpcUaStackCore::ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
        void copyTo(SessionState& value);
        bool operator==(const SessionState& value) const;
        bool operator!=(const SessionState& value) const;
        SessionState& operator=(const SessionState& value);
        SessionState& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };
    
    class DLLEXPORT SessionStateArray
    : public OpcUaStackCore::OpcUaArray<SessionState::SPtr, OpcUaStackCore::SPtrTypeCoder<SessionState> >
    , public OpcUaStackCore::Object
    {
      public:
    	   typedef boost::shared_ptr<SessionStateArray> SPtr;
    };

}

#endif
