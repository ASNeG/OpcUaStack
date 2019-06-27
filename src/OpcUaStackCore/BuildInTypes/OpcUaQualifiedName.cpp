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

#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/BuildInTypes/Json.h"

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
	: Object()
	, namespaceIndex_(0)
	, name_()
	{
	}

	OpcUaQualifiedName::OpcUaQualifiedName(const std::string& name, OpcUaInt16 namespaceIndex)
	: Object()
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

	bool
	OpcUaQualifiedName::encode(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree namespaceIndex;
		if (!Json::encode(namespaceIndex, namespaceIndex_)) return false;
		pt.put_child("NamespaceIndex", namespaceIndex);

		boost::property_tree::ptree name;
		if (!name_.encode(name)) return false;
		pt.put_child("Name", name);

		return true;
	}

	bool
	OpcUaQualifiedName::decode(boost::property_tree::ptree& pt)
	{
		boost::optional<boost::property_tree::ptree&> namespaceIndex;
		namespaceIndex = pt.get_child_optional("NamespaceIndex");
		if (!namespaceIndex) {
			namespaceIndex_ = 0;
		}
		else {
			if (!Json::decode(*namespaceIndex, namespaceIndex_)) return false;
		}

		boost::optional<boost::property_tree::ptree&> name;
		name = pt.get_child_optional("Name");
		if (!name) return false;
		if (!name_.decode(*name)) return false;

		return true;
	}

	bool
	OpcUaQualifiedName::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaQualifiedName xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addxmlns(element), elementTree));
		return true;
	}

	bool
	OpcUaQualifiedName::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		std::stringstream ss;
		ss << namespaceIndex();
		pt.put(xmlns.addxmlns("NamespaceIndex"), ss.str());

		pt.put(xmlns.addxmlns("Name"), name().value());

		return true;
	}

	bool
	OpcUaQualifiedName::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		//
		// namespace index
		//
		boost::optional<std::string> namespaceIndexString = pt.get_optional<std::string>(xmlns.addxmlns("NamespaceIndex"));
		if (!namespaceIndexString) {
			namespaceIndex(0);
		}
		else {
			try
			{
				uint16_t ni = boost::lexical_cast<int16_t>(*namespaceIndexString);
				namespaceIndex(ni);
			}
			catch (boost::bad_lexical_cast&)
			{
				Log(Error, "OpcUaQulifiedName xml encoder error - value invalid")
					.parameter("Element", "NamespaceIndex")
					.parameter("Value", *namespaceIndexString);
				return false;
			}
		}

		//
		// name
		//
		boost::optional<std::string> nameString = pt.get_optional<std::string>(xmlns.addxmlns("Name"));
		if (!nameString) {
			name("");
		}
		else {
			name(*nameString);
		}

		return true;
	}

}
