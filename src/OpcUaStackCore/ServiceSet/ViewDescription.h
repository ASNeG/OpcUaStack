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

#ifndef __OpcUaStackCore_ViewDescription_h__
#define __OpcUaStackCore_ViewDescription_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ViewDescription
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<ViewDescription> SPtr;

		ViewDescription(void);
		virtual ~ViewDescription(void);
		void viewId(const OpcUaNodeId::SPtr viewId);
		OpcUaNodeId::SPtr viewId(void);
		void timestamp(const OpcUaUtcTime& timestamp);
		void timestamp(const boost::posix_time::ptime& timestamp);
		OpcUaUtcTime& timestamp(void);
		void viewVersion(const OpcUaUInt32& viewVersion);
		OpcUaUInt32 viewVersion(void);

		void copyTo(ViewDescription& viewDescription);
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
		OpcUaNodeId::SPtr viewIdSPtr_;
		OpcUaUtcTime timestamp_;
		OpcUaUInt32 viewVersion_;
	};

	class DLLEXPORT ViewDescriptionArray
	: public OpcUaArray<ViewDescription::SPtr, SPtrTypeCoder<ViewDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ViewDescriptionArray> SPtr;
	};

}

#endif
