#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/Client/Client.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{
		
	Client::Client(void)
	: Core()
	{
	}

	Client::~Client(void)
	{
	}

	bool 
	Client::init(void)
	{
		bool rc = true;

		Log(Info, "init opc ua core stack");
		rc = rc && Core::init();

		return rc;
	}

	void 
	Client::cleanup(void)
	{
		Core::cleanup();
	}

	bool 
	Client::start(void)
	{
		return true;
	}

	void 
	Client::stop(void)
	{
	}

}