/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EnumTypeGenerator_h__
#define __OpcUaStackCore_EnumTypeGenerator_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/Generator/NodeInfoEnumType.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT EnumTypeGenerator
	{
	  public:
		typedef boost::shared_ptr<EnumTypeGenerator> SPtr;

		/**
		 * constructor
		 */
		EnumTypeGenerator(void);

		/*
		 * destructor
		 */
		~EnumTypeGenerator(void);

		/**
		 * This function passes the information model to the class.The informationModel
		 * function must be called before generate function.
		 *
		 * @param[in] informationModel			information model
		 */
		void informationModel(InformationModel::SPtr& informationModel);

		/**
		 * This function sets a new namespace entry
		 *
		 * @param[in] namespaceEntry			Set a new namespace entry. The string must have
		 * 										the following format:
		 * 										<NamespaceIndex>:<NamespaceName>
		 *
		 * @return true if successful
		 */
		bool setNamespaceEntry(const std::string& namespaceEntry);

		/**
		 * This function results the C++ source content.
		 *
		 * @return C++ source content
		 */
		std::string& sourceContent(void);

		/**
		 * This function results the C++ header content.
		 *
		 * @return C++ header content
		 */
		std::string& headerContent(void);

		/**
		 * This function generates the C++ header and source content from a given
		 * node identifier. The node must be a data type node in the opc ua information
		 * model. The C++ source content and the header content can be result with
		 * the functions sourceContent and headerContent.
		 *
		 * Conditions:
		 * - The informationModel function must be called before
		 *
		 * @param[in] enumType					enum type node id from the opc ua
		 * 										information model
		 *
		 * @return true if successful
		 */
		bool generate(const OpcUaNodeId& enumType);

	  private:

		//
		// header functions
		//
		bool generateHeader(void);
		bool generateHeaderComments(void);
		bool generateHeaderBegin(void);
		bool generateHeaderEnd(void);
		bool generateHeaderClassBegin(const std::string& prefix);
		bool generateHeaderClassEnd(const std::string& prefix);
		bool generateHeaderClassExtensionInterface(const std::string& prefix);
		bool generateHeaderClassPublic(const std::string& prefix);
		bool generateHeaderClassEncoderDecoder(const std::string& prefix);
		bool generateHeaderClassPrivate(const std::string& prefix);
		bool generateHeaderClassValueGetter(const std::string& prefix);
		bool generateHeaderClassValueDefinition(const std::string& prefix);
		bool generateHeaderClassValueArray(const std::string& prefix);

		//
		// source functions
		//
		bool generateSource(void);
		bool generateSourceComments(void);
		bool generateSourceIncludes(void);
		bool generateSourceClassBegin(void);
		bool generateSourceClassEnd(void);
		bool generateSourceClassConstructor(const std::string& prefix);
		bool generateSourceClassDestructor(const std::string& prefix);
		bool generateSourceClassGetter(const std::string& prefix);
		bool generateSourceClassPublicEQ(const std::string& prefix);
		bool generateSourceClassPublicNE(const std::string& prefix);
		bool generateSourceClassPublicAssign1(const std::string& prefix);
		bool generateSourceClassPublicCP(const std::string& prefix);
		bool generateSourceClassExtensionObjectBase(const std::string& prefix);
		bool generateSourceClassFactory(const std::string& prefix);
		bool generateSourceClassNamespaceName(const std::string& prefix);
		bool generateSourceClassTypeName(const std::string& prefix);
		bool generateSourceClassTypeId(const std::string& prefix);
		bool generateSourceClassBinaryTypeId(const std::string& prefix);
		bool generateSourceClassXmlTypeId(const std::string& prefix);
		bool generateSourceClassJsonTypeId(const std::string& prefix);
		bool generateSourceClassBinaryEncode(const std::string& prefix);
		bool generateSourceClassBinaryDecode(const std::string& prefix);
		bool generateSourceClassXmlEncode(const std::string& prefix);
		bool generateSourceClassXmlDecode(const std::string& prefix);
		bool generateSourceClassJsonEncode(const std::string& prefix);
		bool generateSourceClassJsonDecode(const std::string& prefix);
		bool generateSourceClassCopyTo(const std::string& prefix);
		bool generateSourceClassEqual(const std::string& prefix);
		bool generateSourceClassOut(const std::string& prefix);

		InformationModel::SPtr informationModel_;
		std::string sourceContent_;
		std::string headerContent_;

		NodeInfoEnumType nodeInfo_;						//!< information about the data type node
	};


}

#endif
