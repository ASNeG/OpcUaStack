#include <string.h>
#include "OpcUaStackCore/Base/Bitmask.h"
#include <sstream>

namespace OpcUaStackCore
{

	Bitmask::Bitmask(uint32_t bitmaskLen)
	: bitmask_(NULL)
	, bitmaskLen_(bitmaskLen)
	{
		if (bitmaskLen_ == 0) return;
		bitmask_ = new char[bitmaskLen_];
		memset(bitmask_, 0x00, bitmaskLen_);
	}

	Bitmask::~Bitmask(void)
	{
		if (bitmaskLen_ == 0) return;
		bitmaskLen_ = 0;
		delete [] bitmask_;
	}

	void
	Bitmask::reset(void)
	{
		if (bitmaskLen_ == 0) return;
		memset(bitmask_, 0x00, bitmaskLen_);
	}

	void
	Bitmask::add(uint32_t bit)
	{
		if (bit > bitmaskLen_*8) return;

		bit--;
		uint32_t byte = bit / 8;
		uint32_t pos = bit % 8;
		uint8_t value = bitmask_[byte];

		value = value | (0x01 << (7-pos));
		bitmask_[byte] = value;
	}

	void
	Bitmask::add(std::vector<uint32_t>& bitVec)
	{
		std::vector<uint32_t>::iterator it;
		for (it = bitVec.begin(); it != bitVec.end(); it++) {
			add(*it);
		}
	}

	void
	Bitmask::remove(uint32_t bit)
	{
		if (bit > bitmaskLen_*8) return;

		bit--;
		uint32_t byte = bit / 8;
		uint32_t pos = bit % 8;
		uint8_t value = bitmask_[byte];

		value = value & (~(0x01 << (7-pos)));
		bitmask_[byte] = value;
	}

	void
	Bitmask::remove(std::vector<uint32_t>& bitVec)
	{
		std::vector<uint32_t>::iterator it;
		for (it = bitVec.begin(); it != bitVec.end(); it++) {
			remove(*it);
		}
	}

	void
	Bitmask::get(std::vector<uint32_t>& bitVec)
	{
		for (uint32_t byte=0; byte<bitmaskLen_; byte++) {
			uint8_t value = bitmask_[byte];
			for (uint32_t pos=0; pos<8; pos++) {
				if ((value & (0x01 << (7-pos))) == (0x01 << (7-pos))) {
					uint32_t bit = byte*8 + pos + 1;
					bitVec.push_back(bit);
				}
			}
		}
	}

	uint32_t
	Bitmask::get(void)
	{
		std::vector<uint32_t> bitVec;
		get(bitVec);
		if (bitVec.size() == 0) return 0;
		return bitVec.front();
	}

	void
	Bitmask::get(char** bitmask, uint32_t* bitmaskLen)
	{
		*bitmask = bitmask_;
		*bitmaskLen = bitmaskLen_;
	}

	std::string
	Bitmask::toString(void)
	{
		std::stringstream ss;
		std::vector<uint32_t>::iterator it;
		std::vector<uint32_t> bitVec;
		get(bitVec);

		bool first = true;
		for (it = bitVec.begin(); it != bitVec.end(); it++) {
			if (first) first = false;
			else ss << ",";
			ss << *it;
		}
		return ss.str();
	}

}
