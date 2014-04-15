#pragma once
#ifndef __OpcUaStackCore__BuildInTypes_h__
#define __OpcUaStackCore__BuildInTypes_h__

#include "OpcUaStackCore\OpcUaStringBase.h"
#include <iostream>
#include <stdint.h>

namespace OpcUaStackCore
{
	typedef bool OpcUaBoolean;
	void opcUaBinaryEncode(std::ostream& os, OpcUaBoolean& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value);


	typedef int8_t OpcUaSByte;
	void opcUaBinaryEncode(std::ostream& os, OpcUaSByte& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaSByte& value);


	typedef uint8_t OpcUaByte;
	void opcUaBinaryEncode(std::ostream& os, OpcUaByte& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaByte& value);


	typedef int16_t OpcUaInt16;
	void opcUaBinaryEncode(std::ostream& os, OpcUaInt16& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaInt16& value);


	typedef uint16_t OpcUaUInt16;
	void opcUaBinaryEncode(std::ostream& os, OpcUaUInt16& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value);


	typedef int32_t OpcUaInt32;
	void opcUaBinaryEncode(std::ostream& os, OpcUaInt32& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaInt32& value);


	typedef uint32_t OpcUaUInt32;
	void opcUaBinaryEncode(std::ostream& os, OpcUaUInt32& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value);


	typedef int64_t OpcUaInt64;
	void opcUaBinaryEncode(std::ostream& os, OpcUaInt64& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaInt64& value);


	typedef uint64_t OpcUaUInt64;
	void opcUaBinaryEncode(std::ostream& os, OpcUaUInt64& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value);


	typedef float OpcUaFloat;
	void opcUaBinaryEncode(std::ostream& os, OpcUaFloat& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaFloat& value);


	typedef double OpcUaDouble;
	void opcUaBinaryEncode(std::ostream& os, OpcUaDouble& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaDouble& value);

	typedef OpcUaStringBase OpcUaString;
	void opcUaBinaryEncode(std::ostream& os, OpcUaString& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaString& value);


	class OpcUaDateTime
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaDateTime& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaDateTime& value);


	class OpcUaGuid
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaGuid& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaGuid& value);


	class OpcUaByteString
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaByteString& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaByteString& value);


	class OpcUaXmlElement
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaXmlElement& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaXmlElement& value);


	class OpcUaNodeId
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaNodeId& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaNodeId& value);


	class OpcUaExpandedNodeId
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaExpandedNodeId& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeId& value);


	class OpcUaStatusCode
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaStatusCode& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaStatusCode& value);


	class OpcUaQulifiedName
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaQulifiedName& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaQulifiedName& value);


	class OpcUaLocalizedText
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaLocalizedText& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaLocalizedText& value);


	class OpcUaExtensionObject
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaExtensionObject& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaExtensionObject& value);


	class OpcUaDataValue
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaDataValue& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaDataValue& value);


	class OpcUaVariant
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaVariant& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaVariant& value);


	class OpcUaDiagnosticInfo
	{
	  public:
	};
	void opcUaBinaryEncode(std::ostream& os, OpcUaDiagnosticInfo& value);
	void opcUaBinaryDecode(std::istream& is, OpcUaDiagnosticInfo& value);


}

#endif