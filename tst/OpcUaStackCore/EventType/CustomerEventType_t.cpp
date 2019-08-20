#include "unittest.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"

using namespace OpcUaStackCore;

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// test event class
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	class CustomerEventType
	: public BaseEventType
	{
	  public:
		typedef boost::shared_ptr<CustomerEventType> SPtr;

		CustomerEventType(void)
		: BaseEventType()
		, eventVariables_()
		{
			eventVariables_.registerEventVariable("EventType", OpcUaBuildInType_OpcUaNodeId);
			eventVariables_.registerEventVariable("Variable1", OpcUaBuildInType_OpcUaDouble);
			eventVariables_.registerEventVariable("Variable2", OpcUaBuildInType_OpcUaDouble);

			OpcUaVariant::SPtr eventType = boost::make_shared<OpcUaVariant>();
			eventType->setValue(OpcUaNodeId((OpcUaUInt32)10000));
			eventVariables_.setValue("EventType", eventType);
			eventVariables_.namespaceIndex(0);
			eventVariables_.browseName(OpcUaQualifiedName("CustomerEventType"));
			eventVariables_.namespaceUri("http://ASNeG-Demo.de/Event/");
		}

		virtual ~CustomerEventType(void)
		{
		}

		bool variable1(OpcUaVariant::SPtr& variable1)
		{
			return eventVariables_.setValue("Variable1", variable1);
		}

		OpcUaVariant::SPtr variable1(void)
		{
			OpcUaVariant::SPtr value;
			eventVariables_.getValue("Variable1", value);
			return value;
		}

		bool variable2(OpcUaVariant::SPtr& variable2)
		{
			return eventVariables_.setValue("Variable2", variable2);
		}

		OpcUaVariant::SPtr variable2(void)
		{
			OpcUaVariant::SPtr value;
			eventVariables_.getValue("Variable2", value);
			return value;
		}


		//- EventBase interface
		virtual void mapNamespaceUri(void)
		{
			uint32_t namespaceIndex;
			BaseEventType::mapNamespaceUri();

			OpcUaVariant::SPtr eventType;
			eventVariables_.getValue("EventType", eventType);

			setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);

			eventVariables_.setValue("EventType", eventType);
			eventVariables_.namespaceIndex(namespaceIndex);
		}

		virtual OpcUaVariant::SPtr get(
			OpcUaNodeId& eventType,
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			EventResult::Code& resultCode
		)
		{
			resultCode = EventResult::Success;

			OpcUaNodeId typeNodeId;
			OpcUaVariant::SPtr tmpVariant;
			eventVariables_.getValue("EventType", tmpVariant);
			tmpVariant->getValue(typeNodeId);

			// check whether eventType and typeNodeId are identical
			if (eventType == typeNodeId) {
				return eventVariables_.get(browseNameList, resultCode);
			}

			// the start item was not found. We delegate the search to the base class
			OpcUaVariant::SPtr variant;
			variant = BaseEventType::get(eventType, browseNameList, resultCode);
			if (resultCode != EventResult::Success || browseNameList.empty()) {
				return variant;
			}

			return eventVariables_.get(browseNameList, resultCode);
		}
		//- EventBase interface

	  private:
		EventVariables eventVariables_;
	};


BOOST_AUTO_TEST_SUITE(CustomerEventType_)

BOOST_AUTO_TEST_CASE(CustomerEventType_)
{
	std::cout << "CustomerEventType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CustomerEventType_construct_destruct)
{
	CustomerEventType::SPtr customerEventType = boost::make_shared<CustomerEventType>();
}

BOOST_AUTO_TEST_CASE(CustomerEventType_success)
{
	OpcUaVariant::SPtr variant;

	CustomerEventType customerEventType;

	variant = boost::make_shared<OpcUaVariant>();
	variant->setValue(OpcUaLocalizedText("de", "Dies ist eine Event Message"));
	BOOST_REQUIRE(customerEventType.message(variant) == true);

	variant = boost::make_shared<OpcUaVariant>();
	variant->setValue((OpcUaDouble)123);
	BOOST_REQUIRE(customerEventType.variable1(variant) == true);

	variant = boost::make_shared<OpcUaVariant>();
	variant->setValue((OpcUaDouble)456);
	BOOST_REQUIRE(customerEventType.variable2(variant) == true);

	EventBase* eventBase = &customerEventType;
	std::vector<std::string> namespaceVec;
	namespaceVec.push_back("http://opcfoundation.org/UA/");
	namespaceVec.push_back("http://ASNeG-Demo.de/Event/");
	eventBase->namespaceArray(&namespaceVec);


	OpcUaLocalizedText localizedText;
	OpcUaDouble doubleValue;
	OpcUaNodeId eventType;
	std::list<OpcUaQualifiedName::SPtr> browseNameList;

	// find message (BaseEventType)
	eventType.set((OpcUaUInt32)2041);
	browseNameList.clear();
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Message"));
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::Success);
	BOOST_REQUIRE(variant.get() != nullptr);
	BOOST_REQUIRE(variant->getValue(localizedText) == true);
	BOOST_REQUIRE(localizedText == OpcUaLocalizedText("de", "Dies ist eine Event Message"));

	// find variable1 (BaseEventType)
	eventType.set((OpcUaUInt32)2041);
	browseNameList.clear();
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Variable1", 1));
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::Success);
	BOOST_REQUIRE(variant.get() != nullptr);
	BOOST_REQUIRE(variant->getValue(doubleValue) == true);
	BOOST_REQUIRE(doubleValue == 123);

	// find variable2 (BaseEventType)
	eventType.set((OpcUaUInt32)2041);
	browseNameList.clear();
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Variable2", 1));
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::Success);
	BOOST_REQUIRE(variant.get() != nullptr);
	BOOST_REQUIRE(variant->getValue(doubleValue) == true);
	BOOST_REQUIRE(doubleValue == 456);

	// find variable1 (CustomerEventType)
	eventType.set((OpcUaUInt32)10000, 1);
	browseNameList.clear();
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Variable1", 1));
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::Success);
	BOOST_REQUIRE(variant.get() != nullptr);
	BOOST_REQUIRE(variant->getValue(doubleValue) == true);
	BOOST_REQUIRE(doubleValue == 123);

	// find variable2 (CustomerEventType)
	eventType.set((OpcUaUInt32)10000, 1);
	browseNameList.clear();
	browseNameList.push_back(boost::make_shared<OpcUaQualifiedName>("Variable2", 1));
	BOOST_REQUIRE(eventBase->get(eventType, browseNameList, variant) == EventResult::Success);
	BOOST_REQUIRE(variant.get() != nullptr);
	BOOST_REQUIRE(variant->getValue(doubleValue) == true);
	BOOST_REQUIRE(doubleValue == 456);
}

BOOST_AUTO_TEST_SUITE_END()
