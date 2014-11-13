#ifndef __OpcUaStackCore_OpcUaNodeIdBase_h__
#define __OpcUaStackCore_OpcUaNodeIdBase_h__

#include <boost/variant.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{
	class OpcUaNodeIdNullType 
	{
	  public:
		OpcUaNodeIdNullType(void) {}
		~OpcUaNodeIdNullType(void) {}
	};

	typedef boost::variant<OpcUaNodeIdNullType, OpcUaUInt32,OpcUaString::SPtr,OpcUaGuid::SPtr,OpcUaByteString::SPtr> OpcUaNodeIdValue;

	class DLLEXPORT OpcUaNodeIdBase
	{
	  public:
	    OpcUaNodeIdBase(void);
		virtual ~OpcUaNodeIdBase(void);

		OpcUaNodeIdValue& nodeIdValue(void);
		void nodeIdValue(OpcUaNodeIdValue& nodeIdValue);

		void namespaceIndex(OpcUaUInt16 namespaceIndex);
		OpcUaInt16 namespaceIndex(void) const;

		OpcUaBuildInType nodeIdType(void) const;
		template<typename VAL>
		  void nodeId(const VAL& val) {
			  nodeIdValue_ = val;
		  }
		template<typename VAL>
		  VAL nodeId(void) const
		  {
		      return boost::get<VAL>(nodeIdValue_);
		  }

		void set(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0);
		bool get(OpcUaUInt32& nodeId, OpcUaUInt16& namespaceIndex);
		bool get(std::string& nodeId, OpcUaUInt16& namespaceIndex);
		bool get(OpcUaByte** buf, OpcUaInt32* bufLen, OpcUaUInt16& namespaceIndex);

		bool fromString(const std::string& nodeIdString);
		std::string toString(void) const;

		void copyTo(OpcUaNodeIdBase& opcUaNodeIdBase);
		bool operator!=(const OpcUaNodeIdBase& opcUaNodeId) const;
		bool operator==(const OpcUaNodeIdBase& opcUaNodeIdBase) const;
		bool operator<(const OpcUaNodeIdBase& opcUaNodeIdBase) const;


		virtual OpcUaByte encodingFlag(void) const;
		virtual void encodingFlag(OpcUaByte expandedEncodingFlag);

		friend std::ostream& operator<<(std::ostream& os, const OpcUaNodeIdBase& opcUaNodeId) {
			os << opcUaNodeId.toString();
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  protected:
		OpcUaUInt16 namespaceIndex_;
		OpcUaNodeIdValue nodeIdValue_;

	};
}

#endif
