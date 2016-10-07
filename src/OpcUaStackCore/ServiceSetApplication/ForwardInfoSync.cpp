/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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
	, readHCallbackFlag_(false)
	, writeCallbackFlag_(false)
	, writeHCallbackFlag_(false)
	, methodCallbackFlag_(false)
	, usedReadCallbackFlag_(false)
	, usedReadHCallbackFlag_(false)
	, usedWriteCallbackFlag_(false)
	, usedWriteHCallbackFlag_(false)
	, usedMethodCallbackFlag_(false)
	, readCallback_()
	, readHCallback_()
	, writeCallback_()
	, writeHCallback_()
	, methodCallback_()
	, applicationContext_()
	{
	}

	ForwardInfoSync::~ForwardInfoSync(void)
	{
	}

	void
	ForwardInfoSync::update(ForwardInfoSync& forwardInfoSync)
	{
		// set or unset read callback
		if (forwardInfoSync.usedReadCallback()) {
			if (forwardInfoSync.isReadCallback()) {
				setReadCallback(forwardInfoSync.readCallback());
			}
			else {
				unsetReadCallback();
			}
		}

		// set or unset history read callback
		if (forwardInfoSync.usedReadHCallback()) {
			if (forwardInfoSync.isReadHCallback()) {
				setReadHCallback(forwardInfoSync.readHCallback());
			}
			else {
				unsetReadHCallback();
			}
		}

		// set or unset write callback
		if (forwardInfoSync.usedWriteCallback()) {
			if (forwardInfoSync.isWriteCallback()) {
				setWriteCallback(forwardInfoSync.writeCallback());
			}
			else {
				unsetWriteCallback();
			}
		}

		// set or unset history write callback
		if (forwardInfoSync.usedWriteHCallback()) {
			if (forwardInfoSync.isWriteHCallback()) {
				setWriteHCallback(forwardInfoSync.writeHCallback());
			}
			else {
				unsetWriteHCallback();
			}
		}

		// set or unset method callback
		if (forwardInfoSync.usedMethodCallback()) {
			if (forwardInfoSync.isMethodCallback()) {
				setMethodCallback(forwardInfoSync.methodCallback());
			}
			else {
				unsetMethodCallback();
			}
		}
	}

	void
	ForwardInfoSync::setReadCallback(Callback& readCallback)
	{
		readCallback_ = readCallback;
		readCallbackFlag_ = true;
		usedReadCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetReadCallback(void)
	{
		readCallbackFlag_ = false;
		usedReadCallbackFlag_ = true;
	}

	bool
	ForwardInfoSync::isReadCallback(void)
	{
		return readCallbackFlag_;
	}

	bool
	ForwardInfoSync::usedReadCallback(void)
	{
		return usedReadCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::readCallback(void)
	{
		return readCallback_;
	}

	void
	ForwardInfoSync::setReadHCallback(Callback& readHCallback)
	{
		readHCallback_ = readHCallback;
		readHCallbackFlag_ = true;
		usedReadHCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetReadHCallback(void)
	{
		readHCallbackFlag_ = false;
		usedReadHCallbackFlag_ = true;
	}

	bool
	ForwardInfoSync::isReadHCallback(void)
	{
		return readHCallbackFlag_;
	}

	bool
	ForwardInfoSync::usedReadHCallback(void)
	{
		return usedReadHCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::readHCallback(void)
	{
		return readHCallback_;
	}

	void
	ForwardInfoSync::setWriteCallback(Callback& writeCallback)
	{
		writeCallback_ = writeCallback;
		writeCallbackFlag_ = true;
		usedWriteCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetWriteCallback(void)
	{
		writeCallbackFlag_ = false;
		usedWriteCallbackFlag_ = true;
	}

	bool
	ForwardInfoSync::isWriteCallback(void)
	{
		return writeCallbackFlag_;
	}

	bool
	ForwardInfoSync::usedWriteCallback(void)
	{
		return usedWriteCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::writeCallback(void)
	{
		return writeCallback_;
	}

	void
	ForwardInfoSync::setWriteHCallback(Callback& writeHCallback)
	{
		writeHCallback_ = writeHCallback;
		writeHCallbackFlag_ = true;
		usedWriteHCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetWriteHCallback(void)
	{
		writeHCallbackFlag_ = false;
		usedWriteHCallbackFlag_ = true;
	}

	bool
	ForwardInfoSync::isWriteHCallback(void)
	{
		return writeHCallbackFlag_;
	}

	bool
	ForwardInfoSync::usedWriteHCallback(void)
	{
		return usedWriteHCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::writeHCallback(void)
	{
		return writeHCallback_;
	}

	void
	ForwardInfoSync::setMethodCallback(Callback& methodCallback)
	{
		methodCallback_ = methodCallback;
		methodCallbackFlag_ = true;
		usedMethodCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::unsetMethodCallback(void)
	{
		methodCallbackFlag_ = false;
		usedMethodCallbackFlag_ = true;
	}

	bool
	ForwardInfoSync::isMethodCallback(void)
	{
		return methodCallbackFlag_;
	}

	bool
	ForwardInfoSync::usedMethodCallback(void)
	{
		return usedMethodCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::methodCallback(void)
	{
		return methodCallback_;
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
