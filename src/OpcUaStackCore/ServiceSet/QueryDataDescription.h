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

#ifndef __OpcUaStackCore_QueryDataDescription_h__
#define __OpcUaStackCore_QueryDataDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/StandardDataTypes/RelativePath.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryDataDescription
	: public Object
	, public JsonFormatter
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

		void copyTo(QueryDataDescription& queryDataDescription) {}
		void out(std::ostream& os) const {};

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }

	  private:
		RelativePath relativePath_;
		OpcUaUInt32 attributeId_;
		OpcUaString indexRange_;
	};

	class DLLEXPORT QueryDataDescriptionArray
	: public OpcUaArray<QueryDataDescription::SPtr, SPtrTypeCoder<QueryDataDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<QueryDataDescriptionArray> SPtr;
	};

}

#endif
