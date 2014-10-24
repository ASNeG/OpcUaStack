#ifndef __OpcUaStackServer_ServiceSetBase_h__
#define __OpcUaStackServer_ServiceSetBase_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ServiceSetBase
	{
	  public:
		ServiceSetBase(void);
		~ServiceSetBase(void);

		void informationModel(InformationModel::SPtr informationModel);
		InformationModel::SPtr informationModel(void);
		void ioService(IOService* ioService);
		IOService* ioService(void);
		virtual bool init(void) { return true; }

	  protected:
		InformationModel::SPtr informationModel_;
		IOService *ioService_;
	};

}

#endif