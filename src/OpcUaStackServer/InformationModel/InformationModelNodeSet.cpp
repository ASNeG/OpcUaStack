/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	InformationModelNodeSet::InformationModelNodeSet(void)
	{
	}

	InformationModelNodeSet::~InformationModelNodeSet(void)
	{
	}

	bool 
	InformationModelNodeSet::initial(InformationModel::SPtr informationModelSPtr, NodeSetBaseParser& nodeSetBaseParser)
	{
		// copy nodes from parser to information model 
		{
			DataTypeNodeClassVec::iterator it;
			DataTypeNodeClassVec& dataTypeNodeClassVec = nodeSetBaseParser.dataTypeNodeClassVec();

			for (it=dataTypeNodeClassVec.begin(); it!=dataTypeNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			MethodNodeClassVec::iterator it;
			MethodNodeClassVec& methodNodeClassVec = nodeSetBaseParser.methodNodeClassVec();

			for (it=methodNodeClassVec.begin(); it!=methodNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			ObjectNodeClassVec::iterator it;
			ObjectNodeClassVec& objectNodeClassVec = nodeSetBaseParser.objectNodeClassVec();

			for (it=objectNodeClassVec.begin(); it!=objectNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			ObjectTypeNodeClassVec::iterator it;
			ObjectTypeNodeClassVec& objectTypeNodeClassVec = nodeSetBaseParser.objectTypeNodeClassVec();

			for (it=objectTypeNodeClassVec.begin(); it!=objectTypeNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			ReferenceTypeNodeClassVec::iterator it;
			ReferenceTypeNodeClassVec& referenceTypeNodeClassVec = nodeSetBaseParser.referenceTypeNodeClassVec();

			for (it=referenceTypeNodeClassVec.begin(); it!=referenceTypeNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			VariableNodeClassVec::iterator it;
			VariableNodeClassVec& variableNodeClassVec = nodeSetBaseParser.variableNodeClassVec();

			for (it=variableNodeClassVec.begin(); it!=variableNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			VariableTypeNodeClassVec::iterator it;
			VariableTypeNodeClassVec& variableTypeNodeClassVec = nodeSetBaseParser.variableTypeNodeClassVec();

			for (it=variableTypeNodeClassVec.begin(); it!=variableTypeNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		{
			ViewNodeClassVec::iterator it;
			ViewNodeClassVec& viewNodeClassVec = nodeSetBaseParser.viewNodeClassVec();

			for (it=viewNodeClassVec.begin(); it!=viewNodeClassVec.end(); it++) {
				informationModelSPtr->insert(*it);
			}
		}

		return true;
	}

	bool
	InformationModelNodeSet::initial(
		NodeSetBaseParser& nodeSetBaseParser,
		InformationModel& informationModel,
		std::vector<std::string>& namespaceUris)
	{
		std::set<uint16_t>::iterator it0;
		std::set<uint16_t> namespaceIndexSet;
		std::vector<std::string>::iterator it1;
		NodeSetNamespace nodeSetNamespace;

		// create a set of all namespace indexes to be write
		if (namespaceUris.size() == 0) {
			namespaceUris = nodeSetNamespace.globalNamespaceVec();
		}
		for (it1 = namespaceUris.begin(); it1 != namespaceUris.end(); it1++) {
			uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(*it1);
			namespaceIndexSet.insert(namespaceIndex);
			Log(Debug, "write namespace")
				.parameter("NamespaceUri", *it1)
				.parameter("GlobalNamespaceIndex", namespaceIndex);
		}

		// copy nodes from information model to parser
		InformationModelMap::iterator it2;
		for (
			it2 = informationModel.informationModelMap().begin();
			it2 != informationModel.informationModelMap().end();
			it2++
		)
		{
			BaseNodeClass::SPtr baseNodeClassSPtr = it2->second;

			// copy only the selected namespaces
			OpcUaNodeId& nodeId = baseNodeClassSPtr->nodeId().data();
			it0 = namespaceIndexSet.find(nodeId.namespaceIndex());
			if (it0 == namespaceIndexSet.end()) continue;

			NodeClass::Enum nodeClass = baseNodeClassSPtr->nodeClass().data();
			switch (nodeClass)
			{
				case NodeClass::EnumDataType:
				{
					DataTypeNodeClass::SPtr dataTypeNodeClass;
					dataTypeNodeClass = boost::static_pointer_cast<DataTypeNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.dataTypeNodeClassVec().push_back(dataTypeNodeClass);
					break;
				}
				case NodeClass::EnumMethod:
				{
					MethodNodeClass::SPtr methodNodeClass;
					methodNodeClass = boost::static_pointer_cast<MethodNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.methodNodeClassVec().push_back(methodNodeClass);
					break;
				}
				case NodeClass::EnumObject:
				{
					ObjectNodeClass::SPtr objectNodeClass;
					objectNodeClass = boost::static_pointer_cast<ObjectNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.objectNodeClassVec().push_back(objectNodeClass);
					break;
				}
				case NodeClass::EnumObjectType:
				{
					ObjectTypeNodeClass::SPtr objectTypeNodeClass;
					objectTypeNodeClass = boost::static_pointer_cast<ObjectTypeNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.objectTypeNodeClassVec().push_back(objectTypeNodeClass);
					break;
				}
				case NodeClass::EnumReferenceType:
				{
					ReferenceTypeNodeClass::SPtr referenceTypeNodeClass;
					referenceTypeNodeClass = boost::static_pointer_cast<ReferenceTypeNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.referenceTypeNodeClassVec().push_back(referenceTypeNodeClass);
					break;
				}
				case NodeClass::EnumVariable:
				{
					VariableNodeClass::SPtr variableNodeClass;
					variableNodeClass = boost::static_pointer_cast<VariableNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.variableNodeClassVec().push_back(variableNodeClass);
					break;
				}
				case NodeClass::EnumVariableType:
				{
					VariableTypeNodeClass::SPtr variableTypeNodeClass;
					variableTypeNodeClass = boost::static_pointer_cast<VariableTypeNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.variableTypeNodeClassVec().push_back(variableTypeNodeClass);
					break;
				}
				case NodeClass::EnumView:
				{
					ViewNodeClass::SPtr viewNodeClass;
					viewNodeClass = boost::static_pointer_cast<ViewNodeClass>(baseNodeClassSPtr);
					nodeSetBaseParser.viewNodeClassVec().push_back(viewNodeClass);
					break;
				}
				default:
					Log(Error, "Unknown class").parameter("Class", nodeClass);
			}
		}

		return true;
	}

	bool 
	InformationModelNodeSet::initial(
		NodeSetBaseParser& nodeSetBaseParser,
		InformationModel::SPtr informationModelSPtr,
		std::vector<std::string>& namespaceUris)
	{
		return initial(
			nodeSetBaseParser,
			*informationModelSPtr,
			namespaceUris
		);
	}

	bool 
	InformationModelNodeSet::checkForwardReferences(InformationModel::SPtr informationModelSPtr)
	{
		informationModelSPtr->checkForwardReferences();
		return true;
	}
}
