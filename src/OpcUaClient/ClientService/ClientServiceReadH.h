/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_ClientServiceReadH_h__
#define __OpcUaClient_ClientServiceReadH_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Utility/CSV.h"
#include "OpcUaClient/ClientService/ClientServiceBase.h"
#include "OpcUaClient/ClientService/ClientServiceManager.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ReadNextNode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	class ReadNextNode
	{
	  public:
		typedef std::vector<ReadNextNode> Vec;

		ReadNextNode(void) {}
		~ReadNextNode(void) {}

		OpcUaNodeId nodeId_;
		std::string continousPoint_;
	};


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ClientServiceReadH
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	class ClientServiceReadH
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<ClientServiceReadH> SPtr;

		ClientServiceReadH(void);
		virtual ~ClientServiceReadH(void);

		//- ClientServiceReadH interface ---------------------------------------
		virtual ClientServiceBase::SPtr createClientService(void);
		virtual bool run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase);
		//- ClientServiceReadH interface ---------------------------------------

      private:
		bool hRead(
			AttributeService::SPtr& attributeService,
			CommandReadH::SPtr& commandReadH
		);
		bool hReadNext(
			AttributeService::SPtr& attributeService,
			CommandReadH::SPtr& commandReadH,
			ReadNextNode::Vec& readNextNodeVec
		);
		bool hDelete(
			AttributeService::SPtr& attributeService,
			CommandReadH::SPtr& commandReadH,
			ReadNextNode::Vec& readNextNodeVec
		);
		bool output(
			OpcUaDataValue& dataValue,
			CommandReadH::SPtr& commandReadH
		);
		bool outputCSV(
			OpcUaDataValue& dataValue,
			CommandReadH::SPtr& commandReadH
		);

		CSV::SPtr csv_;
	};

}

#endif

