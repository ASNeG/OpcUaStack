/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_ReferenceItem_h__
#define __OpcUaStackServer_ReferenceItem_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ReferenceItem
	: public Object
	{
	  public:
		typedef boost::shared_ptr<ReferenceItem> SPtr;
		typedef std::vector<ReferenceItem::SPtr> Vec;

		ReferenceItem(void);
		ReferenceItem(const bool& isForward, const OpcUaNodeId& nodeId);
		ReferenceItem(const OpcUaNodeId& typeId, const bool& isForward, const OpcUaNodeId& nodeId);
		~ReferenceItem(void);

		void copyTo(ReferenceItem::SPtr& referenceItem);
		void copyTo(ReferenceItem& referenceItem);
		bool operator==(const ReferenceItem& referenceItem);

		OpcUaNodeId typeId_;
		OpcUaNodeId nodeId_;
		bool isForward_;

	};

}

#endif
