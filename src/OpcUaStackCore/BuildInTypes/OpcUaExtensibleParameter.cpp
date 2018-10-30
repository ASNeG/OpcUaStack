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
    	return constructSPtr<OpcUaExtensibleParameter>();
    }

    OpcUaNodeId
	OpcUaExtensibleParameter::binaryTypeId(void)
    {
    	return OpcUaNodeId(0,0);
    }

    OpcUaNodeId
	OpcUaExtensibleParameter::xmlTypeId(void)
    {
    	return OpcUaNodeId(0,0);
    }

    void
	OpcUaExtensibleParameter::opcUaBinaryEncode(std::ostream& os) const
    {
    	if (eoSPtr_.get() == nullptr) return;

    	parameterTypeId_.opcUaBinaryEncode(os);
    	eoSPtr_->opcUaBinaryEncode(os);
    }

    void
	OpcUaExtensibleParameter::opcUaBinaryDecode(std::istream& is)
    {
    	parameterTypeId_.opcUaBinaryDecode(is);

    	OpcUaExtensionObject eo(parameterTypeId_);
    	if (!eo.createObject()) return;
    	eoSPtr_ = eo.get();
    	eoSPtr_->opcUaBinaryDecode(is);
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
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }

    bool
	OpcUaExtensibleParameter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    	// FIXME: todo
    }

    bool
	OpcUaExtensibleParameter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }

    bool
	OpcUaExtensibleParameter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    	// FIXME: todo
    }

    void
	OpcUaExtensibleParameter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	if (eoSPtr_.get() == nullptr) return;
    	eoSPtr_->copyTo(extensionObjectBase);
    }

    bool
	OpcUaExtensibleParameter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	if (eoSPtr_.get() == nullptr) return false;
    	return eoSPtr_->equal(extensionObjectBase);
    }

    void
	OpcUaExtensibleParameter::out(std::ostream& os)
    {
    	if (eoSPtr_.get() == nullptr) return;
    	eoSPtr_->out(os);
    }

    void
	OpcUaExtensibleParameter::reset(void)
    {
    	parameterTypeId_.set(0, 0);
    	eoSPtr_.reset();
    }

    void
	OpcUaExtensibleParameter::copyTo(OpcUaExtensibleParameter& value)
    {
    	if (eoSPtr_.get() == nullptr) {
    		value.reset();
    		return;
    	}

    	OpcUaExtensionObject eo(parameterTypeId_);
    	if (!eo.createObject()) {
    		value.reset();
    		return;
    	}

    	ExtensionObjectBase::SPtr ptr = eo.get();
    	eoSPtr_->copyTo(*ptr);

    	value.parameterTypeId() = parameterTypeId_;
    	value.eoSPtr() = ptr;
    }

    bool
	OpcUaExtensibleParameter::operator==(const OpcUaExtensibleParameter& value) const
    {
    	OpcUaExtensibleParameter* src = const_cast<OpcUaExtensibleParameter*>(this);
    	OpcUaExtensibleParameter* dst = const_cast<OpcUaExtensibleParameter*>(&value);

    	if (src->eoSPtr().get() == nullptr && dst->eoSPtr().get() != nullptr) return false;
    	if (src->eoSPtr().get() != nullptr && dst->eoSPtr().get() == nullptr) return false;
    	if (src->eoSPtr().get() == nullptr && dst->eoSPtr().get() == nullptr) return true;

    	if (parameterTypeId_ != dst->parameterTypeId()) return false;
    	if (*src->eoSPtr() != *dst->eoSPtr()) return false;

    	return true;
    }

    bool
	OpcUaExtensibleParameter::operator!=(const OpcUaExtensibleParameter& value) const
    {
    	return !this->operator==(value);
    }

    OpcUaExtensibleParameter&
	OpcUaExtensibleParameter::operator=(const OpcUaExtensibleParameter& value)
    {
    }
}
