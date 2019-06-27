/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackPubSub_NetworkReceiverIf_h__
#define __OpcUaStackPubSub_NetworkReceiverIf_h__

#include <set>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/Network/NetworkMessage.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT NetworkReceiverIf
	{
	  public:
		typedef boost::shared_ptr<NetworkReceiverIf> SPtr;
		typedef std::set<NetworkReceiverIf::SPtr> Set;

		NetworkReceiverIf(void);
		virtual ~NetworkReceiverIf(void);

		virtual bool receive(const NetworkMessage& message) = 0;

	  private:
	};

}

#endif
