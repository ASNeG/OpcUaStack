/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_MethodId_h__
#define __OpcUaStackServer_MethodId_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT MethodId
	{
	  public:
		MethodId(void);
		~MethodId(void);

		void methodNodeId(OpcUaNodeId& methodNodeId);
		OpcUaNodeId& methodNodeId(void);
		void objectNodeId(OpcUaNodeId& objectNodeId);
		OpcUaNodeId& objectNodeId(void);

		bool operator<(const MethodId& methodId) const;

	  private:
		OpcUaNodeId methodNodeId_;
		OpcUaNodeId objectNodeId_;

	};

}

#endif
