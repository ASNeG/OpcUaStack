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

#ifndef __OpcUaStackCore_OpcUaDiagnosticInfo_h__
#define __OpcUaStackCore_OpcUaDiagnosticInfo_h__

#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaDiagnosticInfo
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaDiagnosticInfo> SPtr;

	    OpcUaDiagnosticInfo(void);
		~OpcUaDiagnosticInfo(void);

		void setSymbolicId(const OpcUaInt32 symbolicId);
		OpcUaInt32 getSymbolicId() const;
		void setNamespaceUri(const OpcUaInt32 namespaceUri);
		OpcUaInt32 getNamespaceUri() const;
		void setLocalizedText(const OpcUaInt32 localizedText);
		OpcUaInt32 getLocalizedText() const;
		void setLocale(const OpcUaInt32 locale);
		OpcUaInt32 getLocale() const;
		void setAdditionalInfo(const OpcUaString& additionalInfo);
		const OpcUaString& getAdditionalInfo() const;
		void setInnerStatusCode(const OpcUaStatusCode innerStatusCode);
		OpcUaStatusCode getInnerStatusCode() const;

		void copyTo(OpcUaDiagnosticInfo& opcUaDiagnosticInfo);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDiagnosticInfo& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  private:
		OpcUaInt32 symbolicId_;
		OpcUaInt32 namespaceUri_;
		OpcUaInt32 localizedText_;
		OpcUaInt32 locale_;
		OpcUaString additionalInfo_;
		OpcUaStatusCode innerStatusCode_;
		// FIXME: DiagnosticInfo
	};

	class OpcUaDiagnosticInfoArray
	: public OpcUaArray<OpcUaDiagnosticInfo::SPtr, SPtrTypeCoder<OpcUaDiagnosticInfo> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaDiagnosticInfoArray> SPtr;
	};

}

#endif
