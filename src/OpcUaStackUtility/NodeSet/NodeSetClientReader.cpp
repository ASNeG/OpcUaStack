#include "OpcUaStackUtility/NodeSet/NodeSetClientReader.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackUtility
{

	NodeSetClientReader::NodeSetClientReader(void)
	: client_()
	, nodeSetNamespace_()
	, condition_()
	, error_(false)
	{
		client_.init();
		client_.start();
	}

	NodeSetClientReader::~NodeSetClientReader(void)
	{
		client_.stop();
		client_.cleanup();
	}

	bool 
	NodeSetClientReader::readNodes(
		const std::string& sessionConfigPrefix, Config& sessionConfig,
		const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
		uint32_t operationTimeout
	)
	{
		bool rc;

		// open session to opc ua server. A condition is used to wait for
		// the end of the operation
		condition_.conditionInit();
		Session::SPtr session = client_.sessionManager().getNewSession(
			sessionConfigPrefix, sessionConfig,
			secureChannelConfigPrefix, secureChannelConfig,
			this
		);
		session->createSession();
		rc = condition_.waitForCondition(operationTimeout);
		if (!rc) {
			Log(Error, "create session timeout in node set client reader");
			return false;
		}
		if (error_) {
			Log(Error, "create Session error");
			return false;
		}

		// activate session on the opc ua server. A condition is used to wait
		// for the end of the operation


		return true;
	}

	NodeSetNamespace& 
	NodeSetClientReader::nodeSetNamespace(void)
	{
		return nodeSetNamespace_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionIf Interface
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	NodeSetClientReader::error(void)
	{
		Log(Error, "session error in node set client reader");
		error_ = true;
		condition_.conditionTrue();
	}

	void 
	NodeSetClientReader::createSessionComplete(OpcUaStatusCode opcUaStatusCode)
	{
		Log(Debug, "create session complete in node set client reader")
			.parameter("StatusCode", opcUaStatusCode);
		if (opcUaStatusCode != Success) error_ = true;
		condition_.conditionTrue();
	}

	void 
	NodeSetClientReader::activateSessionComplete(OpcUaStatusCode opcUaStatusCode)
	{
		Log(Debug, "activate session complete in node set client reader")
			.parameter("StatusCode", opcUaStatusCode);
		if (opcUaStatusCode != Success) error_ = true;
		condition_.conditionTrue();
	}

}