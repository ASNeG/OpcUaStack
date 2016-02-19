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

#include <boost/asio/streambuf.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaExtensionObject
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool OpcUaExtensionObject::init_ = false;
	ExtensionObjectMap OpcUaExtensionObject::extentionObjectMap_;

	bool
	OpcUaExtensionObject::insertElement(OpcUaNodeId& opcUaNodeId, ExtensionObjectBase::BSPtr epSPtr)
	{
		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(opcUaNodeId);
		if (it != extentionObjectMap_.end()) {
			return false;
		}
		extentionObjectMap_.insert(std::make_pair(opcUaNodeId, epSPtr));
		return true;
	}

	bool
	OpcUaExtensionObject::deleteElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(opcUaNodeId);
		if (it == extentionObjectMap_.end()) {
			return false;
		}
		extentionObjectMap_.erase(it);
		return true;
	}

	ExtensionObjectBase::BSPtr
	OpcUaExtensionObject::findElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensionObjectBase::BSPtr epSPtr;
		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(opcUaNodeId);
		if (it != extentionObjectMap_.end()) {
			epSPtr = it->second;
		}
		return epSPtr;
	}

	OpcUaExtensionObject::OpcUaExtensionObject(void)
	: Object()
	, typeId_()
	, epSPtr_()
	{
	}
		
	OpcUaExtensionObject::~OpcUaExtensionObject(void)
	{
	}

	bool
	OpcUaExtensionObject::deregisterFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex) {
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.set(nodeId, namespaceIndex);
		return deregisterFactoryElement(opcUaNodeId);
	}

	bool
	OpcUaExtensionObject::deregisterFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex) {
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.set(nodeId, namespaceIndex);
		return deregisterFactoryElement(opcUaNodeId);
	}

	bool
	OpcUaExtensionObject::deregisterFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex) {
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.set(buf, bufLen, namespaceIndex);
		return deregisterFactoryElement(opcUaNodeId);
	}

	bool
	OpcUaExtensionObject::deregisterFactoryElement(OpcUaNodeId& opcUaNodeId) {
		return OpcUaExtensionObject::deleteElement(opcUaNodeId);
	}

	void 
	OpcUaExtensionObject::typeId(const OpcUaNodeId& typeId)
	{
		typeId_ = typeId;
	}

	OpcUaNodeId& 
	OpcUaExtensionObject::typeId(void)
	{
		return typeId_;
	}

	bool
	OpcUaExtensionObject::createObject(void)
	{
		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(typeId_);
		if (it == extentionObjectMap_.end()) {
			return false;
		}
		epSPtr_ = it->second->factory();
		return true;
	}

	ExtensionObjectBase::BSPtr&
	OpcUaExtensionObject::get(void)
	{
		return epSPtr_;
	}

	void 
	OpcUaExtensionObject::copyTo(OpcUaExtensionObject& extensionObject)
	{
		if (!epSPtr_) return;
		typeId_.copyTo(extensionObject.typeId());
		if (!extensionObject.createObject()) return;
		epSPtr_->copyTo(*(ExtensionObjectBase*)extensionObject.get().get());
	}

	void 
	OpcUaExtensionObject::out(std::ostream& os) const
	{
		if (!epSPtr_) return;
		epSPtr_->out(os);
	}

	bool 
	OpcUaExtensionObject::operator!=(const OpcUaExtensionObject& extensionObject) const
	{
		return !operator==(extensionObject);
	}

	bool 
	OpcUaExtensionObject::operator==(const OpcUaExtensionObject& extensionObject) const
	{
		if (!epSPtr_) return false;
		ExtensionObjectBase* extensionObjectBase = const_cast<OpcUaExtensionObject*>(&extensionObject)->get().get();
		return epSPtr_->equal(*extensionObjectBase);
	}

	void 
	OpcUaExtensionObject::opcUaBinaryEncode(std::ostream& os) const
	{
		if(epSPtr_.get() == NULL)
		{
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		} else {
			typeId_.opcUaBinaryEncode(os);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);

			boost::asio::streambuf sb;
			std::ostream osb(&sb);
			epSPtr_->opcUaBinaryEncode(osb);

			OpcUaUInt32 bufferLength = OpcUaStackCore::count(sb);
			OpcUaNumber::opcUaBinaryEncode(os, bufferLength);
			os << osb.rdbuf();
		}
	}
		
	void 
	OpcUaExtensionObject::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		typeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(typeId_);
		if (it == extentionObjectMap_.end()) {
			return;
		}

		OpcUaUInt32 bufferLength;
		OpcUaNumber::opcUaBinaryDecode(is, bufferLength);
		epSPtr_ = it->second->factory();
		epSPtr_->opcUaBinaryDecode(is);
	}
	
	bool
	OpcUaExtensionObject::encode(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree typeId;
		if (!typeId_.encode(typeId)) return false;
		pt.put_child("TypeId", typeId);

		return true;
	}

	bool
	OpcUaExtensionObject::decode(boost::property_tree::ptree& pt)
	{
		boost::optional<boost::property_tree::ptree&> typeId;
		typeId = pt.get_child_optional("TypeId");
		if (!typeId) return false;
		if (!typeId_.decode(*typeId)) return false;

		return true;
	}

};
