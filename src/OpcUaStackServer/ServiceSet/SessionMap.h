#ifndef __OpcUaStackServer_SessionMap_h__
#define __OpcUaStackServer_SessionMap_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackServer/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionElement : public ObjectPool<SessionElement>
	{
	  public:
		typedef boost::shared_ptr<SessionElement> SPtr;

		OpcUaUInt32 authenticationToken_;
		Session::SPtr session_;
	};


	class DLLEXPORT SessionMap
	{
	  public:
		typedef std::map<OpcUaInt32, SessionElement::SPtr> SessionElementMap;

		SessionMap(void);
		~SessionMap(void);

		uint32_t size(void);
		bool insert(OpcUaInt32 authenticationToken, Session::SPtr session);
		bool remove(OpcUaInt32 authenticationToken);
		Session::SPtr get(OpcUaInt32 authenticationToken);

	  private:
		SessionElement::SPtr sessionElement(OpcUaInt32 authenticationToken);

		SessionElementMap sessionElementMap_;
	};

}

#endif