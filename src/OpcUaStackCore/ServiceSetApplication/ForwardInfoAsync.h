#ifndef __OpcUaStackCore_ForwardInfoAsync_h__
#define __OpcUaStackCore_ForwardInfoAsync_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardInfoAsync
	: public  ObjectPool<ForwardInfoAsync>
	{
	  public:
		typedef boost::shared_ptr<ForwardInfoAsync> SPtr;
		typedef enum
		{
			F_Read 			= 0x00000001,
			F_Write			= 0x00000002,
			F_All			= 0xFFFFFFFF,
		} Flag;

		ForwardInfoAsync(void);
		virtual ~ForwardInfoAsync(void);

		void flag(Flag flag);
		Flag flag(void);
		bool isFlag(Flag flag);
		void component(Component* component);
		Component* component(void);

	  private:

		Flag flag_;
		Component* component_;
	};

}

#endif
