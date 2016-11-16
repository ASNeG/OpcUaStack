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

#ifndef __OpcUaStackCore_DeleteReferencesItem_h__
#define __OpcUaStackCore_DeleteReferencesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT DeleteReferencesItem
	: public Object
	{
	  public:
		typedef boost::shared_ptr<DeleteReferencesItem> SPtr;

	    DeleteReferencesItem(void);
		~DeleteReferencesItem(void);

		void sourceNodeId(const OpcUaNodeId::SPtr sourceNodeIdSPtr);
		OpcUaNodeId::SPtr sourceNodeId(void) const;
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeIdSPtr);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isForward(const OpcUaBoolean isForward);
        OpcUaBoolean isForward(void) const;
		void targetNodeId(const OpcUaExpandedNodeId::SPtr targetNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr targetNodeId(void) const;
		void deleteBidirectional(const OpcUaBoolean isForward);
        OpcUaBoolean deleteBidirectional(void) const;

		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr sourceNodeIdSPtr_;
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isForward_;
		OpcUaExpandedNodeId::SPtr targetNodeIdSPtr_;
		OpcUaBoolean deleteBidirectional_;
	};

	class DeleteReferencesItemArray
	: public OpcUaArray<DeleteReferencesItem::SPtr, SPtrTypeCoder<DeleteReferencesItem> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<DeleteReferencesItemArray> SPtr;
	};
}

#endif
