/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_OpcUaExtensionObject_h__
#define __OpcUaStackCore_OpcUaExtensionObject_h__

#include <boost/property_tree/ptree.hpp>
#include <map>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	typedef std::map<OpcUaNodeId,ExtensionObjectBase::BSPtr> ExtensionObjectMap;

	class DLLEXPORT OpcUaExtensionObject : public ObjectPool<OpcUaExtensionObject>
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObject> SPtr;

		static bool insertElement(OpcUaNodeId& opcUaNodeId, ExtensionObjectBase::BSPtr epSPtr);
		static bool deleteElement(OpcUaNodeId& opcUaNodeId);
		static ExtensionObjectBase::BSPtr findElement(OpcUaNodeId& opcUaNodeId);

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
		static ExtensionObjectMap extentionObjectMap_;
		static bool init_;

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
