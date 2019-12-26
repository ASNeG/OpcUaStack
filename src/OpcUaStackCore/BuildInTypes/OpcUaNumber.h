/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaNumber_h__
#define __OpcUaStackCore_OpcUaNumber_h__

#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <stdint.h>
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumberTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaBooleanArray
	: public Object
	, public OpcUaArray<OpcUaBoolean, NumberTypeCoder<OpcUaBoolean> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaBooleanArray> SPtr;
	};

	class DLLEXPORT OpcUaSByteArray
	: public Object
	, public OpcUaArray<OpcUaSByte, NumberTypeCoder<OpcUaSByte> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaSByteArray> SPtr;
	};

	class DLLEXPORT OpcUaByteArray
	: public Object
	, public OpcUaArray<OpcUaByte, NumberTypeCoder<OpcUaByte> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaByteArray> SPtr;
	};

	class DLLEXPORT OpcUaInt16Array
	: public Object
	, public OpcUaArray<OpcUaInt16, NumberTypeCoder<OpcUaInt16> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaInt16Array> SPtr;
	};

	class DLLEXPORT OpcUaUInt16Array
	: public Object
	, public OpcUaArray<OpcUaUInt16, NumberTypeCoder<OpcUaUInt16> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaUInt16Array> SPtr;
	};

	class DLLEXPORT OpcUaInt32Array
	: public Object
	, public OpcUaArray<OpcUaInt32, NumberTypeCoder<OpcUaInt32> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaInt32Array> SPtr;
	};

	class DLLEXPORT OpcUaUInt32Array
	: public Object
	, public OpcUaArray<OpcUaUInt32, NumberTypeCoder<OpcUaUInt32> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaUInt32Array> SPtr;
	};

	class DLLEXPORT OpcUaInt64Array
	: public Object
	, public OpcUaArray<OpcUaInt64, NumberTypeCoder<OpcUaInt64> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaInt64Array> SPtr;
	};
	
	class DLLEXPORT OpcUaUInt64Array
	: public Object
	, public OpcUaArray<OpcUaUInt64, NumberTypeCoder<OpcUaUInt64> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaUInt64Array> SPtr;
	};

	class DLLEXPORT OpcUaFloatArray
	: public Object
	, public OpcUaArray<OpcUaFloat, NumberTypeCoder<OpcUaFloat> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaFloatArray> SPtr;
	};

	class DLLEXPORT OpcUaDoubleArray
	: public Object
	, public OpcUaArray<OpcUaDouble, NumberTypeCoder<OpcUaDouble> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaDoubleArray> SPtr;
	};


    class DLLEXPORT OpcUaNumber
    {
	  public:

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// Boolean
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value);

		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray::SPtr& value);

		//
		// SByte
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaSByte& value);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaSByteArray& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaSByteArray::SPtr& value);


		//
		// Byte
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaByte& value);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaByteArray& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaByteArray::SPtr& value);


		//
		// Int16
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt16& value, bool littleEndian=true);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt16Array& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt16Array::SPtr& value);
	

		//
		// UInt16
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value, bool littleEndian=true);

		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array::SPtr& value);
	

		//
		// Int32
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt32& value, bool littleEndian=true);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt32Array& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt32Array::SPtr& value);

	
		//
		// UInt32
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value, bool littleEndian=true);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array::SPtr& value);

	
		//
		// Int64
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt64& value, bool littleEndian=true);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt64Array& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaInt64Array::SPtr& value);
	
		//
		// UInt64
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value, bool littleEndian=true);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array::SPtr& value);

	
		//
		// Float
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaFloat& value, bool littleEndian=true);

		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaFloatArray& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaFloatArray::SPtr& value);

	
		//
		// Double
		//
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value, bool littleEndian=true);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaDouble& value, bool littleEndian=true);
	
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray& value);
		static bool opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray::SPtr& value);
		static bool opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray::SPtr& value);

	};
};

#endif
