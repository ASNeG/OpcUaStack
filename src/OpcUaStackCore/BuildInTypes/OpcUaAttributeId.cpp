/*
   Copyright 2016-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"

namespace OpcUaStackCore
{

	AttributeIdMask::AttributeIdMask(void)
	: attributeIdMask_(0)
	{
	}

    AttributeIdMask::~AttributeIdMask(void)
    {
    }

    void
    AttributeIdMask::add(const AttributeId attributeId)
    {
    	attributeIdMask_ = attributeIdMask_ | (1 << attributeId);
    }

    void
    AttributeIdMask::del(const AttributeId attributeId)
    {
    	uint32_t tmp = 1 << attributeId;
    	attributeIdMask_ = attributeIdMask_ & ~tmp;
    }

    bool
    AttributeIdMask::exist(const AttributeId attributeId)
    {
    	uint32_t tmp = 1 << attributeId;
    	if ((attributeIdMask_ & tmp) == tmp) return true;
    	return false;
    }

    void
    AttributeIdMask::get(AttributeIdMask::Vec& attributeIdMaskVec)
    {
    	for (uint32_t idx = 0; idx <= 27; idx++) {
    		uint32_t tmp = 1 << idx;
    		if ((attributeIdMask_ & tmp) == tmp) {
    			attributeIdMaskVec.push_back((AttributeId)idx);
    		}
    	}
    }

}
