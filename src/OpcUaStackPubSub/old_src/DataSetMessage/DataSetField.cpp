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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/make_shared.hpp>
#include "OpcUaStackPubSub/DataSetMessage/DataSetField.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	DataSetField::DataSetField(void)
	: object_()
	, dataType_(None)
	{
	}

	DataSetField::DataSetField(FieldEncoding dataType)
	{
		createObject(dataType);
	}

	DataSetField::~DataSetField(void)
	{
	}

	FieldEncoding
	DataSetField::dataType(void)
	{
		return dataType_;
	}

	void
	DataSetField::clear(void)
	{
		object_.reset();
		dataType_ = None;
	}

	bool
	DataSetField::exist(void)
	{
		return object_.get() != nullptr;
	}

	void
	DataSetField::createObject(FieldEncoding dataType)
	{
		switch (dataType)
		{
			case VariantEncoding:
			{
				object_ = boost::make_shared<OpcUaVariant>();
				dataType_ = dataType;
				break;
			}
			case DataValueEncoding:
			{
				object_ = boost::make_shared<OpcUaDataValue>();
				dataType_ = dataType;
				break;
			}
			case RawDataEncoding: // FIXME: todo
			default:
			{
				object_.reset();
				dataType_ = None;
			}
		}
	}

	void
	DataSetField::variant(OpcUaVariant::SPtr& variant)
	{
		if (variant.get() == nullptr) {
			clear();
			return;
		}
		dataType_ = VariantEncoding;
		object_ = variant;
	}

	OpcUaVariant::SPtr
	DataSetField::variant(void)
	{
		OpcUaVariant::SPtr variant;
		if (dataType_ != VariantEncoding) {
			return variant;
		}
		return boost::static_pointer_cast<OpcUaVariant>(object_);
	}

	void
	DataSetField::dataValue(OpcUaDataValue::SPtr& dataValue)
	{
		if (dataValue.get() == nullptr) {
			clear();
			return;
		}
		dataType_ = DataValueEncoding;
		object_ = dataValue;
	}

	OpcUaDataValue::SPtr
	DataSetField::dataValue(void)
	{
		OpcUaDataValue::SPtr dataValue;
		if (dataType_ != DataValueEncoding) {
			return dataValue;
		}
		return boost::static_pointer_cast<OpcUaDataValue>(object_);
	}

	Object::SPtr&
	DataSetField::object(void)
	{
		return object_;
	}

	void
	DataSetField::copyTo(DataSetField& dataSetField)
	{
		// FIXME: todo
	}

	void
	DataSetField::out(std::ostream& os) const
	{
		// FIXME: todo
	}

	bool
	DataSetField::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		switch (dataType_)
		{
			case VariantEncoding:
			{
				OpcUaVariant::SPtr variant = boost::static_pointer_cast<OpcUaVariant>(object_);
				rc &= variant->opcUaBinaryEncode(os);
				break;
			}
			case DataValueEncoding:
			{
				OpcUaDataValue::SPtr dataValue = boost::static_pointer_cast<OpcUaDataValue>(object_);
				rc &= dataValue->opcUaBinaryEncode(os);
				break;
			}
			case RawDataEncoding: // FIXME: todo
			default:
			{
				return rc;
			}
		}

		return rc;
	}

	bool
	DataSetField::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		switch (dataType_)
		{
			case VariantEncoding:
			{
				OpcUaVariant::SPtr variant = boost::static_pointer_cast<OpcUaVariant>(object_);
				rc &= variant->opcUaBinaryDecode(is);
				break;
			}
			case DataValueEncoding:
			{
				OpcUaDataValue::SPtr dataValue = boost::static_pointer_cast<OpcUaDataValue>(object_);
				rc &= dataValue->opcUaBinaryDecode(is);
				break;
			}
			case RawDataEncoding: // FIXME: todo
			default:
			{
				return rc;
			}
		}

		return rc;
	}

}
