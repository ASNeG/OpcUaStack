#ifndef __OpcUaStackCore_UpdateDataDetails_h__
#define __OpcUaStackCore_UpdateDataDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UpdateDataDetails : public  ObjectPool<UpdateDataDetails>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<UpdateDataDetails> SPtr;

		UpdateDataDetails(void);
		virtual ~UpdateDataDetails(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void performInsertReplace(const PerformUpdateEnumeration performInsertReplace);
		PerformUpdateEnumeration performInsertReplace(void);
		void updateValue(const OpcUaDataValueArray::SPtr updateValue);
		OpcUaDataValueArray::SPtr updateValue(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaNodeId nodeId_;
		PerformUpdateEnumeration performInsertReplace_;
		OpcUaDataValueArray::SPtr updateValueArraySPtr_;
	};

}

#endif