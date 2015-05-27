#ifndef __OpcUaStackCore_Bitmask_h__
#define __OpcUaStackCore_Bitmask_h__

#include <iostream>
#include <vector>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Bitmask
	{
	  public:
		Bitmask(uint32_t bitmaskLen);
		~Bitmask(void);

		void reset(void);
		void add(uint32_t bit);
		void add(std::vector<uint32_t>& bitVec);
		void remove(uint32_t bit);
		void remove(std::vector<uint32_t>& bitVec);
		void get(std::vector<uint32_t>& bitVec);
		void get(char** bitmask, uint32_t* bitmaskLen);
		uint32_t get(void);

		std::string toString(void);

	  private:
		char* bitmask_;
		uint32_t bitmaskLen_;
	};

}

#endif
