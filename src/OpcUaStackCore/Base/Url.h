/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Url_h__
#define __OpcUaStackCore_Url_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>
#include <stdint.h>

namespace OpcUaStackCore
{

	class DLLEXPORT Url
	{
	  public:
		Url(void);
		Url(const std::string& url);
		~Url(void);

		void url(const std::string& url);
		std::string url(void);

		bool good(void);
		std::string protocol(void) const;
		void protocol(const std::string& protocol);
		std::string host(void);
		void host(const std::string& host);
		int32_t port(void);
		void port(int32_t port);
		std::string portToString(void);
		std::string path(void);
		void path(const std::string& path);
		std::string query(void);
		void query(const std::string& query);
		void clear(void);

		bool isLocalAddress(void);
		bool isAnyAddress(void);
		bool isIPAddress(void);
		bool isHostAddress(void);
	  
	  private:
		bool normalizeHost(void);
		size_t findString(const std::string& str, size_t pos = 0);
		void parse(void);

		bool good_;
	    std::string url_;
		std::string protocol_;
		std::string host_;
		int32_t port_;
		std::string path_;
		std::string query_;
	};

}

#endif
