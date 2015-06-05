#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaQualifiedName
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaQualifiedName::OpcUaQualifiedName(void)
	: ObjectPool<OpcUaQualifiedName>()
	, namespaceIndex_(0)
	, name_()
	{
	}

	OpcUaQualifiedName::OpcUaQualifiedName(const std::string& name, OpcUaInt16 namespaceIndex)
	: ObjectPool<OpcUaQualifiedName>()
	, namespaceIndex_(namespaceIndex)
	, name_(name)
	{
	}

	OpcUaQualifiedName::~OpcUaQualifiedName(void)
	{
	}

	void 
	OpcUaQualifiedName::set(const std::string& name, OpcUaInt16 namespaceIndex)
	{
		name_ = name;
		namespaceIndex_ = namespaceIndex;
	}

	void 
	OpcUaQualifiedName::get(std::string& name, OpcUaUInt16& namespaceIndex)
	{
		name = name_;
		namespaceIndex = namespaceIndex_;
	}

	void 
	OpcUaQualifiedName::namespaceIndex(const OpcUaUInt16& namespaceIndex)
	{
		namespaceIndex_ = namespaceIndex;
	}

	void 
	OpcUaQualifiedName::name(const std::string& name)
	{
		name_ = name;
	}
		
	OpcUaUInt16 
	OpcUaQualifiedName::namespaceIndex(void)
	{
		return namespaceIndex_;
	}
		
	void 
	OpcUaQualifiedName::name(const OpcUaString& name)
	{
		name_ = name;
	}
		
	OpcUaString& 
	OpcUaQualifiedName::name(void)
	{
		return name_;
	}

	bool 
	OpcUaQualifiedName::fromString(const std::string& qualifiedNameString)
	{
		size_t pos = qualifiedNameString.find(":");
		if (pos == std::string::npos) {
			namespaceIndex(0);
			name(qualifiedNameString);
			return true;
		}

		name(qualifiedNameString.substr(pos+1));
		std::string namespaceIndexString = qualifiedNameString.substr(0, pos);

		try
		{
			uint16_t ni = boost::lexical_cast<int16_t>(namespaceIndexString);
			namespaceIndex(ni);
		}
		catch (boost::bad_lexical_cast&)
		{
			return false;
		}

		return true;
	}

	std::string
	OpcUaQualifiedName::toString(void)
	{
		std::stringstream ss;
		if (namespaceIndex_ != 0) {
			ss << namespaceIndex_ << ":";
		}
		ss << name_;
		return ss.str();
	}
		
	OpcUaQualifiedName& 
	OpcUaQualifiedName::operator=(const std::string& name)
	{
		name_ = name;
		return *this;
	}
		
	OpcUaQualifiedName& 
	OpcUaQualifiedName::operator=(const OpcUaUInt16& namespaceIndex)
	{
		namespaceIndex_ = namespaceIndex;
		return *this;
	}
		
	OpcUaQualifiedName::operator std::string const (void)
	{
		return name_.value();
	}
		
	OpcUaQualifiedName::operator OpcUaUInt16 const (void)
	{
		return namespaceIndex_;
	}

	void 
	OpcUaQualifiedName::copyTo(OpcUaQualifiedName& qualifiedName)
	{
		qualifiedName.namespaceIndex(namespaceIndex_);
		name_.copyTo(qualifiedName.name());
	}

	bool 
	OpcUaQualifiedName::operator!=(const OpcUaQualifiedName& opcUaQualifiedName) const
	{
		return operator==(opcUaQualifiedName);
	}

	bool 
	OpcUaQualifiedName::operator==(const OpcUaQualifiedName& opcUaQualifiedName) const
	{
		return 
			namespaceIndex_ == const_cast<OpcUaQualifiedName*>(&opcUaQualifiedName)->namespaceIndex() && 
			name_ == const_cast<OpcUaQualifiedName*>(&opcUaQualifiedName)->name();
	}

	void 
	OpcUaQualifiedName::out(std::ostream& os) const
	{
		os << "ns=" << namespaceIndex_ << ",name=" << name_; 
	}

	void 
	OpcUaQualifiedName::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
		name_.opcUaBinaryEncode(os);
	}
		
	void 
	OpcUaQualifiedName::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
		name_.opcUaBinaryDecode(is);
	}

}
