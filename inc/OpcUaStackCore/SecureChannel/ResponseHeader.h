#ifndef __OpcUaStackCore_ResponseHeader_h__
#define __OpcUaStackCore_ResponseHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ResponseHeader : public  ObjectPool<ResponseHeader>
	{
	  public:
		ResponseHeader(void);
		virtual ~ResponseHeader(void);

		void timestamp(const UtcTime& timestamp);
		UtcTime timestamp(void) const;
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
		UtcTime timestamp_;
		IntegerId requestHandle_;
		OpcUaStatusCode serviceResult_;
		OpcUaDiagnosticInfo::SPtr diagnosticInfoSPtr_;
		OpcUaStringArray::SPtr stringTableSPtr_;
		// FIXME: additionalHeader_ 
	};

}

#endif