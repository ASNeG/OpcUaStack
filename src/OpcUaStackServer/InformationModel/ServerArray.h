/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ServerArray_h__
#define __OpcUaStackServer_ServerArray_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServerArray
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<ServerArray> SPtr;

		ServerArray(void);
		~ServerArray(void);

		void informationModel(InformationModel::SPtr informationModel);

		void serverArray(std::vector<std::string>& serverArray);
		bool addServerName(const std::string& serverName);
		int32_t getServerIndex(const std::string& serverName);
		std::string getServerName(uint32_t serverIndex);
		bool existServerIndex(uint32_t serverIndex);
		bool existServerName(const std::string& serverName);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif
