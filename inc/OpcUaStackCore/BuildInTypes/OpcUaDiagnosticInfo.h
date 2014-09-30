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

		void setSymbolicId(const OpcUaInt32 symbolicId);
		OpcUaInt32 getSymbolicId() const;
		void setNamespaceUri(const OpcUaInt32 namespaceUri);
		OpcUaInt32 getNamespaceUri() const;
		void setLocalizedText(const OpcUaInt32 localizedText);
		OpcUaInt32 getLocalizedText() const;
		void setLocale(const OpcUaInt32 locale);
		OpcUaInt32 getLocale() const;
		void setAdditionalInfo(const OpcUaString& additionalInfo);
		const OpcUaString& getAdditionalInfo() const;
		void setInnerStatusCode(const OpcUaStatusCode innerStatusCode);
		OpcUaStatusCode getInnerStatusCode() const;

		void copyTo(OpcUaDiagnosticInfo& opcUaDiagnosticInfo);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDiagnosticInfo& value) {
			value.out(os);
			return os;
		}

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

	class OpcUaDiagnosticInfoArray : public OpcUaArray<OpcUaDiagnosticInfo::SPtr, SPtrTypeCoder<OpcUaDiagnosticInfo> >, public ObjectPool<OpcUaDiagnosticInfoArray> {};

}

#endif
