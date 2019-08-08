/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ApplicationCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ApplicationCertificate_h__
#define __OpcUaStackCore_ApplicationCertificate_h__

#include <boost/shared_ptr.hpp>
#include <string>
#include "OpcUaStackCore/Certificate/Certificate.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/CertificateManager.h"

namespace OpcUaStackCore
{

	/**
	 * This class manages application instance certificates
	 *
	 */
	class DLLEXPORT ApplicationCertificate
	{
	  public:
		typedef boost::shared_ptr<ApplicationCertificate> SPtr;

		ApplicationCertificate(void);
		~ApplicationCertificate(void);

		bool init(CertificateManager::SPtr& certificateManager);
		bool cleanup(void);

		bool enable(void);
		CertificateChain& certificateChain(void);
		PrivateKey::SPtr& privateKey(void);

	  private:
		bool createSelfSignedCertificate(CertificateManager::SPtr& certificateManager);
		bool readCertificateAndPrivateKey(CertificateManager::SPtr& certificateManager);
		bool readCertificateChain(Certificate::SPtr& certificate, CertificateManager::SPtr& certificateManager);

		bool enable_;
		CertificateChain certificateChain_;
		PrivateKey::SPtr privateKey_;
	};

}

#endif
