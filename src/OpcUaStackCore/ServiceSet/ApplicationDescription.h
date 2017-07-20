/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ApplicationDescription_h__
#define __OpcUaStackCore_ApplicationDescription_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/ApplicationType.h"

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
		virtual ~ApplicationDescription(void);

		void applicationUri(const std::string& applicationUri);
		std::string applicationUri(void) const;
		OpcUaString& getApplicationUri(void);
		void productUri(const std::string& productUri);
		std::string productUri(void) const;
		OpcUaString& getProductUri(void);
		void applicationName(OpcUaLocalizedText applicationName);
		OpcUaLocalizedText& applicationName(void);
		void applicationType(ApplicationType applicationType);
		ApplicationType applicationType(void) const;
		void gatewayServerUri(const std::string& gatewayServerUri);
		std::string gatewayServerUri(void) const;
		OpcUaString& getGatewayServerUri(void);
		void discoveryProfileUri(const std::string& discoveryProfileUri);
		std::string discoveryProfileUri(void) const;
		OpcUaString& getDiscoveryProfileUri(void);
		void discoveryUrls(OpcUaStringArray::SPtr discoveryUrls);
		OpcUaStringArray::SPtr discoveryUrls(void) const;

		void copyTo(ApplicationDescription& applicationDescription);
		bool operator==(const ApplicationDescription& applicationDescription) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------
		
	  private:
		OpcUaString applicationUri_;
		OpcUaString productUri_;
		OpcUaLocalizedText applicationName_;
		ApplicationType applicationType_;
		OpcUaString gatewayServerUri_;
		OpcUaString discoveryProfileUri_;
		OpcUaStringArray::SPtr discoveryUrls_;
	};

	class ApplicationDescriptionArray
	: public OpcUaArray<ApplicationDescription::SPtr, SPtrTypeCoder<ApplicationDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ApplicationDescriptionArray> SPtr;
	};

}

#endif
