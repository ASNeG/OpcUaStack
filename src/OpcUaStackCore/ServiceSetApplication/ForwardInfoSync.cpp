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

#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h"

namespace OpcUaStackCore
{

	ForwardInfoSync::ForwardInfoSync(void)
	: readCallbackFlag_(false)
	, writeCallbackFlag_(false)
	, readCallback_()
	, writeCallback_()
	, applicationContext_()
	{
	}

	ForwardInfoSync::~ForwardInfoSync(void)
	{
	}

	void
	ForwardInfoSync::setReadCallback(Callback& readCallback)
	{
		readCallback_ = readCallback;
		readCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetReadCallback(void)
	{
		readCallbackFlag_ = false;
	}

	bool
	ForwardInfoSync::isReadCallback(void)
	{
		return readCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::readCallback(void)
	{
		return readCallback_;
	}

	void
	ForwardInfoSync::setWriteCallback(Callback& writeCallback)
	{
		writeCallback_ = writeCallback;
		writeCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetWriteCallback(void)
	{
		writeCallbackFlag_ = false;
	}

	bool
	ForwardInfoSync::isWriteCallback(void)
	{
		return writeCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::writeCallback(void)
	{
		return writeCallback_;
	}

	void
	ForwardInfoSync::applicationContext(BaseClass::SPtr& applicationContext)
	{
		applicationContext_ = applicationContext;
	}

	BaseClass::SPtr&
	ForwardInfoSync::applicationContext(void)
	{
		return applicationContext_;
	}

}
