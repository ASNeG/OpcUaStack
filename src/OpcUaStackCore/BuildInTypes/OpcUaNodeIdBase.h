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

#ifndef __OpcUaStackCore_OpcUaNodeIdBase_h__
#define __OpcUaStackCore_OpcUaNodeIdBase_h__

#include <boost/property_tree/ptree.hpp>
#include <boost/variant.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{
	class DLLEXPORT OpcUaNodeIdNullType 
	{
	  public:
		OpcUaNodeIdNullType(void) {}
		~OpcUaNodeIdNullType(void) {}
	};

	typedef boost::variant<OpcUaNodeIdNullType, OpcUaUInt32,OpcUaString::SPtr,OpcUaGuid::SPtr,OpcUaByteString::SPtr> OpcUaNodeIdValue;

	class DLLEXPORT OpcUaNodeIdBase
	: public JsonFormatter
	, public Object

	{
	  public:
	    OpcUaNodeIdBase(void);
	    OpcUaNodeIdBase(const OpcUaNodeIdBase& nodeId);
	    OpcUaNodeIdBase(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);
	    OpcUaNodeIdBase(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);
		virtual ~OpcUaNodeIdBase(void);

		void reset(void);

		OpcUaNodeIdValue& nodeIdValue(void);
		void nodeIdValue(OpcUaNodeIdValue& nodeIdValue);

		void namespaceIndex(OpcUaUInt16 namespaceIndex);
		OpcUaInt16 namespaceIndex(void) const;

		OpcUaBuildInType nodeIdType(void) const;
		template<typename VAL>
		  void nodeId(const VAL& val) {
			  nodeIdValue_ = val;
		  }
		template<typename VAL>
		  VAL nodeId(void) const
		  {
		      return boost::get<VAL>(nodeIdValue_);
		  }

		void set(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(const OpcUaString& nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(const OpcUaGuid& nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(const OpcUaByteString& nodeId, OpcUaUInt16 namespaceIndex = 0);
		void set(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex = 0);
		bool get(OpcUaUInt32& nodeId, OpcUaUInt16& namespaceIndex);
		bool get(std::string& nodeId, OpcUaUInt16& namespaceIndex);
		bool get(OpcUaByteString& nodeId, OpcUaUInt16& namespaceIndex);
		bool get(OpcUaByte** buf, OpcUaInt32* bufLen, OpcUaUInt16& namespaceIndex);

		bool fromString(const std::string& nodeIdString);
		std::string toString(void) const;

		void copyTo(OpcUaNodeIdBase& opcUaNodeIdBase);
		void copyFrom(const OpcUaNodeIdBase& opcUaNodeIdBase);
		bool operator!=(const OpcUaNodeIdBase& opcUaNodeId) const; 
		bool operator==(const OpcUaNodeIdBase& opcUaNodeIdBase) const;
		bool operator<(const OpcUaNodeIdBase& opcUaNodeIdBase) const;


		virtual OpcUaByte encodingFlag(void) const;
		virtual void encodingFlag(OpcUaByte expandedEncodingFlag);

		friend std::ostream& operator<<(std::ostream& os, const OpcUaNodeIdBase& opcUaNodeId) {
			os << opcUaNodeId.toString();
			return os;
		}
		void out(std::ostream& os);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  protected:
        bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;

		OpcUaUInt16 namespaceIndex_;
		OpcUaNodeIdValue nodeIdValue_;

	};
}

#endif
