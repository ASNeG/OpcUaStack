/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/EventHandlerMap.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackCore/EventType/EventBase.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/MethodMap.h"

namespace OpcUaStackServer
{

	typedef std::map<OpcUaStackCore::OpcUaNodeId, BaseNodeClass::SPtr> InformationModelMap;

	class DLLEXPORT InformationModel
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<InformationModel> SPtr;

		InformationModel(void);
		~InformationModel(void);

		void clear(void);
		bool insert(BaseNodeClass::SPtr baseNodeClass);
		bool exist(const OpcUaStackCore::OpcUaNodeId& opcUaNodeId);
		BaseNodeClass::SPtr find(const OpcUaStackCore::OpcUaNodeId& opcUaNodeId);
		BaseNodeClass::SPtr find(OpcUaStackCore::OpcUaNodeId::SPtr opcUaNodeId);
		bool remove(const OpcUaStackCore::OpcUaNodeId& opcUaNodeId);
		bool remove(OpcUaStackCore::OpcUaNodeId::SPtr opcUaNodeId);
		uint32_t size(void);

		InformationModelMap& informationModelMap(void);
		MethodMap& methodMap(void);
		EventHandlerMap& eventHandlerMap(void);
		boost::mutex& mutex(void);

		void checkForwardReferences(void);

		bool setValue(OpcUaStackCore::OpcUaUInt32 nodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaDataValue& dataValue);
		bool setValue(OpcUaStackCore::OpcUaUInt32 nodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaVariant& variant);
		bool getValue(OpcUaStackCore::OpcUaUInt32 nodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaDataValue& dataValue);
		bool getValue(OpcUaStackCore::OpcUaUInt32 nodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaVariant& variant);

		bool setValue(OpcUaStackCore::OpcUaNodeId& opcUaNodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaDataValue& dataValue);
		bool setValue(OpcUaStackCore::OpcUaNodeId& opcUaNodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaVariant& variant);
		bool getValue(OpcUaStackCore::OpcUaNodeId& opcUaNodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaDataValue& dataValue);
		bool getValue(OpcUaStackCore::OpcUaNodeId& opcUaNodeId, OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaVariant& variant);

	  private:
		boost::mutex mutex_;
		InformationModelMap informationModelMap_;
		MethodMap methodMap_;
		EventHandlerMap eventHandlerMap_;

	};

}

#endif
