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

#ifndef __OpcUaStackCore_ResponseHeader_h__
#define __OpcUaStackCore_ResponseHeader_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ResponseHeader
	: public Object
	{
	  public:
		typedef boost::shared_ptr<ResponseHeader> SPtr;

		ResponseHeader(void);
		virtual ~ResponseHeader(void);

		void time(const OpcUaUtcTime& time);
		void time(const boost::posix_time::ptime& time);
		OpcUaUtcTime time(void) const;
		void requestHandle(const OpcUaIntegerId& requestHandle);
		OpcUaIntegerId requestHandle(void) const;
		void serviceResult(const OpcUaStatusCode& serviceResult);
		OpcUaStatusCode serviceResult(void) const;
		void diagnosticInfo(const OpcUaDiagnosticInfo::SPtr& diagnosticInfoSPtr);
		OpcUaDiagnosticInfo::SPtr diagnosticInfo(void) const;
		void stringTable(const OpcUaStringArray::SPtr stringTableSPtr);
		OpcUaStringArray::SPtr stringTable(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUtcTime time_;
		OpcUaIntegerId requestHandle_;
		OpcUaStatusCode serviceResult_;
		OpcUaDiagnosticInfo::SPtr diagnosticInfoSPtr_;
		OpcUaStringArray::SPtr stringTableSPtr_;
		// FIXME: additionalHeader_ 
	};

}

#endif
