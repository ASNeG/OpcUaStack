/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BrowsePath_h__
#define __OpcUaStackCore_BrowsePath_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/StandardDataTypes/RelativePath.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowsePath
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<BrowsePath> SPtr;

		BrowsePath(void);
		virtual ~BrowsePath(void);

		void startingNode(const OpcUaNodeId::SPtr startingNode);
		OpcUaNodeId::SPtr startingNode(void) const;
		void relativePath(const RelativePath& relativePath);
		RelativePath& relativePath(void);

		void copyTo(BrowsePath& browsePath);
		void out(std::ostream& os) const {};

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

      protected:
		virtual bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
		virtual bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		OpcUaNodeId::SPtr startingNodeSPtr_;
		RelativePath relativePath_;
	};

	class DLLEXPORT BrowsePathArray
	: public OpcUaArray<BrowsePath::SPtr, SPtrTypeCoder<BrowsePath> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathArray> SPtr;
	};
	
}

#endif
