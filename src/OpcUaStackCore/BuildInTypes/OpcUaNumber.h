/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/os.h"
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
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaBoolean& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaBoolean& value);

		static void opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaBooleanArray& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaBooleanArray& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaBooleanArray::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaBooleanArray::SPtr& value);

		//
		// SByte
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaSByte& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaSByte& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaSByte& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaSByteArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaSByteArray::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaSByteArray& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaSByteArray& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaSByteArray::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaSByteArray::SPtr& value);


		//
		// Byte
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaByte& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaByte& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaByte& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaByteArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaByteArray::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaByteArray& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaByteArray& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaByteArray::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaByteArray::SPtr& value);


		//
		// Int16
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt16& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt16& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt16& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt16Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt16Array::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt16Array& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt16Array& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt16Array::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt16Array::SPtr& value);
	

		//
		// UInt16
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt16& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt16& value);

		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt16Array& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt16Array& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt16Array::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt16Array::SPtr& value);
	

		//
		// Int32
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt32& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt32& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt32& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt32Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt32Array::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt32Array& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt32Array& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt32Array::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt32Array::SPtr& value);

	
		//
		// UInt32
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt32& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt32& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt32Array& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt32Array& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt32Array::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt32Array::SPtr& value);

	
		//
		// Int64
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt64& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt64& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt64& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt64Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt64Array::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt64Array& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt64Array& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaInt64Array::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaInt64Array::SPtr& value);
	
		//
		// UInt64
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt64& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt64& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt64Array& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt64Array& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaUInt64Array::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaUInt64Array::SPtr& value);

	
		//
		// Float
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaFloat& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaFloat& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaFloat& value);

		static void opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaFloatArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaFloatArray::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaFloatArray& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaFloatArray& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaFloatArray::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaFloatArray::SPtr& value);

	
		//
		// Double
		//
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value, bool littleEndian=true);
		static void opcUaBinaryDecode(std::istream& is, OpcUaDouble& value, bool littleEndian=true);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaDouble& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaDouble& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray::SPtr& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaDoubleArray& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaDoubleArray& value);
		static bool encode(boost::property_tree::ptree& pt, const OpcUaDoubleArray::SPtr& value);
		static bool decode(boost::property_tree::ptree& pt, OpcUaDoubleArray::SPtr& value);

	};
};

#endif
