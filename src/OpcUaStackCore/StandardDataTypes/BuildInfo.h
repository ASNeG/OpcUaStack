/*
    DataTypeClass: BuildInfo

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_BuildInfo_h__
#define __OpcUaStackCore_BuildInfo_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class BuildInfo
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<BuildInfo> SPtr;
    
        BuildInfo(void);
        virtual ~BuildInfo(void);
        
        OpcUaString& productUri(void);
        OpcUaString& manufacturerName(void);
        OpcUaString& productName(void);
        OpcUaString& softwareVersion(void);
        OpcUaString& buildNumber(void);
        OpcUaUtcTime& buildDate(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(BuildInfo& value);
        bool operator==(const BuildInfo& value) const;
        bool operator!=(const BuildInfo& value) const;
        BuildInfo& operator=(const BuildInfo& value);
    
      private:
        OpcUaString productUri_;
        OpcUaString manufacturerName_;
        OpcUaString productName_;
        OpcUaString softwareVersion_;
        OpcUaString buildNumber_;
        OpcUaUtcTime buildDate_;
    
    };
    
    class BuildInfoArray
    : public OpcUaArray<BuildInfo::SPtr, SPtrTypeCoder<BuildInfo> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<BuildInfoArray> SPtr;
    };

}

#endif
