#ifndef __OpcUaStackCore_OpcUaQulifiedName_h__
#define __OpcUaStackCore_OpcUaQulifiedName_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaQualifiedName : public ObjectPool<OpcUaQualifiedName>
	{
	  public:
		OpcUaQualifiedName(void);
		~OpcUaQualifiedName(void);

		void namespaceIndex(const OpcUaUInt16& namespaceIndex);
		OpcUaUInt16 namespaceIndex(void);
		void name(const OpcUaString& name);
		OpcUaString& name(void);
		OpcUaQualifiedName& operator=(const std::string& name);
		OpcUaQualifiedName& operator=(const OpcUaUInt16& namespaceIndex);
		operator std::string const (void); 
		operator OpcUaUInt16 const (void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt16 namespaceIndex_;
		OpcUaString name_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaQualifiedName& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaQualifiedName& value);

};

#endif