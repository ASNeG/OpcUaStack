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
		void nodeId(OpcUaNodeId& nodeId);

		void asyncRead(void);

		//- AttributeServiceIf -----------------------------------------------------
	    //virtual void attributeServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
	    //virtual void attributeServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
	    //- AttributeServiceIf -----------------------------------------------------

	  private:
		AttributeService::SPtr attributeService_;
		AttributeServiceNodeIf* attributeServiceBrowseIf_;

		OpcUaNodeId nodeId_;

	};

}

#endif
