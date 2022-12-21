/*
   Copyright 2015-2022 Kai Huebl (kai@huebl-sgh.de)

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
#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"

namespace OpcUaStackCore
{

	/**
	 * This class manages factory extension objects. For this the class has a extension
	 * map. An entry in the extension map consists of a type identifier (NodeId) an a
	 * extension factory object. This factory object can be used to create instance
	 * objects of the assigned type.
	 *
	 */
	class DLLEXPORT OpcUaExtensionObject
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObject> SPtr;

		typedef enum {
			S_None,								//!< The extension object is not available
			S_Type,								//!< The extension object is available
			S_ByteString						//!< The type of the extension object is not known. The
												//!< extension was saved as string.
		} Style;

		/**
		 * The function inserts a new extension object to the extension map.
		 *
		 * @param[in] opcUaNodeId				type node of the extension object
		 * @param[in] epSPtr					pointer to factory object
		 *
		 * @return true, if successful
		 */
		static bool insertElement(const OpcUaNodeId& opcUaNodeId, ExtensionObjectBase::SPtr epSPtr);

		/**
		 * This function delets an existing extension object from the extension map.
		 *
		 * @param[in] opcUaNodeId				type node of the extension object to
		 *                                      be deleted
		 *
		 * @return true, if successful
		 */
		static bool deleteElement(const OpcUaNodeId& opcUaNodeId);

		/**
		 * This function returns an extension object for a specific type.
		 *
		 * @param[in] opcUaNodeId				type node of extension object to
		 * 										be searched
		 *
		 * @return true, if successful
		 */
		static ExtensionObjectBase::SPtr findElement(const OpcUaNodeId& opcUaNodeId);

		static OpcUaNodeId getBinaryTypeIdFromJsonTypeId(OpcUaNodeId& jsonTypeId);

		/**
		 * Constructor
		 */
	    OpcUaExtensionObject(void);

	    /**
	     * Constructor
	     *
	     * @param[in] typeId					type node identifier
	     */
	    OpcUaExtensionObject(const OpcUaNodeId& typeId);

	    /**
	     * Destructor
	     */
		~OpcUaExtensionObject(void);

		/**
		 * FIXME: todo
		 */
		void reset(void);

		/**
		 * This function is used to register a extension factory object from the specific type T.
		 * The type T must be derived from ExtensionObjectBase.
		 *
		 * @param[in] nodeId					node identifier of the new extension factory object
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true, if successful
		 *
		 */
		template<typename T>
		  bool registerFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		template<typename T>
		  bool registerFactoryObject(void) {
			  ExtensionObjectBase::SPtr epSPtr(boost::make_shared<T>());
			  return registerFactoryElement<T>(epSPtr->typeId());
		  }

		/**
		 * This function is used to register a extension factory object from the specific type T.
		 * The type T must be derived from ExtensionObjectBase.
		 *
		 * @param[in] nodeId					node identifier of the new extension factory object
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true, if successful
		 *
		 */
		template<typename T>
		  bool registerFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(nodeId, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		/**
		 * This function is used to register a extension factory object from the specific type T.
		 * The type T must be derived from ExtensionObjectBase.
		 *
		 * @param[in] buf						string node identifier of the new extension factory object
		 * @param[in] bufLen					length of the buffer
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true, if successful
		 *
		 */
		template<typename T>
		  bool registerFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0) {
			  OpcUaNodeId opcUaNodeId;
			  opcUaNodeId.set(buf, bufLen, namespaceIndex);
			  return registerFactoryElement<T>(opcUaNodeId);
		  }

		/**
		 * This function is used to register a extension factory object from the specific type T.
		 * The type T must be derived from ExtensionObjectBase.
		 *
		 * @param[in] opcUaNodeId				node identifier of the new extension factory object
		 *
		 * @return true, if successful
		 *
		 */
		template<typename T>
		  bool registerFactoryElement(const OpcUaNodeId& opcUaNodeId) {
			  ExtensionObjectBase::SPtr epSPtr(boost::make_shared<T>());

			  OpcUaNodeId opcUaBinaryType(epSPtr->binaryTypeId());
			  OpcUaNodeId xmlType(epSPtr->xmlTypeId());
			  OpcUaNodeId jsonType(epSPtr->jsonTypeId());

			  if (opcUaNodeId != OpcUaNodeId(0, 0)) {
				  if (!OpcUaExtensionObject::insertElement(opcUaNodeId, epSPtr)) {
					 return false;
				  }
			  }

			  if (opcUaBinaryType != OpcUaNodeId(0, 0)) {
				  if (!OpcUaExtensionObject::insertElement(opcUaBinaryType, epSPtr)) {
					  return false;
				  }
			  }

			  if (xmlType != OpcUaNodeId(0, 0)) {
				  if (!OpcUaExtensionObject::insertElement(xmlType, epSPtr)) {
					  return false;
				  }
			  }

			  if (jsonType != OpcUaNodeId(0, 0)) {
				  if (!OpcUaExtensionObject::insertElement(jsonType, epSPtr)) {
					  return false;
				  }
			  }

			  return true;
		  }

		/**
		 * This function is used to delete a extension factory object.
		 *
		 * @param[in] nodeId					node identifier of the extension factory object to be deleted
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true, if successful
		 */
		bool deregisterFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);

		/**
		 * This function is used to delete a extension factory object.
		 *
		 * @param[in] nodeId					node identifier of the extension factory object to be deleted
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true, if successful
		 */
		bool deregisterFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);

		/**
		 * This function is used to delete a extension factory object.
		 *
		 * @param[in] buf						string node identifier of the extension factory object to be deleted
		 * @param[in] bufLen					length of the buffer
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true, if successful
		 */
		bool deregisterFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0);

		/**
		 * This function is used to delete a extension factory object.
		 *
		 * @param[in] opcUaNodeId				node identifier of the extension factory object to be deleted
		 *
		 * @return true, if successful
		 */
		bool deregisterFactoryElement(OpcUaNodeId& opcUaNodeId);

		bool deregisterFactoryElements(void);

		/**
		 * This function is used to create a new extension object. The type of the extension object to be
		 * created must first be passed with the typeId function. The created extension object can determined
		 * with the get function.
		 *
		 * @return true, if successful
		 */
		bool createObject(void);

		/**
		 * This function returns the extension object.
		 *
		 * @return extension object
		 */
		ExtensionObjectBase::SPtr& get(void);

		/**
		 * This function is used to create a new extension object from type T.
		 *
		 * @param[in] typeId					type identifier of new extension object
		 *
		 * @return pointer to new extension object
		 */
		template<typename T>
		   typename T::SPtr parameter(OpcUaUInt32 typeId) {
				this->typeId(typeId);
				return parameter<T>();
			}

		/**
		 * This function is used to create a new extension object from type T.
		 *
		 * @param[in] typeNodeId				type identifier of new extension object
		 *
		 * @return pointer to new extension object
		 */
		template<typename T>
		   typename T::SPtr parameter(const OpcUaNodeId& typeNodeId) {
				typeId(typeNodeId);
				return parameter<T>();
			}
		template<typename T>
		   typename T::SPtr getObjectRef(void) {
				typeId(T().typeId());
				return parameter<T>();
			}

		/**
		 * This function is used to create a new extension object from type T. The type of the
		 * extension object to be created must first be passed with the typeId function.
		 *
		 * @return pointer to new extension object
		 */
		template<typename T>
		   typename T::SPtr parameter(void) {
			   // check if object already exist
			   if (epSPtr_.get() != NULL) {
				   return boost::static_pointer_cast<T>(epSPtr_);
			   }

			   // the type must be exist
			   epSPtr_ = findElement(typeId_);
			   if (epSPtr_.get() == NULL) {
				   typename T::SPtr epSPtr;
				   return epSPtr;
			   }

			   // create object
			   typename T::SPtr epSPtr = boost::make_shared<T>();
			   style_ = S_Type;
			   epSPtr_ = epSPtr;
			   return epSPtr;
		   }

		/**
		 * Setter function
		 *
		 * @param[in] typeId					type identifier of the extension object
		 */
		void typeId(OpcUaUInt32 typeId);

		/**
		 * Setter function
		 *
		 * @param[in] typeNodeId				type identifier of the extension object
		 */
		void typeId(const OpcUaNodeId& typeNodeId);

		/**
		 * Getter function
		 *
		 * @return type identifier of the extension object
		 */
		OpcUaNodeId& typeId(void);

		/**
		 * Getter function
		 *
		 * @return style of the extension object
		 */
		Style style(void);

		/**
		 * Setter function
		 *
		 * @param[in] byteString				extension object content as string
		 */
		void byteString(OpcUaByteString::SPtr& byteString);

		/**
		 * Getter function
		 *
		 * @return extension object content as string
		 */
		OpcUaByteString::SPtr byteString(void);

		/**
		 * Function to create a copy of the extension object
		 *
		 * @param[out] extensionObject			target extension object
		 *
		 */
		void copyTo(OpcUaExtensionObject& extensionObject);

		/**
		 * Function to compare two extension objects
		 *
		 * @param[in] extensionObject			extension object
		 *
		 * @return true, if both extension objects are equal
		 */
		bool operator!=(const OpcUaExtensionObject& extensionObject) const;

		/**
		 * Function to compare two extension objects
		 *
		 * @param[in] extensionObject			extension object
		 *
		 * @return true, if both extension objects are not equal
		 */
		bool operator==(const OpcUaExtensionObject& extensionObject) const;

		/**
		 * Function to show the parameters of the extension object
		 *
		 * @param[out] os					output stream
		 */
		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaExtensionObject& value) {
			value.out(os);
			return os;
		}

		/**
		 * Function to encode the structure data to the binary format.
		 *
		 * @param[out] os					output stream for binary output
		 */
		bool opcUaBinaryEncode(std::ostream& os) const;

		/**
		 * Function to decode the binary format to the structure data
		 *OpcUaExtensionObject(void);
		 * @param[in] is					input stream for binary input
		 */
		bool opcUaBinaryDecode(std::istream& is);

		/**
		 * Function to encode the structure data to a xml tree format.
		 *
		 * @param[out] pt					tree for xml output
		 * @param[in] element				element name of the subtree
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);

		/**
		 * Function to encode the structure data to a xml tree format.
		 *
		 * @param[out] pt					tree for xml output
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);

		/**
		 * Function to decode the xml tree format to the structure data.
		 *
		 * @param[in] pt				OpcUaExtensionObject(void);	tree for xml output
		 * @param[in] element				element name of the subtree
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);

		/**
		 * Function to decode the xml tree format to the structure data.
		 *
		 * @param[in] pt					tree for xml output
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

		bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
		bool jsonEncode(boost::property_tree::ptree& pt);
		bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
		bool jsonDecode(const boost::property_tree::ptree& pt);

		void logExtensionObjectMap(void);

	  private:
		OpcUaExtensionObject(const OpcUaExtensionObject& value);

		static ExtensionObjectBase::Map extentionObjectMap_;
		static bool init_;

		Style style_;
		OpcUaNodeId typeId_;
		ExtensionObjectBase::SPtr epSPtr_;
		OpcUaByteString::SPtr byteString_;
	};

	class DLLEXPORT OpcUaExtensionObjectArray
	: public OpcUaArray<OpcUaExtensionObject::SPtr, SPtrTypeCoder<OpcUaExtensionObject> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensionObjectArray> SPtr;
	};

}

#endif
