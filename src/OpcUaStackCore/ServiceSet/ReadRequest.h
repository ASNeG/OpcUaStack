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

#ifndef __OpcUaStackCore_ReadRequest_h__
#define __OpcUaStackCore_ReadRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/ReadValueId.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ReadRequest> SPtr;

		ReadRequest(void);
		virtual ~ReadRequest(void);

		void maxAge(const OpcUaDouble& maxAge);
		OpcUaDouble maxAge(void) const;
		void timestampsToReturn(const OpcUaInt32& timestampsToReturn);
		OpcUaInt32 timestampsToReturn(void) const;
		void readValueIdArray(const ReadValueIdArray::SPtr readValueIdArray);
		ReadValueIdArray::SPtr readValueIdArray(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaDouble maxAge_;
		OpcUaInt32 timestampsToReturn_;
		ReadValueIdArray::SPtr readValueIdArraySPtr_;
	};

}

#endif
