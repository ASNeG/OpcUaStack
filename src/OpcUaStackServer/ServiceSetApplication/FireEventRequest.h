/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_FireEventRequest_h__
#define __OpcUaStackServer_FireEventRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/EventType/EventBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT FireEventRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<FireEventRequest> SPtr;

		FireEventRequest(void);
		virtual ~FireEventRequest(void);

		void eventBase(OpcUaStackCore::EventBase::SPtr& eventBase);
		OpcUaStackCore::EventBase::SPtr& eventBase(void);
		void nodeId(OpcUaStackCore::OpcUaNodeId& nodeId);
		OpcUaStackCore::OpcUaNodeId& nodeId(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStackCore::EventBase::SPtr eventBase_;
		OpcUaStackCore::OpcUaNodeId nodeId_;
	};

}

#endif
