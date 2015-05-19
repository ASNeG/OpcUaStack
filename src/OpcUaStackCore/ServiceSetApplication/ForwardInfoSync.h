#ifndef __OpcUaStackCore_ForwardInfoSync_h__
#define __OpcUaStackCore_ForwardInfoSync_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardInfoSync
	: public  ObjectPool<ForwardInfoSync>
	{
	  public:
		typedef boost::shared_ptr<ForwardInfoSync> SPtr;

		ForwardInfoSync(void);
		virtual ~ForwardInfoSync(void);

		void setReadCallback(Callback& readCallback);
		void resetReadCallback(void);
		bool isReadCallback(void);
		Callback& readCallback(void);

		void setWriteCallback(Callback& writeCallback);
		void resetWriteCallback(void);
		bool isWriteCallback(void);
		Callback& writeCallback(void);

	  private:

		bool readCallbackFlag_;
		bool writeCallbackFlag_;

		Callback readCallback_;
		Callback writeCallback_;

	};

}

#endif
