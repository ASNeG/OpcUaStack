#ifndef __OpcUaStackCore_os_h__
#define __OpcUaStackCore_os_h__

#ifdef WIN32

	#define DLLEXPORT __declspec(dllexport)
	#pragma warning(disable:4251)

	#define NAMESPACE_BEGIN(name) namespace name {
   	#define NAMESPACE_END }


	#define CONNECTION_OPERATION_ABORTED	ERROR_OPERATION_ABORTED 
	#define CONNECTION_CLOSE_LOCAL			ERROR_CONNECTION_ABORTED
	#define CONNECTION_CLOSE_REMOTE			boost::asio::error::connection_reset

#else

	#define DLLEXPORT

	#define NAMESPACE_BEGIN(name) extern "C" { namespace  name {
 	#define NAMESPACE_END } }

	#define CONNECTION_OPERATION_ABORTED 		boost::asio::error::operation_aborted	
    #define CONNECTION_CLOSE_LOCAL	  		boost::asio::error::operation_aborted	
    #define CONNECTION_CLOSE_REMOTE			boost::asio::error::eof


#endif

#endif
