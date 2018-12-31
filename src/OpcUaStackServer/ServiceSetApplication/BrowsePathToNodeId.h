/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_BrowsePathToNodeId_h__
#define __OpcUaStackServer_BrowsePathToNodeId_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT BrowsePathToNodeId
	{
	  public:
		typedef boost::shared_ptr<BrowsePathToNodeId> SPtr;

		BrowsePathToNodeId(void);
		BrowsePathToNodeId(std::vector<BrowseName::SPtr>& browseNames);
		BrowsePathToNodeId(std::initializer_list<BrowseName::SPtr> browseNames);
		BrowsePathToNodeId(std::initializer_list<BrowseName> browseNames);
		virtual ~BrowsePathToNodeId(void);

		void addBrowseName(const BrowseName::SPtr& browseName);
		void addBrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement
		);
		void addBrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2
		);
		void addBrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3
		);
		void addBrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4
		);
		void addBrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4,
			const OpcUaQualifiedName& pathElement5
		);

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStatusCode>& statuses(void);
		std::vector<OpcUaNodeId>& nodes(void);

	  private:
		std::vector<BrowseName::SPtr> browseNames_;
		OpcUaStatusCode resultCode_;
		std::vector<OpcUaStatusCode> statuses_;
		std::vector<OpcUaNodeId> nodes_;
	};

}
#endif
