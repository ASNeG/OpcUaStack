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

#ifndef __OpcUaStackServer_ReferenceItemMap_h__
#define __OpcUaStackServer_ReferenceItemMap_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::multimap<OpcUaNodeId, ReferenceItem::SPtr> ReferenceItemMultiMap;

	class DLLEXPORT ReferenceItemMap
	: public Object
	{
	  public:
		typedef boost::shared_ptr<ReferenceItemMap> SPtr;

		ReferenceItemMap(void);
		~ReferenceItemMap(void);

		void clear(void);
		bool add(ReferenceType referenceType, ReferenceItem::SPtr referenceItem);
		bool add(ReferenceType referenceType, bool isForward, OpcUaNodeId& nodeId);
		bool add(OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem);
		bool add(OpcUaNodeId& referenceTypeNodeId, bool isForward, OpcUaNodeId& nodeId);

		bool remove(OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem);
		bool remove(OpcUaNodeId& referenceTypeNodeId, OpcUaNodeId& nodeId);

		ReferenceItemMultiMap& referenceItemMultiMap(void);

		void copyTo(ReferenceItemMap::SPtr referenceItemMap);
		void copyTo(ReferenceItemMap& referenceItemMap);

	  private:
		ReferenceItemMultiMap referenceItemMultiMap_;
	};

}

#endif
