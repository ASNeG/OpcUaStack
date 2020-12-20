/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_BrowsePathToNodeIdRequest_h__
#define __OpcUaStackServer_BrowsePathToNodeIdRequest_h__

#include "OpcUaStackCore/Application/BrowseName.h"

namespace OpcUaStackServer
{

	class DLLEXPORT BrowsePathToNodeIdRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathToNodeIdRequest> SPtr;

		BrowsePathToNodeIdRequest(void);
		virtual ~BrowsePathToNodeIdRequest(void);

		void browseNameArray(OpcUaStackCore::BrowseNameArray::SPtr& browseNameArray);
		OpcUaStackCore::BrowseNameArray::SPtr browseNameArray(void);

		void addBrowsePath(
			const OpcUaStackCore::BrowseName::SPtr& browseName
		);
		void addBrowsePath(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement
		);
		void addBrowsePath(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2
		);
		void addBrowsePath(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement3
		);
		void addBrowsePath(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement3,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement4
		);
		void addBrowsePath(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement1,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement2,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement3,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement4,
			const OpcUaStackCore::OpcUaQualifiedName& pathElement5
		);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStackCore::BrowseNameArray::SPtr browseNameArray_;
	};

}

#endif
