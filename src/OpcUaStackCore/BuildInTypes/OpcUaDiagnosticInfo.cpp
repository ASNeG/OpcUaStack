/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDiagnosticInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaDiagnosticInfo::OpcUaDiagnosticInfo(void)
	: Object()
	, symbolicId_(-1)
	, namespaceUri_(-1)
	, localizedText_(-1)
	, locale_(-1)
	, additionalInfo_()
	, innerStatusCode_((OpcUaStatusCode)0)
	, diagnosticInfo_()
	{
	}

	OpcUaDiagnosticInfo::~OpcUaDiagnosticInfo(void)
	{
	}

	void
	OpcUaDiagnosticInfo::setSymbolicId(
		const OpcUaInt32 symbolicId)
	{
		symbolicId_ = symbolicId;
	}

	OpcUaInt32
	OpcUaDiagnosticInfo::getSymbolicId() const
	{
		return symbolicId_;
	}

	void
	OpcUaDiagnosticInfo::setNamespaceUri(
		const OpcUaInt32 namespaceUri)
	{
		namespaceUri_ = namespaceUri;
	}

	OpcUaInt32
	OpcUaDiagnosticInfo::getNamespaceUri() const
	{
		return namespaceUri_;
	}

	void
	OpcUaDiagnosticInfo::setLocalizedText(
		const OpcUaInt32 localizedText)
	{
		localizedText_ = localizedText;
	}

	OpcUaInt32
	OpcUaDiagnosticInfo::getLocalizedText() const
	{
		return localizedText_;
	}

	void
	OpcUaDiagnosticInfo::setLocale(
			const OpcUaInt32 locale)
	{
		locale_ = locale;
	}

	OpcUaInt32
	OpcUaDiagnosticInfo::getLocale() const
	{
		return locale_;
	}

	void
	OpcUaDiagnosticInfo::setAdditionalInfo(
		const OpcUaString& additionalInfo)
	{
		additionalInfo_ = additionalInfo;
	}

	const OpcUaString&
	OpcUaDiagnosticInfo::getAdditionalInfo() const
	{
		return additionalInfo_;
	}

	void
	OpcUaDiagnosticInfo::setInnerStatusCode(
		const OpcUaStatusCode innerStatusCode)
	{
		innerStatusCode_ = innerStatusCode;
	}

	OpcUaStatusCode
	OpcUaDiagnosticInfo::getInnerStatusCode() const
	{
		return innerStatusCode_;
	}

	void
	OpcUaDiagnosticInfo::diagnosticInfo(const OpcUaDiagnosticInfo::SPtr diagnosticInfo)
	{
		diagnosticInfo_ = diagnosticInfo;
	}

	OpcUaDiagnosticInfo::SPtr
	OpcUaDiagnosticInfo::diagnosticInfo(void) const
	{
		return diagnosticInfo_;
	}

	void
	OpcUaDiagnosticInfo::out(std::ostream& os) const
	{
		bool outputExist = false;
		if (symbolicId_ != -1) {
			os << "SymbolId=" << symbolicId_;
			outputExist = true;
		}
		if (namespaceUri_ != -1) {
			if (outputExist) os << ",";
			os << "NamespaceUri=" << namespaceUri_;
			outputExist = true;
		}
		if (localizedText_ != -1) {
			if (outputExist) os << ",";
			os << "LocalizedText=" << localizedText_;
			outputExist = true;
		}
		if (locale_ != -1) {
			if (outputExist) os << ",";
			os << "Localue=" << locale_;
			outputExist = true;
		}
		if (additionalInfo_.exist()) {
			if (outputExist) os << ",";
			os << "AdditionalInfo=" << additionalInfo_;
			outputExist = true;
		}
		if (innerStatusCode_ != 0) {
			if (outputExist) os << ",";
			os << "InnerStatusCode=" << innerStatusCode_;
			outputExist = true;
		}
	}

	void
	OpcUaDiagnosticInfo::copyTo(OpcUaDiagnosticInfo& opcUaDiagnosticInfo)
	{
		if (symbolicId_ != -1) {
			opcUaDiagnosticInfo.setSymbolicId(symbolicId_);
		}
		if (namespaceUri_ != -1) {
			opcUaDiagnosticInfo.setNamespaceUri(namespaceUri_);
		}
		if (localizedText_ != -1) {
			opcUaDiagnosticInfo.setLocalizedText(localizedText_);
		}
		if (locale_ != -1) {
			opcUaDiagnosticInfo.setLocale(locale_);
		}
		if (additionalInfo_.exist()) {
			opcUaDiagnosticInfo.setAdditionalInfo(additionalInfo_);
		}
		if (innerStatusCode_ != 0) {
			opcUaDiagnosticInfo.setInnerStatusCode(innerStatusCode_);
		}
		if (diagnosticInfo_.get() != nullptr) {
			OpcUaDiagnosticInfo::SPtr tmp = boost::make_shared<OpcUaDiagnosticInfo>();
			diagnosticInfo_->copyTo(*tmp);
			opcUaDiagnosticInfo.diagnosticInfo(tmp);
		}
	}

	bool
	OpcUaDiagnosticInfo::operator==(const OpcUaDiagnosticInfo& value)
	{
		OpcUaDiagnosticInfo* dst = const_cast<OpcUaDiagnosticInfo*>(&value);
		if (symbolicId_ != dst->symbolicId_) return false;
		if (namespaceUri_ != dst->namespaceUri_) return false;
		if (localizedText_ != dst->localizedText_) return false;
		if (locale_ != dst->locale_) return false;
		if (additionalInfo_ != dst->additionalInfo_) return false;
		if (innerStatusCode_ != dst->innerStatusCode_) return false;
		return true;
	}

	bool
	OpcUaDiagnosticInfo::operator!=(const OpcUaDiagnosticInfo& value)
	{
		return !this->operator==(value);
	}

	OpcUaDiagnosticInfo&
	OpcUaDiagnosticInfo::operator=(const OpcUaDiagnosticInfo& value)
	{
		const_cast<OpcUaDiagnosticInfo*>(&value)->copyTo(*this);
		return *this;
	}

	bool
	OpcUaDiagnosticInfo::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte encodingMask = 0x00;

		if (symbolicId_ != -1) {
			encodingMask += 0x01;
		}
		if (namespaceUri_ != -1) {
			encodingMask += 0x02;
		}
		if (localizedText_ != -1) {
			encodingMask += 0x04;
		}
		if (locale_ != -1) {
			encodingMask += 0x08;
		}
		if (additionalInfo_.exist()) {
			encodingMask += 0x10;
		}
		if (innerStatusCode_ != 0) {
			encodingMask += 0x20;
		}
		if (diagnosticInfo_.get() != nullptr) {
			encodingMask += 0x40;
		}

		auto rc = OpcUaNumber::opcUaBinaryEncode(os,encodingMask);
		if (symbolicId_ != -1) {
			rc &= OpcUaNumber::opcUaBinaryEncode(os,symbolicId_);
		}
		if (namespaceUri_ != -1) {
			rc &= OpcUaNumber::opcUaBinaryEncode(os,namespaceUri_);
		}
		if (localizedText_ != -1) {
			rc &= OpcUaNumber::opcUaBinaryEncode(os,localizedText_);
		}
		if (locale_ != -1) {
			rc &= OpcUaNumber::opcUaBinaryEncode(os,locale_);
		}
		if (additionalInfo_.exist()) {
			rc &= additionalInfo_.opcUaBinaryEncode(os);
		}
		if (innerStatusCode_ != 0) {
			rc &= OpcUaNumber::opcUaBinaryEncode(os, innerStatusCode_);
		}
		if (diagnosticInfo_.get() != nullptr) {
			rc &= diagnosticInfo_->opcUaBinaryEncode(os);
		}
		return rc;
	}

	bool
	OpcUaDiagnosticInfo::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		auto rc = OpcUaNumber::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			rc &= OpcUaNumber::opcUaBinaryDecode(is,symbolicId_);
		}
		if ((encodingMask & 0x02) == 0x02) {
			rc &= OpcUaNumber::opcUaBinaryDecode(is,namespaceUri_);
		}
		if ((encodingMask & 0x04) == 0x04) {
			rc &= OpcUaNumber::opcUaBinaryDecode(is,localizedText_);
		}
		if ((encodingMask & 0x08) == 0x08) {
			rc &= OpcUaNumber::opcUaBinaryDecode(is,locale_);
		}
		if ((encodingMask & 0x10) == 0x10) {
			rc &= additionalInfo_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaInt32 tmp;
			rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp); innerStatusCode_ = (OpcUaStatusCode)tmp;
		}
		if ((encodingMask & 0x40) == 0x40) {
			diagnosticInfo_ = boost::make_shared<OpcUaDiagnosticInfo>();
			rc &= diagnosticInfo_->opcUaBinaryDecode(is);
		}
		return rc;
	}

	bool
	OpcUaDiagnosticInfo::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaDiagnosticInfo xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaDiagnosticInfo::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{

		if (symbolicId_ != -1) {
			if (!XmlNumber::xmlEncode(pt, symbolicId_, xmlns.addPrefix("SymbolicId"))) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "SymbolicId");
				return false;
			}
		}
		if (namespaceUri_ != -1) {
			if (!XmlNumber::xmlEncode(pt, namespaceUri_, xmlns.addPrefix("NamespaceUri"))) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "NamespaceUri");
				return false;
			}
		}
		if (localizedText_ != -1) {
			if (!XmlNumber::xmlEncode(pt, localizedText_, xmlns.addPrefix("LocalizedText"))) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "LocalizedText");
				return false;
			}
		}
		if (locale_ != -1) {
			if (!XmlNumber::xmlEncode(pt, locale_, xmlns.addPrefix("Locale"))) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "Locale");
				return false;
			}
		}
		if (additionalInfo_.exist()) {
			if (!additionalInfo_.xmlEncode(pt, xmlns.addPrefix("AdditionalInfo"), xmlns)) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "AdditionalInfo");
				return false;
			}
		}
		if (innerStatusCode_ != 0) {
			OpcUaStatus status(innerStatusCode_);
			if (!status.xmlEncode(pt, xmlns.addPrefix("InnerStatusCode"), xmlns)) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "InnerStatusCode");
				return false;
			}
		}
		if (diagnosticInfo_.get() != nullptr) {
			if (!diagnosticInfo_->xmlEncode(pt, xmlns.addPrefix("InnerDiagnosticInfo"), xmlns)) {
				Log(Error, "OpcUaDiagnosticInfo xml encoder error")
					.parameter("Element", "InnerDiagnosticInfo");
				return false;
			}
		}
		return true;
	}

	bool
	OpcUaDiagnosticInfo::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		std::string elementName = xmlns.addPrefix(element);
		boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
		if (!tree) {
			Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
				.parameter("Element", elementName);
			return false;
		}
		return xmlDecode(*tree, xmlns);
	}

	bool
	OpcUaDiagnosticInfo::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::optional<boost::property_tree::ptree&> tree;

		//
		// get SymboliId
		//
		tree = pt.get_child_optional(xmlns.addPrefix("SymbolicId"));
		if (tree) {
			if (!XmlNumber::xmlDecode(*tree, symbolicId_)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "SymbolicId");
				return false;
			}
		}

		//
		// get NamesapceUri
		//
		tree = pt.get_child_optional(xmlns.addPrefix("NamespaceUri"));
		if (tree) {
			if (!XmlNumber::xmlDecode(*tree, namespaceUri_)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "NamespaceUri");
				return false;
			}
		}

		//
		// get Locale
		//
		tree = pt.get_child_optional(xmlns.addPrefix("Locale"));
		if (tree) {
			if (!XmlNumber::xmlDecode(*tree, locale_)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "Locale");
				return false;
			}
		}

		//
		// get LocalizedText
		//
		tree = pt.get_child_optional(xmlns.addPrefix("LocalizedText"));
		if (tree) {
			if (!XmlNumber::xmlDecode(*tree, localizedText_)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "LocalizedText");
				return false;
			}
		}

		//
		// get AdditionalInfo
		//
		tree = pt.get_child_optional(xmlns.addPrefix("AdditionalInfo"));
		if (tree) {
			if (!additionalInfo_.xmlDecode(*tree, xmlns)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "AdditionalInfo");
				return false;
			}
		}

		//
		// get InnerStatusCode
		//
		tree = pt.get_child_optional(xmlns.addPrefix("InnerStatusCode"));
		if (tree) {
			OpcUaStatus status;
			if (!status.xmlDecode(*tree, xmlns)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "InnerStatusCode");
				return false;
			}
			innerStatusCode_ = status.enumeration();
		}

		//
		// get InnerDiagnosticInfo
		//
		tree = pt.get_child_optional(xmlns.addPrefix("InnerDiagnosticInfo"));
		if (tree) {
			diagnosticInfo_ = boost::make_shared<OpcUaDiagnosticInfo>();
			if (!diagnosticInfo_->xmlDecode(*tree, xmlns)) {
				Log(Error, "OpcUaDiagnosticInfo decode xml error - element not found")
					.parameter("Element", "InnerDiagnosticInfo");
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaDiagnosticInfo::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{

		bool rc = jsonNumberEncode(pt, symbolicId_, "SymbolicId", true, -1);
		rc &= jsonNumberEncode(pt, namespaceUri_, "NamespaceUri", true, -1);
		rc &= jsonNumberEncode(pt, localizedText_, "LocalizedText", true, -1);
		rc &= jsonNumberEncode(pt, locale_, "Locale", true, -1);
		rc &= jsonObjectEncode(pt, additionalInfo_, "AdditionalInfo", true);
		rc &= jsonNumberEncode(pt, static_cast<OpcUaUInt32>(innerStatusCode_), "InnerStatusCode", true, OpcUaUInt32(0));
		rc &= jsonObjectSPtrEncode(pt, diagnosticInfo_, "InnerDiagnosticInfo", true);

		return rc;
	}

	bool
	OpcUaDiagnosticInfo::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		bool rc = jsonNumberDecode(pt, symbolicId_, "SymbolicId", true, -1);
		rc &= jsonNumberDecode(pt, namespaceUri_, "NamespaceUri", true, -1);
		rc &= jsonNumberDecode(pt, localizedText_, "LocalizedText", true, -1);
		rc &= jsonNumberDecode(pt, locale_, "Locale", true, -1);
		rc &= jsonObjectDecode(pt, additionalInfo_, "AdditionalInfo", true);

		OpcUaUInt32 status;
		rc &= jsonNumberDecode(pt, status, "InnerStatusCode", true, OpcUaUInt32(0));
		innerStatusCode_ = static_cast<OpcUaStatusCode>(status);

		diagnosticInfo_ = boost::make_shared<OpcUaDiagnosticInfo>();
		rc &= jsonObjectSPtrDecode(pt, diagnosticInfo_, "InnerDiagnosticInfo", true);

		return rc;
	}



};
