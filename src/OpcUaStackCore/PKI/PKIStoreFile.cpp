/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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
			if (dirEntryMap_.find(std::get<0>(dirEntry)) != dirEntryMap_.end()) continue;
			if (std::get<1>(dirEntry).empty()) continue;
			std::string pkiPath = config_->rootPath_ + "/" + std::get<1>(dirEntry);

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
			std::get<1>(dirEntry) = pkiPath;
			dirEntryMap_.insert(std::make_pair(std::get<0>(dirEntry), dirEntry));
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
	PKIStoreFile::exist(
		PKIStoreDataType type,
		const std::string& name
	)
	{
		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;

		// Check if file in directory exist
		std::string filename = std::get<1>(it->second) + "/" + name;
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

		// Find directory in directory map
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;

		// Get ThumbPrint
		std::string thumbPrint;
		if (!createThumbPrint(data, thumbPrint)) {
			Log(Error, "create thumbprint from data error")
				.parameter("Name", name);
			return false;
		}
		std::string filename = std::get<1>(it->second) + "/" + thumbPrint;
		bool useSymlinks = std::get<2>(it->second);

		// Check if file already exist
		if (exist(type, thumbPrint)) {
			Log(Error, "file write error, because file already exist")
				.parameter("ThumbPrint", thumbPrint)
				.parameter("Name", name);
			return false;
		}

		// Save file with thumbprint name
		try {
			boost::filesystem::ofstream ofs(filename);
			ofs << data.toString();
			ofs.close();
		}
		catch (std::exception& e) {
			Log(Error, "file write filename")
				.parameter("Filename", name)
				.parameter("Error", e.what());
			return false;
		}

		// Do we want to create a link?
		if (!useSymlinks) {
			return true;
		}

		// Create name link
		std::string link = std::get<1>(it->second) + "/" + name;
		boost::filesystem::create_symlink(
			boost::filesystem::path(filename),
			boost::filesystem::path(link),
			ec
		);
		if (ec) {
			Log(Error, "create symlink error")
				.parameter("Filename", filename)
				.parameter("Link", link)
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
		auto it = dirEntryMap_.find(type);
		if (it == dirEntryMap_.end()) return false;
		bool useSymlink = std::get<2>(it->second);
		std::string filename = std::get<1>(it->second) + "/" + name;

		// If file is symlink then get target file
		if (useSymlink) {
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
		std::string pkiDir = std::get<1>(it->second);

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
		std::string pkiDir = std::get<1>(it->second);
		bool useSymlink = std::get<2>(it->second);
		std::string filename = pkiDir + "/" + name;

		// Remove target file
		if (boost::filesystem::is_symlink(boost::filesystem::path(filename))) {

			// The file is a symlink file. We must remove the target of the
			// symlink first.
			boost::filesystem::path targetFile;
			targetFile = boost::filesystem::read_symlink(boost::filesystem::path(filename), ec);
			if (ec) {
				Log(Error, "cannot remove file, because read symlink target error")
					.parameter("SymlinkFile", filename)
					.parameter("Error", ec.message());
				return false;
			}

			boost::filesystem::remove(targetFile, ec);
			if (ec) {
				Log(Error, "cannot remove target file")
					.parameter("Filename", targetFile)
					.parameter("Error", ec.message());
				return false;
			}
		}
		else { // Find and remove the symlinks to the file
			if (useSymlink) {
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
							// Remove target file
							boost::filesystem::remove(dirFile, ec);
							if (ec) {
								Log(Error, "cannot remove symlink file")
								    .parameter("Filename", dirFile.string())
									.parameter("Error", ec.message());
								return false;
							}
							break;
						}
					}
				}
			}
		}

		// Remove file
		boost::filesystem::remove(boost::filesystem::path(filename), ec);
		if (ec) {
			Log(Error, "cannot remove file")
			    .parameter("Filename", filename)
				.parameter("Error", ec.message());
			return false;
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
		std::string pkiDir = std::get<1>(it->second);

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
