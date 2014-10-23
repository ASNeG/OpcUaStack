#include "OpcUaStackServer/Server/Server.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Server::Server(void)
	: Core()
	, informationModel_(InformationModel::construct())
	, sessionManager_()
	, serviceManager_()
	{
	}

	Server::~Server(void)
	{
	}

	bool
	Server::init(void)
	{
		if (!Core::init()) return false;
		return true;
	}

	void
	Server::cleanup(void)
	{
		Core::cleanup();
	}

}