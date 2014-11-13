#ifndef __OpcUaStackServer_ServiceSetBase_h__
#define __OpcUaStackServer_ServiceSetBase_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OPcUaStackServer/InformationModel/NamespaceArray.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ServiceSetBase : public Component
	{
	  public:
		ServiceSetBase(void);
		~ServiceSetBase(void);

		void informationModel(InformationModel::SPtr informationModel);
		InformationModel::SPtr informationModel(void);
		NamespaceArray::SPtr namespaceArray(void);

		virtual bool init(void) { return true; }

	  protected:
		InformationModel::SPtr informationModel_;
		NamespaceArray::SPtr namespaceArray_;
	};

}

#endif