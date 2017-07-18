/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

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
		uint32_t rest = asciiLen % 3;
		if (rest != 0) {
			asciiLen += (3 - rest);
		}
		return (4*ceil((double)asciiLen/3.0));
	}

	uint32_t
	Base64::base64Len2asciiLen(uint32_t base64Len)
	{
		return ((6 * base64Len) / 8);
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

#if 0
		BIO *bio, *b64;
		BUF_MEM *bufferPtr;

		uint32_t length = asciiLen2base64Len(asciiLen);
		if (length > base64Len) return false;
		base64Len = length;

		b64 = BIO_new(BIO_f_base64());
		bio = BIO_new(BIO_s_mem());
		bio = BIO_push(b64, bio);

		BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
		BIO_write(bio, asciiBuf, asciiLen);
		BIO_flush(bio);
		BIO_get_mem_ptr(bio, &bufferPtr);
		BIO_set_close(bio, BIO_NOCLOSE);
		BIO_free_all(bio);

		memcpy(base64Buf, bufferPtr->data, base64Len);
#endif
		return true;
	}

	bool
	Base64::decode(const char* base64Buf, uint32_t base64Len, char* asciiBuf, uint32_t& asciiLen)
	{
		uint32_t length = base64Len2asciiLen(base64Len);
		if (length > asciiLen) return false;

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

		std::cout << idx << std::endl;

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



#if 0
		BIO *b64, *bio;
		b64 = BIO_new(BIO_f_base64());
		BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
		bio = BIO_new_mem_buf((char*)base64Buf, base64Len);
		bio = BIO_push(b64, bio);

		length = BIO_read(bio, asciiBuf, length);
		asciiLen = length;

		BIO_free_all(b64);
#endif

		return true;
	}

	bool
	Base64::isBase64(unsigned char c)
	{
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

#if 0

	std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
	  std::string ret;
	  int i = 0;
	  int j = 0;
	  unsigned char char_array_3[3];
	  unsigned char char_array_4[4];

	  while (in_len--) {
	    char_array_3[i++] = *(bytes_to_encode++);
	    if (i == 3) {
	      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	      char_array_4[3] = char_array_3[2] & 0x3f;

	      for(i = 0; (i <4) ; i++)
	        ret += base64_chars[char_array_4[i]];
	      i = 0;
	    }
	  }

	  if (i)
	  {
	    for(j = i; j < 3; j++)
	      char_array_3[j] = '\0';

	    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	    char_array_4[3] = char_array_3[2] & 0x3f;

	    for (j = 0; (j < i + 1); j++)
	      ret += base64_chars[char_array_4[j]];

	    while((i++ < 3))
	      ret += '=';

	  }

	  return ret;

	}
	std::string base64_decode(std::string const& encoded_string) {
	  int in_len = encoded_string.size();
	  int i = 0;
	  int j = 0;
	  int in_ = 0;
	  unsigned char char_array_4[4], char_array_3[3];
	  std::string ret;

	  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
	    char_array_4[i++] = encoded_string[in_]; in_++;
	    if (i ==4) {
	      for (i = 0; i <4; i++)
	        char_array_4[i] = base64_chars.find(char_array_4[i]);

	      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
	      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
	      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

	      for (i = 0; (i < 3); i++)
	        ret += char_array_3[i];
	      i = 0;
	    }
	  }

	  if (i) {
	    for (j = i; j <4; j++)
	      char_array_4[j] = 0;

	    for (j = 0; j <4; j++)
	      char_array_4[j] = base64_chars.find(char_array_4[j]);

	    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
	    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
	    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

	    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	  }

	  return ret;
	}
#endif

}
