#ifndef __OpcUaStackServer_InformationModelNodeSet_h__
#define __OpcUaStackServer_InformationModelNodeSet_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h" 

namespace OpcUaStackServer
{

	class DLLEXPORT InformationModelNodeSet
	{
	  public:
		InformationModelNodeSet(void);
		~InformationModelNodeSet(void);

		static bool initial(InformationModel::SPtr informationModelSPtr, NodeSetBaseParser& nodeSetBaseParser);
		static bool initial(NodeSetBaseParser& nodeSetBaseParser, InformationModel::SPtr informationModelSPtr, std::vector<std::string>& namespaceUris);
		static bool checkForwardReferences(InformationModel::SPtr informationModelSPtr);
	};

}

#endif