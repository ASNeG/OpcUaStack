#ifndef __OpcUaStackCore_os_h__
#define __OpcUaStackCore_os_h__

#ifdef WIN32

#define DLLEXPORT __declspec(dllexport)
#pragma warning(disable:4251)

#else

#define DLLEXPORT

#endif

#endif
