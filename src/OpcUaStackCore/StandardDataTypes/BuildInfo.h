/*
    DataTypeClass: BuildInfo

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BuildInfo_h__
#define __OpcUaStackCore_BuildInfo_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT BuildInfo
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<BuildInfo> SPtr;
        typedef std::vector<BuildInfo::SPtr> Vec;
    
        BuildInfo(void);
        BuildInfo(const BuildInfo& value);
        virtual ~BuildInfo(void);
        
        OpcUaString& productUri(void);
        OpcUaString& manufacturerName(void);
        OpcUaString& productName(void);
        OpcUaString& softwareVersion(void);
        OpcUaString& buildNumber(void);
        OpcUaUtcTime& buildDate(void);
        
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
        
        void copyTo(BuildInfo& value);
        bool operator==(const BuildInfo& value);
        bool operator!=(const BuildInfo& value);
        BuildInfo& operator=(const BuildInfo& value);
    
      private:
        OpcUaString productUri_;
        OpcUaString manufacturerName_;
        OpcUaString productName_;
        OpcUaString softwareVersion_;
        OpcUaString buildNumber_;
        OpcUaUtcTime buildDate_;
    
    };
    
    class DLLEXPORT BuildInfoArray
    : public OpcUaArray<BuildInfo::SPtr, SPtrTypeCoder<BuildInfo> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BuildInfoArray> SPtr;
    };

}

#endif
