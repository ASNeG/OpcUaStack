#ifndef __OpcUaStackCore_OpcUaDiagnosticInfo_h__
#define __OpcUaStackCore_OpcUaDiagnosticInfo_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaDiagnosticInfo : public ObjectPool<OpcUaDiagnosticInfo>
	{
	  public:
	    OpcUaDiagnosticInfo(void);
		~OpcUaDiagnosticInfo(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaInt32 symbolicId_;
		OpcUaInt32 namespaceUri_;
		OpcUaInt32 localizedText_;
		OpcUaInt32 locale_;
		OpcUaString additionalInfo_;
		OpcUaStatusCode innerStatusCode_;
		// FIXME: DiagnosticInfo
	};

	class OpcUaDiagnosticInfoArray : public OpcUaArray<OpcUaDiagnosticInfo::SPtr>, public ObjectPool<OpcUaDiagnosticInfoArray> {};

}

#endif
