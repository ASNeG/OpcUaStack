/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

/*
  OPC UA Specification Part 4:
  Chapter 7.4.3 Filter Operator
  Table 118 Conversion Rules
 */

#ifndef __OpcUaStackCore_OpcUaTypeConversion_h__
#define __OpcUaStackCore_OpcUaTypeConversion_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaTypeConversion
	{
	  public:

		OpcUaTypeConversion(void);
		~OpcUaTypeConversion(void);

		char conversionType(OpcUaBuildInType sourceType, OpcUaBuildInType targetType);
		bool conversion(
			OpcUaVariant::SPtr& sourceVariant,		// source variant data
			OpcUaBuildInType targetType,			// target type
			OpcUaVariant::SPtr& targetVariant 		// target variant data
		);

	  private:
	};

}

#endif
