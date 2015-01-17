#ifndef __OpcUaStackUtility_NodeSetClientReader_h__
#define __OpcUaStackUtility_NodeSetClientReader_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConditionBool.h"
#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackClient;
using namespace OpcUaStackServer;

namespace OpcUaStackUtility
{

	class DLLEXPORT NodeSetClientReader 
	: public NodeSetBaseParser
	, public SessionIf
	{
	  public:
		NodeSetClientReader(void);
		~NodeSetClientReader(void);

		bool readNodes(
			const std::string& sessionConfigPrefix, Config& sessionConfig,
			const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
			uint32_t operationTimeout = 5000
		);

		NodeSetNamespace& nodeSetNamespace(void);

		//- SessionIf interface -----------------------------------------------
		void error(void);
		void createSessionComplete(OpcUaStatusCode opcUaStatusCode);
		void activateSessionComplete(OpcUaStatusCode opcUaStatusCode);
		//- SessionIf interface -----------------------------------------------

	  private:
		bool readNamespaceArray(void);
		bool browse(OpcUaNodeId& nodeId);
	
		Client client_;
		NodeSetNamespace nodeSetNamespace_;
		ConditionBool condition_;
		
		uint32_t operationTimeout_;
		Session::SPtr session_;
		bool error_;

		typedef std::map<OpcUaNodeId, ReferenceDescription::SPtr> NodeIdMap;
		NodeIdMap nodeIdMap_;
	};

}

#endif