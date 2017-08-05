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

#ifndef __OpcUaStackServer_FilterStack_h__
#define __OpcUaStackServer_FilterStack_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFilterResult.h"
#include "OpcUaStackServer/ServiceSet/FilterNode.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    class DLLEXPORT FilterStack
    : public  Object
    {
      public:
        typedef boost::shared_ptr<FilterStack> SPtr;

        FilterStack(void);
        virtual ~FilterStack(void);

        OpcUaStatusCode receive(const ContentFilter& contentFilter, ContentFilterResult& contentilterResult);
        bool process() const;

      private:
        FilterNode::SPtr root_;

        OpcUaStatusCode buildOperatorNode(const ContentFilter& contentFilter, int idx, FilterNode::SPtr& node);
    };

}
#endif
