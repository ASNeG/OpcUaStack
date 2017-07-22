/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_DataMemArray_h__
#define __OpcUaStackCore_DataMemArray_h__

#include <stdint.h>
#include <map>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DataMemArrayHeader
	{
	  public:
		DataMemArrayHeader(void);
		~DataMemArrayHeader(void);

		char eye_[4]; // HEAD

		uint32_t maxMemorySize_;
		uint32_t expandMemorySize_;

		uint32_t actMemorySize_;
		uint32_t actArraySize_;
	};


	class DataMemArraySlot
	{
	  public:
		typedef std::map<uint32_t, DataMemArraySlot*> Map;

		DataMemArraySlot(void);
		~DataMemArraySlot(void);

		DataMemArraySlot* last(void);
		DataMemArraySlot* next(void);
		uint32_t dataSize(void);

		char eye_[4]; 		// SLOT

		char type_; 		// U = Used, F=Free, S = Start, E = End
		uint32_t size_;		// size exclusive slot header and slot tail
	};


	class DLLEXPORT DataMemArray
	{
	  public:
		DataMemArray(void);
		~DataMemArray(void);

		void startMemorySize(uint32_t startMemorySize);
		uint32_t startMemorySize(void);
		void maxMemorySize(uint32_t maxMemorySize);
		uint32_t maxMemorySize(void);
		void expandMemorySize(uint32_t expandMemorySize);
		uint32_t expandMemorySize(void);

		uint32_t size(void);
		bool resize(uint32_t arraySize);
		bool set(uint32_t idx, const char* buf, uint32_t bufLen);
		bool get(uint32_t idx, char**buf, uint32_t& bufLen);
		bool exist(uint32_t idx);

		bool setMemoryBuf(char* memBuf, uint32_t memLen);
		bool getMemoryBuf(char** memBuf, uint32_t* memLen);

	  private:
		uint32_t ptrToPos(char* ptr);
		bool createNewMemory(uint32_t arraySize);
		void createNewSlot(char* mem, char type, uint32_t size);

		bool debug_;
		DataMemArrayHeader* dataMemArrayHeader_;
		DataMemArraySlot::Map freeSlotMap_;

		static uint32_t minMemorySize_;
		uint32_t startMemorySize_;
		uint32_t maxMemorySize_;
		uint32_t expandMemorySize_;
	};

}

#endif
