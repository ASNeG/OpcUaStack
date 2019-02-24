#ifndef __OpcUaStackClient_CryptoManagerTest_h__
#define __OpcUaStackClient_CryptoManagerTest_h__

#include "OpcUaStackCore/Certificate/CryptoManager.h"

using namespace OpcUaStackCore;

class CryptoManagerTest
{
  public:
	static const std::string clientCertificateName_;
	static const std::string serverCertificateName_;

	static const CryptoManager::SPtr& getInstance(void);
	static void delInstance(void);

	static void trustedClientServerCertificates(void);
	static void trustedClientCertificate(void);
	static void trustedServerCertificate(void);
	static void untrustedClientServerCertificates(void);
	static void untrusteClientCertificate(void);
	static void untrusteServerCertificate(void);

	static std::string getServerHostName(void);
	static std::string getServerPkiRootDir(void);

  private:
	static CryptoManager::SPtr cryptoManager_;
};

#endif
