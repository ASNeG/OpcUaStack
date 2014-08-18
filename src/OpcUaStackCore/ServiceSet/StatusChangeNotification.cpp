#include "OpcUaStackCore/ServiceSet/StatusChangeNotification.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DataChangeNotification
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	StatusChangeNotification::StatusChangeNotification(void)
	: ObjectPool<StatusChangeNotification>()
	, statusCode_()
	, diagnosticInfo_()
	{
	}

	StatusChangeNotification::~StatusChangeNotification(void)
	{
	}

	void 
	StatusChangeNotification::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode& 
	StatusChangeNotification::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	StatusChangeNotification::diagnosticInfo(const OpcUaDiagnosticInfo& diagnosticInfo)
	{
		diagnosticInfo_ = diagnosticInfo;
	}
	
	OpcUaDiagnosticInfo& 
	StatusChangeNotification::diagnosticInfo(void)
	{
		return diagnosticInfo_;
	}

	ExtensibleParameterBase::BSPtr 
	StatusChangeNotification::factory(void)
	{
		return StatusChangeNotification::construct();
	}

	void 
	StatusChangeNotification::opcUaBinaryEncode(std::ostream& os) const
	{
		// FIXME: magic (OpcUaInt32), see EventNotificationList or DataChangeNotification ???
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		diagnosticInfo_.opcUaBinaryEncode(os);
	}
	
	void 
	StatusChangeNotification::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: magic (OpcUaInt32), see EventNotificationList or DataChangeNotification ???
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		diagnosticInfo_.opcUaBinaryDecode(is);
	}
}