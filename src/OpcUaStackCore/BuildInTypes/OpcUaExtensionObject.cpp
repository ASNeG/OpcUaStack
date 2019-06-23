/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/XmlnsGuard.h"
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
	ExtensionObjectBase::Map OpcUaExtensionObject::extentionObjectMap_;

	bool
	OpcUaExtensionObject::insertElement(OpcUaNodeId& opcUaNodeId, ExtensionObjectBase::SPtr epSPtr)
	{
		// check if extension object already exist
		auto it = extentionObjectMap_.find(opcUaNodeId);
		if (it != extentionObjectMap_.end()) {
			Log(Error, "cannot insert new extension object, because object type id already exost")
				.parameter("TypeId", opcUaNodeId);
			return false;
		}

		// added extension object to extension object map
		extentionObjectMap_.insert(std::make_pair(opcUaNodeId, epSPtr));
		return true;
	}

	bool
	OpcUaExtensionObject::deleteElement(OpcUaNodeId& opcUaNodeId)
	{
		// check if extension object exists
		auto it = extentionObjectMap_.find(opcUaNodeId);
		if (it == extentionObjectMap_.end()) {
			return false;
		}

		// remove extension object from extension object map
		extentionObjectMap_.erase(it);
		return true;
	}

	ExtensionObjectBase::SPtr
	OpcUaExtensionObject::findElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensionObjectBase::SPtr epSPtr;
		auto it = extentionObjectMap_.find(opcUaNodeId);
		if (it != extentionObjectMap_.end()) {
			epSPtr = it->second;
		}
		return epSPtr;
	}

	OpcUaNodeId
	OpcUaExtensionObject::getBinaryTypeIdFromJsonTypeId(OpcUaNodeId& jsonTypeId)
	{
		auto extenstionObject = findElement(jsonTypeId);
		if (extenstionObject.get() == nullptr) {
			return OpcUaNodeId(0,0);
		}
		else {
			return extenstionObject->binaryTypeId();
		}
	}

	OpcUaExtensionObject::OpcUaExtensionObject(void)
	: Object()
	, style_(S_None)
	, typeId_()
	, epSPtr_()
	, byteString_()
	{
	}

	OpcUaExtensionObject::OpcUaExtensionObject(const OpcUaNodeId& typeId)
	: Object()
	, style_(S_None)
	, typeId_(typeId)
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
		// find extension object
		auto it = extentionObjectMap_.find(typeId_);
		if (it == extentionObjectMap_.end()) {
			return false;
		}

		// create new extension object
		style_ = S_Type;
		epSPtr_ = it->second->factory();

		if (epSPtr_.get() == nullptr) {
			return false;
		}
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

		ExtensionObjectBase::Map::iterator it;
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
	OpcUaExtensionObject::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml encoder error")
				.parameter("Element", element);
			return false;
		}

		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
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
		pt.add_child(xmlns.addPrefix("TypeId"), typeIdTree);

		//
		// encode body
		//
		boost::property_tree::ptree bodyTree;
		std::string uri = xmlns.getPrefix("http://opcfoundation.org/UA/2008/02/Types.xsd");
		xmlns.addNamespace("", "http://opcfoundation.org/UA/2008/02/Types.xsd");

		if (!epSPtr_->xmlEncode(bodyTree, epSPtr_->typeName(), xmlns)) {
			Log(Error, "OpcUaExtensionObject xml encoder error")
				.parameter("Element", "Body");
			xmlns.addNamespace(uri, "http://opcfoundation.org/UA/2008/02/Types.xsd");
			return false;
		}
		bodyTree.front().second.put("<xmlattr>.xmlns", "http://opcfoundation.org/UA/2008/02/Types.xsd");

		//
		// added types namespace element
		//


		xmlns.addNamespace(uri, "http://opcfoundation.org/UA/2008/02/Types.xsd");
		pt.add_child(xmlns.addPrefix("Body"), bodyTree);

		return true;
	}

	bool
	OpcUaExtensionObject::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
	}

	bool
	OpcUaExtensionObject::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		//
		// get typeIdTree tree
		//
		boost::optional<boost::property_tree::ptree&> typeIdTree = pt.get_child_optional(xmlns.addPrefix("TypeId"));
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
		boost::optional<boost::property_tree::ptree&> bodyTree = pt.get_child_optional(xmlns.addPrefix("Body"));
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
		// handle namespaces in object tag
		//
		XmlnsGuard xmlnsGuard(bodyTree->front().second, xmlns);

		//
		// check namespace
		//
		//std::cout << "TypeName=" << epSPtr_->typeName() << " " << bodyTree->front().first << std::endl;

		//
		// decode extension object from xml file
		//
		if (!epSPtr_->xmlDecode(bodyTree->front().second, xmlns)) {
			Log(Error, "OpcUaExtensionObject xml decoder error")
				.parameter("Element", "Body")
				.parameter("XmlTypeNodeId", xmlTypeNodeId);
			return false;
		}
		return true;
	}

	bool
	OpcUaExtensionObject::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "OpcUaExtensionObject json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	OpcUaExtensionObject::jsonEncode(boost::property_tree::ptree& pt)
	{

		if (epSPtr_.get() == nullptr) {
			Log(Error, "OpcUaExtensionObject json encoder error - object invalid");
			return false;
		}

		//
		// encode type id
		//
		boost::property_tree::ptree typeIdTree;
		OpcUaNodeId jsonNodeId = epSPtr_->jsonTypeId();
		if (!jsonNodeId.jsonEncode(typeIdTree)) {
			Log(Error, "OpcUaExtensionObject json encoder error")
				.parameter("Element", "TypeId");
			return false;
		}
		pt.add_child("TypeId", typeIdTree);

		//
		// encode body
		//
		boost::property_tree::ptree bodyTree;
		if (!epSPtr_->jsonEncode(bodyTree, epSPtr_->typeName())) {
			Log(Error, "OpcUaExtensionObject json encoder error")
				.parameter("Element", "Body");
			return false;
		}
		pt.add_child("Body", bodyTree);

		return true;
	}

	bool
	OpcUaExtensionObject::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "OpcUaExtensionObject json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	OpcUaExtensionObject::jsonDecode(const boost::property_tree::ptree& pt)
	{
		//
		// get typeIdTree tree
		//
		boost::optional<const boost::property_tree::ptree&> typeIdTree = pt.get_child_optional("TypeId");
		if (!typeIdTree) {
			Log(Error, "OpcUaExtensionObject json decoder error - element not exist in json document")
				.parameter("Element", "TypeId");
			return false;
		}

		//
		// get type id
		//
		OpcUaNodeId jsonTypeNodeId;
		if (!jsonTypeNodeId.jsonDecode(*typeIdTree)) {
			Log(Error, "OpcUaExtensionObject json decoder error")
				.parameter("Element", "TypeId");
			return false;
		}

		//
		// get body tree
		//
		boost::optional<const boost::property_tree::ptree&> bodyTree = pt.get_child_optional("Body");
		if (!bodyTree) {
			Log(Error, "OpcUaExtensionObject json decoder error - element not exist in json document")
				.parameter("Element", "Body")
				.parameter("JsonTypeNodeId", jsonTypeNodeId);
			return false;
		}

		this->typeId(jsonTypeNodeId);
		if (!createObject()) {
			// Extension object unknown
			logExtensionObjectMap();
			Log(Error, "OpcUaExtensionObject json decoder error - object create error")
				.parameter("Element", "Body")
				.parameter("JsonTypeNodeId", jsonTypeNodeId);
			return false;
		}

		// Currently the Json type is stored in the object. Now we determine
		// the binary type by the XMl type.
		typeId_ = epSPtr_->binaryTypeId();

		//
		// check namespace
		//
		//std::cout << "TypeName=" << epSPtr_->typeName() << " " << bodyTree->front().first << std::endl;

		//
		// decode extension object from json file
		//
		if (!epSPtr_->jsonDecode(bodyTree->front().second)) {
			Log(Error, "OpcUaExtensionObject json decoder error")
				.parameter("Element", "Body")
				.parameter("JsonTypeNodeId", jsonTypeNodeId);
			return false;
		}
		return true;
	}

	void
	OpcUaExtensionObject::logExtensionObjectMap(void)
	{
		Log(Debug, "extension object map entries");

		ExtensionObjectBase::Map::iterator it;
		for (it=extentionObjectMap_.begin(); it!=extentionObjectMap_.end(); it++) {
			Log(Debug, "  ").parameter(" ", it->first);
		}
	}

};
