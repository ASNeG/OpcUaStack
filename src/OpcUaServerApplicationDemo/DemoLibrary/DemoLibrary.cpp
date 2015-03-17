#include "OpcUaServerApplicationDemo/DemoLibrary/DemoLibrary.h"

namespace OpcUaServerApplicationDemo
{

	DemoLibrary::DemoLibrary(void)
	: ApplicationIf()
	{
	}

	DemoLibrary::~DemoLibrary(void)
	{
	}

	void
	DemoLibrary::startup(void)
	{
	}

	void
	DemoLibrary::shutdown(void)
	{
	}

}

extern "C" void init(ApplicationIf** applicationIf) {
    *applicationIf = new OpcUaServerApplicationDemo::DemoLibrary();
}

