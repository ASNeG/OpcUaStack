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

	OpcUaQualifiedName::~OpcUaQualifiedName(void)
	{
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