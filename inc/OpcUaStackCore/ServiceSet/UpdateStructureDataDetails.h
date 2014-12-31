#ifndef __OpcUaStackCore_UpdateStructureDataDetails_h__
#define __OpcUaStackCore_UpdateStructureDataDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UpdateStructureDataDetails : public  ObjectPool<UpdateStructureDataDetails>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<UpdateStructureDataDetails> SPtr;

		UpdateStructureDataDetails(void);
		virtual ~UpdateStructureDataDetails(void);

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