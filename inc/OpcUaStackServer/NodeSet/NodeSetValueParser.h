#ifndef __OpcUaStackServer_NodeSetValueParser_h__
#define __OpcUaStackServer_NodeSetValueParser_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
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

		bool decode(DataTypeElement& dataTypeElement, boost::property_tree::ptree& ptreeValue, OpcUaVariant& variant);
		bool decode(boost::property_tree::ptree& ptree, OpcUaUInt32& uint32);
		bool decode(boost::property_tree::ptree& ptree, OpcUaVariantValue::Vec& variantValueVec);

	  private:
		static void insertDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeELement);
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
		OpcUaBuildInType_OpcUaBoolean = 1,
		OpcUaBuildInType_OpcUaSByte = 2,
		OpcUaBuildInType_OpcUaByte = 3,
		OpcUaBuildInType_OpcUaInt16 = 4,
		OpcUaBuildInType_OpcUaUInt16 = 5,
		OpcUaBuildInType_OpcUaInt32 = 6,
		OpcUaBuildInType_OpcUaUInt32 = 7,
		OpcUaBuildInType_OpcUaInt64 = 8,
		OpcUaBuildInType_OpcUaUInt64 = 9,
		OpcUaBuildInType_OpcUaFloat = 10,
		OpcUaBuildInType_OpcUaDouble = 11,
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