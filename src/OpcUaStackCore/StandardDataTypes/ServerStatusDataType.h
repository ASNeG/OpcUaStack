/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ServerStatusDataType_h__
#define __OpcUaStackCore_ServerStatusDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServerStatusDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<ServerStatusDataType> SPtr;

		ServerStatusDataType(void);
		virtual ~ServerStatusDataType(void);

		OpcUaDateTime& startTime(void);
		void startTime(OpcUaDateTime startTime);
		OpcUaDateTime& currentTime(void);
		void currentTime(OpcUaDateTime currentTime);
		OpcUaUInt32& serverState(void);
		void serverState(OpcUaUInt32 serverState);
		BuildInfo& buildInfo(void);
		void buildInfo(BuildInfo buildInfo);
		OpcUaUInt32& secondsTillShutdown(void);
		void secondsTillShutdown(OpcUaUInt32 secondsTillShutdown);
		OpcUaLocalizedText& shutdownReason(void);
		void shutdownReason(OpcUaLocalizedText shutdownReason);

		void copyTo(ServerStatusDataType& serverStatusDataType);
		bool operator==(const ServerStatusDataType& serverStatusDataType) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

	  private:
		OpcUaDateTime startTime_;
		OpcUaDateTime currentTime_;
		OpcUaUInt32 serverState_;
		BuildInfo buildInfo_;
		OpcUaUInt32 secondsTillShutdown_;
		OpcUaLocalizedText shutdownReason_;
	};

}

#endif
