/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ServerInfo_h__
#define __OpcUaStackServer_ServerInfo_h__

#include <boost/shared_ptr.hpp>
#include <string>
#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServerInfo
	{
	  public:
		typedef boost::shared_ptr<ServerInfo> SPtr;

		ServerInfo(void);
	    ~ServerInfo(void);

	    bool parse(OpcUaStackCore::Config* cfg, const std::string& prefix);

	    void serverUri(const std::string& serverUri);
	    std::string& serverUri(void);
	    void serverName(const std::string& serverName);
	    std::string& serverName(void);

	  private:
	    std::string serverUri_;
	    std::string serverName_;
	};

}

#endif
