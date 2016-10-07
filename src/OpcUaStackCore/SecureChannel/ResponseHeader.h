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

#ifndef __OpcUaStackCore_ResponseHeader_h__
#define __OpcUaStackCore_ResponseHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
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

		void time(const UtcTime& time);
		void time(const boost::posix_time::ptime& time);
		UtcTime time(void) const;
		void requestHandle(const IntegerId& requestHandle);
		IntegerId requestHandle(void) const;
		void serviceResult(const OpcUaStatusCode& serviceResult);
		OpcUaStatusCode serviceResult(void) const;
		void diagnosticInfo(const OpcUaDiagnosticInfo::SPtr& diagnosticInfoSPtr);
		OpcUaDiagnosticInfo::SPtr diagnosticInfo(void) const;
		void stringTable(const OpcUaStringArray::SPtr stringTableSPtr);
		OpcUaStringArray::SPtr stringTable(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		UtcTime time_;
		IntegerId requestHandle_;
		OpcUaStatusCode serviceResult_;
		OpcUaDiagnosticInfo::SPtr diagnosticInfoSPtr_;
		OpcUaStringArray::SPtr stringTableSPtr_;
		// FIXME: additionalHeader_ 
	};

}

#endif
