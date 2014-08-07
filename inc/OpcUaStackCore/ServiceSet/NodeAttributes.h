#ifndef __OpcUaStackCore_NodeAttributes_h__
#define __OpcUaStackCore_NodeAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ObjectAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableAttributes.h"
#include "OpcUaStackCore/ServiceSet/MethodAttributes.h"
#include "OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/DataTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ViewAttributes.h"
#include <boost/variant.hpp>


namespace OpcUaStackCore
{
	typedef boost::variant<
	    ObjectAttributes::SPtr,
	    VariableAttributes::SPtr,
	    MethodAttributes::SPtr,
	    ObjectTypeAttributes::SPtr,
	    VariableTypeAttributes::SPtr,
	    ReferenceTypeAttributes::SPtr,
	    DataTypeAttributes::SPtr,
	    ViewAttributes::SPtr
	    > NodeAttributesVariantType;

	class DLLEXPORT NodeAttributes : public  ObjectPool<NodeAttributes>
	{
	  public:
		NodeAttributes(void);
		virtual ~NodeAttributes(void);

                void variant(const ObjectAttributes::SPtr valSPtr);
                void variant(const VariableAttributes::SPtr valSPtr);
                void variant(const ObjectTypeAttributes::SPtr valSPtr);
                void variant(const VariableTypeAttributes::SPtr valSPtr);
                void variant(const ReferenceTypeAttributes::SPtr valSPtr);
                void variant(const DataTypeAttributes::SPtr valSPtr);
                void variant(const ViewAttributes::SPtr valSPtr);
		NodeAtributesVariantType variantType(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		NodeAtributesVariantType variantValue_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const NodeAttributes& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const NodeAttributes::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, NodeAttributes& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, NodeAttributes::SPtr& value);


	class NodeAttributesArray : public OpcUaArray<NodeAttributes::SPtr>,
	                            public ObjectPool<NodeAttributesArray> {};

        DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const NodeAttributesArray& value);
        DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const NodeAttributesArray::SPtr& value);
        DLLEXPORT void opcUaBinaryDecode(std::istream& is,NodeAttributesArray& value);
        DLLEXPORT void opcUaBinaryDecode(std::istream& is,NodeAttributesArray::SPtr& value);

}

#endif
