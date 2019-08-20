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

#ifndef __OpcUaStackCore_NodeReference_h__
#define __OpcUaStackCore_NodeReference_h__

#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NodeReference
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<NodeReference> SPtr;

		NodeReference(void);
		virtual ~NodeReference(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void);

		void copyTo(NodeReference& nodeReference);
		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const NodeReference& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const {};
		void opcUaBinaryDecode(std::istream& is) {};

		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return true; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return true; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }
		
	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }

	  private:
		OpcUaStatusCode statusCode_;
	};

	class DLLEXPORT NodeReferenceArray
	: public OpcUaArray<NodeReference::SPtr
	, SPtrTypeCoder<NodeReference> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<NodeReferenceArray> SPtr;
	};

}

#endif
