#ifndef __OpcUaStackCore_SimpleAttributeOperand_h__
#define __OpcUaStackCore_SimpleAttributeOperand_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SimpleAttributeOperand : public  ObjectPool<SimpleAttributeOperand>, public ExtensibleParameterBase
	{
	  public:
		SimpleAttributeOperand(void);
		virtual ~SimpleAttributeOperand(void);

		void typeId(const OpcUaNodeId::SPtr typeId);
		OpcUaNodeId::SPtr typeId(void) const;
		void browsePath(const OpcUaQualifiedNameArray::SPtr browsePath);
		OpcUaQualifiedNameArray::SPtr browsePath(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const std::string& indexRange);
		OpcUaString& indexRange(void);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr typeIdSPtr_;
		OpcUaQualifiedNameArray::SPtr browsePathArraySPtr_;
		OpcUaUInt32 attributeId_;
		OpcUaString indexRange_;
	};

	class SimpleAttributeOperandArray : public OpcUaArray<SimpleAttributeOperand::SPtr, SPtrTypeCoder<SimpleAttributeOperand> >, public ObjectPool<SimpleAttributeOperandArray> {};

}

#endif