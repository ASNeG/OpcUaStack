/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	: ObjectPool<QueryDataDescription>()
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

	void 
	QueryDataDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		relativePath_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryDataDescription::opcUaBinaryDecode(std::istream& is)
	{
		relativePath_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
	}

}
