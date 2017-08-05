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

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru)
 */

#ifndef __OpcUaStackServer_SimpleAttributeIf_h__
#define __OpcUaStackServer_SimpleAttributeIf_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    class DLLEXPORT SimpleAttributeIf
    {
      public:
        SimpleAttributeIf(void);
        virtual ~SimpleAttributeIf(void);

        virtual bool getAttribute(
        	OpcUaNodeId& typeId,
			std::list<OpcUaQualifiedName>& browsePath,
			OpcUaUInt32 attributeId,
			OpcUaString& numericRange,
			OpcUaVariant& value
		) = 0;
    };

}
#endif
