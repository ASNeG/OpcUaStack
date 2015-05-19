#include "OpcUaStackCore/Base/os.h"
#include "OpcUaServerApplicationDemo/DemoLibrary/DemoLibrary.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
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

	bool
	DemoLibrary::startup(void)
	{
		std::cout << "DemoLibrary::startup" << std::endl;

		ServiceTransactionRegisterForward::SPtr trx = ServiceTransactionRegisterForward::construct();
		RegisterForwardRequest::SPtr req = trx->request();
		RegisterForwardResponse::SPtr res = trx->response();

		OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
		nodeId->namespaceIndex(1);
		nodeId->nodeId((uint32_t)220);

		req->forwardInfoAsync()->flag(ForwardInfoAsync::F_Read);
		req->nodesToRegister()->resize(1);
		req->nodesToRegister()->set(0, nodeId);

		service().sendSync(trx);
		if (trx->responseHeader()->serviceResult() != Success) {
			std::cout << "response error" << std::endl;
			return false;
		}

		OpcUaStatusCode statusCode;
		res->statusCodeArray()->get(0, statusCode);
		if (statusCode != Success) {
			std::cout << "register value error" << std::endl;
			return false;
		}

		std::cout << "register forward ok..." << std::endl;

		return true;
	}

	bool
	DemoLibrary::shutdown(void)
	{
		std::cout << "DemoLibrary::shutdown" << std::endl;
		return true;
	}

}

extern "C" DLLEXPORT void  init(ApplicationIf** applicationIf) {
    *applicationIf = new OpcUaServerApplicationDemo::DemoLibrary();
}

