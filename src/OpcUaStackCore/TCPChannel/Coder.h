#ifndef __CODER_H__
#define __CODER_H__

#include "Common/Base/DataValue.h"

class CDAEncoder
{
  public:
	static std::ostream& encode(std::ostream& os, bool value);
	static std::ostream& encode(std::ostream& os, uint16_t value);
	static std::ostream& encode(std::ostream& os, int16_t value);
	static std::ostream& encode(std::ostream& os, uint32_t value);
	static std::ostream& encode(std::ostream& os, int32_t value);
	static std::ostream& encode(std::ostream& os, double value);
	static std::ostream& encode(std::ostream& os, float value);
	static std::ostream& encode(std::ostream& os, time_t value);
	static std::ostream& encode(std::ostream& os, std::string& value);
	static std::ostream& encode(std::ostream& os, DataValue::VecSPtr& dataValueVecSPtr);
	static std::ostream& encode(std::ostream& os, DataValue::Type type);
	static std::ostream& encode(std::ostream& os, DataValue::SPtr dataValueSPtr);
};


class CDADecoder
{
  public:
	static std::istream& decode(std::istream& is, bool& value);
	static std::istream& decode(std::istream& is, int16_t& value);
	static std::istream& decode(std::istream& is, uint16_t& value);
	static std::istream& decode(std::istream& is, int32_t& value);
	static std::istream& decode(std::istream& is, uint32_t& value);
	static std::istream& decode(std::istream& is, double& value);
	static std::istream& decode(std::istream& is, float& value);
	static std::istream& decode(std::istream& is, time_t& value);
	static std::istream& decode(std::istream& is, std::string& value);
	static std::istream& decode(std::istream& is, DataValue::VecSPtr& dataValueVecSPtr);
	static std::istream& decode(std::istream& is, DataValue::Type& type);
	static std::istream& decode(std::istream& is, DataValue::SPtr& dataValueSPtr);
};


#endif