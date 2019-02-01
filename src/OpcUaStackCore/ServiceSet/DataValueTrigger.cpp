/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/DataValueTrigger.h"

namespace OpcUaStackCore
{

	DataValueTrigger::DataValueTrigger(void)
	{
	}

	DataValueTrigger::~DataValueTrigger(void)
	{
	}
	
	bool
	DataValueTrigger::run(
		OpcUaDataValue::SPtr& dataValue1,
		OpcUaDataValue::SPtr& dataValue2,
		DataChangeTrigger::Enum dataChangeTrigger
	)
	{
		return run(*dataValue1, *dataValue2, dataChangeTrigger);
	}

	bool
	DataValueTrigger::run(
		OpcUaDataValue& dataValue1,
		OpcUaDataValue& dataValue2,
		DataChangeTrigger::Enum dataChangeTrigger
	)
	{
		switch (dataChangeTrigger)
		{
			case DataChangeTrigger::EnumStatusValueTimestamp:
			{
				if (dataValue1.sourceTimestamp() != dataValue2.sourceTimestamp()) return true;
				// fall through
			}
			case DataChangeTrigger::EnumStatusValue:
			{
				if (dataValue1.isNullVariant() && !dataValue2.isNullVariant()) return true;
				if (!dataValue1.isNullVariant() && dataValue2.isNullVariant()) return true;
				if (!dataValue1.isNullVariant() && !dataValue2.isNullVariant()) {
					if (*dataValue1.variant() != *dataValue2.variant()) return true;
				}
				// fall through
			}
			case DataChangeTrigger::EnumStatus:
			{
				if (dataValue1.statusCode() != dataValue2.statusCode()) return true;
				// fall through
			}
		}
		return false;
	}

}
