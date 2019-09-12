/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaClient/ClientService/ClientAccessObject.h"

using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientAccessObject::ClientAccessObject(void)
	: serviceSetManager_()
	, sessionService_()
	, attributeService_()
	, viewService_()
	{
	}

	ClientAccessObject::~ClientAccessObject(void)
	{
	}

	AttributeService::SPtr
	ClientAccessObject::createAttributeService(AttributeServiceConfig& attributeServiceConfig)
	{
		return serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
	}

	AttributeService::SPtr
	ClientAccessObject::createAttributeService(void)
	{
		return serviceSetManager_.attributeService(sessionService_);
	}

	AttributeService::SPtr
	ClientAccessObject::getOrCreateAttributeService(AttributeServiceConfig& attributeServiceConfig)
	{
		if (attributeService_.get() != nullptr ) {
			return attributeService_;
		}

		if (sessionService_.get() == nullptr) {
			return attributeService_;
		}

		attributeService_ = serviceSetManager_.attributeService(sessionService_, attributeServiceConfig);
		return attributeService_;
	}

	AttributeService::SPtr
	ClientAccessObject::getOrCreateAttributeService(void)
	{
		if (attributeService_.get() != nullptr ) {
			return attributeService_;
		}

		if (sessionService_.get() == nullptr) {
			return attributeService_;
		}

		attributeService_ = serviceSetManager_.attributeService(sessionService_);
		return attributeService_;
	}

	ViewService::SPtr
	ClientAccessObject::createViewService(ViewServiceConfig& viewServiceConfig)
	{
		return serviceSetManager_.viewService(sessionService_, viewServiceConfig);
	}

	ViewService::SPtr
	ClientAccessObject::createViewService(void)
	{
		return serviceSetManager_.viewService(sessionService_);
	}

	ViewService::SPtr
	ClientAccessObject::getOrCreateViewService(ViewServiceConfig& viewServiceConfig)
	{
		if (viewService_.get() != nullptr ) {
			return viewService_;
		}

		if (sessionService_.get() == nullptr) {
			return viewService_;
		}

		viewService_ = serviceSetManager_.viewService(sessionService_, viewServiceConfig);
		return viewService_;
	}

	ViewService::SPtr
	ClientAccessObject::getOrCreateViewService(void)
	{
		if (viewService_.get() != nullptr ) {
			return viewService_;
		}

		if (sessionService_.get() == nullptr) {
			return viewService_;
		}

		viewService_ = serviceSetManager_.viewService(sessionService_);
		return viewService_;
	}

	MethodService::SPtr
	ClientAccessObject::createMethodService(MethodServiceConfig& methodServiceConfig)
	{
		return serviceSetManager_.methodService(sessionService_, methodServiceConfig);
	}

	MethodService::SPtr
	ClientAccessObject::createMethodService(void)
	{
		return serviceSetManager_.methodService(sessionService_);
	}

	MethodService::SPtr
	ClientAccessObject::getOrCreateMethodService(MethodServiceConfig& methodServiceConfig)
	{
		if (methodService_.get() != nullptr ) {
			return methodService_;
		}

		if (sessionService_.get() == nullptr) {
			return methodService_;
		}

		methodService_ = serviceSetManager_.methodService(sessionService_, methodServiceConfig);
		return methodService_;
	}

	MethodService::SPtr
	ClientAccessObject::getOrCreateMethodService(void)
	{
		if (methodService_.get() != nullptr ) {
			return methodService_;
		}

		if (sessionService_.get() == nullptr) {
			return methodService_;
		}

		methodService_ = serviceSetManager_.methodService(sessionService_);
		return methodService_;
	}

	DiscoveryService::SPtr
	ClientAccessObject::createDiscoveryService(DiscoveryServiceConfig& discoveryServiceConfig)
	{
		return serviceSetManager_.discoveryService(sessionService_, discoveryServiceConfig);
	}

	DiscoveryService::SPtr
	ClientAccessObject::createDiscoveryService(void)
	{
		return serviceSetManager_.discoveryService(sessionService_);
	}

	DiscoveryService::SPtr
	ClientAccessObject::getOrCreateDiscoveryService(DiscoveryServiceConfig& discoveryServiceConfig)
	{
		if (discoveryService_.get() != nullptr ) {
			return discoveryService_;
		}

		if (sessionService_.get() == nullptr) {
			return discoveryService_;
		}

		discoveryService_ = serviceSetManager_.discoveryService(sessionService_, discoveryServiceConfig);
		return discoveryService_;
	}

	DiscoveryService::SPtr
	ClientAccessObject::getOrCreateDiscoveryService(void)
	{
		if (discoveryService_.get() != nullptr ) {
			return discoveryService_;
		}

		if (sessionService_.get() == nullptr) {
			return discoveryService_;
		}

		discoveryService_ = serviceSetManager_.discoveryService(sessionService_);
		return discoveryService_;
	}

}

