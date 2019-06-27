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

#ifndef __OpcUaStackCore_QueryDataDescription_h__
#define __OpcUaStackCore_QueryDataDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/RelativePath.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryDataDescription
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<QueryDataDescription> SPtr;

		QueryDataDescription(void);
		virtual ~QueryDataDescription(void);

		void relativePath(const RelativePath& relativePath);
		RelativePath& relativePath(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void);
		void indexRange(const OpcUaString& indexRange);
		void indexRange(const std::string& indexRange);
		OpcUaString& indexRange(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RelativePath relativePath_;
		OpcUaUInt32 attributeId_;
		OpcUaString indexRange_;
	};

	class QueryDataDescriptionArray
	: public OpcUaArray<QueryDataDescription::SPtr, SPtrTypeCoder<QueryDataDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<QueryDataDescriptionArray> SPtr;
	};

}

#endif
