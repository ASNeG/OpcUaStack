#ifndef __OpcUaStackClient_NamespaceArray_h__
#define __OpcUaStackClient_NamespaceArray_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

namespace OpcUaStackClient
{

	class DLLEXPORT NamespaceArray
	{
	  public:
		NamespaceArray(void);
		NamespaceArray(Session::SPtr session);
		~NamespaceArray(void);

		void session(Session::SPtr session);
		bool readSync(void);
		std::vector<std::string>& namespaceVec(void);

	  private:
		Session::SPtr session_;
		std::vector<std::string> namespaceVec_;
	};

}

#endif
