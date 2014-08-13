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