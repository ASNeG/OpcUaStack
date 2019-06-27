/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_ViewServiceIf_h__
#define __OpcUaStackClient_ViewServiceIf_h__

#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT ViewServiceIf
	{
	  public:
		ViewServiceIf(void) {}
		virtual ~ViewServiceIf(void) {}

        virtual void viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse) {};
        virtual void viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext) {};
        virtual void viewServiceTranslateBrowsePathsToNodeIdsResponse(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds) {};
	};

	class DLLEXPORT ViewServiceIfTestHandler
	: public ViewServiceIf
	{
	  public:
		ViewServiceIfTestHandler(void);
		virtual ~ViewServiceIfTestHandler(void);

		Condition viewServiceBrowseResponse_;
	    void viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
	    Condition viewServiceBrowseNextResponse_;
	    void viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
	    Condition viewServiceTranslateBrowsePathsToNodeIdsResponse_;
	    void viewServiceTranslateBrowsePathsToNodeIdsResponse(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds);

	};

}

#endif
