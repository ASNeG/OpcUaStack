#ifndef __OpcUaStackServer_InformationModel_h__
#define __OpcUaStackServer_InformationModel_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::map<OpcUaNodeId, BaseNodeClass::SPtr> InformationModelMap;

	class DLLEXPORT InformationModel : public ObjectPool<InformationModel>
	{
	  public:
		InformationModel(void);
		~InformationModel(void);

		bool insert(BaseNodeClass::SPtr baseNodeClass);
		BaseNodeClass::SPtr find(OpcUaNodeId& opcUaNodeId);
		BaseNodeClass::SPtr find(OpcUaNodeId::SPtr opcUaNodeId);

		bool setValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaDataValue& dataValue);
		bool setValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaVariant& variant);
		bool getValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaDataValue& dataValue);
		bool getValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaVariant& variant);

		bool setValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaDataValue& dataValue);
		bool setValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaVariant& variant);
		bool getValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaDataValue& dataValue);
		bool getValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaVariant& variant);

	  private:
		boost::mutex mutex_;
		InformationModelMap informationModelMap_;

	};

}

#endif