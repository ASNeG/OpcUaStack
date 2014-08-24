#ifndef __OpcUaStackCore_ConfigXml_h__
#define __OpcUaStackCore_ConfigXml_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaStackCore
{

	class DLLEXPORT ConfigXml
	{
	  public:
		ConfigXml(void);
		~ConfigXml(void);

		bool parse(const std::string& configFileName);
	};

}

#endif