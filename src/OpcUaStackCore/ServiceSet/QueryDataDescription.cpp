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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/ServiceSet/QueryDataDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryDataDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryDataDescription::QueryDataDescription(void)
	: Object()
	, relativePath_()
	, attributeId_()
	, indexRange_()
	{
	}

	QueryDataDescription::~QueryDataDescription(void)
	{
	}

	void 
	QueryDataDescription::relativePath(const RelativePath& relativePath)
	{
		relativePath_ = relativePath;
	}
	
	RelativePath& 
	QueryDataDescription::relativePath(void)
	{
		return relativePath_;
	}
	
	void 
	QueryDataDescription::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}
	
	OpcUaUInt32 
	QueryDataDescription::attributeId(void)
	{
		return attributeId_;
	}
	
	void 
	QueryDataDescription::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}
	
	void 
	QueryDataDescription::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}
	
	OpcUaString& 
	QueryDataDescription::indexRange(void)
	{
		return indexRange_;
	}

	bool
	QueryDataDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= relativePath_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		rc &= indexRange_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	QueryDataDescription::opcUaBinaryDecode(std::istream& is)
	{
		bool rc= true;

		rc &= relativePath_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		rc &= indexRange_.opcUaBinaryDecode(is);

		return rc;
	}

}
