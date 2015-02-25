#ifndef __OpcUaStackServer_InformationModelConfig_h__
#define __OpcUaStackServer_InformationModelConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT InformationModelConfig
	{
	  public:
		static bool initial(InformationModel::SPtr informationModelSPtr, const std::string& configPrefix, Config* config = nullptr);
	};

}

#endif