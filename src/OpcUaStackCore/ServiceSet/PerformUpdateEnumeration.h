#ifndef __OpcUaStackCore_PerformUpdateEnumeration_h__
#define __OpcUaStackCore_PerformUpdateEnumeration_h__

namespace OpcUaStackCore
{

	typedef enum {
		PerformUpdateEnumeration_Insert = 1,
		PerformUpdateEnumeration_Replace = 2, 
		PerformUpdateEnumeration_Update = 3,
		PerformUpdateEnumeration_Remove = 4
	} PerformUpdateEnumeration;

}

#endif