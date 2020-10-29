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

#ifndef __OpcUaStackCore_RegisterForwardNodeAsyncRequest_h__
#define __OpcUaStackCore_RegisterForwardNodeAsyncRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardNodeAsync.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterForwardNodeAsyncRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardNodeAsyncRequest> SPtr;

		RegisterForwardNodeAsyncRequest(void);
		virtual ~RegisterForwardNodeAsyncRequest(void);

		void nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister);
		OpcUaNodeIdArray::SPtr nodesToRegister(void) const;
		void forwardNodeAsync(ForwardNodeAsync::SPtr forwardInfo);
		ForwardNodeAsync::SPtr forwardNodeAsync(void);
		void applicationContextArray(BaseClassArray::SPtr& applicationContextArray);
		BaseClassArray::SPtr& applicationContextArray(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		ForwardNodeAsync::SPtr forwardNodeAsync_;
		OpcUaNodeIdArray::SPtr nodesToRegisterArraySPtr_;
		BaseClassArray::SPtr applicationContextArray_;
	};

}

#endif
