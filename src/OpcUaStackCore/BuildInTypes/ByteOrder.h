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

#ifdef WIN32

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
		  opcUaBinaryDecodeNumberLE(std::istream& is, const T& value)
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
    };
}

#endif
