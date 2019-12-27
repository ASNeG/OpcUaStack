/*
    DataTypeClass: EUInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_EUInformation_h__
#define __OpcUaStackCore_EUInformation_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT EUInformation
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<EUInformation> SPtr;
        typedef std::vector<EUInformation::SPtr> Vec;
    
        EUInformation(void);
        EUInformation(const EUInformation& value);
        virtual ~EUInformation(void);
        
        OpcUaString& namespaceUri(void);
        OpcUaInt32& unitId(void);
        OpcUaLocalizedText& displayName(void);
        OpcUaLocalizedText& description(void);
        
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
        
        void copyTo(EUInformation& value);
        bool operator==(const EUInformation& value);
        bool operator!=(const EUInformation& value);
        EUInformation& operator=(const EUInformation& value);
    
      private:
        OpcUaString namespaceUri_;
        OpcUaInt32 unitId_;
        OpcUaLocalizedText displayName_;
        OpcUaLocalizedText description_;
    
    };
    
    class DLLEXPORT EUInformationArray
    : public OpcUaArray<EUInformation::SPtr, SPtrTypeCoder<EUInformation> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<EUInformationArray> SPtr;
    };

}

#endif
