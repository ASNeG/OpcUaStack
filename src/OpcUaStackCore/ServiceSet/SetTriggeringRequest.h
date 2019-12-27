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

#ifndef __OpcUaStackCore_SetTriggeringRequest_h__
#define __OpcUaStackCore_SetTriggeringRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SetTriggeringRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SetTriggeringRequest> SPtr;

		SetTriggeringRequest(void);
		virtual ~SetTriggeringRequest(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void triggeringItemId(const OpcUaUInt32& triggeringItemId);
		OpcUaUInt32 triggeringItemId(void) const;
		void linksToAdd(const OpcUaUInt32Array::SPtr linksToAdd);
		OpcUaUInt32Array::SPtr linksToAdd(void) const;
		void linksToRemove(const OpcUaUInt32Array::SPtr linksToRemove);
		OpcUaUInt32Array::SPtr linksToRemove(void) const;
		
		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32 triggeringItemId_;
		OpcUaUInt32Array::SPtr linksToAddArraySPtr_;
		OpcUaUInt32Array::SPtr linksToRemoveArraySPtr_;
	};

}

#endif
