/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackServer/Server/ServerStatusDataType.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServerStatusDataType::ServerStatusDataType(void)
	: OpcUaStackCore::ServerStatusDataType()
	, informationModel_()
	{
	}

	ServerStatusDataType::~ServerStatusDataType(void)
	{
	}

	bool
	ServerStatusDataType::init(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
		if (!initData()) return false;

		// set ServerStatus
		{
			OpcUaExtensionObject::SPtr extensionObject = boost::make_shared<OpcUaExtensionObject>();
			OpcUaNodeId typeId;
			typeId.set(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
			extensionObject->typeId(typeId);
		    copyTo(*extensionObject->parameter<ServerStatusDataType>().get());

			OpcUaDataValue dataValue;
			dataValue.variant()->variant(extensionObject);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus, AttributeId_Value, dataValue);
		}

		// set BuildInfo
		{
			OpcUaExtensionObject::SPtr extensionObject = boost::make_shared<OpcUaExtensionObject>();
			OpcUaDateTime now(boost::posix_time::microsec_clock::universal_time());

			OpcUaNodeId typeId;
			typeId.set(OpcUaId_BuildInfo_Encoding_DefaultBinary);
			extensionObject->typeId(typeId);
			buildInfo().copyTo(*extensionObject->parameter<BuildInfo>().get());

			OpcUaDataValue dataValue;
			dataValue.variant()->variant(extensionObject);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_BuildInfo, AttributeId_Value, dataValue);
		}

		// set Current Time
		{
			OpcUaDataValue dataValue;
			dataValue.variant()->variant(currentTime());
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_CurrentTime, AttributeId_Value, dataValue);
		}

		// set SecondsTillShutdown
		{
			OpcUaDataValue dataValue;
			dataValue.variant()->variant(secondsTillShutdown());
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_SecondsTillShutdown, AttributeId_Value, dataValue);
		}

		// set ShutdownReason
		{
			OpcUaLocalizedText::SPtr value = boost::make_shared<OpcUaLocalizedText>();
			shutdownReason().copyTo(*value);

			OpcUaDataValue dataValue;
			dataValue.variant()->variant(value);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_ShutdownReason, AttributeId_Value, dataValue);
		}

		// set StartTime
		{
			OpcUaDataValue dataValue;
			dataValue.variant()->variant(startTime());
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_StartTime, AttributeId_Value, dataValue);
		}

		// set State
		{
			OpcUaDataValue dataValue;
			dataValue.variant()->variant((OpcUaInt32)0);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::universal_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_State, AttributeId_Value, dataValue);
		}

		return true;
	}

	bool
	ServerStatusDataType::shutdown(void)
	{
		if (!shutdownData()) return false;
		return true;
	}

	bool
	ServerStatusDataType::initData(void)
	{
		startTime() = boost::posix_time::microsec_clock::local_time();
		currentTime() = boost::posix_time::microsec_clock::local_time();
		state().enumeration(ServerState::EnumRunning);
		secondsTillShutdown() = 0;
		shutdownReason().set("", "");

		buildInfo().productUri() = "urn:ASNeG:OpcUaServer";
		buildInfo().manufacturerName() = "ASNeG";
		buildInfo().productName() = "ASNeG OpcUaServer";
		buildInfo().softwareVersion() = "";											// FIXME
		buildInfo().buildNumber() = "";												// FIXME
		buildInfo().buildDate() = boost::posix_time::microsec_clock::universal_time();	// FIXME

		return true;
	}

	bool
	ServerStatusDataType::shutdownData(void)
	{
		return true;
	}

}
