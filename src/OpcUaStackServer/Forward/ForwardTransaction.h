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

#ifndef __OpcUaStackServer_ForwardTransaction_h__
#define __OpcUaStackServer_ForwardTransaction_h__

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/MessageBus/MessageBusMember.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

#include <vector>

namespace OpcUaStackServer
{
	class DLLEXPORT ForwardTransaction
	: public OpcUaStackCore::Message
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardTransaction>;
		using WPtr = boost::weak_ptr<ForwardTransaction>;
		using Vec = std::vector<SPtr>;

		ForwardTransaction(
			OpcUaStackCore::OpcUaUInt32 nodeTypeRequest,
			OpcUaStackCore::OpcUaUInt32 nodeTypeResponse
		);
		~ForwardTransaction(void);

		OpcUaStackCore::OpcUaNodeId& nodeTypeRequest(void);
		OpcUaStackCore::OpcUaNodeId& nodeTypeResponse(void);

		void messageBusMemberSource(const OpcUaStackCore::MessageBusMember::WPtr& messageBusMemberSource);
		OpcUaStackCore::MessageBusMember::WPtr messageBusMemberSource(void);
		void messageBusMemberTarget(const OpcUaStackCore::MessageBusMember::WPtr& messageBusMemberTarget);
		OpcUaStackCore::MessageBusMember::WPtr messageBusMemberTarget(void);

		void name(const std::string& name);
		std::string& name(void);
		void applicationContext(const OpcUaStackCore::BaseClass::SPtr& applicationContext);
		OpcUaStackCore::BaseClass::SPtr applicationContext(void);
		void forwardJob(const OpcUaStackCore::Object::WPtr& forwardJob);
		OpcUaStackCore::Object::WPtr& forwardJob(void);
		void idx(uint32_t idx);
		uint32_t idx(void);
		void complete(bool complete);
		bool complete(void);
		void userContext(const OpcUaStackCore::UserContext::SPtr& userContext);
		OpcUaStackCore::UserContext::SPtr userContext(void);
		void statusCode(OpcUaStackCore::OpcUaStatusCode statusCode);
		OpcUaStackCore::OpcUaStatusCode statusCode(void);

	  private:
		OpcUaStackCore::MessageBusMember::WPtr messageBusMemberSource_;
		OpcUaStackCore::MessageBusMember::WPtr messageBusMemberTarget_;

		OpcUaStackCore::OpcUaNodeId nodeTypeRequest_;
		OpcUaStackCore::OpcUaNodeId nodeTypeResponse_;

		std::string name_ = "Unknown";
		OpcUaStackCore::BaseClass::SPtr applicationContext_ = nullptr;
		OpcUaStackCore::OpcUaStatusCode statusCode_ = OpcUaStackCore::Success; // status code
		OpcUaStackCore::UserContext::SPtr userContext_;	// user context
		OpcUaStackCore::Object::WPtr forwardJob_;	// reference to the associated job
		uint32_t idx_ = 0;							// index of the entry in the service transaction
		bool complete_ = false;						// transaction completed

	};
}

#endif
