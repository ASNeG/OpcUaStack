/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_RegisterForwardNodeRequest_h__
#define __OpcUaStackServer_RegisterForwardNodeRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardNodeSync.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardNodeRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardNodeRequest> SPtr;

		RegisterForwardNodeRequest(void);
		virtual ~RegisterForwardNodeRequest(void);

		void nodesToRegister(const OpcUaStackCore::OpcUaNodeIdArray::SPtr nodesToRegister);
		OpcUaStackCore::OpcUaNodeIdArray::SPtr nodesToRegister(void) const;
		void forwardNodeSync(ForwardNodeSync::SPtr forwardInfo);
		ForwardNodeSync::SPtr forwardNodeSync(void);
		void applicationContextArray(OpcUaStackCore::BaseClassArray::SPtr& applicationContextArray);
		OpcUaStackCore::BaseClassArray::SPtr& applicationContextArray(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		ForwardNodeSync::SPtr forwardNodeSync_;
		OpcUaStackCore::OpcUaNodeIdArray::SPtr nodesToRegisterArraySPtr_;
		OpcUaStackCore::BaseClassArray::SPtr applicationContextArray_;
	};

}

#endif
