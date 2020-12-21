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

#include "OpcUaStackServer/ServiceSetApplication/ForwardMethodSync.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardMethodAsync.h"
#include "OpcUaStackServer/InformationModel/MethodId.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MethodMap
	{
	  public:
		typedef std::map<MethodId, ForwardMethodSync::SPtr> ForwardMethodSyncMap;
		typedef std::map<MethodId, ForwardMethodAsync::SPtr> ForwardMethodAsyncMap;

		MethodMap(
			void
		);
		~MethodMap(
			void
		);

		void clear(
			void
		);
		bool existMethodSync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		bool existMethodAsync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		bool registerMethodSync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId,
			ForwardMethodSync::SPtr& forwardMethodSync
		);
		bool registerMethodAsync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId,
			ForwardMethodAsync::SPtr& forwardMethodAsync
		);
		bool deregisterMethodSync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		bool deregisterMethodAsync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		ForwardMethodSync::SPtr getMethodSync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);
		ForwardMethodAsync::SPtr getMethodAsync(
			const OpcUaStackCore::OpcUaNodeId& objectNodeId,
			const OpcUaStackCore::OpcUaNodeId& methodNodeId
		);

	  private:
		ForwardMethodSyncMap forwardMethodSyncMap_;
		ForwardMethodAsyncMap forwardMethodAsyncMap_;
	};

}

#endif
