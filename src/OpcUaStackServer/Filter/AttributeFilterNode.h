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

#ifndef __OpcUaStackServer_AttributeFilterNode_h__
#define __OpcUaStackServer_AttributeFilterNode_h__

#include "OpcUaStackServer/Filter/FilterNode.h"
#include "OpcUaStackServer/Filter/AttributeIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    class DLLEXPORT AttributeFilterNode
	: public FilterNode
    {
      public:

        typedef boost::shared_ptr<AttributeFilterNode> SPtr;

        AttributeFilterNode(void);
        virtual ~AttributeFilterNode(void);

        void attributeIf(AttributeIf* attributeIf);

        virtual bool evaluate(OpcUaVariant& value) override;

      private:
        AttributeIf* attributeIf_;

       	OpcUaNodeId typeId_;
       	OpcUaString alias_;
		RelativePath::SPtr relativePath_;
		OpcUaUInt32 attributeId_;
		OpcUaString numericRange_;
    };

}
#endif
