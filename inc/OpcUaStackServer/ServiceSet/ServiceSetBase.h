#ifndef __OpcUaStackServer_ServiceSetBase_h__
#define __OpcUaStackServer_ServiceSetBase_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServiceSetBase
	{
	  public:
		ServiceSetBase(void);
		~ServiceSetBase(void);

		void informationModel(InformationModel::SPtr informationModel);
		InformationModel::SPtr informationModel(void);

	  protected:
		InformationModel::SPtr informationModel_;
	};

}

#endif