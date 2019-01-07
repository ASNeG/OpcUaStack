/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_FireEvent_h__
#define __OpcUaStackServer_FireEvent_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/EventType/EventBase.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT FireEvent
	{
	  public:
		typedef boost::shared_ptr<FireEvent> SPtr;

		FireEvent(void);
		FireEvent(const OpcUaNodeId& node, const EventBase::SPtr& eventBase);
		virtual ~FireEvent(void);

		void node(const OpcUaNodeId& node);
		void eventBase(const EventBase::SPtr& eventBase);

		bool fireEvent(ApplicationServiceIf* applicationServiceIf);
		OpcUaStatusCode resultCode(void);

	  private:
		OpcUaNodeId node_;
		EventBase::SPtr eventBase_;
		OpcUaStatusCode resultCode_;
	};

}
#endif
