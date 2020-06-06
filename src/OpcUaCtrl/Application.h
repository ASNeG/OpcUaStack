/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaCtrl_Application_h__
#define __OpcUaCtrl_Application_h__

#include <boost/shared_ptr.hpp>
#include <set>
#include <map>
#include <vector>
#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaCtrl
{

	class DLLEXPORT ApplicationInfo
	{
	  public:
		using SPtr = boost::shared_ptr<ApplicationInfo>;
		using Map = std::map<std::string, SPtr>;

		ApplicationInfo(void);
		~ApplicationInfo(void);

		std::string installPath_ = "";
		std::string applName_ = "";
	};

	class DLLEXPORT Application
	{
	  public:
		using iterator = ApplicationInfo::Map::iterator;

		Application(
		    const std::set<std::string>& applBlackList,
			const std::vector<std::string>& installPathList
		);
		virtual ~Application(void);

		ApplicationInfo::Map& map(void);
		const iterator begin(void);
		const iterator end(void);

	  private:
		ApplicationInfo::Map applicationInfoMap_;
	};

}

#endif
