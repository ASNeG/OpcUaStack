#ifndef __OpcUaStackCore_SetTriggeringResponse_h__
#define __OpcUaStackCore_SetTriggeringResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SetTriggeringResponse : public  ObjectPool<SetTriggeringResponse>
	{
	  public:
		SetTriggeringResponse(void);
		virtual ~SetTriggeringResponse(void);

		void addResults(const OpcUaStatusCodeArray::SPtr addResults);
		OpcUaStatusCodeArray::SPtr addResults(void) const;
		void addDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr addDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr addDiagnosticInfos(void) const;
		void removeResults(const OpcUaStatusCodeArray::SPtr removeResults);
		OpcUaStatusCodeArray::SPtr removeResults(void) const;
		void removeDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr removeDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr removeDiagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCodeArray::SPtr addResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr addDiagnosticInfoArraySPtr_;
		OpcUaStatusCodeArray::SPtr removeResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr removeDiagnosticInfoArraySPtr_;
	};

}

#endif