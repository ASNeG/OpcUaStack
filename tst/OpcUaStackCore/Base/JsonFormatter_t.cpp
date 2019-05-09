#include "unittest.h"
#include <iostream>
#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"

using namespace OpcUaStackCore;

class NumberJsonFormatter : public JsonFormatter
{
public:
    using SPtr = boost::shared_ptr<NumberJsonFormatter>;

    OpcUaInt16 mandatoryNumber_;
    OpcUaInt32 optionalNumber_;
    OpcUaInt32 optionalNumberDefault_;

protected:
    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override {
        bool rc = jsonNumberEncode(pt, mandatoryNumber_, "MandatoryNumber");
        rc &= jsonNumberEncode(pt, optionalNumber_, "OptionalNumber", true, optionalNumberDefault_);
        return rc;
    }

    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override {
        bool rc = jsonNumberDecode(pt, mandatoryNumber_, "MandatoryNumber");
        rc &= jsonNumberDecode(pt, optionalNumber_, "OptionalNumber", true, optionalNumberDefault_);

        return rc;
    }

};

class ObjectJsonFormatter : public JsonFormatter
{
public:
    NumberJsonFormatter::SPtr mandatoryObj_;
    NumberJsonFormatter::SPtr optionalObj_;

protected:
    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override {
        bool rc = jsonObjectSPtrEncode(pt, mandatoryObj_, "MandatoryObj");
        rc &= jsonObjectSPtrEncode(pt, optionalObj_, "OptionalObj", true);
        return rc;
    }

    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override {
        bool rc = jsonObjectSPtrDecode(pt, mandatoryObj_, "MandatoryObj");
        rc &= jsonObjectSPtrDecode(pt, optionalObj_, "OptionalObj", true);

        return rc;
    }

};

struct JsonFormatterInit
{
public:
    JsonFormatterInit()
    : numberJsonFormatter()
    {
    }

    ~JsonFormatterInit()
    {

    }

    boost::property_tree::ptree pt;
    NumberJsonFormatter numberJsonFormatter;
    ObjectJsonFormatter objectJsonFormatter;
};

BOOST_FIXTURE_TEST_SUITE(JsonFormatter_t, JsonFormatterInit)

BOOST_AUTO_TEST_CASE(JsonFormatter_)
{
    std::cout << "JsonFormatter_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(JsonFormatter_MandatoryNumberEncode)
{
    numberJsonFormatter.mandatoryNumber_ = 10;
    BOOST_REQUIRE(numberJsonFormatter.jsonEncode(pt));

    auto value = pt.get_child("MandatoryNumber").get_value<std::string>();
    BOOST_REQUIRE_EQUAL("10", value);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_MandatoryNumberDecode)
{
    pt.put("MandatoryNumber", "50");
    BOOST_REQUIRE(numberJsonFormatter.jsonDecode(pt));

    BOOST_REQUIRE_EQUAL(50, numberJsonFormatter.mandatoryNumber_);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_MandatoryNumberDecodeError)
{
    BOOST_REQUIRE(!numberJsonFormatter.jsonDecode(pt));
}

BOOST_AUTO_TEST_CASE(JsonFormatter_OptionalNumberEncode)
{
    numberJsonFormatter.optionalNumber_ = 10;
    numberJsonFormatter.optionalNumberDefault_ = 50;
    BOOST_REQUIRE(numberJsonFormatter.jsonEncode(pt));

    auto value = pt.get_child("OptionalNumber").get_value<std::string>();
    BOOST_REQUIRE_EQUAL("10", value);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_OptionalNumberEncodeDefault)
{
    numberJsonFormatter.optionalNumber_ = 10;
    numberJsonFormatter.optionalNumberDefault_ = 10;
    BOOST_REQUIRE(numberJsonFormatter.jsonEncode(pt));

    auto value = pt.get_child_optional("OptionalNumber");
    BOOST_REQUIRE(!value);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_OptionalNumberDecode)
{
    pt.put("MandatoryNumber", "50");
    pt.put("OptionalNumber", "60");
    BOOST_REQUIRE(numberJsonFormatter.jsonDecode(pt));

    BOOST_REQUIRE_EQUAL(60, numberJsonFormatter.optionalNumber_);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_OptionalNumberDecodeDefault)
{
    pt.put("MandatoryNumber", "50");

    numberJsonFormatter.optionalNumberDefault_ = 70;
    BOOST_REQUIRE(numberJsonFormatter.jsonDecode(pt));

    BOOST_REQUIRE_EQUAL(70, numberJsonFormatter.optionalNumber_);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_MandatoryObjEncode)
{
    auto mandatoryObj = boost::make_shared<NumberJsonFormatter>();

    mandatoryObj->mandatoryNumber_ = 10;
    objectJsonFormatter.mandatoryObj_ = mandatoryObj;
    
    BOOST_REQUIRE(objectJsonFormatter.jsonEncode(pt));

    auto value = pt.get_child("MandatoryObj.MandatoryNumber").get_value<std::string>();
    BOOST_REQUIRE_EQUAL("10", value);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_MandatoryObjDecode)
{
    pt.put("MandatoryObj.MandatoryNumber", "50");
    objectJsonFormatter.mandatoryObj_  = boost::make_shared<NumberJsonFormatter>();
    BOOST_REQUIRE(objectJsonFormatter.jsonDecode(pt));

    BOOST_REQUIRE_EQUAL(50, objectJsonFormatter.mandatoryObj_->mandatoryNumber_);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_MandatoryObjDecodeError)
{
    BOOST_REQUIRE(!objectJsonFormatter.jsonDecode(pt));
}

BOOST_AUTO_TEST_CASE(JsonFormatter_OptionalObjEncode)
{
    auto mandatoryObj = boost::make_shared<NumberJsonFormatter>();

    mandatoryObj->mandatoryNumber_ = 10;
    objectJsonFormatter.mandatoryObj_ = mandatoryObj;
    objectJsonFormatter.optionalObj_ = mandatoryObj;

    BOOST_REQUIRE(objectJsonFormatter.jsonEncode(pt));

    auto value = pt.get_child("OptionalObj.MandatoryNumber").get_value<std::string>();
    BOOST_REQUIRE_EQUAL("10", value);
}

BOOST_AUTO_TEST_CASE(JsonFormatter_OptionalObjDecode)
{
    pt.put("MandatoryObj.MandatoryNumber", "50");
    pt.put("OptionalObj.MandatoryNumber", "60");
    objectJsonFormatter.mandatoryObj_  = boost::make_shared<NumberJsonFormatter>();
    objectJsonFormatter.optionalObj_  = boost::make_shared<NumberJsonFormatter>();
    BOOST_REQUIRE(objectJsonFormatter.jsonDecode(pt));

    BOOST_REQUIRE_EQUAL(60, objectJsonFormatter.optionalObj_->mandatoryNumber_);
}

BOOST_AUTO_TEST_SUITE_END()