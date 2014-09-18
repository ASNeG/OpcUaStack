#ifndef __OpcUaStackCore_MonitoringMode_h__
#define __OpcUaStackCore_MonitoringMode_h__

namespace OpcUaStackCore
{

	typedef enum {
		MonitoringMode_Disabled = 0,
		MonitoringMode_Sampling = 1,
		MonitoringMode_Reporting = 2
	} MonitoringMode;

}

#endif