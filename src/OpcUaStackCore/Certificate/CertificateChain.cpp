/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateChainrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

namespace OpcUaStackCore
{

	CertificateChain::CertificateChain(void)
	: certificateVec_()
	{
	}

	CertificateChain::~CertificateChain(void)
	{
		certificateVec_.clear();
	}

	void
	CertificateChain::clear(void)
	{
		certificateVec_.clear();
	}

	Certificate::Vec&
	CertificateChain::certificateVec(void)
	{
		return certificateVec_;
	}

	void
	CertificateChain::addCertificate(Certificate::SPtr& certificate)
	{
		certificateVec_.push_back(certificate);
	}

	Certificate::SPtr
	CertificateChain::getCertificate(uint32_t idx)
	{
		if (idx >= certificateVec_.size()) {
			Certificate::SPtr certificate;
			return certificate;
		}
		return certificateVec_[idx];
	}

	bool
	CertificateChain::empty(void)
	{
		return certificateVec_.size() == 0;
	}

	uint32_t
	CertificateChain::size(void)
	{
		return certificateVec_.size();
	}

	uint32_t
	CertificateChain::certificateSize(void)
	{
		uint32_t size = 0;
		for (auto certificate : certificateVec_) {
			size += certificate->getDERBufSize();
		}
		return size;
	}

	uint32_t
	CertificateChain::lastCertificateSize(void)
	{
		if (certificateVec_.size() == 0) {
			return 0;
		}

		auto certificate = certificateVec_[certificateVec_.size()-1];
		return certificate->getDERBufSize();
	}

	bool
	CertificateChain::fromByteString(OpcUaByteString& byteString)
	{
		certificateVec_.clear();

		// get pointer to certificate chain
		char* certBuf = nullptr;
		int32_t certLen = 0;
		byteString.value(&certBuf, &certLen);
		if (certLen <= 0) {
			Log(Error, "input parameter error");
			return false;
		}

		char* mem = certBuf;
		while (certLen > 0) {
			auto certificate = boost::make_shared<Certificate>();
			if (!certificate->fromDERBuf(mem, (uint32_t)certLen)) {
				certificate->log(Error, "decode certificate chain error - Certificate::fromDERBuf");
				return false;
			}
			certificateVec_.push_back(certificate);

			uint32_t len = certificate->getDERBufSize();
			if (len == 0) {
				Log(Error, "decode certificate chain error - DER buflen error");
				return false;
			}

			mem += len;
			certLen -= len;
		}

		return true;
	}

	CertificateChain&
	CertificateChain::operator = (const CertificateChain& other)
	{
		for (auto certificate : other.certificateVec_) {
			certificateVec_.push_back(certificate);
		}
		return *this;
	}

	bool
	CertificateChain::operator!=(const CertificateChain& rhs) const
	{
		return !operator==(rhs);
	}

	bool
	CertificateChain::operator==(const CertificateChain& rhs) const
	{
		if (certificateVec_.size() != rhs.certificateVec_.size()) {
			return false;
		}
		for (uint32_t idx=0; idx < certificateVec_.size(); idx++) {
			auto cert1 = certificateVec_[idx];
			auto cert2 = rhs.certificateVec_[idx];
			if (*cert1.get() != *cert2.get()) return false;
		}
		return true;
	}

	bool
	CertificateChain::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByteString byteString;
		byteString.opcUaBinaryDecode(is);

		if (!byteString.exist() || byteString.size() == 0) {
			return true;
		}

		return fromByteString(byteString);
	}

	bool
	CertificateChain::toByteString(OpcUaByteString& byteString) const
	{
		if (certificateVec_.empty()) {
			Log(Error, "certificate vector empty");
			return false;
		}

		// calculate buffer size
		uint32_t usedBufferSize = 0;
		for (auto certificate : certificateVec_) {
			usedBufferSize += certificate->getDERBufSize();
		}

		if (usedBufferSize == 0) {
			Log(Error, "certificate length is 0");
			return false;
		}

		// create buffer
		MemoryBuffer buffer(usedBufferSize);
		char* mem = buffer.memBuf();
		for (auto certificate : certificateVec_) {
			uint32_t length = certificate->getDERBufSize();
			certificate->toDERBuf(mem, &length);

			mem += length;
		}

		byteString.value(buffer.memBuf(), buffer.memLen());
		return true;
	}

	bool
	CertificateChain::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByteString byteString;
		if (!certificateVec_.empty()) {
			toByteString(byteString);
		}
		byteString.opcUaBinaryEncode(os);
		return true;
	}

}
