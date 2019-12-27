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

#include "OpcUaStackCore/ServiceSet/ViewDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ViewDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ViewDescription::ViewDescription(void)
	: Object()
	, viewIdSPtr_(boost::make_shared<OpcUaNodeId>())
	, timestamp_()
	, viewVersion_()
	{
	}

	ViewDescription::~ViewDescription(void)
	{
	}

	void 
	ViewDescription::viewId(const OpcUaNodeId::SPtr viewId)
	{
		viewIdSPtr_ = viewId;
	}
	
	OpcUaNodeId::SPtr 
	ViewDescription::viewId(void)
	{
		return viewIdSPtr_;
	}
	
	void 
	ViewDescription::timestamp(const OpcUaUtcTime& timestamp)
	{
		timestamp_ = timestamp;
	}
	
	void 
	ViewDescription::timestamp(const boost::posix_time::ptime& timestamp)
	{
		timestamp_.dateTime(timestamp);
	}
	
	OpcUaUtcTime&
	ViewDescription::timestamp(void)
	{
		return timestamp_;
	}
	
	void 
	ViewDescription::viewVersion(const OpcUaUInt32& viewVersion)
	{
		viewVersion_ = viewVersion;
	}
	
	OpcUaUInt32 
	ViewDescription::viewVersion(void)
	{
		return viewVersion_;
	}

	void
	ViewDescription::copyTo(ViewDescription& viewDescription)
	{
		viewIdSPtr_->copyTo(*viewDescription.viewId().get());
		timestamp_.copyTo(viewDescription.timestamp());
		viewDescription.viewVersion(viewVersion_);
	}

	bool
	ViewDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= viewIdSPtr_->opcUaBinaryEncode(os);
		rc &= timestamp_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, viewVersion_);

		return rc;
	}
	
	bool
	ViewDescription::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= viewIdSPtr_->opcUaBinaryDecode(is);
		rc &= timestamp_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, viewVersion_);

		return rc;
	}

	bool
	ViewDescription::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = jsonObjectSPtrEncode(pt, viewIdSPtr_, "ViewId", true);
		rc &= jsonObjectEncode(pt, timestamp_, "Timestamp", true);
		rc &= jsonNumberEncode(pt, viewVersion_, "ViewVersion", true, OpcUaUInt32(0));
		return rc;
	}

	bool
	ViewDescription::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = jsonObjectSPtrDecode(pt, viewIdSPtr_, "ViewId", true);
		rc &= jsonObjectDecode(pt, timestamp_, "Timestamp", true);
		rc &= jsonNumberDecode(pt, viewVersion_, "ViewVersion", true, OpcUaUInt32(0));
		return rc;
	}

}
