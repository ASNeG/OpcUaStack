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

#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/DeleteNodeInstance.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	DeleteNodeInstance::DeleteNodeInstance(void)
	: resultCode_(Success)
	{
	}

	DeleteNodeInstance::~DeleteNodeInstance(void)
	{
	}

	bool
	DeleteNodeInstance::query(ApplicationServiceIf* applicationServiceIf)
	{
		// FIXME:
		return true;
	}

	OpcUaStatusCode
	DeleteNodeInstance::resultCode(void)
	{
		return resultCode_;
	}

}
