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

#include "OpcUaStackCore/ServiceSet/ModificationInfo.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModificationInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModificationInfo::ModificationInfo(void)
	: Object()
	, username_()
	, modificationTime_()
	, updateType_()
	{
	}

	ModificationInfo::~ModificationInfo(void)
	{
	}

	void 
	ModificationInfo::username(const OpcUaString& username)
	{
		username_ = username;
	}
	
	void 
	ModificationInfo::username(const std::string& username)
	{
		username_.value(username);
	}
	
	OpcUaString& 
	ModificationInfo::username(void)
	{
		return username_;
	}
	
	void 
	ModificationInfo::modificationTime(const UtcTime& modificationTime)
	{
		modificationTime_ = modificationTime;
	}
	
	void 
	ModificationInfo::modificationTime(const boost::posix_time::ptime& modificationTime)
	{
		modificationTime_.dateTime(modificationTime);
	}
	
	UtcTime& 
	ModificationInfo::modificationTime(void)
	{
		return modificationTime_;
	}
	
	void 
	ModificationInfo::updateType(const HistoryUpdateMode updateType)
	{
		updateType_ = updateType;
	}
	
	HistoryUpdateMode 
	ModificationInfo::updateType(void)
	{
		return updateType_;
	}

	void 
	ModificationInfo::opcUaBinaryEncode(std::ostream& os) const
	{
		username_.opcUaBinaryEncode(os);
		modificationTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)updateType_);
	}
	
	void 
	ModificationInfo::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		username_.opcUaBinaryDecode(is);
		modificationTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		updateType_ = (HistoryUpdateMode)tmp;
	}
}
