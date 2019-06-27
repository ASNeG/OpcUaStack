/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_InformationModel_h__
#define __OpcUaStackServer_InformationModel_h__

#include <boost/thread/mutex.hpp>
#include <OpcUaStackServer/InformationModel/EventHandlerMap.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackCore/EventType/EventBase.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/MethodMap.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::map<OpcUaNodeId, BaseNodeClass::SPtr> InformationModelMap;

	class DLLEXPORT InformationModel
	: public Object
	{
	  public:
		typedef boost::shared_ptr<InformationModel> SPtr;

		InformationModel(void);
		~InformationModel(void);

		void clear(void);
		bool insert(BaseNodeClass::SPtr baseNodeClass);
		BaseNodeClass::SPtr find(const OpcUaNodeId& opcUaNodeId);
		BaseNodeClass::SPtr find(OpcUaNodeId::SPtr opcUaNodeId);
		bool remove(const OpcUaNodeId& opcUaNodeId);
		bool remove(OpcUaNodeId::SPtr opcUaNodeId);
		uint32_t size(void);

		InformationModelMap& informationModelMap(void);
		MethodMap& methodMap(void);
		EventHandlerMap& eventHandlerMap(void);
		boost::mutex& mutex(void);

		void checkForwardReferences(void);

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
		MethodMap methodMap_;
		EventHandlerMap eventHandlerMap_;

	};

}

#endif
