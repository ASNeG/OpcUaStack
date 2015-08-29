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

#ifndef __OpcUaServerApplicationDemo_DemoLibrary_h__
#define __OpcUaServerApplicationDemo_DemoLibrary_h__

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServerApplicationDemo
{

	class DemoLibrary
	: public ApplicationIf
	{
	  public:
		DemoLibrary(void);
		virtual ~DemoLibrary(void);

		//- ApplicationIf -----------------------------------------------------
		virtual bool startup(void);
		virtual bool shutdown(void);
		//- ApplicationIf -----------------------------------------------------

	  private:
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

		IOService ioService_;
		SlotTimer slotTimer_;
		SlotTimerElement::SPtr slotTimerElement_;
	};

}

#endif
