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

#ifndef __OpcUaStackCore_QueryFirstRequest_h__
#define __OpcUaStackCore_QueryFirstRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/ServiceSet/NodeTypeDescription.h"
#include "OpcUaStackCore/ServiceSet/ViewDescription.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryFirstRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<QueryFirstRequest> SPtr;

		QueryFirstRequest(void);
		virtual ~QueryFirstRequest(void);

		void view(const ViewDescription& view);
		ViewDescription& view(void);
		void nodeTypes(const NodeTypeDescriptionArray::SPtr nodeTypes);
		NodeTypeDescriptionArray::SPtr nodeTypes(void) const;
		void filter(const ContentFilter& filter);
		ContentFilter& filter(void);
		void maxDataSetsToReturn(const OpcUaUInt32& maxDataSetsToReturn);
		OpcUaUInt32 maxDataSetsToReturn(void);
		void maxReferencesToReturn(const OpcUaUInt32& maxReferencesToReturn);
		OpcUaUInt32 maxReferencesToReturn(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		ViewDescription view_;
		NodeTypeDescriptionArray::SPtr nodeTypeArraySPtr_;
		ContentFilter filter_;
		OpcUaUInt32 maxDataSetsToReturn_;
		OpcUaUInt32 maxReferencesToReturn_;
	};

}

#endif
