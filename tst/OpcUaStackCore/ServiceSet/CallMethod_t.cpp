#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/CallMethodRequest.h"
#include "OpcUaStackCore/ServiceSet/CallMethodResult.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CallMethod_)

BOOST_AUTO_TEST_CASE(CallMethod_Title)
{
	std::cout << "CallMethod_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CallMethod_CallMethodRequest)
{
	OpcUaNodeId::SPtr objectIdSPtr, methodIdSPtr;
	OpcUaVariant::SPtr variantSPtr;
	CallMethodRequest callMethodRequest1, callMethodRequest2;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode
	variantSPtr = boost::make_shared<OpcUaVariant>();
	variantSPtr->variant((OpcUaFloat)321);

	objectIdSPtr = boost::make_shared<OpcUaNodeId>();
	objectIdSPtr->namespaceIndex(130);
	objectIdSPtr->nodeId((OpcUaUInt32)11);

	methodIdSPtr = boost::make_shared<OpcUaNodeId>();
	methodIdSPtr->namespaceIndex(131);
	methodIdSPtr->nodeId((OpcUaUInt32)12);

	callMethodRequest1.objectId(objectIdSPtr);
	callMethodRequest1.methodId(methodIdSPtr);
	callMethodRequest1.inputArguments()->set(variantSPtr);

	callMethodRequest1.opcUaBinaryEncode(ios);

	// decode
	callMethodRequest2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(callMethodRequest2.objectId()->nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(callMethodRequest2.methodId()->nodeId<OpcUaUInt32>() == 12);
	
	BOOST_REQUIRE(callMethodRequest2.inputArguments()->size() == 1);
	variantSPtr = boost::make_shared<OpcUaVariant>();
	callMethodRequest2.inputArguments()->get(variantSPtr);
	BOOST_REQUIRE(variantSPtr->variant<OpcUaFloat>() == 321);
}


BOOST_AUTO_TEST_CASE(CallMethod_CallMethodResult)
{
	OpcUaStatusCode statusCode;
	OpcUaVariant::SPtr variantSPtr;
	CallMethodResult callMethodResult1, callMethodResult2;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode
	variantSPtr = boost::make_shared<OpcUaVariant>();
	variantSPtr->variant((OpcUaFloat)321);

	callMethodResult1.statusCode((OpcUaStatusCode) 1);
	callMethodResult1.inputArgumentResults()->set((OpcUaStatusCode) 2);
	callMethodResult1.outputArguments()->set(variantSPtr);

	callMethodResult1.opcUaBinaryEncode(ios);

	// decode
	callMethodResult2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(callMethodResult2.statusCode() ==  1);
	
	BOOST_REQUIRE(callMethodResult2.inputArgumentResults()->size() == 1);
	callMethodResult2.inputArgumentResults()->get(statusCode);
	BOOST_REQUIRE(statusCode == 2);

	BOOST_REQUIRE(callMethodResult2.outputArguments()->size() == 1);
	variantSPtr = boost::make_shared<OpcUaVariant>();
	callMethodResult2.outputArguments()->get(variantSPtr);
	BOOST_REQUIRE(variantSPtr->variant<OpcUaFloat>() == 321);
}

BOOST_AUTO_TEST_SUITE_END()
