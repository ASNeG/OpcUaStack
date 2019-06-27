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

#ifndef __OpcUaStackCore_ByteOrder_h__
#define __OpcUaStackCore_ByteOrder_h__

#include <stdint.h>
#include <iostream>

#ifdef _WIN32

	#define BIG_ENDIAN false
	#define LITTLE_ENDIAN true

#endif

namespace OpcUaStackCore
{

	template<typename T>
      class ByteOrder 
      {
	    public:

		  static void 
		  opcUaBinaryEncodeNumber(std::ostream& os, const T& value, bool littleEndian = true)
		  {
			  if (littleEndian) {
				  opcUaBinaryEncodeNumberLE(os, value);
			  }
			  else {
				  opcUaBinaryEncodeNumberBE(os, value);
			  }
		  }

		  static void
		  opcUaBinaryEncodeNumber(char* os, const T& value, bool littleEndian = true)
		  {
			  if (littleEndian) {
				  opcUaBinaryEncodeNumberLE(os, value);
			  }
			  else {
				  opcUaBinaryEncodeNumberBE(os, value);
			  }
		  }

		  static void
		  opcUaBinaryEncodeNumberLE(std::ostream& os, const T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  os.write((char*)&value, sizeof(T));
			  }
			  else {
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  os.write(((char*)&value)+size-1,1);
				  }
			  }
		  }

		  static void
		  opcUaBinaryEncodeNumberLE(char* os, const T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  *(T*)os = value;
			  }
			  else {
				  uint32_t pos = 0;
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  os[pos] = *(((char*)&value)+size-1);
					  pos++;
				  }
			  }
		  }

		  static void
		  opcUaBinaryEncodeNumberBE(std::ostream& os, const T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  os.write(((char*)&value)+size-1,1);
				  }
			  }
			  else {
				  os.write((char*)&value, sizeof(T));
			  }
		  }

		  static void
		  opcUaBinaryEncodeNumberBE(char* os, const T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  uint32_t pos = 0;
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  os[pos] = *(((char*)&value)+size-1);
					  pos++;
				  }
			  }
			  else {
				  *(T*)os = value;
			  }
		  }

		  static void
		  opcUaBinaryDecodeNumber(std::istream& is, T& value, bool littleEndian = true)
		  {
			  if (littleEndian) {
				  opcUaBinaryDecodeNumberLE(is, value);
			  }
			  else {
				  opcUaBinaryDecodeNumberBE(is, value);
			  }
		  }

		  static void
		  opcUaBinaryDecodeNumber(char* is, T& value, bool littleEndian = true)
		  {
			  if (littleEndian) {
				  opcUaBinaryDecodeNumberLE(is, value);
			  }
			  else {
				  opcUaBinaryDecodeNumberBE(is, value);
			  }
		  }

		  static void 
		  opcUaBinaryDecodeNumberLE(std::istream& is, T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  is.read((char*)&value, sizeof(T));
			  }
			  else {
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  is.read(((char*)&value)+size-1,1);
				  }
			  }
		  }

		  static void
		  opcUaBinaryDecodeNumberLE(char* is, T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  value = *(T*)is;
			  }
			  else {
				  uint32_t pos = 0;
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  ((char*)&value)[pos] = is[size-1];
					  pos++;
				  }
			  }
		  }

		  static void
		  opcUaBinaryDecodeNumberBE(std::istream& is, T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  is.read(((char*)&value)+size-1,1);
				  }
			  }
			  else {
				  is.read((char*)&value, sizeof(T));
			  }
		  }

		  static void
		  opcUaBinaryDecodeNumberBE(char* is, T& value)
		  {
			  if (LITTLE_ENDIAN) {
				  uint32_t pos = 0;
				  for (uint32_t size=sizeof(T); size>0; size--) {
					  ((char*)&value)[pos] = is[size-1];
					  pos++;
				  }
			  }
			  else {
				  value = *(T*)is;
			  }
		  }

    };
}

#endif
