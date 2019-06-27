/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BrowsePathToNodeIdRequest_h__
#define __OpcUaStackCore_BrowsePathToNodeIdRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowseName
	{
	  public:
		typedef boost::shared_ptr<BrowseName> SPtr;

		BrowseName(void);
		BrowseName(const BrowseName& browseName);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4,
			const OpcUaQualifiedName& pathElement5
		);
		~BrowseName(void);

		void nodeId(OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void pathNames(OpcUaQualifiedNameArray::SPtr& pathNames);
		OpcUaQualifiedNameArray::SPtr pathNames(void);

		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4,
			const OpcUaQualifiedName& pathElement5
		);

	  private:
		OpcUaNodeId nodeId_;
		OpcUaQualifiedNameArray::SPtr pathNames_;
	};


	class BrowseNameArray
	: public OpcUaArray<BrowseName::SPtr, SPtrTypeCoder<BrowseName> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowseNameArray> SPtr;
	};


	class DLLEXPORT BrowsePathToNodeIdRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathToNodeIdRequest> SPtr;

		BrowsePathToNodeIdRequest(void);
		virtual ~BrowsePathToNodeIdRequest(void);

		void browseNameArray(BrowseNameArray::SPtr& browseNameArray);
		BrowseNameArray::SPtr browseNameArray(void);

		void addBrowsePath(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement
		);
		void addBrowsePath(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2
		);
		void addBrowsePath(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3
		);
		void addBrowsePath(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4
		);
		void addBrowsePath(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4,
			const OpcUaQualifiedName& pathElement5
		);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		BrowseNameArray::SPtr browseNameArray_;
	};

}

#endif
