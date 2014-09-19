#ifndef __OpcUaStackServer_NodeSetXmlParser_h__
#define __OpcUaStackServer_NodeSetXmlParser_h__

#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NodeSetXmlParser : public NodeSetBaseParser
	{
	  public:
		NodeSetXmlParser(void);
		~NodeSetXmlParser(void);

		bool decode(boost::property_tree::ptree& ptree);
		bool encode(boost::property_tree::ptree& ptree);

	  private:
		bool decodeNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree);
		bool decodeReferences(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree);
		bool decodeAliases(boost::property_tree::ptree& ptree);
		bool decodeUAObject(boost::property_tree::ptree& ptree);
		bool decodeUAObjectType(boost::property_tree::ptree& ptree);
		bool decodeUAVariable(boost::property_tree::ptree& ptree);
		bool decodeUAVariableType(boost::property_tree::ptree& ptree);
		bool decodeUADataType(boost::property_tree::ptree& ptree);
		bool decodeUAReferenceType(boost::property_tree::ptree& ptree);
		bool decodeUAMethod(boost::property_tree::ptree& ptree);
	};

}

#endif