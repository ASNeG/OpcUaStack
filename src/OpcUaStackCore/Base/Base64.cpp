/*
   Copyright 2016-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include <cstring>
#include <cmath>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include "OpcUaStackCore/Base/Base64.h"

namespace OpcUaStackCore
{

	const std::string Base64::base64Chars_ =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";

	Base64::Base64(void)
	{
	}

	Base64::~Base64(void)
	{
	}

	uint32_t
	Base64::asciiLen2base64Len(uint32_t asciiLen)
	{
		asciiLen = ((asciiLen + 3 - 1) / 3 ) * 3;
		return (4*(asciiLen/3));
	}

	uint32_t
	Base64::base64Len2asciiLen(uint32_t base64Len, uint32_t numberPaddingBytes)
	{
		uint32_t asciiLen = ((3 * base64Len) / 4);
		return (asciiLen - numberPaddingBytes);
	}

	uint32_t
	Base64::base64Len2asciiLen(uint32_t base64Len, const char* base64Buf)
	{
		return base64Len2asciiLen(
			base64Len,
			base64NumberPaddingBytes(base64Buf, base64Len)
		);
	}

	uint32_t
	Base64::base64NumberPaddingBytes(const char* base64Buf, uint32_t base64Len)
	{
		uint32_t numberPaddings = 0;
		while ( base64Buf[base64Len-1] == '=' &&  base64Len > 0) {
			base64Len--;
			numberPaddings++;
		}
		return numberPaddings;
	}

	bool
	Base64::encode(const char* asciiBuf, uint32_t asciiLen, char* base64Buf, uint32_t& base64Len)
	{
		uint32_t pos = 0;

		// check length
		uint32_t length = asciiLen2base64Len(asciiLen);
		if (length > base64Len) return false;
		base64Len = length;
		char* buf= (char*)asciiBuf;

		memset(base64Buf, 0x00, length);

		unsigned char charArray3[3];
		unsigned char charArray4[4];

		uint32_t idx = 0;
		while (asciiLen--) {
			charArray3[idx] = *buf;
			idx++;
			buf++;

		    if (idx == 3) {
		    	charArray4[0] = (charArray3[0] & 0xfc) >> 2;
		    	charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
		    	charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
		    	charArray4[3] = charArray3[2] & 0x3f;

		        for(uint32_t i = 0; i<4; i++) {
		        	base64Buf[pos] = base64Chars_[charArray4[i]];
		        	pos++;
		        }
		        idx = 0;
		    }
		 }

		 if (idx) {
			 for(uint32_t j = idx; j < 3; j++) {
				 charArray3[j] = '\0';
			 }

			 charArray4[0] = (charArray3[0] & 0xfc) >> 2;
			 charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
			 charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
			 charArray4[3] = charArray3[2] & 0x3f;

			 for (uint32_t j = 0; (j < idx + 1); j++) {
				 base64Buf[pos] = base64Chars_[charArray4[j]];
				 pos++;
			 }

			 while((idx++ < 3)) {
				 base64Buf[pos] = '=';
				 pos++;
			 }
		 }

		return true;
	}

	bool
	Base64::decode(const char* base64Buf, uint32_t base64Len, char* asciiBuf, uint32_t& asciiLen)
	{
		uint32_t length = base64Len2asciiLen(base64Len, base64Buf);
		if (length > asciiLen) return false;
		asciiLen = 0;

		memset(asciiBuf, 0x00, length);
		char* buf = (char*)base64Buf;

		uint32_t idx = 0;
		uint32_t rpos = 0;
		uint32_t wpos = 0;
		unsigned char charArray4[4];
		unsigned char charArray3[3];

		while (base64Len-- && ( buf[rpos] != '=') && Base64::isBase64(buf[rpos])) {
		    charArray4[idx] = buf[rpos];
		    rpos++;
		    idx++;

		    if (idx == 4) {
		        for (idx = 0; idx <4; idx++) {
		            charArray4[idx] = base64Chars_.find(charArray4[idx]);
		        }

		        charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
		        charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
		        charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

		        for (idx = 0; (idx < 3); idx++){
		        	asciiBuf[wpos] = charArray3[idx];
		        	wpos++;
		        }
		        idx = 0;
		    }
		}

		if (idx) {
		    for (uint32_t j = idx; j < 4; j++) {
		        charArray4[j] = 0;
		    }

		    for (uint32_t j = 0; j < 4; j++) {
		        charArray4[j] = base64Chars_.find(charArray4[j]);
		    }

		    charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
		    charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
		    charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

		    for (uint32_t j = 0; (j < idx - 1); j++) {
	        	asciiBuf[wpos] = charArray3[j];
	        	wpos++;
		    }
		}

		asciiLen = wpos;

		return true;
	}

	bool
	Base64::isBase64(unsigned char c)
	{
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

}
