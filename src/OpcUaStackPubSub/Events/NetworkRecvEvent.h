/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackPubSub_NetworkRecvEvent_h__
#define __OpcUaStackPubSub_NetworkRecvEvent_h__

#include <boost/asio.hpp>
#include "OpcUaStackPubSub/Events/Event.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT NetworkRecvEvent
	: public Event
	{
	  public:
		using SPtr = boost::shared_ptr<NetworkRecvEvent>;

		NetworkRecvEvent(void);
		~NetworkRecvEvent(void);

		boost::asio::streambuf& streamBuf(void);

	  private:
		boost::asio::streambuf streamBuf_;
	};

}

#endif
