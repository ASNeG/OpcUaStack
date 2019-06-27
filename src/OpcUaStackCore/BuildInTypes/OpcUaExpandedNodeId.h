/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaExpandedNodeId_h__
#define __OpcUaStackCore_OpcUaExpandedNodeId_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaExpandedNodeId
	: public OpcUaNodeIdBase
	{
	  public:
		typedef boost::shared_ptr<OpcUaExpandedNodeId> SPtr;

		OpcUaExpandedNodeId(void);
		~OpcUaExpandedNodeId(void);

		virtual OpcUaByte encodingFlag(void) const;
		virtual void encodingFlag(OpcUaByte expandedEncodingFlag);

		void namespaceUri(OpcUaString& namespaceUri);
		void namespaceUri(const std::string& namespaceUri);
		OpcUaString& namespaceUri(void);
		void serverIndex(OpcUaUInt32 serverIndex);
		OpcUaUInt32 serverIndex(void); 

		bool fromString(const std::string& nodeIdString);
		std::string toString(void) const;

		void copyTo(OpcUaExpandedNodeId& opcUaExpandedNodeId);
		bool operator!=(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const;
		bool operator==(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaExpandedNodeId& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  private:
		OpcUaByte expandedEncodingFlag_;
		OpcUaString namespaceUri_; 
		OpcUaUInt32 serverIndex_; 
	};


	class OpcUaExpandedNodeIdArray
	: public OpcUaArray<OpcUaExpandedNodeId::SPtr, SPtrTypeCoder<OpcUaExpandedNodeId> >
	{
  	  public:
		boost::shared_ptr<OpcUaExpandedNodeIdArray> SPtr;
	};

}

#endif
