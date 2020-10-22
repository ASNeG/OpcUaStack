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

#ifndef __OpcUaStackServer_MethodMap_h__
#define __OpcUaStackServer_MethodMap_h__

#include <map>

#include "OpcUaStackCore/ServiceSetApplication/ForwardMethodSync.h"
#include "OpcUaStackServer/InformationModel/MethodId.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MethodMap
	{
	  public:
		typedef std::map<MethodId, OpcUaStackCore::ForwardMethodSync::SPtr> ForwardMethodSyncMap;

		MethodMap(
			void
		);
		~MethodMap(
			void
		);

		void clear(
			void
		);
		bool existMethod(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		bool registerMethod(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId,
			OpcUaStackCore::ForwardMethodSync::SPtr& forwardMethodSync
		);
		bool deregisterMethod(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		OpcUaStackCore::ForwardMethodSync::SPtr getMethod(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);

	  private:
		ForwardMethodSyncMap forwardMethodSyncMap_;
	};

}

#endif
