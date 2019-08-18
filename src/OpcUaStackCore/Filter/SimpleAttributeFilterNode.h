/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_SimpleAttributeFilterNode_h__
#define __OpcUaStackCore_SimpleAttributeFilterNode_h__

#include "OpcUaStackCore/Filter/FilterNode.h"
#include "OpcUaStackCore/Filter/SimpleAttributeIf.h"

namespace OpcUaStackCore
{
    class DLLEXPORT SimpleAttributeFilterNode
	: public FilterNode
    {
      public:

        typedef boost::shared_ptr<SimpleAttributeFilterNode> SPtr;

        SimpleAttributeFilterNode(void);
        SimpleAttributeFilterNode(
                const OpcUaNodeId& typeId,
                OpcUaQualifiedNameArray& browsePath,
                OpcUaUInt32 attributeId,
                const OpcUaString& numericRange);

        virtual ~SimpleAttributeFilterNode(void);

        void simpleAttributeIf(SimpleAttributeIf* simpleAttributeIf);

        virtual bool evaluate(OpcUaVariant& value) override;
        virtual OpcUaStatusCode& status() override;
        virtual std::vector<OpcUaStatusCode>& operandStatuses() override;

      private:
        SimpleAttributeIf* simpleAttributeIf_;

        OpcUaNodeId typeId_;
        std::list<OpcUaQualifiedName::SPtr> browsePath_;
        OpcUaUInt32 attributeId_;
        OpcUaString numericRange_;

        OpcUaStatusCode status_;
        std::vector<OpcUaStatusCode> operandStatuses_;
    };

}
#endif
