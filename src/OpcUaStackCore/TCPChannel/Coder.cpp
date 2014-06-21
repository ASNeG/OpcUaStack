#include "Application/CDA/Coder.h"
#include <stdint.h>

#define STRING_MAX_LEN	64000

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAEncoder
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
std::ostream& 
CDAEncoder::encode(std::ostream& os, bool value)
{
	char c = 0;
	if (value) c = 1;
    os << c;
	return os;
}
	
std::ostream& 
CDAEncoder::encode(std::ostream& os, uint16_t value)
{
	os.write((char*)&value, 2);
	return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, int16_t value)
{
	os.write((char*)&value, 2);
	return os;
}
	
std::ostream& 
CDAEncoder::encode(std::ostream& os, uint32_t value)
{
	os.write((char*)&value, 4);
	return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, int32_t value)
{
	os.write((char*)&value, 4);
	return os;
}
	
std::ostream& 
CDAEncoder::encode(std::ostream& os, double value)
{
	os.write((char*)&value, sizeof(double));
	return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, float value)
{
	os.write((char*)&value, sizeof(float));
	return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, time_t value)
{
	os.write((char*)&value, sizeof(time_t));
	return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, std::string& value)
{
	encode(os, (uint32_t)value.length());
	os.write(value.c_str(), value.length());
	return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, DataValue::VecSPtr& dataValueVecSPtr)
{
	encode(os, (uint32_t)dataValueVecSPtr.size());
	DataValue::VecSPtr::iterator it;
	for (it = dataValueVecSPtr.begin(); it != dataValueVecSPtr.end(); it++) {
		encode(os, *it);
	}
	return os;
}
	
std::ostream& 
CDAEncoder::encode(std::ostream& os, DataValue::Type type)
{
  uint32_t value = type;
  os.write((char*)&value, 4);
  return os;
}

std::ostream& 
CDAEncoder::encode(std::ostream& os, DataValue::SPtr dataValueSPtr)
{
	DataValue::Type dataValueType = dataValueSPtr->type();
	encode(os, dataValueType);

	switch (dataValueType)
	{
		case DataValue::T_Double:
		{
			double value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_Float:
		{
			float value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_String:
		{
			std::string value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_Timestamp:
		{
			time_t value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_UInt32:
		{
			uint32_t value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_Int32:
		{
			int32_t value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_UInt16:
		{
			uint16_t value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
		case DataValue::T_Int16:
		{
			int16_t value;
			dataValueSPtr->get(value);
			encode(os, value);
			break;
		}
	}
	
	return os;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// Decoder
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
std::istream& 
CDADecoder::decode(std::istream& is, bool& value)
{
	value = false;

	char c;
	is >> c;
	if (c == 0x01) value = true;
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, int16_t& value)
{
	is.read((char*)&value, 2);
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, uint16_t& value)
{
	is.read((char*)&value, 2);
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, int32_t& value)
{
	is.read((char*)&value, 4);
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, uint32_t& value)
{
	is.read((char*)&value, 4);
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, double& value)
{
	is.read((char*)&value, sizeof(double));
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, float& value)
{
	is.read((char*)&value, sizeof(float));
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, time_t& value)
{
	is.read((char*)&value, sizeof(time_t));
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, std::string& value)
{
	char dataBuf[STRING_MAX_LEN];
	uint32_t dataLen = 0;

	decode(is, dataLen);
	if (dataLen > STRING_MAX_LEN) {
		return is;
	}
	is.read(dataBuf, dataLen);
	value = std::string(dataBuf, dataLen);

	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, DataValue::VecSPtr& dataValueVecSPtr)
{
	uint32_t size = 0;
	decode(is, size);

	uint32_t idx;
	for (idx=0; idx<size; idx++) {
		DataValue::SPtr dataValueSPtr;
		decode(is, dataValueSPtr);
		dataValueVecSPtr.push_back(dataValueSPtr);
	}

	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, DataValue::Type& type)
{
	uint32_t value = 0;
	decode(is, value);
	type = (DataValue::Type)value;
	return is;
}

std::istream& 
CDADecoder::decode(std::istream& is, DataValue::SPtr& dataValueSPtr)
{
    DataValue::Type dataValueType;
	decode(is, dataValueType);
	dataValueSPtr.reset(new DataValue()); 
	switch (dataValueType)
	{
		case DataValue::T_Double:
		{
			double value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_Float:
		{
			float value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_Int16:
		{
			int16_t value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_UInt16:
		{
			uint16_t value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_Int32:
		{
			int32_t value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_UInt32:
		{
			uint32_t value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_Timestamp:
		{
			time_t value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
		case DataValue::T_String:
		{
			std::string value;
			decode(is, value);
			dataValueSPtr->set(value);
			break;
		}
	}

	return is;
}