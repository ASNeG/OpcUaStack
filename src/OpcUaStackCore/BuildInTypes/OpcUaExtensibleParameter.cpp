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

#include <boost/asio/streambuf.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/Base/Utility.h"

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

	void
	OpcUaExtensibleParameter::clear(void)
	{
		eoSPtr_.reset();
		parameterTypeId_ = OpcUaNodeId();
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

	bool
	OpcUaExtensibleParameter::exist(void) const
	{
		return eoSPtr_.get() != nullptr;
	}

    ExtensionObjectBase::SPtr
	OpcUaExtensibleParameter::factory(void)
    {
    	return constructSPtr<OpcUaExtensibleParameter>();
    }

	std::string
	OpcUaExtensibleParameter::namespaceName(void)
	{
		return "UnknownNamespace";
	}

	std::string
	OpcUaExtensibleParameter::typeName(void)
	{
		return "UnknownType";
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

    OpcUaNodeId
	OpcUaExtensibleParameter::jsonTypeId(void)
    {
    	return OpcUaNodeId(0,0);
    }

    void
	OpcUaExtensibleParameter::opcUaBinaryEncode(std::ostream& os) const
    {
    	if (eoSPtr_.get() == nullptr) {
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
    		return;
    	}

    	parameterTypeId_.opcUaBinaryEncode(os);
    	OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);

		boost::asio::streambuf sb;
		std::ostream osb(&sb);
		eoSPtr_->opcUaBinaryEncode(osb);

		OpcUaUInt32 bufferLength = OpcUaStackCore::count(sb);
		OpcUaNumber::opcUaBinaryEncode(os, bufferLength);
		os << osb.rdbuf();
    }

    void
	OpcUaExtensibleParameter::opcUaBinaryDecode(std::istream& is)
    {
    	OpcUaByte encodingMask;
    	parameterTypeId_.opcUaBinaryDecode(is);

    	OpcUaNumber::opcUaBinaryDecode(is, encodingMask);
    	if (encodingMask == 0x00) {
    		return;
    	}

    	OpcUaUInt32 bufferLength;
    	OpcUaNumber::opcUaBinaryDecode(is, bufferLength);

    	OpcUaExtensionObject eo(parameterTypeId_);
    	if (!eo.createObject()) return;
    	eoSPtr_ = eo.get();
    	eoSPtr_->opcUaBinaryDecode(is);
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
    	return false;
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
    	return false;
    }

    bool
	OpcUaExtensibleParameter::jsonEncodeImpl(boost::property_tree::ptree &pt) const
    {
    	// check pointer
    	if (!exist()) {
    		return true;
    	}

    	// map binary type id to json type id
    	auto jsonTypeId = eoSPtr_->jsonTypeId();

    	// encode type id
    	if (!jsonTypeId.jsonEncode(pt, "TypeId")) {
			Log(Error, "OpcUaExtensibleParameter json encoder error")
				.parameter("Element", "TypeId");
			return false;
    	}

    	// encode body
    	if (!eoSPtr_->jsonEncode(pt, "Body")) {
			Log(Error, "OpcUaExtensibleParameter json encoder error")
				.parameter("Element", "Body");
			return false;
    	}

    	return true;
    }

    bool
	OpcUaExtensibleParameter::jsonDecodeImpl(const boost::property_tree::ptree &pt)
    {
       	// decode type id
        if (!parameterTypeId_.jsonDecode(pt, "TypeId")) {
    		Log(Error, "OpcUaExtensibleParameter json decoder error")
    			.parameter("Element", "TypeId");
    		return false;
        }

        // get binary type id from json type id
        auto binaryTypeId = OpcUaExtensionObject::getBinaryTypeIdFromJsonTypeId(parameterTypeId_);
        if (binaryTypeId == OpcUaNodeId(0, 0)) {
    		Log(Error, "OpcUaExtensibleParameter json decoder error, because binary type id not found")
    			.parameter("Element", "Body")
				.parameter("JsonTypeId", parameterTypeId_);
    		return false;
        }
        parameterTypeId_ = binaryTypeId;

        // decode body
        OpcUaExtensionObject eo(parameterTypeId_);
        if (!eo.createObject()) {
       		Log(Error, "OpcUaExtensibleParameter create error")
        			.parameter("Element", "TypeId")
					.parameter("Attribute", parameterTypeId_);
        	return false;
        }
        eoSPtr_ = eo.get();

        if (!eoSPtr_->jsonDecode(pt, "Body")) {
    		Log(Error, "OpcUaExtensibleParameter json decoder error")
    			.parameter("Element", "Body");
    		return false;
        }

        return true;
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
    	const_cast<OpcUaExtensibleParameter*>(&value)->copyTo(*this);
    	return *this;
    }
}
