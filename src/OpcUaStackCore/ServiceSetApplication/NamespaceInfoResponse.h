#ifndef __OpcUaStackCore_NamespaceInfoResponse_h__
#define __OpcUaStackCore_NamespaceInfoResponse_h__

#include <map>
#include <string>
#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackCore
{

	class DLLEXPORT NamespaceInfoResponse
	: public ObjectPool<NamespaceInfoResponse>
	{
	  public:
		typedef boost::shared_ptr<NamespaceInfoResponse> SPtr;
		typedef std::map<uint32_t,std::string> Index2NamespaceMap;
		typedef std::map<std::string,uint32_t> Namespace2IndexMap;

	    NamespaceInfoResponse(void);
		virtual ~NamespaceInfoResponse(void);

		Index2NamespaceMap& index2NamespaceMap(void);
		Namespace2IndexMap& namespace2IndexMap(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		Index2NamespaceMap index2NamespaceMap_;
		Namespace2IndexMap namespace2IndexMap_;
	};
}

#endif
