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

#ifndef __OpcUaStackCore_BrowseDescritpion_h__
#define __OpcUaStackCore_BrowseDescritpion_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{
	
	typedef enum {
		BrowseDirection_Forward = 0,
		BrowseDirection_Inverse = 1,
		BrowseDirection_Both = 2
	} BrowseDirectionEnum;

	class DLLEXPORT BrowseDescription
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<BrowseDescription> SPtr;

		BrowseDescription(void);
		virtual ~BrowseDescription(void);

		void nodeId(const OpcUaNodeId::SPtr nodeId);
		OpcUaNodeId::SPtr nodeId(void) const;
		void browseDirection(const BrowseDirectionEnum browseDirection);
		BrowseDirectionEnum browseDirection(void);
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void includeSubtypes(const OpcUaBoolean includeSubtypes);
		OpcUaBoolean includeSubtypes(void);
		void nodeClassMask(const OpcUaUInt32 nodeClassMask);
		OpcUaUInt32 nodeClassMask(void);
		void resultMask(const OpcUaUInt32 resultMask);
		OpcUaUInt32 resultMask(void);
		
		void copyTo(BrowseDescription& browseDescription);
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
		OpcUaNodeId::SPtr nodeIdSPtr_;
		BrowseDirectionEnum browseDirection_;
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean includeSubtypes_;
		OpcUaUInt32 nodeClassMask_;
		OpcUaUInt32 resultMask_;
	};

	class DLLEXPORT BrowseDescriptionArray
	: public OpcUaArray<BrowseDescription::SPtr, SPtrTypeCoder<BrowseDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowseDescriptionArray> SPtr;
	};

}

#endif
