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

#ifndef __OpcUaStackCore_RequestHeader_h__
#define __OpcUaStackCore_RequestHeader_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h"

namespace OpcUaStackCore
{
	class DLLEXPORT RequestHeader
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<RequestHeader> SPtr;

		RequestHeader(void);
		virtual ~RequestHeader(void);

		OpcUaNodeId& sessionAuthenticationToken(void);
		void time(const OpcUaUtcTime& time);
		void time(const boost::posix_time::ptime& time);
		OpcUaUtcTime time(void) const;
		void requestHandle(const OpcUaIntegerId& requestHandle);
		OpcUaIntegerId requestHandle(void) const;
		void returnDisagnostics(const OpcUaUInt32& returnDisagnostics);
		OpcUaUInt32 returnDisagnostics(void) const;
		void auditEntryId(const std::string& auditEntryId);
		std::string auditEntryId(void) const;
		void timeoutHint(const OpcUaUInt32& timeoutHint);
		OpcUaUInt32 timeoutHint(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId sessionAuthenticationToken_;
		OpcUaUtcTime time_;
		OpcUaIntegerId requestHandle_;
		OpcUaUInt32 returnDisagnostics_;
		OpcUaString auditEntryId_;
		OpcUaUInt32 timeoutHint_;
	};

}

#endif
