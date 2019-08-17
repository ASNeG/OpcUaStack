/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_NodeSetValueParser_h__
#define __OpcUaStackServer_NodeSetValueParser_h__

#include <boost/make_shared.hpp>
#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"

namespace OpcUaStackServer
{

	class DLLEXPORT DataTypeElement
	{
	  public:
		DataTypeElement(void);
		DataTypeElement(OpcUaStackCore::OpcUaBuildInType buildInType, bool isArray);
		 ~DataTypeElement(void);

		OpcUaStackCore::OpcUaBuildInType buildInType_;
		bool isArray_;
	};

	class DLLEXPORT NodeSetValueParser
	{
	  public:
		typedef std::map<std::string, DataTypeElement> DataTypeElementMap;

		NodeSetValueParser(void);
		~NodeSetValueParser(void);

		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		//
		// decode functions
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		bool xmlDecodeValue(
			const std::string& nodeId,
			boost::property_tree::ptree& ptree,
			OpcUaStackCore::OpcUaVariant& opcUaVariant,
			OpcUaStackCore::Xmlns& xmlns
		);

		template<typename T>
			bool 
			xmlDecode(
				DataTypeElement& dataTypeElement,
				boost::property_tree::ptree& ptreeValue,
				OpcUaStackCore::OpcUaVariant& variant,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				bool rc;
				if (dataTypeElement.isArray_) {
					OpcUaStackCore::OpcUaVariantValue::Vec variantValueVec;
					rc = xmlDecode<T>(ptreeValue.front().second, variantValueVec, element, xmlns);
					if (rc) variant.variant(variantValueVec);
				}
				else {
					T value;
					rc = xmlDecode(ptreeValue.front().second, value, element, xmlns);
					if (rc) variant.variant(value);
				}
				return rc;
			}

		template<typename T>
			bool 
			xmlDecodeSPtr(
				DataTypeElement& dataTypeElement,
				boost::property_tree::ptree& ptreeValue,
				OpcUaStackCore::OpcUaVariant& variant,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				bool rc;
				if (dataTypeElement.isArray_) {

					boost::property_tree::ptree::iterator it;
					OpcUaStackCore::OpcUaVariantValue::Vec variantValueVec;
					rc = xmlDecodeSPtr<T>(ptreeValue.front().second, variantValueVec, element, xmlns);
					if (rc) variant.variant(variantValueVec);
				}
				else {
					typename T::SPtr value = boost::make_shared<T>();
					rc = xmlDecode(ptreeValue.front().second, value, element, xmlns);
					if (rc) variant.variant(value);
				}
				return rc;
			}

		template<typename T>
			bool xmlDecode(
				boost::property_tree::ptree& ptree,
				OpcUaStackCore::OpcUaVariantValue::Vec& variantValueVec,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				if (ptree.size() == 0) {
					OpcUaStackCore::Log(OpcUaStackCore::Error, "tag empty")
						.parameter("Tag", element);
					return false;
				}

				boost::property_tree::ptree::iterator it;
				for (it = ptree.begin(); it!=ptree.end(); it++) {
					std::string tagValue = xmlns.cutPrefix(it->first);
					if (tagValue == "<xmlattr>") continue;
					if (tagValue != element) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "Invalid tag")
							.parameter("ExpectedTag", element)
							.parameter("AvailTag", tagValue);
						return false;
					}

					T value;
					if (!xmlDecode(it->second, value, element, xmlns)) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "decode error")
							.parameter("Tag", element);
						return false;
					}
			
					OpcUaStackCore::OpcUaVariantValue variantValue;
					variantValue.variant(value);
					variantValueVec.push_back(variantValue);
				}
				return true;
			}

		template<typename T>
			bool xmlDecodeSPtr(
				boost::property_tree::ptree& ptree,
				OpcUaStackCore::OpcUaVariantValue::Vec& variantValueVec,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
	
				if (ptree.size() == 0) {
					OpcUaStackCore::Log(OpcUaStackCore::Error, "tag empty")
						.parameter("Tag", element);
					return false;
				}

				boost::property_tree::ptree::iterator it;
				for (it = ptree.begin(); it!=ptree.end(); it++) {
					std::string tagValue = xmlns.cutPrefix(it->first);
					if (tagValue == "<xmlattr>") continue;
					if (tagValue != element) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "Invalid tag")
							.parameter("ExpectedTag", element)
							.parameter("AvailTag", tagValue);
						return false;
					}

					typename T::SPtr value = boost::make_shared<T>();
					if (!xmlDecode(it->second, value, element, xmlns)) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "decode error")
							.parameter("Tag", element);
						return false;
					}
			
					OpcUaStackCore::OpcUaVariantValue variantValue;
					variantValue.variant(value);
					variantValueVec.push_back(variantValue);
				}
				return true;
			}

		template<typename T>
			bool xmlDecode(
				boost::property_tree::ptree& ptree,
				T& destValue,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				std::string sourceValue = ptree.get_value<std::string>();
				try {
					destValue = boost::lexical_cast<T>(sourceValue);
				} catch(boost::bad_lexical_cast& e) {
					OpcUaStackCore::Log(OpcUaStackCore::Error, "bad_lexical_cast in decode")
						.parameter("Tag", element)
						.parameter("SourceValue", sourceValue)
						.parameter("What", e.what());
					return false;
				}
				return true;
			}

		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaStatusCode& destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaBoolean& destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaByte& destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaSByte& destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaDateTime& destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaString::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaByteString::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaLocalizedText::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaGuid::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaNodeId::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaQualifiedName::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaExtensionObject::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaDataValue::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaDiagnosticInfo::SPtr destValue, const std::string& element, OpcUaStackCore::Xmlns& xmlns);


		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		//
		// encode functions
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		bool xmlEncodeValue(
			const std::string& nodeId,
			boost::property_tree::ptree& ptree,
			OpcUaStackCore::OpcUaVariant& opcUaVariant,
			OpcUaStackCore::Xmlns& xmlns
		);

		template<typename T>
			bool 
			xmlEncode(
				boost::property_tree::ptree& ptreeValue,
				OpcUaStackCore::OpcUaVariant& variant,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				boost::property_tree::ptree ptree;
				if (variant.isArray()) {
					OpcUaStackCore::OpcUaVariantValue::Vec& variantValueVec = variant.variant();
					if (!xmlEncode<T>(ptree, variantValueVec, element, xmlns)) {
						return false;
					}
				}
				else {
					T value;
					value = variant.variant<T>();
					
					if (!xmlEncode(ptree, value, element, xmlns)) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "encode error")
							.parameter("Tag", element);
						return false;
					}
					
				}
				ptreeValue.add_child("Value", ptree);
				return true;
			}

		template<typename T>
			bool 
			xmlEncodeSPtr(
				boost::property_tree::ptree& ptreeValue,
				OpcUaStackCore::OpcUaVariant& variant,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				boost::property_tree::ptree ptree;
				if (variant.isArray()) {
					OpcUaStackCore::OpcUaVariantValue::Vec& variantValueVec = variant.variant();
					if (!xmlEncodeSPtr<T>(ptree, variantValueVec, element, xmlns)) {
						return false;
					}
				}
				else {
					typename T::SPtr value;
					value = variant.variantSPtr<T>();
					
					if (!xmlEncode(ptree, value, element, xmlns)) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "encode error")
							.parameter("Tag", element);
						return false;
					}
					
				}
				ptreeValue.add_child("Value", ptree);
				return true;
			}

		template<typename T>
	        bool
			xmlEncode(
				boost::property_tree::ptree& ptreeValue,
				OpcUaStackCore::OpcUaVariantValue::Vec& variantValueVec,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				std::string listTag = xmlns.addPrefix("ListOf" + element);

				boost::property_tree::ptree ptree;
				OpcUaStackCore::OpcUaVariantValue::Vec::iterator it;
				for (it = variantValueVec.begin(); it != variantValueVec.end(); it++) {
					T value;
					value = it->variant<T>();
					
					boost::property_tree::ptree localPtree;
					if (!xmlEncode(localPtree, value, element, xmlns)) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "encode error")
							.parameter("Tag", element);
						return false;
					}

					ptree.add_child(localPtree.front().first, localPtree.front().second);
				}
				ptreeValue.add_child(listTag, ptree);

				return true;
			}

		template<typename T>
	        bool
			xmlEncodeSPtr(
				boost::property_tree::ptree& ptreeValue,
				OpcUaStackCore::OpcUaVariantValue::Vec& variantValueVec,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				std::string listTag = xmlns.addPrefix("ListOf" + element);

				boost::property_tree::ptree ptree;
				OpcUaStackCore::OpcUaVariantValue::Vec::iterator it;
				for (it = variantValueVec.begin(); it != variantValueVec.end(); it++) {
					typename T::SPtr value;
					value = it->variantSPtr<T>();
					
					boost::property_tree::ptree localPtree;
					if (!xmlEncode(localPtree, value, element, xmlns)) {
						OpcUaStackCore::Log(OpcUaStackCore::Error, "encode error")
							.parameter("Tag", element);
						return false;
					}

					ptree.add_child(localPtree.front().first, localPtree.front().second);
				}
				ptreeValue.add_child(listTag, ptree);

				return true;
			}

		template<typename T>
			bool xmlEncode(
				boost::property_tree::ptree& ptree,
				T& value,
				const std::string& element,
				OpcUaStackCore::Xmlns& xmlns
			)
			{
				std::stringstream ss;
				ss << value;
				ptree.put(xmlns.addPrefix(element), ss.str());
				return true;
			}

		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaStatusCode& value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaBoolean& value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaByte& value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaSByte& value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaDateTime& value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaString::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaByteString::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaLocalizedText::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaGuid::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaNodeId::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaQualifiedName::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaExtensionObject::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaDataValue::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& ptree, OpcUaStackCore::OpcUaDiagnosticInfo::SPtr value, const std::string& element, OpcUaStackCore::Xmlns& xmlns);

	  private:
		static void insertDataTypeElement(const std::string& elementName, const DataTypeElement& dataTypeELement);
		static bool findDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeElement);
		static void start(void);
		static DataTypeElementMap dataTypeElementMap_;
		static bool initial_;
	};


}

#endif
