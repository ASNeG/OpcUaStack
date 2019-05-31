/*
    DataTypeClass: AggregateConfiguration

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AggregateConfiguration_h__
#define __OpcUaStackCore_AggregateConfiguration_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AggregateConfiguration
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<AggregateConfiguration> SPtr;
        typedef std::vector<AggregateConfiguration::SPtr> Vec;
    
        AggregateConfiguration(void);
        AggregateConfiguration(const AggregateConfiguration& value);
        virtual ~AggregateConfiguration(void);
        
        OpcUaBoolean& useServerCapabilitiesDefaults(void);
        OpcUaBoolean& treatUncertainAsBad(void);
        OpcUaByte& percentDataBad(void);
        OpcUaByte& percentDataGood(void);
        OpcUaBoolean& useSlopedExtrapolation(void);
        
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
        
        void copyTo(AggregateConfiguration& value);
        bool operator==(const AggregateConfiguration& value);
        bool operator!=(const AggregateConfiguration& value);
        AggregateConfiguration& operator=(const AggregateConfiguration& value);
    
      private:
        OpcUaBoolean useServerCapabilitiesDefaults_;
        OpcUaBoolean treatUncertainAsBad_;
        OpcUaByte percentDataBad_;
        OpcUaByte percentDataGood_;
        OpcUaBoolean useSlopedExtrapolation_;
    
    };
    
    class DLLEXPORT AggregateConfigurationArray
    : public OpcUaArray<AggregateConfiguration::SPtr, SPtrTypeCoder<AggregateConfiguration> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AggregateConfigurationArray> SPtr;
    };

}

#endif
