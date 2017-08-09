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

#ifndef __OpcUaStackCore_AttributeFilterNode_h__
#define __OpcUaStackCore_AttributeFilterNode_h__

#include "OpcUaStackCore/Filter/FilterNode.h"
#include "OpcUaStackCore/Filter/AttributeIf.h"

namespace OpcUaStackCore
{
    class DLLEXPORT AttributeFilterNode
	: public FilterNode
    {
      public:

        typedef boost::shared_ptr<AttributeFilterNode> SPtr;

        AttributeFilterNode(void);
        AttributeFilterNode(const OpcUaNodeId& typeId,
            const OpcUaString& alias,
            const RelativePath& browsePath,
            OpcUaUInt32 attributeId,
            const OpcUaString& numericRange);

        virtual ~AttributeFilterNode(void);

        void attributeIf(AttributeIf* attributeIf);

        // FilterNode interface
        virtual bool evaluate(OpcUaVariant& value) override;
        virtual OpcUaStatusCode& status();
        virtual std::vector<OpcUaStatusCode>& operandStatuses();

      private:
        AttributeIf* attributeIf_;

       	OpcUaNodeId typeId_;
       	OpcUaString alias_;
		RelativePath::SPtr browsePath_;
		OpcUaUInt32 attributeId_;
		OpcUaString numericRange_;

        OpcUaStatusCode status_;
        std::vector<OpcUaStatusCode> operandStatuses_;
    };

}
#endif
