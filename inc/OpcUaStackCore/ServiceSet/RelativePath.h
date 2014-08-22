#ifndef __OpcUaStackCore_RelativePath_h__
#define __OpcUaStackCore_RelativePath_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/RelativePathElement.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RelativePath : public  ObjectPool<RelativePath>
	{
	  public:
		RelativePath(void);
		virtual ~RelativePath(void);

		void elements(const RelativePathElementArray::SPtr elements);
		RelativePathElementArray::SPtr elements(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RelativePathElementArray::SPtr elementsArraySPtr_; 
	};

}

#endif