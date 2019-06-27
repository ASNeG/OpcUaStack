#include "unittest.h"
#include <boost/asio/streambuf.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(Streambuf_t)

BOOST_AUTO_TEST_CASE(Streambuf_)
{
	std::cout << "Streambuf_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Streambuf_streambbuf_to_buffer)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios << "0123456789";

	boost::asio::const_buffer buffer(sb.data());
}

BOOST_AUTO_TEST_CASE(Streambuf_streambbuf_to_buffer_iterate)
{
	char buf[10];
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios << "0123456789";

	boost::asio::const_buffer buffer(sb.data());
	boost::asio::const_buffers_1 buffer1(buffer);
	boost::asio::const_buffers_1::const_iterator it;

	for (it = buffer1.begin(); it!= buffer1.end(); it++) {
	    ;
	}
}

BOOST_AUTO_TEST_CASE(Streambuf_buffer_to_streambuf)
{
	const char *buf = "0123456789";
	boost::asio::const_buffer buffer(buf, 10);

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios.write(
		boost::asio::buffer_cast<const char*>(buffer),
		boost::asio::buffer_size(buffer)
	);
	
	std::string str;
	ios >> str;

	BOOST_REQUIRE(str == "0123456789");
}

BOOST_AUTO_TEST_CASE(Streambuf_redirect)
{
	const char *buf = "0123456789";

	boost::asio::streambuf sb1; 
	std::iostream ios(std::cout.rdbuf());

	ios << buf;
}

BOOST_AUTO_TEST_CASE(Streambuf_streambbuf_to_string)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios << "0123456789";

	boost::asio::streambuf::const_buffers_type buffer = sb.data();
	std::string str(
		boost::asio::buffers_begin(buffer),
		boost::asio::buffers_begin(buffer) + 10
	);
	BOOST_REQUIRE(str == "0123456789");
}

BOOST_AUTO_TEST_CASE(Streambuf_buffer_size)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios << "0123456789";

	boost::asio::const_buffer buffer(sb.data());
	BOOST_REQUIRE(boost::asio::buffer_size(buffer) == 10);
}

BOOST_AUTO_TEST_CASE(Streambuf_streambbuf_to_buffer_to_string)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios << "0123456789";

	boost::asio::const_buffer buffer(sb.data());
	std::string str(
		boost::asio::buffer_cast<const char*>(buffer),
		boost::asio::buffer_size(buffer)
	);
	BOOST_REQUIRE(str == "0123456789");
}

BOOST_AUTO_TEST_CASE(Streambuf_split_buffer)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ios << "0123456789";

	boost::asio::const_buffer buffer(sb.data());

	boost::asio::const_buffer b1 = boost::asio::buffer(buffer, 5);
	boost::asio::const_buffer b2 = boost::asio::buffer(buffer+5, 5);

	std::string str1(
		boost::asio::buffer_cast<const char*>(b1),
		boost::asio::buffer_size(b1)
	);
	std::string str2(
		boost::asio::buffer_cast<const char*>(b2),
		boost::asio::buffer_size(b2)
	);

	BOOST_REQUIRE(str1 == "01234");
	BOOST_REQUIRE(str2 == "56789");
}

BOOST_AUTO_TEST_SUITE_END()
