#ifndef __OpcUaStackCore_AttributeOperand_h__
#define __OpcUaStackCore_AttributeOperand_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/ServiceSet/RelativePath.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AttributeOperand : public  ObjectPool<AttributeOperand>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<AttributeOperand> SPtr;

		AttributeOperand(void);
		virtual ~AttributeOperand(void);

		void nodeId(const OpcUaNodeId::SPtr nodeId);
		OpcUaNodeId::SPtr nodeId(void) const;
		void alias(const std::string& alias);
		OpcUaString& alias(void);
		void browsePath(const RelativePath& browsePath);
		RelativePath& browsePath(void);
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
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaString alias_;
		RelativePath browsePath_;
		OpcUaUInt32 attributeId_;
		OpcUaString indexRange_;
	};

}

#endif