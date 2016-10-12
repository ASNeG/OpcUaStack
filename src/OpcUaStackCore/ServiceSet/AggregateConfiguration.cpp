/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/AggregateConfiguration.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa AggregateConfiguration
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	AggregateConfiguration::AggregateConfiguration(void)
	: Object()
	, useServerCapabilitiesDefaults_()
	, treatUncertainAsBad_()
	, percentDataBad_()
	, percentDataGood_()
	, steppedSlopedExtrapolation_()
	{
	}

	AggregateConfiguration::~AggregateConfiguration(void)
	{
	}

	void 
	AggregateConfiguration::useServerCapabilitiesDefaults(const OpcUaBoolean& useServerCapabilitiesDefaults)
	{
		useServerCapabilitiesDefaults_ = useServerCapabilitiesDefaults;
	}
		
	OpcUaBoolean 
	AggregateConfiguration::useServerCapabilitiesDefaults(void)
	{
		return useServerCapabilitiesDefaults_;
	}
		
	void 
	AggregateConfiguration::treatUncertainAsBad(const OpcUaBoolean& treatUncertainAsBad)
	{
		treatUncertainAsBad_ = treatUncertainAsBad;
	}
	
	OpcUaBoolean 
	AggregateConfiguration::treatUncertainAsBad(void)
	{
		return treatUncertainAsBad_;
	}
	
	void 
	AggregateConfiguration::percentDataBad(const OpcUaByte& percentDataBad)
	{
		percentDataBad_ = percentDataBad;
	}
	
	OpcUaByte 
	AggregateConfiguration::percentDataBad(void)
	{
		return percentDataBad_;
	}
	
	void 
	AggregateConfiguration::percentDataGood(const OpcUaByte& percentDataGood)
	{
		percentDataGood_ = percentDataGood;
	}
	
	OpcUaByte 
	AggregateConfiguration::percentDataGood(void)
	{
		return percentDataGood_;
	}
		
	void 
	AggregateConfiguration::steppedSlopedExtrapolation(const OpcUaBoolean& steppedSlopedExtrapolation)
	{
		steppedSlopedExtrapolation_ = steppedSlopedExtrapolation;
	}
	
	OpcUaByte 
	AggregateConfiguration::steppedSlopedExtrapolation(void)
	{
		return steppedSlopedExtrapolation_;
	}

	void 
	AggregateConfiguration::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, useServerCapabilitiesDefaults_);
		OpcUaNumber::opcUaBinaryEncode(os, treatUncertainAsBad_);
		OpcUaNumber::opcUaBinaryEncode(os, percentDataBad_);
		OpcUaNumber::opcUaBinaryEncode(os, percentDataGood_);
		OpcUaNumber::opcUaBinaryEncode(os, steppedSlopedExtrapolation_);
	}
	
	void 
	AggregateConfiguration::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, useServerCapabilitiesDefaults_);
		OpcUaNumber::opcUaBinaryDecode(is, treatUncertainAsBad_);
		OpcUaNumber::opcUaBinaryDecode(is, percentDataBad_);
		OpcUaNumber::opcUaBinaryDecode(is, percentDataGood_);
		OpcUaNumber::opcUaBinaryDecode(is, steppedSlopedExtrapolation_);
	}
}
