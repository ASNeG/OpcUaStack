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

#ifndef __OpcUaStackClient_ViewServiceBrowse_h__
#define __OpcUaStackClient_ViewServiceBrowse_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/ViewService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT ViewServiceBrowseIf
	{
	  public:
		ViewServiceBrowseIf(void) {}
		virtual ~ViewServiceBrowseIf(void) {}

		virtual void done(OpcUaStatusCode statusCode) = 0;
		virtual void browseResult(OpcUaNodeId::SPtr& nodeId, ReferenceDescription::Vec& referenceDescriptionVec) = 0;
	};


	class DLLEXPORT ViewServiceBrowse
	: public ViewServiceIf
	{
	  public:
		typedef boost::shared_ptr<ViewServiceBrowse> SPtr;

		ViewServiceBrowse(void);
		~ViewServiceBrowse(void);

		void viewService(ViewService::SPtr& viewService);
		void nodeIdVec(OpcUaNodeId::Vec& nodeIdVec);
		void viewServiceBrowseIf(ViewServiceBrowseIf* viewServiceBrowseIf);

		void asyncBrowse(void);

		//- ViewServiceIf -----------------------------------------------------
	    virtual void viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
	    virtual void viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
	    //- ViewServiceIf -----------------------------------------------------

	  private:
	    void asyncBrowseNext(void);

		ViewService::SPtr viewService_;
		ViewServiceBrowseIf* viewServiceBrowseIf_;

		OpcUaNodeId::Vec nodeIdVec_;
		std::vector<ReferenceDescription::Vec> referenceDescriptionVecVec_;
		std::vector<std::string> continuationPointVec_;
	};

}

#endif
