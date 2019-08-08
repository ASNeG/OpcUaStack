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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

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
	OpcUaExtensionObject::insertElement(OpcUaNodeId& opcUaNodeId, ExtensionObjectBase::SPtr epSPtr)
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

	ExtensionObjectBase::SPtr
	OpcUaExtensionObject::findElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensionObjectBase::SPtr epSPtr;
		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(opcUaNodeId);
		if (it != extentionObjectMap_.end()) {
			epSPtr = it->second;
		}
		return epSPtr;
	}

	OpcUaExtensionObject::OpcUaExtensionObject(void)
	: Object()
	, style_(S_None)
	, typeId_()
	, epSPtr_()
	, byteString_()
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
	OpcUaExtensionObject::reset(void)
	{
		style_ = S_None;
		typeId_.reset();
		epSPtr_.reset();
		byteString_.reset();
	}

	void
	OpcUaExtensionObject::typeId(OpcUaUInt32 typeId)
	{
		OpcUaNodeId typeNodeId;
		typeNodeId.set(typeId);
		this->typeId(typeNodeId);
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

	OpcUaExtensionObject::Style
	OpcUaExtensionObject::style(void)
	{
		return style_;
	}

	void
	OpcUaExtensionObject::byteString(OpcUaByteString::SPtr& byteString)
	{
		style_ = S_ByteString;
		byteString_ = byteString;
	}

	OpcUaByteString::SPtr
	OpcUaExtensionObject::byteString(void)
	{
		return byteString_;
	}

	bool
	OpcUaExtensionObject::createObject(void)
	{
		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(typeId_);
		if (it == extentionObjectMap_.end()) {
			return false;
		}
		style_ = S_Type;
		epSPtr_ = it->second->factory();
		return true;
	}

	ExtensionObjectBase::SPtr&
	OpcUaExtensionObject::get(void)
	{
		return epSPtr_;
	}

	void 
	OpcUaExtensionObject::copyTo(OpcUaExtensionObject& extensionObject)
	{
		if (style_ == S_None) {
			return;
		}

		if (style_ == S_ByteString) {
			if (byteString_.get() == nullptr) return;
			typeId_.copyTo(extensionObject.typeId());
			OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>();
			byteString_->copyTo(*byteString);
			extensionObject.byteString(byteString);
		}

		else {
			if (!epSPtr_) return;
			typeId_.copyTo(extensionObject.typeId());
			if (!extensionObject.createObject()) return;
			epSPtr_->copyTo(*(ExtensionObjectBase*)extensionObject.get().get());
		}
	}

	void 
	OpcUaExtensionObject::out(std::ostream& os) const
	{
		if (!epSPtr_) return;

		if (style_ == S_ByteString) {
			if (byteString_.get() == nullptr) return;
			byteString_->out(os);
		}
		else {
			epSPtr_->out(os);
		}
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

		if (style_ == S_ByteString) {
			OpcUaByteString* byteString = const_cast<OpcUaExtensionObject*>(&extensionObject)->byteString().get();

			if (byteString_.get() == nullptr && byteString == nullptr) return true;
			if (byteString_.get() == nullptr) return false;
			if (byteString == nullptr) return false;

			return (*byteString_ == *byteString);
		}

		else {
			ExtensionObjectBase* extensionObjectBase = const_cast<OpcUaExtensionObject*>(&extensionObject)->get().get();
			return epSPtr_->equal(*extensionObjectBase);
		}
	}

	void 
	OpcUaExtensionObject::opcUaBinaryEncode(std::ostream& os) const
	{
		if (style_ == S_None) {
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		}

		else if (style_ == S_ByteString) {
			if (byteString_.get() == nullptr) {
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			}

			else {
				typeId_.opcUaBinaryEncode(os);
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);
				byteString_->opcUaBinaryEncode(os);
			}
		}

		else {
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
	}
		
	void 
	OpcUaExtensionObject::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		typeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		if (encodingMask == 0x00) {
			style_ = S_None;
			return;
		}

		ExtensionObjectMap::iterator it;
		it = extentionObjectMap_.find(typeId_);
		if (it == extentionObjectMap_.end()) {

			// Extension object unknown - read extension data as raw byte string

			style_ = S_ByteString;
			byteString_ = constructSPtr<OpcUaByteString>();
			byteString_->opcUaBinaryDecode(is);

			return;
		}

		style_ = S_Type;
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
	OpcUaExtensionObject::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// get typeId
		boost::optional<boost::property_tree::ptree&> typeId = pt.get_child_optional(xmlns.addxmlns("TypeId"));
		if (!typeId) typeId = pt.get_child_optional("TypeId");
		if (!typeId) {
			Log(Error, "value empty")
				.parameter("Tag", xmlns.addxmlns("TypeId"));
			return false;
		}

		// get identifier
		boost::optional<std::string> identifier = typeId->get_optional<std::string>(xmlns.addxmlns("Identifier"));
		if (!identifier) identifier = typeId->get_optional<std::string>("Identifier");
		if (!identifier) {
			Log(Error, "value empty")
				.parameter("Tag", xmlns.addxmlns("Identifier"));
			return false;
		}

		OpcUaNodeId xmlNodeIdType;
		std::string s = *identifier;
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		bool rc = xmlNodeIdType.fromString(s);
		if (!rc) {
			Log(Error, "value format error")
				.parameter("Tag", xmlns.addxmlns("Identifier"))
				.parameter("Identifier", s);
			return false;
		}

		// get body
		boost::optional<boost::property_tree::ptree&> body = pt.get_child_optional(xmlns.addxmlns("Body"));
		if (!body) body = pt.get_child_optional("Body");
		if (!body) {
			Log(Error, "value empty")
				.parameter("Tag", xmlns.addxmlns("Body"))
				.parameter("NodeIdType", xmlNodeIdType);
			return false;
		}

		this->typeId(xmlNodeIdType);
		if (!createObject()) {
			// Extension object unknown
			logExtensionObjectMap();
			Log(Error, "extension object unknown")
				.parameter("NodeIdType", xmlNodeIdType);
			return false;
		}

		// Currently the XML type ist stored in the object. Now we determine
		// the binary type by the XMl type.
		typeId_ = epSPtr_->binaryTypeId();

		// decode extension object from xml file
		return epSPtr_->decode(*body, xmlns);
	}

	bool
	OpcUaExtensionObject::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addxmlns(element), elementTree));
		return true;
	}

	bool
	OpcUaExtensionObject::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		if (epSPtr_.get() == nullptr) {
			Log(Error, "OpcUaExtensionObject xml encoder error - object invalid");
			return false;
		}

		//
		// encode type id
		//
		boost::property_tree::ptree typeIdTree;
		OpcUaNodeId xmlNodeId = epSPtr_->xmlTypeId();
		if (!xmlNodeId.xmlEncode(typeIdTree, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml encoder error")
				.parameter("Element", "TypeId");
			return false;
		}
		pt.add_child(xmlns.addxmlns("TypeId"), typeIdTree);

		//
		// encode body
		//
		boost::property_tree::ptree bodyTree;
		if (!epSPtr_->xmlEncode(bodyTree, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml encoder error")
				.parameter("Element", "Body");
			return false;
		}
		pt.add_child(xmlns.addxmlns("Body"), bodyTree);

		return true;
	}

	bool
	OpcUaExtensionObject::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		//
		// get typeIdTree tree
		//
		boost::optional<boost::property_tree::ptree&> typeIdTree = pt.get_child_optional(xmlns.addxmlns("TypeId"));
		if (!typeIdTree) {
			Log(Error, "OpcUaExtensionObject xml decoder error - element not exist in xml document")
				.parameter("Element", "TypeId");
			return false;
		}

		//
		// get type id
		//
		OpcUaNodeId xmlTypeNodeId;
		if (!xmlTypeNodeId.xmlDecode(*typeIdTree, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml decoder error")
				.parameter("Element", "TypeId");
			return false;
		}

		//
		// get body tree
		//
		boost::optional<boost::property_tree::ptree&> bodyTree = pt.get_child_optional(xmlns.addxmlns("Body"));
		if (!bodyTree) {
			Log(Error, "OpcUaExtensionObject xml decoder error - element not exist in xml document")
				.parameter("Element", "Body")
				.parameter("XmlTypeNodeId", xmlTypeNodeId);
			return false;
		}

		this->typeId(xmlTypeNodeId);
		if (!createObject()) {
			// Extension object unknown
			logExtensionObjectMap();
			Log(Error, "OpcUaExtensionObject xml decoder error - object create error")
				.parameter("Element", "Body")
				.parameter("XmlTypeNodeId", xmlTypeNodeId);
			return false;
		}

		// Currently the XML type ist stored in the object. Now we determine
		// the binary type by the XMl type.
		typeId_ = epSPtr_->binaryTypeId();

		//
		// decode extension object from xml file
		//
		if (!epSPtr_->xmlDecode(*bodyTree, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml decoder error")
				.parameter("Element", "Body")
				.parameter("XmlTypeNodeId", xmlTypeNodeId);
			return false;
		}
		return true;
	}

	void
	OpcUaExtensionObject::logExtensionObjectMap(void)
	{
		Log(Debug, "extension object map entries");

		ExtensionObjectMap::iterator it;
		for (it=extentionObjectMap_.begin(); it!=extentionObjectMap_.end(); it++) {
			Log(Debug, "  ").parameter(" ", it->first);
		}
	}

};
