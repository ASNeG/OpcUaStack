/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EventTypeGenerator_h__
#define __OpcUaStackCore_EventTypeGenerator_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT EventTypeGenerator
	{
	  public:
		typedef boost::shared_ptr<EventTypeGenerator> SPtr;

		EventTypeGenerator(void);
		~EventTypeGenerator(void);

		void informationModel(InformationModel::SPtr& informationModel);
		void eventType(OpcUaNodeId& eventType);
		void projectNamespace(const std::string& projectNamespace);
		void parentProjectNamespace(const std::string& parentProjectNamespace);
		std::string& sourceContent(void);
		std::string& headerContent(void);

		bool generate(void);

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
		bool generateHeaderClassPublic(const std::string& prefix);
		bool generateHeaderClassPrivate(const std::string& prefix);

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
		bool generateSourceClassSetter(const std::string& prefix);
		bool generateSourceClassNamespaceUri(const std::string& prefix);
		bool generateSourceClassGet(const std::string& prefix);

		InformationModel::SPtr informationModel_;
		BaseNodeClass::SPtr eventTypeNode_;
		BaseNodeClass::SPtr parentEventTypeNode_;
		OpcUaNodeId eventTypeNodeId_;
		OpcUaNodeId parentEventTypeNodeId_;
		uint32_t eventTypeNumber_;
		std::string eventTypeName_;
		std::string parentEventTypeName_;
		std::string sourceContent_;
		std::string headerContent_;

		std::string namespaceUri_;
		std::string projectNamespace_;
		std::string parentProjectNamespace_;
		std::string projectDirectory_;
		std::string parentProjectDirectory_;
	};


}

#endif
