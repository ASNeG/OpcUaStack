#include "OpcUaServerApplicationDemo/DemoLibrary/DemoLibrary.h"
#include <iostream>

namespace OpcUaServerApplicationDemo
{

	DemoLibrary::DemoLibrary(void)
	: ApplicationIf()
	{
		std::cout << "DemoLibrary::construct" << std::endl;
	}

	DemoLibrary::~DemoLibrary(void)
	{
		std::cout << "DemoLibrary::destruct" << std::endl;
	}

	void
	DemoLibrary::startup(void)
	{
		std::cout << "DemoLibrary::startup" << std::endl;
	}

	void
	DemoLibrary::shutdown(void)
	{
		std::cout << "DemoLibrary::shutdown" << std::endl;
	}

}

extern "C" void init(ApplicationIf** applicationIf) {
    *applicationIf = new OpcUaServerApplicationDemo::DemoLibrary();
}

