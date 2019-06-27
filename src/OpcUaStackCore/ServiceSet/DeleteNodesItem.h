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

#ifndef __OpcUaStackCore_DeleteNodesItem_h__
#define __OpcUaStackCore_DeleteNodesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"



namespace OpcUaStackCore
{

	class DLLEXPORT DeleteNodesItem
	: public Object
	{
	  public:
		typedef boost::shared_ptr<DeleteNodesItem> SPtr;

	    DeleteNodesItem(void);
		~DeleteNodesItem(void);

		void nodeId(const OpcUaNodeId::SPtr nodeIdSPtr);
		OpcUaNodeId::SPtr nodeId(void) const;
		void deleteTargetReferences(const OpcUaBoolean deleteTargetReferences);
        OpcUaBoolean deleteTargetReferences(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaBoolean deleteTargetReferences_;
	};

	class DeleteNodesItemArray
	: public OpcUaArray<DeleteNodesItem::SPtr, SPtrTypeCoder<DeleteNodesItem> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<DeleteNodesItemArray> SPtr;
	};
}

#endif
