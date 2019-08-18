#include "unittest.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryModifiedData.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
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
	value = boost::make_shared<OpcUaDataValue>();;
	value->statusCode((OpcUaStatusCode)Success);

	data1.dataValues().resize(1);
	data1.dataValues().set(0, value);
	data1.opcUaBinaryEncode(ios);

	// decode
	data2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(data2.dataValues().size() == 1);
	value = boost::make_shared<OpcUaDataValue>();;
	data2.dataValues().get(0, value);
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
	value = boost::make_shared<OpcUaDataValue>();;
	value->statusCode((OpcUaStatusCode)Success);

	modificationInfo = boost::make_shared<ModificationInfo>();
	modificationInfo->userName() = OpcUaString("username");
	modificationInfo->modificationTime() = ptime;
	modificationInfo->updateType().enumeration(HistoryUpdateType::EnumInsert);

	data1.dataValues().resize(1);
	data1.dataValues().set(0, value);
	data1.modificationInfos().resize(1);
	data1.modificationInfos().set(modificationInfo);
	data1.opcUaBinaryEncode(ios);

	// decode
	data2.opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(data2.dataValues().size() == 1);
	value = boost::make_shared<OpcUaDataValue>();;
	data2.dataValues().get(0, value);
	BOOST_REQUIRE(value->statusCode() == Success);

	BOOST_REQUIRE(data2.modificationInfos().size() == 1);
	modificationInfo = boost::make_shared<ModificationInfo>();
	data2.modificationInfos().get(0, modificationInfo);
	BOOST_REQUIRE(modificationInfo->userName().value() == "username");
	BOOST_REQUIRE(modificationInfo->modificationTime().dateTime() == ptime);
	BOOST_REQUIRE(modificationInfo->updateType().enumeration() == HistoryUpdateType::EnumInsert);
}

BOOST_AUTO_TEST_SUITE_END()
