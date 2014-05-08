#include "OpcUaStackCore/BuildInTypes.h"

#define MAX_STREAMBUF_SIZE	8192
#define BIG_ENDIAN ((*(char*)&number) != 1)
#define LITTLE_ENDIAN ((*(char*)&number) == 1)


using namespace OpcUaStackCore;


static uint32_t number = 1;


void opcUaBinaryEncode(std::ostream& os, OpcUaBoolean& value)
{
	os.write((char*)&value, 1);
}

void opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value)
{	
	is.read((char*)&value, 1);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaSByte& value)
{	
	os.write((char*)&value, 1);
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaSByte& value)
{	
	is.read((char*)&value, 1);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaByte& value)
{	
	os.write((char*)&value, 1);
}

void opcUaBinaryDecode(std::istream& is, OpcUaByte& value)
{	
	is.read((char*)&value, 1);
}

template <typename T>
  void opcUaBinaryEncodeNumber(std::ostream& os, T& value)
  {
	  if (LITTLE_ENDIAN) {
		  os.write((char*)&value, sizeof(T));
	  }
	  else {
		  for (uint32_t size=sizeof(T); size>0; size++) {
			  os.write(((char*)&value)+size-1,1);
		  }
	  }
  }

template <typename T>
  void opcUaBinaryDecodeNumber(std::istream& is, T& value)
  {
	  if (LITTLE_ENDIAN) {
		  is.read((char*)&value, sizeof(T));
	  }
	  else {
		  for (uint32_t size=sizeof(T); size>0; size++) {
			  is.read(((char*)&value)+size-1,1);
		  }
	  }
  }

void opcUaBinaryEncode(std::ostream& os, OpcUaInt16& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaInt16& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaUInt16& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}

void opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaInt32& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaInt32& value)
{
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaUInt32& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}

void opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaInt64& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaInt64& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaUInt64& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}

void opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaFloat& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}

void opcUaBinaryDecode(std::istream& is, OpcUaFloat& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaDouble& value)
{	
	opcUaBinaryEncodeNumber(os, value);
}

void opcUaBinaryDecode(std::istream& is, OpcUaDouble& value)
{	
	opcUaBinaryDecodeNumber(is, value);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaString& value)
{
	if (!value.exist()) {
		int32_t value = 1;
		opcUaBinaryEncodeNumber(os, value);
		return;
	}

	uint32_t length = value.size();
	opcUaBinaryEncodeNumber(os, length);

	std::string string = value.value();
	os.write(string.c_str(), length); 
}

void opcUaBinaryDecode(std::istream& is, OpcUaString& value)
{	
	int32_t length;
	opcUaBinaryDecodeNumber(is, length);

	if (length == -1) {
		value.reset();
		return;
	}

	if (length == 0) {
		value.value("");
		return;
	}

	std::string string;
	char buf[MAX_STREAMBUF_SIZE];
	uint32_t sizeToRead;
	do 
	{
		sizeToRead = MAX_STREAMBUF_SIZE;
		if (length < MAX_STREAMBUF_SIZE) {
			sizeToRead = length;
		}

		is.read(buf, sizeToRead);
		string.append(buf, sizeToRead);

		length -= sizeToRead;
	} while (length > 0);

	value.value(string);
}


void opcUaBinaryEncode(std::ostream& os, OpcUaDateTime& value)
{	
}

void opcUaBinaryDecode(std::istream& is, OpcUaDateTime& value)
{	
}


void opcUaBinaryEncode(std::ostream& os, OpcUaGuid& value)
{	
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaGuid& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaByteString& value)
{
}

void opcUaBinaryDecode(std::istream& is, OpcUaByteString& value)
{
}


void opcUaBinaryDecode(std::ostream& os, OpcUaXmlElement& value)
{
}

void opcUaBinaryDecode(std::istream& is, OpcUaXmlElement& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaNodeId& value)
{
}

void opcUaBinaryDecode(std::istream& is, OpcUaNodeId& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaExpandedNodeId& value)
{
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeId& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaStatusCode& value)
{
}
	
void opcUaBinaryDecode(std::istream& is, OpcUaStatusCode& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaQulifiedName& value)
{
}

void opcUaBoolBinaryDecode(std::istream& is, OpcUaQulifiedName& value)
{
}

void opcUaBinaryEncode(std::ostream& os, OpcUaLocalizedText& value)
{
}
	
void opcUaBoolBinaryDecode(std::istream& is, OpcUaLocalizedText& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaExtensionObject& value)
{
}
	
void opcUaBoolBinaryDecode(std::istream& is, OpcUaExtensionObject& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaDataValue& value)
{
}

void opcUaBoolBinaryDecode(std::istream& is, OpcUaDataValue& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaVariant& value)
{
}

void opcUaBoolBinaryDecode(std::istream& is, OpcUaVariant& value)
{
}


void opcUaBinaryEncode(std::ostream& os, OpcUaDiagnosticInfo& value)
{
}

void opcUaBoolBinaryDecode(std::istream& is, OpcUaDiagnosticInfo& value)
{
}
