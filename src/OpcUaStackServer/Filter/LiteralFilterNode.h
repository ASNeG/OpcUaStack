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

#ifndef __OpcUaStackServer_LiteralFilterNode_h__
#define __OpcUaStackServer_LiteralFilterNode_h__

#include "OpcUaStackServer/Filter/FilterNode.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    class DLLEXPORT LiteralFilterNode
	: public FilterNode
    {
      public:

        typedef boost::shared_ptr<LiteralFilterNode> SPtr;

        LiteralFilterNode(const OpcUaVariant& value);
        virtual ~LiteralFilterNode(void);

        virtual bool evaluate(OpcUaVariant& value) override;

      private:
        OpcUaVariant value_;


    };

}
#endif
