#include "unittest.h"
#include "OpcUaStackCore/EventType/BaseEventType.h"

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
		}

		virtual ~CustomerEventType(void)
		{
			eventVariables_.registerEventVariable("Variable1", OpcUaBuildInType_OpcUaDouble);
			eventVariables_.registerEventVariable("Variable2", OpcUaBuildInType_OpcUaDouble);

			OpcUaVariant::SPtr eventType = constructSPtr<OpcUaVariant>();
			eventType->setValue(OpcUaNodeId((OpcUaUInt32)10000));
			eventVariables_.setValue("EventType", eventType);
			eventVariables_.namespaceIndex(0);
			eventVariables_.browseName(OpcUaQualifiedName("CustomerEventType"));
			eventVariables_.namespaceUri("http://ASNeG-Demo.de/Event/");
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
			OpcUaVariant::SPtr eventType = this->eventType();

			EventBase::mapNamespaceUri();
			setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);

			this->eventType(eventType);
			eventVariables_.namespaceIndex(namespaceIndex);
		}

		virtual OpcUaVariant::SPtr get(
			OpcUaNodeId& eventType,
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			EventResult::Code& resultCode
		)
		{
			OpcUaNodeId typeNodeId;
			this->eventType()->getValue(typeNodeId);
			resultCode = EventResult::Success;

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

BOOST_AUTO_TEST_SUITE_END()
