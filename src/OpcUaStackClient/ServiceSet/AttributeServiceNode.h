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

#ifndef __OpcUaStackClient_AttributeServiceNode_h__
#define __OpcUaStackClient_AttributeServiceNode_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeServiceNodeIf
	{
	  public:
		AttributeServiceNodeIf(void) {}
		virtual ~AttributeServiceNodeIf(void) {}

		virtual void done(OpcUaStatusCode statusCode) = 0;
	};


	class DLLEXPORT AttributeServiceNode
	: public AttributeServiceIf
	{
	  public:
		typedef boost::shared_ptr<AttributeServiceNode> SPtr;

		AttributeServiceNode(void);
		~AttributeServiceNode(void);

		void attributeService(AttributeService::SPtr& attributeService);
		void attributeServiceBrowseIf(AttributeServiceNodeIf* attributeServiceBrowseIf);

		void asyncRead(void);

		//- AttributeServiceIf -----------------------------------------------------
	    virtual void attributeServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
	    virtual void attributeServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
	    //- AttributeServiceIf -----------------------------------------------------

	  private:
	    void asyncReadNext(void);
		void done(OpcUaStatusCode statusCode);
		void browseResult(
			OpcUaStatusCode statusCode,
			OpcUaNodeId::SPtr& nodeId,
			ReferenceDescription::Vec& referenceDescriptionVec
		);

		AttributeService::SPtr attributeService_;
		AttributeServiceNodeIf* attributeServiceBrowseIf_;

		uint32_t maxNodesInBrowse_;
		OpcUaNodeId::Vec nodeIdVec_;
		BrowseDirectionEnum direction_;
		bool recursive_;
		std::vector<ReferenceDescription::Vec> referenceDescriptionVecVec_;
		std::vector<std::string> continuationPointVec_;

		std::set<OpcUaNodeId> nodeIdToReadSet_;
		std::set<OpcUaNodeId> nodeIdProcessedSet_;

	};

}

#endif
