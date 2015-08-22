#ifndef __OpcUaStackCore_OpcUaExtensionObject_h__
#define __OpcUaStackCore_OpcUaExtensionObject_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaExtensionObject : public ObjectPool<OpcUaExtensionObject>
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObject> SPtr;

	    OpcUaExtensionObject(void);
		~OpcUaExtensionObject(void);

		void typeId(const OpcUaNodeId& typeId);
		OpcUaNodeId& typeId(void);
		void body(const OpcUaByteString& body);
		OpcUaByteString& body(void);

		void copyTo(OpcUaExtensionObject& extensionObject);
		bool operator!=(const OpcUaExtensionObject& extensionObject) const;
		bool operator==(const OpcUaExtensionObject& extensionObject) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaExtensionObject& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);

	  private:
		OpcUaNodeId typeId_;
		OpcUaByteString body_;
	};

	class OpcUaExtensionObjectArray : public OpcUaArray<OpcUaExtensionObject::SPtr, SPtrTypeCoder<OpcUaExtensionObject> >, public ObjectPool<OpcUaExtensionObjectArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObjectArray> SPtr;
	};

}

#endif
