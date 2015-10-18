/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BuildInfo_h__
#define __OpcUaStackCore_BuildInfo_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"

namespace OpcUaStackCore
{

	class BuildInfo
	{
	  public:
		BuildInfo(void);
		~BuildInfo(void);

		OpcUaString& productUri(void);
		OpcUaString& manufacturerName(void);
		OpcUaString& productName(void);
		OpcUaString& softwareVersion(void);
		OpcUaString& buildNumber(void);
		OpcUaDateTime& buildDate(void);

	  private:
		OpcUaString productUri_;
		OpcUaString manufacturerName_;
		OpcUaString productName_;
		OpcUaString softwareVersion_;
		OpcUaString buildNumber_;
		OpcUaDateTime buildDate_;
	};

}

#endif
