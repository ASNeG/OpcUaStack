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
