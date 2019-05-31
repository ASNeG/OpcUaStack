/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BrowsePathResult_h__
#define __OpcUaStackCore_BrowsePathResult_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/BrowsePathTarget.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowsePathResult
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathResult> SPtr;

		BrowsePathResult(void);
		virtual ~BrowsePathResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void targets(const BrowsePathTargetArray::SPtr targets);
		BrowsePathTargetArray::SPtr targets(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		BrowsePathTargetArray::SPtr targetArraySPtr_;
	};

	class DLLEXPORT BrowsePathResultArray
	: public OpcUaArray<BrowsePathResult::SPtr, SPtrTypeCoder<BrowsePathResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathResultArray> SPtr;
	};

}

#endif
