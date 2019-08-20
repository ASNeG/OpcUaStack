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
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

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
