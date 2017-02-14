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

#ifndef __OpcUaStackCore_RegisteredServerResponse_h__
#define __OpcUaStackCore_RegisteredServerResponse_h__

#include <stdint.h>
#include <vector>
#include <map>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisteredServer
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<RegisteredServer> SPtr;
		typedef std::map<std::string, RegisteredServer::SPtr> Map;
		typedef std::vector<RegisteredServer::SPtr> Vec;

		RegisteredServer(void);
		virtual ~RegisteredServer(void);

		void serverUri(const OpcUaString& serverUri);
		void serverUri(const std::string& serverUri);
		OpcUaString& serverUri(void);
		void productUri(const OpcUaString& productUri);
		void productUri(const std::string& productUri);
		OpcUaString& productUri(void);
		void serverNames(const OpcUaLocalizedTextArray::SPtr& serverNames);
		OpcUaLocalizedTextArray::SPtr serverNames(void) const;
		void serverType(const ApplicationType serverType);
		ApplicationType serverType(void);
		void gatewayServerUri(const OpcUaString& gatewayServerUri);
		void gatewayServerUri(const std::string& gatewayServerUri);
		OpcUaString& gatewayServerUri(void);
		void discoveryUrls(const OpcUaStringArray::SPtr discoveryUrls);
		OpcUaStringArray::SPtr discoveryUrls(void) const;
		void semaphoreFilePath(const OpcUaString& semaphoreFilePath);
		void semaphoreFilePath(const std::string& semaphoreFilePath);
		OpcUaString& semaphoreFilePath(void);
		void isOnline(const OpcUaBoolean& isOnline);
		OpcUaBoolean isOnline(void);

		void copyTo(RegisteredServer& registeredServer);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString serverUri_;
		OpcUaString productUri_;
		OpcUaLocalizedTextArray::SPtr serverNameArraySPtr_;
		ApplicationType serverType_;
		OpcUaString gatewayServerUri_;
		OpcUaStringArray::SPtr discoveryUrlArraySPtr_;
		OpcUaString semaphoreFilePath_;
		OpcUaBoolean isOnline_;
	};

}

#endif
