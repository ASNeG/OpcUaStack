/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/EventType/EventBase.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT FireEvent
	{
	  public:
		typedef boost::shared_ptr<FireEvent> SPtr;

		FireEvent(void);
		FireEvent(const OpcUaStackCore::OpcUaNodeId& node, const OpcUaStackCore::EventBase::SPtr& eventBase);
		virtual ~FireEvent(void);

		void node(const OpcUaStackCore::OpcUaNodeId& node);
		void eventBase(const OpcUaStackCore::EventBase::SPtr& eventBase);

		bool fireEvent(ApplicationServiceIf* applicationServiceIf);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

	  private:
		OpcUaStackCore::OpcUaNodeId node_;
		OpcUaStackCore::EventBase::SPtr eventBase_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
	};

}
#endif
