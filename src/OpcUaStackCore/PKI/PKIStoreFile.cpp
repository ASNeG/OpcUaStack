/*
   Copyright 2022-2023 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/filesystem.hpp>
#include <boost/uuid/detail/sha1.hpp>

#include <sstream>
#include <iomanip>

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/PKI/PKIStoreFile.h"

namespace OpcUaStackCore
{
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PKIStoreFileConfiguration
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PKIStoreFileConfiguration::PKIStoreFileConfiguration(void)
	: PKIStoreConfiguration()
	{
	}

	PKIStoreFileConfiguration::~PKIStoreFileConfiguration(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PKIStoreFile
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PKIStoreFile::PKIStoreFile(void)
	: PKIStore()
	{
	}
		
	PKIStoreFile::~PKIStoreFile(void)
	{
	}

	bool
	PKIStoreFile::open(PKIStoreConfiguration::SPtr config)
	{
		boost::system::error_code ec;
		bool rc = true;

		config_ = boost::static_pointer_cast<PKIStoreFileConfiguration>(config);

		Log(Info, "PKIFileStore open")
		    .parameter("RootDirectory", config_->rootPath_);

		// Check pki root directory
		if (!boost::filesystem::exists(boost::filesystem::path(config_->rootPath_))) {
			// Create pki root directory
			rc = boost::filesystem::create_directories(boost::filesystem::path(config_->rootPath_), ec);
			if (!rc || ec) {
				Log(Error, "create root directory error")
					.parameter("RootDirectory", config_->rootPath_)
					.parameter("Error", ec.message());
				return false;
			}
		}

		// Create PKI directories
		for (auto dirEntry : config_->dirEntryVec_) {
			if (dirEntryMap_.find(pkiStoreDataType(dirEntry)) != dirEntryMap_.end()) continue;
			if (subdirectory(dirEntry).empty()) continue;
			std::string pkiPath = config_->rootPath_ + "/" + subdirectory(dirEntry);

			// Create PKI directory
			if (!boost::filesystem::exists(boost::filesystem::path(pkiPath))) {
				rc = boost::filesystem::create_directories(boost::filesystem::path(pkiPath), ec);
				if (!rc || ec) {
					Log(Error, "create pki directory error")
						.parameter("PKIPath", pkiPath)
						.parameter("Error", ec.message());
					return false;
				}
			}

			// Add PKI directory to directory map
			subdirectory(dirEntry) = pkiPath;
			dirEntryMap_.insert(std::make_pair(pkiStoreDataType(dirEntry), dirEntry));
		}

		return true;
	}

	bool
	PKIStoreFile::close(void)
	{
		Log(Info, "PKIFileStore close");
		return true;
	}

	bool
	PKIStoreFile::cleanup(void)
	{
		// Delete all files and directories inclusive root path
		boost::filesystem::remove_all(boost::filesystem::path(config_->rootPath_));
		return true;
	}

	bool
	PKIStoreFile::empty(
		PKIStoreDataType type
	)
	{
		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return true;
		auto dirEntry = it->second;

		// Check if file exist in subdirectory
		std::string directory = config_->rootPath_ + "/" + subdirectory(dirEntry);
		for (boost::filesystem::directory_iterator it(directory);
			 it != boost::filesystem::directory_iterator(); ++it
		) {
		    boost::filesystem::path filename = it->path();
		    if (boost::filesystem::is_regular_file(filename)) return false;
		}
		return true;
	}

	bool
	PKIStoreFile::exist(
		PKIStoreDataType type,
		const std::string& name
	)
	{
		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		auto dirEntry = it->second;

		std::string filename = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + name;
		std::replace(filename.begin(), filename.end(), ' ', '_');

		// Check if file in directory exist
		return boost::filesystem::exists(boost::filesystem::path(filename)) ||
			   boost::filesystem::is_symlink(boost::filesystem::path(filename));
	}

	bool
	PKIStoreFile::write(
		PKIStoreDataType type,
		const std::string& name,
		const OpcUaByteString& data
	)
	{
		boost::system::error_code ec;

		// Check parameter
		if (data.isNull() || data.size() == 0) {
			Log(Error, "cannot write data, because data is null or empty")
				.parameter("Name", name);
			return false;
		}

		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) {
			return false;
		}
		auto dirEntry = it->second;

		std::string firstFile = "";
		std::string secondFile = "";

		if (firstFileThumbprintUsed(dirEntry) == true) {

			// First file: ThumbPrint name
			std::string thumbPrint;
			if (!createThumbPrint(data, thumbPrint)) {
				Log(Error, "create thumbprint from data error")
					.parameter("Name", name);
				return false;
			}
			firstFile = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + thumbPrint;

			// Second File: Real name
			if (symlinkUsed(dirEntry) == true) {
				secondFile = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + name;
			}
		}
		else {
			// First File: Real name
			firstFile = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + name;

			// Second file: ThumbPrint name
			if (symlinkUsed(dirEntry) == true) {
				std::string thumbPrint;
				if (!createThumbPrint(data, thumbPrint)) {
					Log(Error, "create thumbprint from data error")
						.parameter("Name", name);
					return false;
				}
				secondFile = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + thumbPrint;
			}
		}

		std::replace(firstFile.begin(), firstFile.end(), ' ', '_');
		std::replace(secondFile.begin(), secondFile.end(), ' ', '_');

		// Check if file already exist
		if (exist(type, firstFile)) {
			Log(Error, "file write error, because file already exist")
				.parameter("ThumbPrint", firstFile)
				.parameter("Name", name);
			return false;
		}

		// Save first file
		try {
			boost::filesystem::ofstream ofs(firstFile);
			ofs << data.toString();
			ofs.close();
		}
		catch (std::exception& e) {
			Log(Error, "file write filename")
				.parameter("Filename", firstFile)
				.parameter("Error", e.what());
			return false;
		}

		// Do we want to create a link?
		if (secondFile == "") {
			return true;
		}

		// Create name link
		boost::filesystem::create_symlink(
			boost::filesystem::path(firstFile),
			boost::filesystem::path(secondFile),
			ec
		);
		if (ec) {
			Log(Error, "create symlink error")
				.parameter("LinkTo", firstFile)
				.parameter("LinkFrom", secondFile)
				.parameter("Error", ec.message());
			return false;
		}

		return true;
	}

	bool
	PKIStoreFile::writeFile(
		PKIStoreDataType type,
		const std::string& name,
		const std::string& filename
	)
	{
		OpcUaByteString data;
		boost::system::error_code ec;
		std::string file = filename;

		// get target file name of symlink
		if (boost::filesystem::is_symlink(boost::filesystem::path(filename))) {
			boost::filesystem::path targetFile;
			targetFile = boost::filesystem::read_symlink(boost::filesystem::path(filename), ec);
			if (ec) {
				Log(Error, "Read symlink error")
				    .parameter("Filename", filename)
					.parameter("Error", ec.message());
				return false;
			}

			file = targetFile.string();
		}

		// Read file
		try {
			std::ifstream ifs(file);
			ifs.seekg(0, std::ios::end);
			size_t size = ifs.tellg();
			data.resize(size);
			ifs.seekg(0);
			ifs.read(data.memBuf(), size);
		}
		catch (std::exception& e) {
			Log(Error, "Read file error")
				.parameter("Filename", filename)
				.parameter("Error", e.what());
			return false;
		}

		// write data to pki store
		return write(type, name, data);
	}

	bool
	PKIStoreFile::read(
		PKIStoreDataType type,
		const std::string& name,
		OpcUaByteString& data
	)
	{
		boost::system::error_code ec;

		// Check if file exist
		if (!exist(type, name)) {
			return false;
		}

		// Find directory in directory map
		std::string pkiFileName = name;
		std::replace(pkiFileName.begin(), pkiFileName.end(), ' ', '_');


		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		auto dirEntry = it->second;

		std::string filename = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + pkiFileName;

		// If file is symlink then get target file
		if (boost::filesystem::is_symlink(boost::filesystem::path(filename))) {
			boost::filesystem::path targetFile;
			targetFile = boost::filesystem::read_symlink(boost::filesystem::path(filename), ec);
			if (ec) {
				Log(Error, "Read symlink error")
					.parameter("Filename", filename)
					.parameter("Error", ec.message());
				return false;
			}

			filename = targetFile.string();
		}

		// Read file
		try {
			std::ifstream ifs(filename);
			ifs.seekg(0, std::ios::end);
			size_t size = ifs.tellg();
			data.resize(size);
			ifs.seekg(0);
			ifs.read(data.memBuf(), size);
		}
		catch (std::exception& e) {
			Log(Error, "Read file error")
				.parameter("Filename", filename)
				.parameter("Error", e.what());
			return false;
		}
		return true;
	}

	bool
	PKIStoreFile::readAll(
		PKIStoreDataType type,
		std::vector<OpcUaByteString>& dataVec
	)
	{
		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		std::string pkiDir = config_->rootPath_ + "/" + subdirectory(it->second);

		// Read all regular files from directory
		for (boost::filesystem::directory_iterator it1(pkiDir);
			 it1 != boost::filesystem::directory_iterator(); ++it1
		) {
		    boost::filesystem::path filename = it1->path();
		    if (!boost::filesystem::is_regular_file(filename)) continue;

		    // Read data from file
		    OpcUaByteString data;
		    if (!read(type, filename.filename().string(), data)) {
		    	return false;
		    }
		    dataVec.push_back(data);
		}

		return true;
	}

	bool
	PKIStoreFile::remove(
		PKIStoreDataType type,
		const std::string& name
	)
	{
		boost::system::error_code ec;

		// Check if file exist
		if (!exist(type, name)) {
			return true;
		}

		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		auto dirEntry = it->second;

		std::string pkiDir = config_->rootPath_ + "/" + subdirectory(dirEntry);
		std::string filename = config_->rootPath_ + "/" + subdirectory(dirEntry) + "/" + name;
		std::string firstFile = "";
		std::string secondFile = "";

		// Remove target file
		if (boost::filesystem::is_symlink(boost::filesystem::path(filename))) {

			// The file is a symlink file.
			boost::filesystem::path targetFile;
			targetFile = boost::filesystem::read_symlink(boost::filesystem::path(filename), ec);
			if (ec) {
				Log(Error, "cannot remove file, because read symlink target error")
					.parameter("SymlinkFile", filename)
					.parameter("Error", ec.message());
				return false;
			}

			firstFile = targetFile.string();
			secondFile = filename;
		}
		else { // Find and remove the symlinks to the file
			firstFile = filename;

			for (boost::filesystem::directory_iterator it1(pkiDir);
				it1 != boost::filesystem::directory_iterator(); ++it1
			) {
				boost::filesystem::path dirFile = it1->path();

				if (boost::filesystem::is_symlink(dirFile)) {
					boost::filesystem::path targetFile;
					targetFile = boost::filesystem::read_symlink(dirFile, ec);
					if (ec) {
						Log(Error, "cannot remove file, because read symlink target error")
							.parameter("SymlinkFile", dirFile.string())
							.parameter("Error", ec.message());
						return false;
					}

					if (targetFile.string() == filename) {
						secondFile = dirFile.string();
						break;
					}
				}
			}
		}

		// Remove first file
		if (!firstFile.empty()) {
			boost::filesystem::remove(boost::filesystem::path(firstFile), ec);
			if (ec) {
				Log(Error, "cannot remove file")
			    	.parameter("Filename", firstFile)
					.parameter("Error", ec.message());
				return false;
			}
		}

		// Remove second file
		if (!secondFile.empty()) {
			boost::filesystem::remove(boost::filesystem::path(secondFile), ec);
			if (ec) {
				Log(Error, "cannot remove file")
			    	.parameter("Filename", secondFile)
					.parameter("Error", ec.message());
				return false;
			}
		}

		return true;
	}

	bool
	PKIStoreFile::removeAll(
		PKIStoreDataType type
	)
	{
		boost::system::error_code ec;

		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		auto dirEntry = it->second;

		std::string pkiDir = config_->rootPath_ + "/" + subdirectory(dirEntry);

		// Remove all files from directory
		boost::filesystem::remove_all(pkiDir, ec);
		if (ec) {
			Log(Error, "remove all files in directory error")
				.parameter("Directory", pkiDir)
				.parameter("Error", ec.message());
			return false;
		}

		return true;
	}

	bool
	PKIStoreFile::getNameList(
		PKIStoreDataType type,
		std::vector<std::string>& nameVec,
		PKIStoreNameType nameType
	)
	{
		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		auto dirEntry = it->second;

		std::string pkiDir = config_->rootPath_ + "/" + subdirectory(dirEntry);

		for (boost::filesystem::directory_iterator it1(pkiDir);
			it1 != boost::filesystem::directory_iterator(); ++it1
		) {
			boost::filesystem::path dirFile = it1->path();

			bool addToList = false;
			if (!boost::filesystem::is_symlink(dirFile)) {
				if (firstFileThumbprintUsed(dirEntry)) {
					if (nameType == PKIStoreNameType::ThumbPrint) {
						addToList = true;
					}
				}
				else {
					if (nameType == PKIStoreNameType::RealName) {
						addToList = true;
					}
				}
			}
			else {
				if (firstFileThumbprintUsed(dirEntry)) {
					if (nameType == PKIStoreNameType::RealName) {
						addToList = true;
					}
				}
				else {
					if (nameType == PKIStoreNameType::ThumbPrint) {
						addToList = true;
					}
				}
			}

			if (addToList) {
				nameVec.push_back(dirFile.filename().string());
			}
		}



		return true;
	}

	bool
	PKIStoreFile::createThumbPrint(const OpcUaByteString& buffer, std::string& thumbPrint)
	{
		// Check command line parameter
		if (buffer.size() == 0) {
			return false;
		}
		thumbPrint.resize(20);

		// Generate thumbprint
		boost::uuids::detail::sha1 sha;
		unsigned int digest[5];
		sha.process_bytes(const_cast<OpcUaByteString&>(buffer).memBuf(), buffer.size());
		sha.get_digest(digest);

		std::stringstream ss;
		for(int i = 0; i < 5; ++i) {
		    ss << std::hex << std::setfill('0') << std::setw(8) << digest[i];
		}
		thumbPrint = ss.str();
		return true;
	}

}
