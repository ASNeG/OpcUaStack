#ifndef __OpcUaStackCore_OpcUaNumber_h__
#define __OpcUaStackCore_OpcUaNumber_h__

#include <iostream>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/Base/ObjectPool.h"

namespace OpcUaStackCore
{

	typedef bool OpcUaBoolean;
	class DLLEXPORT OpcUaBooleanArray : public OpcUaArray<OpcUaBoolean, NumberTypeCoder<OpcUaBoolean> >, public ObjectPool<OpcUaBooleanArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaBooleanArray> SPtr;
	};

	typedef int8_t OpcUaSByte;
	class DLLEXPORT OpcUaSByteArray : public OpcUaArray<OpcUaSByte, NumberTypeCoder<OpcUaSByte> >, public ObjectPool<OpcUaSByteArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaSByteArray> SPtr;
	};

	typedef uint8_t OpcUaByte;
	class DLLEXPORT OpcUaByteArray : public OpcUaArray<OpcUaByte, NumberTypeCoder<OpcUaByte> >, public ObjectPool<OpcUaByteArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaByteArray> SPtr;
	};

	typedef int16_t OpcUaInt16;
	class DLLEXPORT OpcUaInt16Array : public OpcUaArray<OpcUaInt16, NumberTypeCoder<OpcUaInt16> >, public ObjectPool<OpcUaInt16Array> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaInt16Array> SPtr;
	};

	typedef uint16_t OpcUaUInt16;
	class DLLEXPORT OpcUaUInt16Array : public OpcUaArray<OpcUaUInt16, NumberTypeCoder<OpcUaUInt16> >, public ObjectPool<OpcUaUInt16Array> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaUInt16Array> SPtr;
	};

	typedef int32_t OpcUaInt32;
	class DLLEXPORT OpcUaInt32Array : public OpcUaArray<OpcUaInt32, NumberTypeCoder<OpcUaInt32> >, public ObjectPool<OpcUaInt32Array> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaInt32Array> SPtr;
	};

	typedef uint32_t OpcUaUInt32;
	class DLLEXPORT OpcUaUInt32Array : public OpcUaArray<OpcUaUInt32, NumberTypeCoder<OpcUaUInt32> >, public ObjectPool<OpcUaUInt32Array> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaUInt32Array> SPtr;
	};

	typedef int64_t OpcUaInt64;
	class DLLEXPORT OpcUaInt64Array : public OpcUaArray<OpcUaInt64, NumberTypeCoder<OpcUaInt64> >, public ObjectPool<OpcUaInt64Array> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaInt64Array> SPtr;
	};
	
	typedef uint64_t OpcUaUInt64;
	class DLLEXPORT OpcUaUInt64Array : public OpcUaArray<OpcUaUInt64, NumberTypeCoder<OpcUaUInt64> >, public ObjectPool<OpcUaUInt64Array> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaUInt64Array> SPtr;
	};

	typedef float OpcUaFloat;
	class DLLEXPORT OpcUaFloatArray : public OpcUaArray<OpcUaFloat, NumberTypeCoder<OpcUaFloat> >, public ObjectPool<OpcUaFloatArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaFloatArray> SPtr;
	};

	typedef double OpcUaDouble;
	class DLLEXPORT OpcUaDoubleArray : public OpcUaArray<OpcUaDouble, NumberTypeCoder<OpcUaDouble> >, public ObjectPool<OpcUaDoubleArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaDoubleArray> SPtr;
	};


    class DLLEXPORT OpcUaNumber
    {
	  public:
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value);

		static void opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray::SPtr& value);

		static void opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaSByte& value);
	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaSByteArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaSByteArray::SPtr& value);


		static void opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaByte& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaByteArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaByteArray::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt16& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt16Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt16Array::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt32& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt32Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt32Array::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt64& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt64Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaInt64Array::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaFloat& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaFloatArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaFloatArray::SPtr& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaDouble& value);

	
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray& value);
		static void opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray::SPtr& value);
		static void opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray::SPtr& value);

	};
};

#endif
