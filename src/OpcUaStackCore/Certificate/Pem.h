/*
   Copyright 2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Pemrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_Pem_h__
#define __OpcUaStackCore_Pem_h__

#include <boost/shared_ptr.hpp>

#include <string>

#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/BIOCtx.h"
#include "OpcUaStackCore/Base/MemoryBuffer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Pem
	: public OpenSSLError
	{
	  public:
		using SPtr = boost::shared_ptr<Pem>;

		Pem(void);
		~Pem(void);

		bool toText(
			MemoryBuffer& memoryBuffer,
			std::string& str,
			const std::string& textName
		);

		bool toBIO(
			MemoryBuffer& memoryBuffer,
			BIOCtx& bioCtx,
			const std::string& textName
		);

		bool fromText(
			std::string& str,
			MemoryBuffer& memoryBuffer,
			std::string& textName
		);

		bool fromBIO(
			BIOCtx& bioCtx,
			MemoryBuffer& memoryBuffer,
			std::string& textName
		);
	};
}

#endif
