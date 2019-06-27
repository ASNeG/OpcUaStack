/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateChainrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_CertificateChain_h__
#define __OpcUaStackCore_CertificateChain_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Certificate/Certificate.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CertificateChain
	{
	  public:
		typedef boost::shared_ptr<CertificateChain> SPtr;

		CertificateChain(void);
		~CertificateChain(void);

		void clear(void);
		Certificate::Vec& certificateVec(void);
		void addCertificate(Certificate::SPtr& certificate);
		Certificate::SPtr getCertificate(uint32_t idx = 0);

		uint32_t size(void);
		bool fromByteString(OpcUaByteString& byteString);
		bool toByteString(OpcUaByteString& byteString);

	  private:
		Certificate::Vec certificateVec_;
	};

}

#endif
