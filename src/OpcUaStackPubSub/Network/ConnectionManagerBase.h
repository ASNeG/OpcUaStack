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

#ifndef __OpcUaStackPubSub_ConnectionManagerBase_h__
#define __OpcUaStackPubSub_ConnectionManagerBase_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/Network/NetworkReceiverIf.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT ConnectionManagerBase
	{
	  public:
		typedef boost::shared_ptr<ConnectionManagerBase> SPtr;

		ConnectionManagerBase(void);
		virtual ~ConnectionManagerBase(void);

		bool registerReceiverIf(const NetworkReceiverIf::SPtr& receiver);
		bool deregisterReceiverIf(const NetworkReceiverIf::SPtr& receiver);

		virtual bool startup() = 0;
		virtual bool shutdown() = 0;

	  protected:
		NetworkReceiverIf::Set receiverSet_;

	};

}

#endif
