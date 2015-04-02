#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "OpcUaServer/Server/ServerApplication.h"

namespace OpcUaServer
{

	ServerApplication::ServerApplication(void)
	: ServerApplicationIf()
	, running_(false)
	{
	}

	ServerApplication::~ServerApplication(void)
	{
	}

	bool 
	ServerApplication::startup(void)
	{
		return true;
	}

	bool 
	ServerApplication::shutdown(void)
	{
		return true;
	}

	bool 
	ServerApplication::run(void)
	{
		running_ = true;
		while (running_) boost::this_thread::sleep(boost::posix_time::seconds(1));
		return true;
	}

	void 
	ServerApplication::stop(void)
	{
		running_ = false;
	}

}