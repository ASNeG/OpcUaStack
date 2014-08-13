#ifndef __OpcUaStackCore_ExtensibleParameter_h__
#define __OpcUaStackCore_ExtensibleParameter_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ExtensibleParameter : public  ObjectPool<ExtensibleParameter>
	{
	  public:
		typedef std::map<OpcUaNodeId,ExtensibleParameterBase::SPtr> ExtensibleParameterMap;

		ExtensibleParameter(void);
		~ExtensibleParameter(void);

		template<typename T>
		  void registerParameter(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.namespaceIndex(namespaceIndex);
			  opcUaNodeId.nodeId(nodeId);
			  registerParameter<T>(opcUaNodeId);
		  }

		template<typename T>
		  void registerParameter(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;

			  if (nodeId.length() == 36 && nodeId.substr(8,1) == "-" && nodeId.substr(13,1) == "-" && nodeId.substr(18,1) == "-" && nodeId.substr(23,1) == "-") {
				  OpcUaGuid::SPtr opcUaGuidSPtr = OpcUaGuid::construct();
				  *opcUaGuidSPtr = nodeId;
				  opcUaNodeId.nodeId(opcUaGuidSPtr);
			  }
			  else {
				  opcUaNodeId.nodeId(nodeId);
			  }
			  opcUaNodeId.namespaceIndex(namespaceIndex);
			  registerParameter<T>(opcUaNodeId);
		  }

		template<typename T>
		  void registerParameter(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  OpcUaByteString::SPtr opcUaByteStringSPtr = OpcUaByteString::construct();
			  opcUaByteStringSPtr->value(buf, bufLen);
			  opcUaNodeId.namespaceIndex(namespaceIndex);
			  opcUaNodeId.nodeId(opcUaNodeId);
			  registerParameter<T>(opcUaNodeId);
		  }

		template<typename T>
		  void registerParameter(OpcUaNodeId& opcUaNodeId) {
			  typename T::SPtr epSPtr = T::construct();
			  extensibleParameterMap_.insert(make_pair(opcUaNodeId, epSPtr));
		  }

		OpcUaNodeId& parameterTypeId(void);
		bool exist(void);

		template<typename T>
		   typename T::SPtr parameter(void) {
			   if (epSPtr_.get() != NULL) {
				   return boost::static_pointer_cast<T>(epSPtr_);
			   }

			   ExtensibleParameterMap::iterator it = extensibleParameterMap_.find(parameterTypeId_);
			   if (it == extensibleParameterMap_.end()) {
				   return epSPtr_;
			   }
			   typename T::SPtr epSPtr = T::construct();
			   epSPtr_ = epSPtr;
			   return epSPtr;
		   }

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		static bool init_;
		static ExtensibleParameterMap extensibleParameterMap_;

		OpcUaNodeId parameterTypeId_;
		ExtensibleParameterBase::SPtr epSPtr_;
	};

}

#endif
