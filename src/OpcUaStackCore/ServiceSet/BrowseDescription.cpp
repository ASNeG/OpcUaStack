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

#include "OpcUaStackCore/ServiceSet/BrowseDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseDescription::BrowseDescription(void)
	: Object()
	, nodeIdSPtr_(boost::make_shared<OpcUaNodeId>())
	, browseDirection_()
	, referenceTypeIdSPtr_(boost::make_shared<OpcUaNodeId>())
	, includeSubtypes_()
	, nodeClassMask_()
	, resultMask_()
	{
	}

	BrowseDescription::~BrowseDescription(void)
	{
	}

	void 
	BrowseDescription::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaNodeId::SPtr 
	BrowseDescription::nodeId(void) const
	{
		return nodeIdSPtr_;
	}
	
	void 
	BrowseDescription::browseDirection(const BrowseDirectionEnum browseDirection)
	{
		browseDirection_ = browseDirection;
	}
	
	BrowseDirectionEnum 
	BrowseDescription::browseDirection(void)
	{
		return browseDirection_;
	}

	void 
	BrowseDescription::referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId)
	{
		referenceTypeIdSPtr_ = referenceTypeId;
	}
	
	OpcUaNodeId::SPtr 
	BrowseDescription::referenceTypeId(void) const
	{
		return referenceTypeIdSPtr_;
	}
	
	void 
	BrowseDescription::includeSubtypes(const OpcUaBoolean includeSubtypes)
	{
		includeSubtypes_ = includeSubtypes;
	}
	
	OpcUaBoolean 
	BrowseDescription::includeSubtypes(void)
	{
		return includeSubtypes_;
	}
	
	void 
	BrowseDescription::nodeClassMask(const OpcUaUInt32 nodeClassMask)
	{
		nodeClassMask_ = nodeClassMask;
	}
	
	OpcUaUInt32 
	BrowseDescription::nodeClassMask(void)
	{
		return nodeClassMask_;
	}
	
	void 
	BrowseDescription::resultMask(const OpcUaUInt32 resultMask)
	{
		resultMask_ = resultMask;
	}
	
	OpcUaUInt32 
	BrowseDescription::resultMask(void)
	{
		return resultMask_;
	}

	void
	BrowseDescription::copyTo(BrowseDescription& browseDescription)
	{
		nodeIdSPtr_->copyTo(*browseDescription.nodeId().get());
		browseDescription.browseDirection(browseDirection_);
		referenceTypeIdSPtr_->copyTo(*browseDescription.referenceTypeId().get());
		browseDescription.includeSubtypes(includeSubtypes_);
		browseDescription.nodeClassMask(nodeClassMask_);
		browseDescription.resultMask(resultMask_);
	}

	void 
	BrowseDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)browseDirection_);
		referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		OpcUaNumber::opcUaBinaryEncode(os, nodeClassMask_);
		OpcUaNumber::opcUaBinaryEncode(os, resultMask_);
	}
	
	void 
	BrowseDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		nodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		browseDirection_ = (BrowseDirectionEnum)tmp;
		referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		OpcUaNumber::opcUaBinaryDecode(is, nodeClassMask_);
		OpcUaNumber::opcUaBinaryDecode(is, resultMask_);
	}

	bool
	BrowseDescription::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		bool rc = jsonObjectSPtrEncode(pt, nodeIdSPtr_, "NodeId");
		rc &= jsonNumberEncode(pt, (OpcUaUInt32)browseDirection_, "BrowseDirection");
		rc &= jsonObjectSPtrEncode(pt, referenceTypeIdSPtr_, "ReferenceTypeId", true);
		rc &= jsonNumberEncode(pt, includeSubtypes_, "IncludeSubtypes");
		rc &= jsonNumberEncode(pt, nodeClassMask_, "NodeClassMask");
		rc &= jsonNumberEncode(pt, resultMask_, "ResultMask");

		return rc;
	}

	bool
	BrowseDescription::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		bool rc = jsonObjectSPtrDecode(pt, nodeIdSPtr_, "NodeId");

		OpcUaUInt32 tmp;
		rc &= jsonNumberDecode(pt, tmp, "BrowseDirection");
		browseDirection_ = (BrowseDirectionEnum)tmp;

		rc &= jsonObjectSPtrDecode(pt, referenceTypeIdSPtr_, "ReferenceTypeId", true);
		rc &= jsonNumberDecode(pt, includeSubtypes_, "IncludeSubtypes");
		rc &= jsonNumberDecode(pt, nodeClassMask_, "NodeClassMask");
		rc &= jsonNumberDecode(pt, resultMask_, "ResultMask");

		return rc;
	}


}
