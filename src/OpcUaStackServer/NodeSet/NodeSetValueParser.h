/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DataTypeElement
	{
	  public:
		DataTypeElement(void);
		DataTypeElement(OpcUaBuildInType buildInType, bool isArray);
		 ~DataTypeElement(void);

		OpcUaBuildInType buildInType_;
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
		bool decodeValue(const std::string& nodeId, boost::property_tree::ptree& ptree, OpcUaVariant& opcUaVariant, const std::string& xmls = "");

		template<typename T>
			bool 
			decode(DataTypeElement& dataTypeElement, boost::property_tree::ptree& ptreeValue, OpcUaVariant& variant, const std::string& tag)
			{
				bool rc;
				if (dataTypeElement.isArray_) {
					OpcUaVariantValue::Vec variantValueVec;
					rc = decode<T>(ptreeValue.front().second, variantValueVec, tag);
					if (rc) variant.variant(variantValueVec);
				}
				else {
					T value;
					rc = decode(ptreeValue.front().second, value, tag);
					if (rc) variant.variant(value);
				}
				return rc;
			}

		template<typename T>
			bool 
			decodeSPtr(DataTypeElement& dataTypeElement, boost::property_tree::ptree& ptreeValue, OpcUaVariant& variant, const std::string& tag)
			{
				bool rc;
				if (dataTypeElement.isArray_) {

					boost::property_tree::ptree::iterator it;
					OpcUaVariantValue::Vec variantValueVec;
					rc = decodeSPtr<T>(ptreeValue.front().second, variantValueVec, tag);
					if (rc) variant.variant(variantValueVec);
				}
				else {
					typename T::SPtr value = constructSPtr<T>();
					rc = decode(ptreeValue.front().second, value, tag);
					if (rc) variant.variant(value);
				}
				return rc;
			}

		template<typename T>
			bool decode(boost::property_tree::ptree& ptree, OpcUaVariantValue::Vec& variantValueVec, const std::string& tag)
			{
				if (ptree.size() == 0) {
					Log(Error, "tag empty")
						.parameter("Tag", tag);
					return false;
				}

				boost::property_tree::ptree::iterator it;
				for (it = ptree.begin(); it!=ptree.end(); it++) {
					std::string tagValue = cutxmls(it->first);
					if (tagValue == "<xmlattr>") continue;
					if (tagValue != tag) {
						Log(Error, "Invalid tag")
							.parameter("ExpectedTag", tag)
							.parameter("AvailTag", tagValue);
						return false;
					}

					T value;
					if (!decode(it->second, value, tag)) {
						Log(Error, "decode error")
							.parameter("Tag", tag);
						return false;
					}
			
					OpcUaVariantValue variantValue;
					variantValue.variant(value);
					variantValueVec.push_back(variantValue);
			}
			return true;
		}

		template<typename T>
			bool decodeSPtr(boost::property_tree::ptree& ptree, OpcUaVariantValue::Vec& variantValueVec, const std::string& tag)
			{
	
				if (ptree.size() == 0) {
					Log(Error, "tag empty")
						.parameter("Tag", tag);
					return false;
				}

				boost::property_tree::ptree::iterator it;
				for (it = ptree.begin(); it!=ptree.end(); it++) {
					std::string tagValue = cutxmls(it->first);
					if (tagValue == "<xmlattr>") continue;
					if (tagValue != tag) {
						Log(Error, "Invalid tag")
							.parameter("ExpectedTag", tag)
							.parameter("AvailTag", tagValue);
						return false;
					}

					typename T::SPtr value = constructSPtr<T>();
					if (!decode(it->second, value, tag)) {
						Log(Error, "decode error")
							.parameter("Tag", tag);
						return false;
					}
			
					OpcUaVariantValue variantValue;
					variantValue.variant(value);
					variantValueVec.push_back(variantValue);
			}
			return true;
		}

		template<typename T>
			bool decode(boost::property_tree::ptree& ptree, T& destValue, const std::string& tag)
			{
				std::string sourceValue = ptree.get_value<std::string>();
				try {
					destValue = boost::lexical_cast<T>(sourceValue);
				} catch(boost::bad_lexical_cast& e) {
					Log(Error, "bad_lexical_cast in decode")
						.parameter("Tag", tag)
						.parameter("SourceValue", sourceValue)
						.parameter("What", e.what());
					return false;
				}
				return true;
			}

		bool decode(boost::property_tree::ptree& ptree, OpcUaBoolean& destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaByte& destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaSByte& destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaDateTime& destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaString::SPtr destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr destValue, const std::string& tag);
		bool decode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr destValue, const std::string& tag);


		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		//
		// encode functions
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		bool encodeValue(const std::string& nodeId, boost::property_tree::ptree& ptree, OpcUaVariant& opcUaVariant, const std::string& xmls = "");

		template<typename T>
			bool 
			encode(boost::property_tree::ptree& ptreeValue, OpcUaVariant& variant, const std::string& tag)
			{
				boost::property_tree::ptree ptree;
				if (variant.isArray()) {
					OpcUaVariantValue::Vec& variantValueVec = variant.variant();
					if (!encode<T>(ptree, variantValueVec, tag)) {
						return false;
					}
				}
				else {
					T value;
					value = variant.variant<T>();
					
					if (!encode(ptree, value, addxmls(tag))) {
						Log(Error, "encode error")
							.parameter("Tag", tag);
						return false;
					}
					
				}
				ptreeValue.add_child("Value", ptree);
				return true;
			}

		template<typename T>
			bool 
			encodeSPtr(boost::property_tree::ptree& ptreeValue, OpcUaVariant& variant, const std::string& tag)
			{
				boost::property_tree::ptree ptree;
				if (variant.isArray()) {
					OpcUaVariantValue::Vec& variantValueVec = variant.variant();
					if (!encodeSPtr<T>(ptree, variantValueVec, tag)) {
						return false;
					}
				}
				else {
					typename T::SPtr value;
					value = variant.variantSPtr<T>();
					
					if (!encode(ptree, value, addxmls(tag))) {
						Log(Error, "encode error")
							.parameter("Tag", tag);
						return false;
					}
					
				}
				ptreeValue.add_child("Value", ptree);
				return true;
			}

		template<typename T>
	        bool
			encode(boost::property_tree::ptree& ptreeValue, OpcUaVariantValue::Vec& variantValueVec, const std::string& tag)
			{
				std::string listTag = addxmls("ListOf" + tag);

				boost::property_tree::ptree ptree;
				OpcUaVariantValue::Vec::iterator it;
				for (it = variantValueVec.begin(); it != variantValueVec.end(); it++) {
					T value;
					value = it->variant<T>();
					
					boost::property_tree::ptree localPtree;
					if (!encode(localPtree, value, addxmls(tag))) {
						Log(Error, "encode error")
							.parameter("Tag", tag);
						return false;
					}

					ptree.add_child(localPtree.front().first, localPtree.front().second);
				}
				ptreeValue.add_child(listTag, ptree);

				return true;
			}

		template<typename T>
	        bool
			encodeSPtr(boost::property_tree::ptree& ptreeValue, OpcUaVariantValue::Vec& variantValueVec, const std::string& tag)
			{
				std::string listTag = addxmls("ListOf" + tag);

				boost::property_tree::ptree ptree;
				OpcUaVariantValue::Vec::iterator it;
				for (it = variantValueVec.begin(); it != variantValueVec.end(); it++) {
					typename T::SPtr value;
					value = it->variantSPtr<T>();
					
					boost::property_tree::ptree localPtree;
					if (!encode(localPtree, value, addxmls(tag))) {
						Log(Error, "encode error")
							.parameter("Tag", tag);
						return false;
					}

					ptree.add_child(localPtree.front().first, localPtree.front().second);
				}
				ptreeValue.add_child(listTag, ptree);

				return true;
			}

		template<typename T>
			bool encode(boost::property_tree::ptree& ptree, T& value, const std::string& tag)
			{
				std::stringstream ss;
				ss << value;
				ptree.put(tag, ss.str());
				return true;
			}

		bool encode(boost::property_tree::ptree& ptree, OpcUaBoolean& value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaByte& value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaSByte& value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaDateTime& value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaString::SPtr value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr value, const std::string& tag);
		bool encode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr value, const std::string& tag);

	  private:
		static void insertDataTypeElement(const std::string& elementName, const DataTypeElement& dataTypeELement);
		static bool findDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeElement);
		static void start(void);
		static DataTypeElementMap dataTypeElementMap_;
		static bool initial_;

		std::string xmls_;
		std::string cutxmls(const std::string& tag);
		std::string addxmls(const std::string& tag);
	};


}

#endif
