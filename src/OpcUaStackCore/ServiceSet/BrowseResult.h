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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_BrowseResult_h__
#define __OpcUaStackCore_BrowseResult_h__

#include <cstdint>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"

namespace OpcUaStackCore
{
   
	class DLLEXPORT BrowseResult
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<BrowseResult> SPtr;

		BrowseResult(void);
		virtual ~BrowseResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void continuationPoint(const OpcUaByteString& continuationPoint);
		OpcUaByteString& continuationPoint(void);
		void references(const ReferenceDescriptionArray::SPtr references);
		ReferenceDescriptionArray::SPtr references(void) const;

		void copyTo(BrowseResult& browseResult) {}
		void out(std::ostream& os) const {};

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaByteString continuationPoint_;
		ReferenceDescriptionArray::SPtr referenceArraySPtr_;
	};

	class DLLEXPORT BrowseResultArray
	: public OpcUaArray<BrowseResult::SPtr, SPtrTypeCoder<BrowseResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowseResultArray> SPtr;
	};

}

#endif
