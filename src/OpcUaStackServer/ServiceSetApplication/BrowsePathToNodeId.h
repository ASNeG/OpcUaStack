/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/ServiceSetApplication/ApplicationServiceTransaction.h"

namespace OpcUaStackServer
{

	class DLLEXPORT BrowsePathToNodeId
	{
	  public:
		typedef boost::shared_ptr<BrowsePathToNodeId> SPtr;

		BrowsePathToNodeId(void);
		BrowsePathToNodeId(std::vector<OpcUaStackCore::BrowseName::SPtr>& browseNames);
		BrowsePathToNodeId(std::initializer_list<OpcUaStackCore::BrowseName::SPtr> browseNames);
		BrowsePathToNodeId(std::initializer_list<OpcUaStackCore::BrowseName> browseNames);
		virtual ~BrowsePathToNodeId(void);

		void addBrowseName(const OpcUaStackCore::BrowseName::SPtr& browseName);
		void addBrowseName(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement
		);
		void addBrowseName(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2
		);
		void addBrowseName(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement3
		);
		void addBrowseName(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement3,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement4
		);
		void addBrowseName(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement3,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement4,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement5
		);

		bool query(ApplicationServiceIf* applicationServiceIf, bool checkStatusCodeArray = false);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

		std::vector<OpcUaStackCore::OpcUaStatusCode>& statuses(void);
		std::vector<OpcUaStackCore::OpcUaNodeId>& nodes(void);

	  private:
		std::vector<OpcUaStackCore::BrowseName::SPtr> browseNames_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
		std::vector<OpcUaStackCore::OpcUaStatusCode> statuses_;
		std::vector<OpcUaStackCore::OpcUaNodeId> nodes_;
	};

}
#endif
