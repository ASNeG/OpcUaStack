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

		void startMemorySizeDefault(uint32_t startMemorySizeDefault);
		void maxMemorySizeDefault(uint32_t maxMemorySizeDefault);
		void expandMemorySizeDefault(uint32_t expandMemorySizeDefault);

		uint32_t arraySize(void);
		bool arrayResize(uint32_t numberElements);
		bool set(uint32_t idx, const char* buf, uint32_t bufLen);
		bool get(uint32_t idx, char**buf, uint32_t& bufLen);

		void setMemoryBuf(char* memBuf, uint32_t memLen);
		void getMemoryBuf(char** memBuf, uint32_t* memLen);

	  private:
		DataMemArrayHeader* dataMemArrayHeader_;

		uint32_t startMemorySizeDefault_;
		uint32_t maxMemorySizeDefault_;
		uint32_t expandMemorySizeDefault_;
	};

}

#endif
