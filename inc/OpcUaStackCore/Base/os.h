#ifndef __OpcUaStackCore_os_h__
#define __OpcUaStackCore_os_h__

#ifdef WIN32

	#define DLLEXPORT __declspec(dllexport)
	#pragma warning(disable:4251)

	#define NAMESPACE_BEGIN(name) namespace name {
   	#define NAMESPACE_END }

#else

	#define DLLEXPORT

	#define NAMESPACE_BEGIN(name) extern "C" { namespace  name {
 	#define NAMESPACE_END } }

#endif

#endif
