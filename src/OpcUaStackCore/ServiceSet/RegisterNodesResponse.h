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

#ifndef __OpcUaStackCore_RegisterNodesResponse_h__
#define __OpcUaStackCore_RegisterNodesResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterNodesResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<RegisterNodesResponse> SPtr;

	    RegisterNodesResponse(void);
		virtual ~RegisterNodesResponse(void);

		void registeredNodeIds(const OpcUaNodeIdArray::SPtr registeredNodeIds);
		OpcUaNodeIdArray::SPtr registeredNodeIds(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeIdArray::SPtr registeredNodeIdArraySPtr_;
	};
}

#endif
