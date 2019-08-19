/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/InformationModel/MethodId.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MethodId::MethodId(void)
	{
	}

	MethodId::~MethodId(void)
	{
	}

	void
	MethodId::methodNodeId(OpcUaNodeId& methodNodeId)
	{
		methodNodeId_.copyFrom(methodNodeId);
	}

	OpcUaNodeId&
	MethodId::methodNodeId(void)
	{
		return methodNodeId_;
	}

	void
	MethodId::objectNodeId(OpcUaNodeId& objectNodeId)
	{
		objectNodeId_.copyFrom(objectNodeId);
	}

	OpcUaNodeId&
	MethodId::objectNodeId(void)
	{
		return objectNodeId_;
	}

	bool
	MethodId::operator<(const MethodId& methodId) const
	{
		MethodId *tmpMethodId = const_cast<MethodId*>(&methodId);
		if (tmpMethodId->methodNodeId() < methodNodeId_) return true;
		if (methodNodeId_ < tmpMethodId->methodNodeId()) return false;
		return tmpMethodId->objectNodeId() < objectNodeId_;
	}

}
