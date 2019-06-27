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

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#ifndef __OpcUaStackCore_SamplingIntervalDiagnosticsDataType_h__
#define __OpcUaStackCore_SamplingIntervalDiagnosticsDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SamplingIntervalDiagnosticsDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<SamplingIntervalDiagnosticsDataType> SPtr;

		SamplingIntervalDiagnosticsDataType(void);
		virtual ~SamplingIntervalDiagnosticsDataType(void);

		OpcUaDouble& samplingRate(void);
		void samplingRate(OpcUaDouble samplingRate);
		OpcUaUInt32& sampledMonitoredItemsCount(void);
		void sampledMonitoredItemsCount(OpcUaUInt32 sampledMonitoredItemsCount);
		OpcUaUInt32& maxSampledMonitoredItemsCount(void);
		void maxSampledMonitoredItemsCount(OpcUaUInt32 maxSampledMonitoredItemsCount);
		OpcUaUInt32& disabledMonitoredItemsSamplingCount(void);
		void disabledMonitoredItemsSamplingCount(OpcUaUInt32 disabledMonitoredItemsSamplingCount);


		void copyTo(SamplingIntervalDiagnosticsDataType& samplingIntervalDiagnosticsDataType);
		bool operator==(const SamplingIntervalDiagnosticsDataType& samplingIntervalDiagnosticsDataType) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

	  private:
        OpcUaDouble samplingRate_;
        OpcUaUInt32 sampledMonitoredItemsCount_;
        OpcUaUInt32 maxSampledMonitoredItemsCount_;
        OpcUaUInt32 disabledMonitoredItemsSamplingCount_;

	};

}

#endif
