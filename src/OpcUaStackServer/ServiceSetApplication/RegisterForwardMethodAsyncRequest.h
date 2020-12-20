/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_RegisterForwardMethodAsyncRequest_h__
#define __OpcUaStackServer_RegisterForwardMethodAsyncRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardMethodAsync.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardMethodAsyncRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardMethodAsyncRequest> SPtr;

		RegisterForwardMethodAsyncRequest(void);
		virtual ~RegisterForwardMethodAsyncRequest(void);

		void forwardMethodAsync(ForwardMethodAsync::SPtr forwardMethodAsync);
		ForwardMethodAsync::SPtr& forwardMethodAsync(void);
		void objectNodeId(OpcUaStackCore::OpcUaNodeId& objectNodeId);
		OpcUaStackCore::OpcUaNodeId& objectNodeId(void);
		void methodNodeId(OpcUaStackCore::OpcUaNodeId& methodNodeId);
		OpcUaStackCore::OpcUaNodeId& methodNodeId(void);

		bool opcUaBinaryEncode(std::ostream& os) const { return true; }
		bool opcUaBinaryDecode(std::istream& is) { return true; }

	  private:
		ForwardMethodAsync::SPtr forwardMethodAsync_;
		OpcUaStackCore::OpcUaNodeId objectNodeId_;
		OpcUaStackCore::OpcUaNodeId methodNodeId_;
	};

}

#endif
