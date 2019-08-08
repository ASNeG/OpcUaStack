/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_FilterNode_h__
#define __OpcUaStackCore_FilterNode_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilterElementResult.h"

namespace OpcUaStackCore
{
    class DLLEXPORT FilterNode
    {
      public:

        typedef boost::shared_ptr<FilterNode> SPtr;

        virtual ~FilterNode(void) {}

        virtual bool evaluate(OpcUaVariant& value) = 0;
        virtual OpcUaStatusCode& status() = 0;
        virtual std::vector<OpcUaStatusCode>& operandStatuses() = 0;

    };

}
#endif

