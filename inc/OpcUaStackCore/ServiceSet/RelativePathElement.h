#ifndef __OpcUaStackCore_RelativePathElement_h__
#define __OpcUaStackCore_RelativePathElement_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RelativePathElement : public  ObjectPool<RelativePathElement>
	{
	  public:
		typedef boost::shared_ptr<RelativePathElement> SPtr;

		RelativePathElement(void);
		virtual ~RelativePathElement(void);

		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isInverse(const OpcUaBoolean& isInverse);
		OpcUaBoolean isInverse(void) const;
		void includeSubtypes(const OpcUaBoolean& includeSubtypes);
		OpcUaBoolean includeSubtypes(void) const;
		void targetName(const OpcUaQualifiedName& tragetName);
		OpcUaQualifiedName& targetName(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isInverse_;
		OpcUaBoolean includeSubtypes_;
		OpcUaQualifiedName targetName_;
	};

	class RelativePathElementArray : public OpcUaArray<RelativePathElement::SPtr, SPtrTypeCoder<RelativePathElement> >, public ObjectPool<RelativePathElementArray> 
	{
	  public:
		typedef boost::shared_ptr<RelativePathElementArray> SPtr;
	};

}

#endif