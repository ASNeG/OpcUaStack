#ifndef __OpcUaStackServer_ServerArray_h__
#define __OpcUaStackServer_ServerArray_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OPcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ServerArray : public ObjectPool<ServerArray>
	{
	  public:
		typedef boost::shared_ptr<ServerArray> SPtr;

		ServerArray(void);
		~ServerArray(void);

		void informationModel(InformationModel::SPtr informationModel);

		void serverArray(std::vector<std::string>& serverArray);
		bool addServerName(const std::string& serverName);
		int32_t getServerIndex(const std::string& serverName);
		std::string getServerName(uint32_t serverIndex);
		bool existServerIndex(uint32_t serverIndex);
		bool existServerName(const std::string& serverName);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif