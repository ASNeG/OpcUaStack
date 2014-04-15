#include "OpcUaStackCore/OpcUaStringBase.h"

using namespace OpcUaStackCore;

		
OpcUaStringBase::OpcUaStringBase(void)
: exist_(false)
, value_("")
{
}

OpcUaStringBase::OpcUaStringBase(const std::string& value)
: exist_(true)
, value_(value)
{
}

OpcUaStringBase::~OpcUaStringBase(void)
{
}

void 
OpcUaStringBase::value(const std::string& value)
{
	exist_ = true;
	value_ = value;
}

std::string 
OpcUaStringBase::value(void)
{
	return value_;
}

uint32_t
OpcUaStringBase::size(void)
{
	return value_.size();
}
		
void 
OpcUaStringBase::reset(void)
{
	exist_ = false;
	value_ = "";
}
		
bool 
OpcUaStringBase::exist(void)
{
	return exist_;
}