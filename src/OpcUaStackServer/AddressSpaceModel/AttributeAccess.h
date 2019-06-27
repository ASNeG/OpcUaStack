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

#ifndef __OpcUaStackServer_AttributeAccess_h__
#define __OpcUaStackServer_AttributeAccess_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeAccess
	{
	  public:
		static bool copy(Attribute& attribute, OpcUaVariant& variant);
		static bool copy(OpcUaVariant& variant, Attribute& attribute);
		static bool copy(Attribute& attribute, OpcUaDataValue& dataValue);
		static bool copy(OpcUaDataValue& dataValue, Attribute& attribute);

		static bool trigger(OpcUaDataValue& dataValue, Attribute& attribute, DataChangeTrigger dataChangeTrigger = DCT_StatusValue);
	};

}

#endif
