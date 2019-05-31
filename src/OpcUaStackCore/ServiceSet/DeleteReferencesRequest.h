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

#ifndef __OpcUaStackCore_DeleteReferencesRequest_h__
#define __OpcUaStackCore_DeleteReferencesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteReferencesItem.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteReferencesRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<DeleteReferencesRequest> SPtr;

		DeleteReferencesRequest(void);
		virtual ~DeleteReferencesRequest(void);

		void referencesToDelete(const DeleteReferencesItemArray::SPtr deleteReferencesItemArray);
		DeleteReferencesItemArray::SPtr referencesToDelete() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element) { return false; }
		bool jsonEncode(boost::property_tree::ptree& pt) { return false; }
		bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element) { return false; }
		bool jsonDecode(boost::property_tree::ptree& pt) { return false; }

	  private:
		DeleteReferencesItemArray::SPtr deleteReferencesItemArray_;
	};

}

#endif
