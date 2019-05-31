/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Random_h__
#define __OpcUaStackCore_Random_h__

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ContextPSHA256
	{
	  public:
		ContextPSHA256(void);
		~ContextPSHA256(void);

		void set(MemoryBuffer& secret, MemoryBuffer& seed);
		uint32_t aLen(void);
		uint32_t seedLen(void);
		uint32_t secretLen(void);
		char* a(void);
		char* seed(void);
		char* secret(void);

	  private:
		uint32_t secretLen_;
		uint32_t seedLen_;
		MemoryBuffer context_;	// a - seed - secret
	};

	class DLLEXPORT ContextPSHA1
	{
	  public:
		ContextPSHA1(void);
		~ContextPSHA1(void);

		void set(MemoryBuffer& secret, MemoryBuffer& seed);
		uint32_t aLen(void);
		uint32_t seedLen(void);
		uint32_t secretLen(void);
		char* a(void);
		char* seed(void);
		char* secret(void);

	  private:
		uint32_t secretLen_;
		uint32_t seedLen_;
		MemoryBuffer context_;	// a - seed - secret
	};


	class DLLEXPORT Random
	: public OpenSSLError
	{
	  public:
		Random(void);
		virtual ~Random(void);

		OpcUaStatusCode getPSHA256Context(
			MemoryBuffer& secret,
			MemoryBuffer& seed,
			ContextPSHA256& ctx
		);

		OpcUaStatusCode getPSHA1Context(
			MemoryBuffer& secret,
			MemoryBuffer& seed,
			ContextPSHA1& ctx
		);

		OpcUaStatusCode hashGeneratePSHA256(
			ContextPSHA256& ctx,
			char* hash
		);

		OpcUaStatusCode hashGeneratePSHA1(
			ContextPSHA1& ctx,
			char* hash
		);

		OpcUaStatusCode keyDerivePSHA256(
			MemoryBuffer& secret,			// remote nonce
		    MemoryBuffer& seed,				// local nonce
			MemoryBuffer& key				// output len = sig key + enc key + iv
		);

		OpcUaStatusCode keyDerivePSHA1(
			MemoryBuffer& secret,			// remote nonce
		    MemoryBuffer& seed,				// local nonce
			MemoryBuffer& key				// output len = sig key + enc key + iv
		);

	  private:
	};
}

#endif
