#ifndef __OpcUaStackCore_ContentFilterResult_h__
#define __OpcUaStackCore_ContentFilterResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ContentFilterElementResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ContentFilterResult : public  ObjectPool<ContentFilterResult>
	{
	  public:
		ContentFilterResult(void);
		virtual ~ContentFilterResult(void);

		void elementResults(const ContentFilterElementResult& elements);
		ContentFilterElementResult& elementResults(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ContentFilterElementResult elementResults_;
	};

}

#endif