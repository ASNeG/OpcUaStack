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

#ifndef __OpcUaStackCore_HistoryReadRequest_h__
#define __OpcUaStackCore_HistoryReadRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadValueId.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/TimestampsToReturn.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryReadRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<HistoryReadRequest> SPtr;

		HistoryReadRequest(void);
		virtual ~HistoryReadRequest(void);

		void historyReadDetails(const ExtensibleParameter::SPtr historyReadDetails);
		ExtensibleParameter::SPtr historyReadDetails(void) const;
		void timestampsToReturn(const TimestampsToReturn timestampsToReturn);
		TimestampsToReturn timestampsToReturn(void);
		void releaseContinuationPoints(const OpcUaBoolean& releaseContinuationPoints);
		OpcUaBoolean releaseContinuationPoints(void);
		void nodesToRead(const HistoryReadValueIdArray::SPtr nodesToRead);
		HistoryReadValueIdArray::SPtr nodesToRead(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		ExtensibleParameter::SPtr historyReadDetailsSPtr_;
		TimestampsToReturn timestampsToReturn_;
		OpcUaBoolean releaseContinuationPoints_;
		HistoryReadValueIdArray::SPtr nodesToReadArraySPtr_;
	};

}

#endif
