#ifndef __OpcUaStackCore_TimestampsToReturn_h__
#define __OpcUaStackCore_TimestampsToReturn_h__

namespace OpcUaStackCore
{

	typedef enum {
		TimestampsToReturn_Source = 0,
		TimestampsToReturn_Server = 1,
		TimestampsToReturn_Both = 2,
		TimestampsToReturn_Neither = 3
	} TimestampsToReturn;

}

#endif