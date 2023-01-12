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

#ifndef __OpcUaStackCore_UserExtension_h__
#define __OpcUaStackCore_UserExtension_h__

#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>
#include <map>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UserExtension
	{
	  public:
		using SPtr = boost::shared_ptr<UserExtension>;
		using Map = std::map<uint32_t, SPtr>;
		using Vec = std::vector<SPtr>;
		using EntryMap = std::map<std::string, std::string>;

		UserExtension(void);
		virtual ~UserExtension(void);

		void nid(uint32_t nid);
		uint32_t nid(void);
		bool existEntry(const std::string& name);
		bool setEntry(const std::string& name, const std::string& value);
		bool getEntry(const std::string& name, std::string& value);
		void delEntry(const std::string& name);
		void getEntryVec(std::vector<std::string>& names);
		void logContent(const std::string& message);

		virtual bool encodeExtensionData(void) = 0;
		virtual bool decodeExtensionData(void) = 0;

	  protected:
		uint32_t nid_ = 0;
		EntryMap entryMap_;
	};

}

#endif
