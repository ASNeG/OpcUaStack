/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_ParameterFlags_h__
#define __OpcUaClient_ParameterFlags_h__

#include <stdint.h>
#include <map>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaClient
{

	class DLLEXPORT ParameterFlags
	{
	  public:
		ParameterFlags(void);
		~ParameterFlags(void);

		void addParameter(uint32_t parameterId);
		bool existParameter(uint32_t parameterId);
		uint32_t getParameter(uint32_t parameterId);

	  private:
		typedef std::map<uint32_t, uint32_t> FlagMap;
		FlagMap flagMap_;

	};

}

#endif
