/*
   Copyright 2016-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BrowsePathTarget_h__
#define __OpcUaStackCore_BrowsePathTarget_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowsePathTarget
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<BrowsePathTarget> SPtr;

		BrowsePathTarget(void);
		virtual ~BrowsePathTarget(void);

		void tragetId(const OpcUaExpandedNodeId::SPtr targetId);
		OpcUaExpandedNodeId::SPtr targetId(void);
		void remainingPathIndex(const OpcUaUInt32& remainingPathIndex);
		OpcUaUInt32 remainingPathIndex(void);

		void copyTo(BrowsePathTarget& browsePathTarget);
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
		OpcUaExpandedNodeId::SPtr targetIdSPtr_;
		OpcUaUInt32 remainingPathIndex_;
	};

	class DLLEXPORT BrowsePathTargetArray
	: public OpcUaArray<BrowsePathTarget::SPtr, SPtrTypeCoder<BrowsePathTarget> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathTargetArray> SPtr;
	};

}

#endif
