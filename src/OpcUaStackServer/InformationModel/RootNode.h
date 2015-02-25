#ifndef __OpcUaStackServer_RootNode_h__
#define __OpcUaStackServer_RootNode_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RootNode 
	{
	  public:
		typedef boost::shared_ptr<RootNode> SPtr;

		RootNode(void);
		~RootNode(void);

		void informationModel(InformationModel::SPtr informationModel);

		BaseNodeClass::SPtr rootNode(void);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif