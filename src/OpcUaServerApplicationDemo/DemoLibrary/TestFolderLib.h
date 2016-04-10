/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaServerApplicationDemo_TestFolderLib_h__
#define __OpcUaServerApplicationDemo_TestFolderLib_h__

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServerApplicationDemo
{

	class TestFolderLib
	{
	  public:
		TestFolderLib(void);
		virtual ~TestFolderLib(void);

		bool startup(IOThread& ioThread, ApplicationServiceIf& applicationServiceIf, ApplicationInfo* applicationInfo);
		bool shutdown(void);

	  private:
		int32_t mySign(void);
		double myPercent(void);
		bool getNamespaceInfo(void);
		void readValue(ApplicationReadContext* applicationReadContext);
		void readLoopTimeValue(ApplicationReadContext* applicationReadContext);
		void writeValue(ApplicationWriteContext* applicationWriteContext);
		void writeLoopTimeValue(ApplicationWriteContext* applicationWriteContext);
		void updateSingle(const OpcUaNodeId& nodeId, const OpcUaDataValue::SPtr dataValue, const BaseNodeClass::SPtr baseNodeClass);
		void updateArray(const OpcUaNodeId& nodeId, const OpcUaDataValue::SPtr dataValue, const BaseNodeClass::SPtr baseNodeClass);

		OpcUaDataValue::SPtr createDataValue(void);
		bool createValueMap(void);
		bool registerCallbacks(void);
		bool registerLoopTimeCallbacks(void);
		bool createNodeReferences(void);

		void startTimerLoop(void);
		void timerLoop(void);

		uint32_t namespaceIndex_;
		OpcUaDataValue::SPtr loopTime_;
		Callback readCallback_;
		Callback readLoopTimeCallback_;
		Callback writeCallback_;
		Callback writeLoopTimeCallback_;

		typedef std::map<OpcUaNodeId,OpcUaDataValue::SPtr> ValueMap;
		typedef std::map<OpcUaNodeId,BaseNodeClass::WPtr> BaseNodeClassWMap;
		ValueMap valueMap_;
		BaseNodeClassWMap baseNodeClassWMap_;

		IOThread* ioThread_;
		SlotTimerElement::SPtr slotTimerElement_;
		ApplicationServiceIf* applicationServiceIf_;
		ApplicationInfo* applicationInfo_;
	};

}

#endif
