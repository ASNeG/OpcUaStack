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

#include "OpcUaStackCore/StandardDataTypes/SamplingIntervalDiagnosticsDataType.h"

namespace OpcUaStackCore
{

	SamplingIntervalDiagnosticsDataType::SamplingIntervalDiagnosticsDataType(void)
	: Object()
	, samplingRate_()
	, sampledMonitoredItemsCount_()
	, maxSampledMonitoredItemsCount_()
	, disabledMonitoredItemsSamplingCount_()
	{
	}

	SamplingIntervalDiagnosticsDataType::~SamplingIntervalDiagnosticsDataType(void)
	{
	}

	OpcUaDouble&
	SamplingIntervalDiagnosticsDataType::samplingRate(void)
	{
		return samplingRate_;
	}

	void
	SamplingIntervalDiagnosticsDataType::samplingRate(OpcUaDouble samplingRate)
	{
		samplingRate_ = samplingRate;
	}

	OpcUaUInt32&
	SamplingIntervalDiagnosticsDataType::sampledMonitoredItemsCount(void)
	{
		return sampledMonitoredItemsCount_;
	}

	void
	SamplingIntervalDiagnosticsDataType::sampledMonitoredItemsCount(OpcUaUInt32 sampledMonitoredItemsCount)
	{
		sampledMonitoredItemsCount_ = sampledMonitoredItemsCount;
	}

	OpcUaUInt32&
	SamplingIntervalDiagnosticsDataType::maxSampledMonitoredItemsCount(void)
	{
		return maxSampledMonitoredItemsCount_;
	}

	void
	SamplingIntervalDiagnosticsDataType::maxSampledMonitoredItemsCount(OpcUaUInt32 maxSampledMonitoredItemsCount)
	{
		maxSampledMonitoredItemsCount_ = maxSampledMonitoredItemsCount;
	}

	OpcUaUInt32&
	SamplingIntervalDiagnosticsDataType::disabledMonitoredItemsSamplingCount(void)
	{
		return disabledMonitoredItemsSamplingCount_;
	}

	void
	SamplingIntervalDiagnosticsDataType::disabledMonitoredItemsSamplingCount(OpcUaUInt32 disabledMonitoredItemsSamplingCount)
	{
		disabledMonitoredItemsSamplingCount_ = disabledMonitoredItemsSamplingCount;
	}

	void
	SamplingIntervalDiagnosticsDataType::copyTo(SamplingIntervalDiagnosticsDataType& samplingIntervalDiagnosticsDataType)
	{
		samplingIntervalDiagnosticsDataType.samplingRate(samplingRate_);
		samplingIntervalDiagnosticsDataType.sampledMonitoredItemsCount(sampledMonitoredItemsCount_);
		samplingIntervalDiagnosticsDataType.maxSampledMonitoredItemsCount(maxSampledMonitoredItemsCount_);
		samplingIntervalDiagnosticsDataType.disabledMonitoredItemsSamplingCount(disabledMonitoredItemsSamplingCount_);
	}

	bool
	SamplingIntervalDiagnosticsDataType::operator==(const SamplingIntervalDiagnosticsDataType& samplingIntervalDiagnosticsDataType) const
	{
		SamplingIntervalDiagnosticsDataType* dst = const_cast<SamplingIntervalDiagnosticsDataType*>(&samplingIntervalDiagnosticsDataType);
		return
			samplingRate_ == dst->samplingRate() &&
			sampledMonitoredItemsCount_ == dst->sampledMonitoredItemsCount() &&
			maxSampledMonitoredItemsCount_ == dst->maxSampledMonitoredItemsCount() &&
			disabledMonitoredItemsSamplingCount_ == dst->disabledMonitoredItemsSamplingCount();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	SamplingIntervalDiagnosticsDataType::factory(void)
	{
		return constructSPtr<SamplingIntervalDiagnosticsDataType>();
	}

	void
	SamplingIntervalDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, samplingRate_);
		OpcUaNumber::opcUaBinaryEncode(os, sampledMonitoredItemsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, maxSampledMonitoredItemsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, disabledMonitoredItemsSamplingCount_);
	}

	void
	SamplingIntervalDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, samplingRate_);
		OpcUaNumber::opcUaBinaryDecode(is, sampledMonitoredItemsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, maxSampledMonitoredItemsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, disabledMonitoredItemsSamplingCount_);
	}

	bool
	SamplingIntervalDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SamplingIntervalDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SamplingIntervalDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	SamplingIntervalDiagnosticsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		SamplingIntervalDiagnosticsDataType* dst = dynamic_cast<SamplingIntervalDiagnosticsDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	SamplingIntervalDiagnosticsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		SamplingIntervalDiagnosticsDataType* dst = dynamic_cast<SamplingIntervalDiagnosticsDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	SamplingIntervalDiagnosticsDataType::out(std::ostream& os)
	{
		os << "SimplingRate=" << samplingRate_;
		os << ", SampledMonitoredItemsCount=" << sampledMonitoredItemsCount_;
		os << ", MaxSampledMonitoredItemsCount=" << maxSampledMonitoredItemsCount_;
		os << ", DisableMonitoredItemsSamplingCount=" << disabledMonitoredItemsSamplingCount_;
	}

}

