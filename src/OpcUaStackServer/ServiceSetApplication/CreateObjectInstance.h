/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_CreateObjectInstance_h__
#define __OpcUaStackServer_CreateObjectInstance_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT CreateObjectInstance
	{
	  public:
		typedef boost::shared_ptr<CreateObjectInstance> SPtr;

		CreateObjectInstance(void);
		CreateObjectInstance(
			const OpcUaNodeId& parentNodeId,
			const OpcUaNodeId& referenceTypeNodeId,
			Object::SPtr& variableInstance
		);
		virtual ~CreateObjectInstance(void);

		void parentNodeId(const OpcUaNodeId& parentNodeId);
		OpcUaNodeId& parentnodeId(void);
		void referenceTypeNodeId(const OpcUaNodeId& referenceTypeNodeId);
		OpcUaNodeId& referenceTypeNodeId(void);
		void variableInstance(Object::SPtr& variableInstance);
		Object::SPtr& variableInstace(void);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStatusCode resultCode(void);

	  private:
		OpcUaNodeId parentNodeId_;
		OpcUaNodeId referenceTypeNodeId_;
		Object::SPtr variableInstance_;
		OpcUaStatusCode resultCode_;
	};

}
#endif
