#ifndef __OpcUaStackClient_CryptoManagerTest_h__
#define __OpcUaStackClient_CryptoManagerTest_h__

#include "OpcUaStackCore/Certificate/CryptoManager.h"

using namespace OpcUaStackCore;

class CryptoManagerTest
{
  public:
	static const CryptoManager::SPtr& getInstance(void);
	static void delInstance(void);

  private:
	static CryptoManager::SPtr cryptoManager_;
};

#endif
