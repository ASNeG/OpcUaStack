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
