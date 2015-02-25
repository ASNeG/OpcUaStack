#ifndef __OpcuaStackCore_Url_h__
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

		bool good(void);
		std::string protocol(void) const;
		std::string host(void);
		int32_t port(void);
		std::string path(void);
		std::string query(void);
		void clear(void);
	  
	  private:
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