#ifndef __OpcUaStackCore_StatusChangeNotification_h__
#define __OpcUaStackCore_StatusChangeNotification_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT StatusChangeNotification : public  ObjectPool<StatusChangeNotification>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<StatusChangeNotification> SPtr;

		StatusChangeNotification(void);
		virtual ~StatusChangeNotification(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void diagnosticInfo(const OpcUaDiagnosticInfo& diagnosticInfo);
		OpcUaDiagnosticInfo& diagnosticInfo(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		  OpcUaStatusCode statusCode_;
		  OpcUaDiagnosticInfo diagnosticInfo_;
	};

	
}

#endif