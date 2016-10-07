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

#ifndef __OpcUaStackServer_SessionMap_h__
#define __OpcUaStackServer_SessionMap_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackServer/ServiceSet/SessionOld.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionElement : public ObjectPool<SessionElement>
	{
	  public:
		typedef boost::shared_ptr<SessionElement> SPtr;

		OpcUaUInt32 authenticationToken_;
		SessionOld::SPtr session_;
	};


	class DLLEXPORT SessionMap
	{
	  public:
		typedef std::map<OpcUaInt32, SessionElement::SPtr> SessionElementMap;

		SessionMap(void);
		~SessionMap(void);

		uint32_t size(void);
		bool insert(OpcUaInt32 authenticationToken, SessionOld::SPtr session);
		bool remove(OpcUaInt32 authenticationToken);
		SessionOld::SPtr get(OpcUaInt32 authenticationToken);

	  private:
		SessionElement::SPtr sessionElement(OpcUaInt32 authenticationToken);

		SessionElementMap sessionElementMap_;
	};

}

#endif
