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
	, viewIdSPtr_(constructSPtr<OpcUaNodeId>())
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
	ViewDescription::timestamp(const UtcTime& timestamp)
	{
		timestamp_ = timestamp;
	}
	
	void 
	ViewDescription::timestamp(const boost::posix_time::ptime& timestamp)
	{
		timestamp_.dateTime(timestamp);
	}
	
	UtcTime& 
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
	ViewDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		viewIdSPtr_->opcUaBinaryEncode(os);
		timestamp_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, viewVersion_);
	}
	
	void 
	ViewDescription::opcUaBinaryDecode(std::istream& is)
	{
		viewIdSPtr_->opcUaBinaryDecode(is);
		timestamp_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, viewVersion_);
	}

}
