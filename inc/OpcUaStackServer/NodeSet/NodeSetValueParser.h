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

		bool decodeValue(const std::string& nodeId, boost::property_tree::ptree& ptree, OpcUaVariant& opcUaVariant);

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
					OpcUaVariantValue::Vec variantValueVec;
					rc = decodeSPtr<T>(ptreeValue.front().second, variantValueVec, tag);
					if (rc) variant.variant(variantValueVec);
				}
				else {
					typename T::SPtr value = T::construct();
					rc = decode(ptreeValue.front().second, value, tag);
					if (rc) variant.variant(value);
				}
				return rc;
			}

		template<typename T>
			bool decode(boost::property_tree::ptree& ptree, OpcUaVariantValue::Vec& variantValueVec, const std::string& tag)
			{
				if (ptree.size() == 0) return false;

				boost::property_tree::ptree::iterator it;
				for (it = ptree.begin(); it!=ptree.end(); it++) {
					std::string tagValue = cutxmls(it->first);
					if (tagValue != tag) return false;

					T value;
					if (!decode(it->second, value, tag)) return false;
			
					OpcUaVariantValue variantValue;
					variantValue.variant(value);
					variantValueVec.push_back(variantValue);
			}
			return true;
		}

		template<typename T>
			bool decodeSPtr(boost::property_tree::ptree& ptree, OpcUaVariantValue::Vec& variantValueVec, const std::string& tag)
			{
				if (ptree.size() == 0) return false;

				boost::property_tree::ptree::iterator it;
				for (it = ptree.begin(); it!=ptree.end(); it++) {
					std::string tagValue = cutxmls(it->first);
					if (tagValue != tag) return false;

					typename T::SPtr value = T::construct();
					if (!decode(it->second, value, tag)) return false;
			
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
		bool decode(boost::property_tree::ptree& ptree, OpcUaString::SPtr destValue, const std::string& tag);


	  private:
		static void insertDataTypeElement(const std::string& elementName, const DataTypeElement& dataTypeELement);
		static bool findDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeElement);
		static void start(void);
		static DataTypeElementMap dataTypeElementMap_;
		static bool initial_;

		std::string cutxmls(const std::string& tag);
	};


}


#if 0
	typedef enum 
	{
		OpcUaBuildInType_Unknown = 0,
		OpcUaBuildInType_OpcUaString = 12,
		OpcUaBuildInType_OpcUaDateTime = 13,
		OpcUaBuildInType_OpcUaGuid = 14,
		OpcUaBuildInType_OpcUaByteString = 15,
		OpcUaBuildInType_OpcUaXmlElement = 16,
		OpcUaBuildInType_OpcUaNodeId = 17,
		OpcUaBuildInType_OpcUaExpandedNodeId = 18,
		OpcUaBuildInType_OpcUaStatusCode = 19,
		OpcUaBuildInType_OpcUaQualifiedName = 20,
		OpcUaBuildInType_OpcUaLocalizedText = 21,
		OpcUaBuildInType_OpcUaExtensionObject = 22,
		OpcUaBuildInType_OpcUaDataValue = 23,
		OpcUaBuildInType_OpcUaVariant = 24,
		OpcUaBuildInType_OpcUaDiagnosticInfo = 25
	} OpcUaBuildInType;
#endif

#endif
