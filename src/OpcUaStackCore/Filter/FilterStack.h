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

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru), Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_FilterStack_h__
#define __OpcUaStackCore_FilterStack_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilterResult.h"
#include "OpcUaStackCore/Filter/FilterNode.h"
#include "OpcUaStackCore/Filter/AttributeIf.h"
#include "OpcUaStackCore/Filter/SimpleAttributeIf.h"

namespace OpcUaStackCore
{
    class DLLEXPORT FilterStack
    : public  Object
    {
      public:
        typedef boost::shared_ptr<FilterStack> SPtr;

        FilterStack(void);
        virtual ~FilterStack(void);

        void attributeIf(AttributeIf* attributeIf);
        void simpleAttributeIf(SimpleAttributeIf* simpleAttributeIf);
        bool receive(ContentFilter& contentFilter, ContentFilterResult& contentilterResult);
        bool process(bool& filterResult) const;

      private:
        FilterNode::SPtr root_;
        AttributeIf* attributeIf_;
        SimpleAttributeIf* simpleAttributeIf_;

        bool buildOperatorNode(ContentFilter& contentFilter, ContentFilterResult& contentFilterResult, int idx, FilterNode::SPtr& node);
    };

}
#endif
