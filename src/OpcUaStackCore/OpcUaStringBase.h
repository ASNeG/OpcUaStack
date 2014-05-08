#ifndef __OpcUaStackCore__OpcUaStringBase_h__
#define __OpcUaStackCore__OpcUaStringBase_h__

#include <string>
#include <stdint.h>

namespace OpcUaStackCore
{

	class OpcUaStringBase
	{
	  public:
		OpcUaStringBase(void);
		OpcUaStringBase(const std::string& value);
		~OpcUaStringBase(void);

		void value(const std::string& value);
		std::string value(void);
		uint32_t size(void);
		void reset(void);
		bool exist(void);

	  private:
		bool exist_;
		std::string value_;
	};

}

#endif