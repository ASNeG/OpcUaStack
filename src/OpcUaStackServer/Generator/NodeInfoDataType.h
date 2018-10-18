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

#ifndef __OpcUaStackCore_NodeInfoDataType_h__
#define __OpcUaStackCore_NodeInfoDataType_h__

#include <OpcUaStackServer/Generator/NodeInfo.h>

namespace OpcUaStackServer
{

/**
 * This function manages node data type information
 */
class DLLEXPORT NodeInfoDataType
: public NodeInfo
{
  public:
	typedef boost::shared_ptr<NodeInfoDataType> SPtr;

	/**
	 * constructor
	 */
	NodeInfoDataType(void);

	/**
	 * destructor
	 */
	~NodeInfoDataType(void);

};

}

#endif
