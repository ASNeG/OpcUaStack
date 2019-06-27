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

#ifndef __OpcUaStackCore_GetNodeReferenceResponse_h__
#define __OpcUaStackCore_GetNodeReferenceResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetNodeReferenceResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<GetNodeReferenceResponse> SPtr;

	    GetNodeReferenceResponse(void);
		virtual ~GetNodeReferenceResponse(void);

		void nodeReferenceArray(const NodeReferenceArray::SPtr& nodeReferenceArray);
		NodeReferenceArray::SPtr& nodeReferenceArray(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		NodeReferenceArray::SPtr nodeReferenceArray_;
	};
}

#endif
