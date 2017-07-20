/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"

namespace OpcUaStackCore
{

	typedef std::map<OpcUaNodeId,ExtensionObjectBase::SPtr> ExtensionObjectMap;

	class DLLEXPORT OpcUaExtensionObject
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObject> SPtr;

		typedef enum {
			S_None,
			S_Type,
			S_ByteString
		} Style;

		static bool insertElement(OpcUaNodeId& opcUaNodeId, ExtensionObjectBase::SPtr epSPtr);
		static bool deleteElement(OpcUaNodeId& opcUaNodeId);
		static ExtensionObjectBase::SPtr findElement(OpcUaNodeId& opcUaNodeId);

	    OpcUaExtensionObject(void);
		~OpcUaExtensionObject(void);

		void reset(void);
		template<typename T>
		  bool registerFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(buf, bufLen, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryElement(OpcUaNodeId& opcUaNodeId) {
			  ExtensionObjectBase::SPtr epSPtr(constructSPtr<T>());
			  return OpcUaExtensionObject::insertElement(opcUaNodeId, epSPtr);
		  }

		bool deregisterFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);
		bool deregisterFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);
		bool deregisterFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0);
		bool deregisterFactoryElement(OpcUaNodeId& opcUaNodeId);

		bool createObject(void);
		ExtensionObjectBase::SPtr& get(void);
		template<typename T>
		   typename T::SPtr parameter(OpcUaUInt32 typeId) {
				this->typeId(typeId);
				return parameter<T>();
			}
		template<typename T>
		   typename T::SPtr parameter(const OpcUaNodeId& typeNodeId) {
				typeId(typeNodeId);
				return parameter<T>();
			}
		template<typename T>
		   typename T::SPtr parameter(void) {
			   if (epSPtr_.get() != NULL) {
				   return boost::static_pointer_cast<T>(epSPtr_);
			   }

			   epSPtr_ = findElement(typeId_);
			   if (epSPtr_.get() == NULL) {
				   typename T::SPtr epSPtr;
				   return epSPtr;
			   }

			   typename T::SPtr epSPtr = constructSPtr<T>();
			   style_ = S_Type;
			   epSPtr_ = epSPtr;
			   return epSPtr;
		   }

		void typeId(OpcUaUInt32 typeId);
		void typeId(const OpcUaNodeId& typeNodeId);
		OpcUaNodeId& typeId(void);

		Style style(void);
		void byteString(OpcUaByteString::SPtr& byteString);
		OpcUaByteString::SPtr byteString(void);

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
		bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

		void logExtensionObjectMap(void);

	  private:
		static ExtensionObjectMap extentionObjectMap_;
		static bool init_;

		Style style_;
		OpcUaNodeId typeId_;
		ExtensionObjectBase::SPtr epSPtr_;
		OpcUaByteString::SPtr byteString_;
	};

	class OpcUaExtensionObjectArray
	: public OpcUaArray<OpcUaExtensionObject::SPtr, SPtrTypeCoder<OpcUaExtensionObject> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObjectArray> SPtr;
	};

}

#endif
