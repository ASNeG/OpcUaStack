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

#ifndef __OpcUaStackCore_os_h__
#define __OpcUaStackCore_os_h__

#ifdef _WIN32
	
	#define _WIN32_WINNT	0x0501

	#define DLLEXPORT __declspec(dllexport)
	#pragma warning(disable:4251)

	#define NAMESPACE_BEGIN(name) namespace name {
   	#define NAMESPACE_END }


	#define CONNECTION_OPERATION_ABORTED	ERROR_OPERATION_ABORTED 
	#define CONNECTION_CLOSE_LOCAL			ERROR_CONNECTION_ABORTED
	#define CONNECTION_CLOSE_REMOTE			boost::asio::error::connection_reset
	#define CONNECTION_CLOSE_EOF			boost::asio::error::eof			

#else

	#define DLLEXPORT

	#define NAMESPACE_BEGIN(name) extern "C" { namespace  name {
 	#define NAMESPACE_END } }

	#define CONNECTION_OPERATION_ABORTED 	boost::asio::error::operation_aborted	
    #define CONNECTION_CLOSE_LOCAL	  		boost::asio::error::operation_aborted	
    #define CONNECTION_CLOSE_REMOTE			boost::asio::error::eof
	#define CONNECTION_CLOSE_EOF			boost::asio::error::eof

	#if __cplusplus < 201103L
		#define nullptr 				NULL
	#endif

#endif

#endif
