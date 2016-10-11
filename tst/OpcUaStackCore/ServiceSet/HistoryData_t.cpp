#include "unittest.h"
#include "OpcUaStackCore/ServiceSet/HistoryModifiedData.h"
#include "OpcUaStackCore/ServiceSet/HistoryData.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(HistoryData_)

BOOST_AUTO_TEST_CASE(HistoryData_Title)
{
	std::cout << "HistoryData_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(HistoryData_HistoryData)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	OpcUaDataValue::SPtr value;
	HistoryData data1, data2;

	// encode
	value = constructSPtr<OpcUaDataValue>();;
	value->statusCode((OpcUaStatusCode)Success);

	data1.dataValues()->set(value);
	data1.opcUaBinaryEncode(ios);

	// decode
	data2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(data2.dataValues()->size() == 1);
	value = constructSPtr<OpcUaDataValue>();;
	data2.dataValues()->get(value);
	BOOST_REQUIRE(value->statusCode() == Success);

}

BOOST_AUTO_TEST_CASE(HistoryData_HistoryModifiedData)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	OpcUaDataValue::SPtr value;
	ModificationInfo::SPtr modificationInfo;
	HistoryModifiedData data1, data2;
	
	// encode
	value = constructSPtr<OpcUaDataValue>();;
	value->statusCode((OpcUaStatusCode)Success);

	modificationInfo = constructSPtr<ModificationInfo>();
	modificationInfo->username("username");
	modificationInfo->modificationTime(ptime);
	modificationInfo->updateType(HistoryUpdateMode_Insert);

	data1.dataValues()->set(value);
	data1.modificationInfos()->set(modificationInfo);
	data1.opcUaBinaryEncode(ios);

	// decode
	data2.opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(data2.dataValues()->size() == 1);
	value = constructSPtr<OpcUaDataValue>();;
	data2.dataValues()->get(value);
	BOOST_REQUIRE(value->statusCode() == Success);

	BOOST_REQUIRE(data2.modificationInfos()->size() == 1);
	modificationInfo = constructSPtr<ModificationInfo>();
	data2.modificationInfos()->get(modificationInfo);
	BOOST_REQUIRE(modificationInfo->username().value() == "username");
	BOOST_REQUIRE(modificationInfo->modificationTime().dateTime() == ptime);
	BOOST_REQUIRE(modificationInfo->updateType() == HistoryUpdateMode_Insert);
}

BOOST_AUTO_TEST_SUITE_END()
