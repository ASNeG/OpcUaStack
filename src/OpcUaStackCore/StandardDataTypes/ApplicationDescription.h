/*
    DataTypeClass: ApplicationDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ApplicationDescription_h__
#define __OpcUaStackCore_ApplicationDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ApplicationDescription
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ApplicationDescription> SPtr;
        typedef std::vector<ApplicationDescription::SPtr> Vec;
    
        ApplicationDescription(void);
        ApplicationDescription(const ApplicationDescription& value);
        virtual ~ApplicationDescription(void);
        
        OpcUaString& applicationUri(void);
        OpcUaString& productUri(void);
        OpcUaLocalizedText& applicationName(void);
        ApplicationType& applicationType(void);
        OpcUaString& gatewayServerUri(void);
        OpcUaString& discoveryProfileUri(void);
        OpcUaStringArray& discoveryUrls(void);
        
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
        
        void copyTo(ApplicationDescription& value);
        bool operator==(const ApplicationDescription& value);
        bool operator!=(const ApplicationDescription& value);
        ApplicationDescription& operator=(const ApplicationDescription& value);
    
      private:
        OpcUaString applicationUri_; //!< The globally unique identifier for the application.
        OpcUaString productUri_; //!< The globally unique identifier for the product.
        OpcUaLocalizedText applicationName_; //!< The name of application.
        ApplicationType applicationType_; //!< The type of application.
        OpcUaString gatewayServerUri_; //!< The globally unique identifier for the server that is acting as a gateway for the server.
        OpcUaString discoveryProfileUri_; //!< The globally unique identifier for the discovery profile supported by the server.
        OpcUaStringArray discoveryUrls_; //!< The URLs for the server's discovery endpoints.
    
    };
    
    class DLLEXPORT ApplicationDescriptionArray
    : public OpcUaArray<ApplicationDescription::SPtr, SPtrTypeCoder<ApplicationDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ApplicationDescriptionArray> SPtr;
    };

}

#endif
