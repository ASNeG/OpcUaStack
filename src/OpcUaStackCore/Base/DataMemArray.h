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
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DataMemArrayHeader;

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

		uint32_t arraySize(void);
		bool arrayResize(uint32_t numberElements);
		bool set(uint32_t idx, const char* buf, uint32_t bufLen);
		bool get(uint32_t idx, char**buf, uint32_t& bufLen);

		void setMemoryBuf(char* memBuf, uint32_t memLen);
		void getMemoryBuf(char** memBuf, uint32_t* memLen);

	  private:
		DataMemArrayHeader* dataMemArrayHeader_;

		static uint32_t minMemorySize_;
		uint32_t startMemorySize_;
		uint32_t maxMemorySize_;
		uint32_t expandMemorySize_;
	};

}

#endif
