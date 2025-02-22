/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_RegisterForwardMethodAsync_h__
#define __OpcUaStackServer_RegisterForwardMethodAsync_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardMethodAsync
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardMethodAsync> SPtr;

		RegisterForwardMethodAsync(void);
		RegisterForwardMethodAsync(const OpcUaStackCore::OpcUaNodeId& objectNodeId, const OpcUaStackCore::OpcUaNodeId& methodNodeId);
		virtual ~RegisterForwardMethodAsync(void);

		void objectNodeId(const OpcUaStackCore::OpcUaNodeId& objectNodeId);
		void methodNodeId(const OpcUaStackCore::OpcUaNodeId& methodNodeId);
		void activate(void);
		void applicationContext(OpcUaStackCore::BaseClass::SPtr& applicationContext);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

	  private:
		OpcUaStackCore::OpcUaNodeId objectNodeId_;
		OpcUaStackCore::OpcUaNodeId methodNodeId_;
		ForwardMethodAsync forwardMethodAsync_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
	};

}
#endif
