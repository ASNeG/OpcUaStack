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

#ifndef __OpcUaStackCore_AddNodesResult_h__
#define __OpcUaStackCore_AddNodesResult_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT AddNodesResult
	: public Object
	{
	  public:
		typedef boost::shared_ptr<AddNodesResult> SPtr;

	    AddNodesResult(void);
		~AddNodesResult(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void) const;

		void addedNodeId(const OpcUaNodeId::SPtr addedNodeIdSPtr);
		OpcUaNodeId::SPtr addedNodeId(void) const;

		void opcUaBinaryEncode(std::ostream& os) const; 
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaNodeId::SPtr addedNodeIdSPtr_;		
	};

	class AddNodesResultArray
	: public OpcUaArray<AddNodesResult::SPtr, SPtrTypeCoder<AddNodesResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<AddNodesResultArray> SPtr;
	};
}

#endif
