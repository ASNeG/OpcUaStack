/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/tokenizer.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Utility/CSV.h"

#define MAX_LINE_LEN	1000000

namespace OpcUaStackCore
{

	CSV::CSV(void)
	: delimiter_(",")
	, fileName_("")
	, ifFile_()
	, ofFile_()
	, lineNumber_(0)
	{
	}

	CSV::~CSV(void)
	{
		close();
	}

	void
	CSV::delimiter(const std::string& delimiter)
	{
		delimiter_ = delimiter;
	}

	bool
	CSV::open(const std::string& fileName, Mode mode)
	{
		fileName_ = fileName;
		if (mode == M_Read) {
			ifFile_.open(fileName_.c_str(), std::ifstream::in);
			if (!ifFile_.is_open()) {
				Log(Error, "open csv file error for reading")
					.parameter("FileName", fileName_);
				fileName_ = "";
				return false;
			}
		}

		else {
			ofFile_.open(fileName_.c_str(), std::ofstream::out);
			if (!ofFile_.is_open()) {
				Log(Error, "open csv file error for writing")
					.parameter("FileName", fileName_);
				fileName_ = "";
				return false;
			}
		}

		lineNumber_ = 0;
		return true;
	}

	bool
	CSV::close(void)
	{
		if (ifFile_.is_open()) {
			ifFile_.close();
		}

		if (ofFile_.is_open()) {
			ofFile_.close();
		}

		return true;
	}

	CSV::State
	CSV::readLine(Line& line)
	{
		lineNumber_++;

		char lineBuffer[MAX_LINE_LEN];
		if (!ifFile_.getline(lineBuffer, MAX_LINE_LEN)) {
			return S_EndOfFile;
		}

		std::string str(lineBuffer);
		std::vector<std::string> vec;
		boost::escaped_list_separator<char> els("\\", delimiter_, "\"");
		boost::tokenizer<boost::escaped_list_separator<char> > tok(str, els);
		boost::tokenizer<boost::escaped_list_separator<char> >::iterator it;
		for(it=tok.begin(); it!=tok.end(); ++it) {
			line.push_back(*it);
		}

		return S_Ok;
	}

	CSV::State
	CSV::writeLine(Line& line)
	{
		for (uint32_t idx=0; idx<line.size(); idx++) {
			if (idx != 0) {
				ofFile_ << ",";
			}
			ofFile_ << "\"" << line[idx] << "\"";
		}
		ofFile_ << std::endl;
		return S_Ok;
	}

	uint32_t
	CSV::lineNumber(void)
	{
		return lineNumber_;
	}

}
