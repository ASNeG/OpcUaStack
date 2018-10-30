/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{
	OpcUaExtensibleParameter::OpcUaExtensibleParameter(void)
	: parameterTypeId_()
	, eoSPtr_()
	{
	}

	OpcUaExtensibleParameter::~OpcUaExtensibleParameter(void)
	{
	}

	OpcUaNodeId&
	OpcUaExtensibleParameter::parameterTypeId(void)
	{
		return parameterTypeId_;
	}

	ExtensionObjectBase::SPtr&
	OpcUaExtensibleParameter::eoSPtr(void)
	{
		return eoSPtr_;
	}


    ExtensionObjectBase::SPtr
	OpcUaExtensibleParameter::factory(void)
    {
    }

    OpcUaNodeId
	OpcUaExtensibleParameter::binaryTypeId(void)
    {
    }

    OpcUaNodeId
	OpcUaExtensibleParameter::xmlTypeId(void)
    {
    }

    void
	OpcUaExtensibleParameter::opcUaBinaryEncode(std::ostream& os) const
    {
    }

    void
	OpcUaExtensibleParameter::opcUaBinaryDecode(std::istream& is)
    {
    }

    bool
	OpcUaExtensibleParameter::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }

    bool
	OpcUaExtensibleParameter::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }

    bool
	OpcUaExtensibleParameter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }

    bool
	OpcUaExtensibleParameter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }

    bool
	OpcUaExtensibleParameter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }

    bool
	OpcUaExtensibleParameter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }

    void
	OpcUaExtensibleParameter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    }

    bool
	OpcUaExtensibleParameter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    }

    void
	OpcUaExtensibleParameter::out(std::ostream& os)
    {
    }

    void
	OpcUaExtensibleParameter::copyTo(OpcUaExtensibleParameter& value)
    {
    }

    bool
	OpcUaExtensibleParameter::operator==(const OpcUaExtensibleParameter& value) const
    {
    }

    bool
	OpcUaExtensibleParameter::operator!=(const OpcUaExtensibleParameter& value) const
    {
    }

    OpcUaExtensibleParameter&
	OpcUaExtensibleParameter::operator=(const OpcUaExtensibleParameter& value)
    {
    }
}
