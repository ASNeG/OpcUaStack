/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	typedef enum {
		ApplicationType_Server = 0,
		ApplicationType_Client = 1,
		ApplicationType_ClientAndServer = 3,
		ApplicationType_DiscoveryServer = 4
	} ApplicationType;

	class DLLEXPORT ApplicationDescription : public  ObjectPool<ApplicationDescription>
	{
	  public:
		typedef boost::shared_ptr<ApplicationDescription> SPtr;

		ApplicationDescription(void);
		virtual ~ApplicationDescription(void);

		void applicationUri(const std::string& applicationUri);
		std::string applicationUri(void) const;
		void productUri(const std::string& productUri);
		std::string productUri(void) const;
		OpcUaLocalizedText& applicationName(void);
		void applicationType(ApplicationType applicationType);
		ApplicationType applicationType(void) const;
		void gatewayServerUri(const std::string& gatewayServerUri);
		std::string gatewayServerUri(void) const;
		void discoveryProfileUri(const std::string& discoveryProfileUri);
		std::string discoveryProfileUri(void) const;
		void discoveryUrls(OpcUaStringArray::SPtr discoveryUrls);
		OpcUaStringArray::SPtr discoveryUrls(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		OpcUaString applicationUri_;
		OpcUaString productUri_;
		OpcUaLocalizedText applicationName_;
		ApplicationType applicationType_;
		OpcUaString gatewayServerUri_;
		OpcUaString discoveryProfileUri_;
		OpcUaStringArray::SPtr discoveryUrls_;
	};

	class ApplicationDescriptionArray : public OpcUaArray<ApplicationDescription::SPtr, SPtrTypeCoder<ApplicationDescription> >, public ObjectPool<ApplicationDescriptionArray> 
	{
	  public:
		typedef boost::shared_ptr<ApplicationDescriptionArray> SPtr;
	};

}

#endif
