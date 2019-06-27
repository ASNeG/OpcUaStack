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

#ifndef __OpcUaStackPubSub_DataSetField_h__
#define __OpcUaStackPubSub_DataSetField_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/DataSetMessage/FieldEncoding.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetField
	: public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<DataSetField> SPtr;

		DataSetField(void);
		DataSetField(FieldEncoding dataType);
		virtual ~DataSetField(void);

		FieldEncoding dataType(void);
		void clear(void);
		bool exist(void);
		void createObject(FieldEncoding dataType);

		void variant(OpcUaVariant::SPtr& variant);
		OpcUaVariant::SPtr variant(void);
		void dataValue(OpcUaDataValue::SPtr& dataValue);
		OpcUaDataValue::SPtr dataValue(void);
		// FIXME: meta data ....
		Object::SPtr& object(void);

		void copyTo(DataSetField& dataSetField);
		void out(std::ostream& os) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

      protected:
        bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; };
        bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; };

      private:
		FieldEncoding dataType_;
		Object::SPtr object_;
	};

	class DLLEXPORT DataSetFieldArray
	: public OpcUaArray<DataSetField::SPtr, SPtrTypeCoder<DataSetField> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<DataSetFieldArray> SPtr;
	};

}

#endif
