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

		static bool insertElement(OpcUaNodeId& opcUaNodeId, ExtensibleParameterBase::SPtr epSPtr);
		static bool deleteElement(OpcUaNodeId& opcUaNodeId);
		static ExtensibleParameterBase::SPtr findElement(OpcUaNodeId& opcUaNodeId);

		ExtensibleParameter(void);
		~ExtensibleParameter(void);

		template<typename T>
		  bool registerFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool deregisterFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return deregisterFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool factoryElementParameter(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return deregisterFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(buf, bufLen, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool deregisterFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(buf, bufLen, namespaceIndex);
			  return deregisterFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(OpcUaNodeId& opcUaNodeId) {
			  ExtensibleParameterBase::SPtr epSPtr(T::construct());
			  return ExtensibleParameter::insertElement(opcUaNodeId, epSPtr);
		  }

		template<typename T>
		  bool deregisterFactoryElement(OpcUaNodeId& opcUaNodeId) {
			  return ExtensibleParameter::deleteElement(opcUaNodeId);
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