#ifndef __OpcUaStackCore_ContentFilter_h__
#define __OpcUaStackCore_ContentFilter_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ContentFilterElement.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ContentFilter : public  ObjectPool<ContentFilter>
	{
	  public:
		typedef boost::shared_ptr<ContentFilter> SPtr;

		ContentFilter(void);
		virtual ~ContentFilter(void);

		void elements(const ContentFilterElementArray::SPtr elements);
		ContentFilterElementArray::SPtr elements(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ContentFilterElementArray::SPtr elementsArraySPtr_; 
	};

}

#endif