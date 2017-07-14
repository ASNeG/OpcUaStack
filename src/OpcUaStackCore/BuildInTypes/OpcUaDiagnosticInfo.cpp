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

#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"

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
	}

	void 
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

		OpcUaNumber::opcUaBinaryEncode(os,encodingMask);
		if (symbolicId_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,symbolicId_);
		}
		if (namespaceUri_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,namespaceUri_);
		}
		if (localizedText_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,localizedText_);
		}
		if (locale_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,locale_);
		}
		if (additionalInfo_.exist()) {
			additionalInfo_.opcUaBinaryEncode(os);
		}
		if (innerStatusCode_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os, innerStatusCode_);
		}
	}
		
	void 
	OpcUaDiagnosticInfo::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaNumber::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			OpcUaNumber::opcUaBinaryDecode(is,symbolicId_);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaNumber::opcUaBinaryDecode(is,namespaceUri_);
		}
		if ((encodingMask & 0x04) == 0x04) {
			OpcUaNumber::opcUaBinaryDecode(is,localizedText_);
		}
		if ((encodingMask & 0x08) == 0x08) {
			OpcUaNumber::opcUaBinaryDecode(is,locale_);
		}
		if ((encodingMask & 0x10) == 0x10) {
			additionalInfo_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaInt32 tmp;
			OpcUaNumber::opcUaBinaryDecode(is, tmp); innerStatusCode_ = (OpcUaStatusCode)tmp;
		}
	}

	bool
	OpcUaDiagnosticInfo::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	OpcUaDiagnosticInfo::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	OpcUaDiagnosticInfo::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

};
