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

#ifndef __OpcUaStackServer_RegisterForwardMethodRequest_h__
#define __OpcUaStackServer_RegisterForwardMethodRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardMethodSync.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardMethodRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardMethodRequest> SPtr;

		RegisterForwardMethodRequest(void);
		virtual ~RegisterForwardMethodRequest(void);

		void forwardMethodSync(OpcUaStackCore::ForwardMethodSync::SPtr forwardMethodSync);
		OpcUaStackCore::ForwardMethodSync::SPtr& forwardMethodSync(void);
		void objectNodeId(OpcUaStackCore::OpcUaNodeId& objectNodeId);
		OpcUaStackCore::OpcUaNodeId& objectNodeId(void);
		void methodNodeId(OpcUaStackCore::OpcUaNodeId& methodNodeId);
		OpcUaStackCore::OpcUaNodeId& methodNodeId(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStackCore::ForwardMethodSync::SPtr forwardMethodSync_;
		OpcUaStackCore::OpcUaNodeId objectNodeId_;
		OpcUaStackCore::OpcUaNodeId methodNodeId_;
	};

}

#endif
