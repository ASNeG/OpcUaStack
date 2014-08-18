#ifndef __OpcUaStackCore_StatusChangeNotification_h__
#define __OpcUaStackCore_StatusChangeNotification_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildINTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT StatusChangeNotification : public  ObjectPool<StatusChangeNotification>
	{
	  public:
		StatusChangeNotification(void);
		virtual ~StatusChangeNotification(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void diagnosticInfo(const OpcUaDiagnosticInfo& diagnosticInfo);
		OpcUaDiagnosticInfo& diagnosticInfo(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaStatusCode statusCode_;
		  OpcUaDiagnosticInfo diagnosticInfo_;
	};

	
}

#endif