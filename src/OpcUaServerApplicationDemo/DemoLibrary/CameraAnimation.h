/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaServerApplicationDemo_CameraAnimation_h__
#define __OpcUaServerApplicationDemo_CameraAnimation_h__

#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServerApplicationDemo
{

	class CameraAnimation
	{
	  public:
		CameraAnimation(void);
		~CameraAnimation(void);

		bool startup(IOThread& ioThread, ApplicationServiceIf& applicationServiceIf);
		bool shutdown(void);

	  private:
		bool getNamespaceInfo(void);
		bool createValueMap(void);
		OpcUaDataValue::SPtr createDataValue(void);
		bool createNodeReferences();

		IOThread* ioThread_;
		ApplicationServiceIf* applicationServiceIf_;

		uint32_t namespaceIndex_;

		typedef std::map<OpcUaNodeId,OpcUaDataValue::SPtr> ValueMap;
		typedef std::map<OpcUaNodeId,BaseNodeClass::WPtr> BaseNodeClassWMap;
		ValueMap valueMap_;
		BaseNodeClassWMap baseNodeClassWMap_;
	};

}

#endif
