/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BrowseName_h__
#define __OpcUaStackCore_BrowseName_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowseName
	: public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<BrowseName> SPtr;

		BrowseName(void);
		BrowseName(
			const BrowseName& browseName
		);
		BrowseName(
			const OpcUaNodeId& nodeId
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			std::initializer_list<const OpcUaQualifiedName> pathElementList
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4
		);
		BrowseName(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4,
			const OpcUaQualifiedName& pathElement5
		);
		~BrowseName(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void pathNames(OpcUaQualifiedNameArray::SPtr& pathNames);
		OpcUaQualifiedNameArray::SPtr pathNames(void);

		bool pushBack(const OpcUaQualifiedName& pathElement);

		void set(
			const OpcUaNodeId& nodeId
		);
		void set(
			const OpcUaNodeId& nodeId,
			std::initializer_list<const OpcUaQualifiedName> pathElementList
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4
		);
		void set(
			const OpcUaNodeId& nodeId,
			const OpcUaQualifiedName& pathElement1,
			const OpcUaQualifiedName& pathElement2,
			const OpcUaQualifiedName& pathElement3,
			const OpcUaQualifiedName& pathElement4,
			const OpcUaQualifiedName& pathElement5
		);

		void copyTo(BrowseName& browseName);
		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const BrowseName& value) {
			value.out(os);
			return os;
		}

		std::string stringId(const std::string& suffix);

		bool opcUaBinaryEncode(std::ostream& os) const { return false; }
		bool opcUaBinaryDecode(std::istream& is) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }


	  private:
		OpcUaNodeId nodeId_;
		OpcUaQualifiedNameArray::SPtr pathNames_;
	};


	class DLLEXPORT BrowseNameArray
	: public OpcUaArray<BrowseName::SPtr, SPtrTypeCoder<BrowseName> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowseNameArray> SPtr;
	};



}

#endif
