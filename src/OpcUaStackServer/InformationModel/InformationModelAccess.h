#ifndef __OpcUaStackServer_InformationModelAccess_h__
#define __OpcUaStackServer_InformationModelAccess_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT InformationModelAccess
	{
	  public:
		typedef boost::shared_ptr<InformationModelAccess> SPtr;

		InformationModelAccess(void);
		InformationModelAccess(InformationModel::SPtr informationModel);
		~InformationModelAccess(void);

		void informationModel(InformationModel::SPtr informationModel);

		// --------------------------------------------------------------------
		// type functions
		// --------------------------------------------------------------------
		bool getType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& typeBaseNodeClass);
		bool getType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& typeNodeId);
		bool getSubType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& subTypeBaseNodeClass);
		bool getSubType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& subTypeNodeId);

	  private:
		InformationModel::SPtr informationModel_;
	};

}

#endif
