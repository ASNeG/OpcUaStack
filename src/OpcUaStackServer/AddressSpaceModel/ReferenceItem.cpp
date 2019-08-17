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

#include "OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ReferenceItem::ReferenceItem(void)
	: typeId_()
	, isForward_(false)
	, nodeId_()
	{
	}

	ReferenceItem::ReferenceItem(const bool& isForward, const OpcUaNodeId& nodeId)
	: typeId_()
	, isForward_(isForward)
	, nodeId_(nodeId)
	{
	}

	ReferenceItem::ReferenceItem(const OpcUaNodeId& typeId, const bool& isForward, const OpcUaNodeId& nodeId)
	: typeId_(typeId)
	, isForward_(isForward)
	, nodeId_(nodeId)
	{
	}

	ReferenceItem::~ReferenceItem(void)
	{
	}

	void
	ReferenceItem::copyTo(ReferenceItem::SPtr& referenceItem)
	{
		copyTo(*referenceItem);
	}

	void
	ReferenceItem::copyTo(ReferenceItem& referenceItem)
	{
		typeId_.copyTo(referenceItem.typeId_);
		nodeId_.copyTo(referenceItem.nodeId_);
		referenceItem.isForward_ = isForward_;
	}

	bool 
	ReferenceItem::operator==(const ReferenceItem& referenceItem)
	{
		return typeId_ == referenceItem.typeId_
				&& nodeId_ == referenceItem.nodeId_
				&& isForward_ == referenceItem.isForward_;
	}

}
