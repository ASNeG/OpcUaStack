/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_SecureChannelTransaction_h__
#define __OpcUaStackCore_SecureChannelTransaction_h__

#include <boost/asio/streambuf.hpp>
#include <stdint.h>
#include <list>
#include "OpcUaStackCore/Certificate/CryptoBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelTransaction
	: public Object
	{
	  public:
		typedef boost::shared_ptr<SecureChannelTransaction> SPtr;
		typedef std::list<SecureChannelTransaction::SPtr> List;

	    SecureChannelTransaction(void);
	    ~SecureChannelTransaction(void);

	    void isAppend(boost::asio::streambuf& sb);
	    void osAppend(boost::asio::streambuf& sb);

		OpcUaNodeId requestTypeNodeId_;
		OpcUaNodeId responseTypeNodeId_;
		OpcUaUInt32 requestId_;
		Object::SPtr handle_;
		CryptoBase::SPtr cryptoBase_;

		boost::asio::streambuf is_;
		boost::asio::streambuf os_;
	};

}

#endif
