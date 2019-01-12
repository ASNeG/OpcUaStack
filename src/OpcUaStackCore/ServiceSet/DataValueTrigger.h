/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_DataValueTrigger_h__
#define __OpcUaStackCore_DataValueTrigger_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeTrigger.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DataValueTrigger
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<DataValueTrigger> SPtr;

		DataValueTrigger(void);
		virtual ~DataValueTrigger(void);

		static bool run(
			OpcUaDataValue::SPtr& dataValue1,
			OpcUaDataValue::SPtr& dataValue2,
			DataChangeTrigger::Enum dataChangeTrigger = DataChangeTrigger::EnumStatusValue
		);
		static bool run(
			OpcUaDataValue& dataValue1,
			OpcUaDataValue& dataValue2,
			DataChangeTrigger::Enum dataChangeTrigger = DataChangeTrigger::EnumStatusValue
		);
	};

}

#endif
