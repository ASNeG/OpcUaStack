#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"

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

		informationModelSPtr->checkForwardReferences();
		return true;
	}

}