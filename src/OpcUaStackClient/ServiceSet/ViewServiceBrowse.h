/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_ViewServiceBrowse_h__
#define __OpcUaStackClient_ViewServiceBrowse_h__

#include "OpcUaStackClient/ServiceSet/ViewService.h"
#include <set>

namespace OpcUaStackClient
{

	class DLLEXPORT ViewServiceBrowseIf
	{
	  public:
		ViewServiceBrowseIf(void) {}
		virtual ~ViewServiceBrowseIf(void) {}

		virtual void viewServiceBrowseDone(OpcUaStackCore::OpcUaStatusCode statusCode) = 0;
		virtual void viewServiceBrowseResult(
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::OpcUaNodeId::SPtr& nodeId,
			OpcUaStackCore::ReferenceDescription::Vec& referenceDescriptionVec
		) = 0;
	};


	class DLLEXPORT ViewServiceBrowse
	{
	  public:
		typedef boost::shared_ptr<ViewServiceBrowse> SPtr;

		ViewServiceBrowse(void);
		~ViewServiceBrowse(void);

		void maxNodesInBrowse(uint32_t maxNodesInBrowse);
		void viewService(ViewService::SPtr& viewService);
		void nodeIdVec(OpcUaStackCore::OpcUaNodeId::Vec& nodeIdVec);
		void direction(OpcUaStackCore::BrowseDirectionEnum direction);
		void recursive(bool recursive);
		void viewServiceBrowseIf(ViewServiceBrowseIf* viewServiceBrowseIf);

		void asyncBrowse(void);

	  private:
	    void viewServiceBrowseResponse(OpcUaStackCore::ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
	    void viewServiceBrowseNextResponse(OpcUaStackCore::ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);

	    void asyncBrowseNext(void);
		void done(OpcUaStackCore::OpcUaStatusCode statusCode);
		void browseResult(
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::OpcUaNodeId::SPtr& nodeId,
			OpcUaStackCore::ReferenceDescription::Vec& referenceDescriptionVec
		);

		ViewService::SPtr viewService_;
		ViewServiceBrowseIf* viewServiceBrowseIf_;

		uint32_t maxNodesInBrowse_;
		OpcUaStackCore::OpcUaNodeId::Vec nodeIdVec_;
		OpcUaStackCore::BrowseDirectionEnum direction_;
		bool recursive_;
		std::vector<OpcUaStackCore::ReferenceDescription::Vec> referenceDescriptionVecVec_;
		std::vector<std::string> continuationPointVec_;

		std::set<OpcUaStackCore::OpcUaNodeId> nodeIdToReadSet_;
		std::set<OpcUaStackCore::OpcUaNodeId> nodeIdProcessedSet_;

	};

}

#endif
