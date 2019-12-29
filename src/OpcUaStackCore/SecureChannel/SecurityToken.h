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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_SecurityToken_h__
#define __OpcUaStackCore_SecurityToken_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
	class DLLEXPORT SecurityToken
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SecurityToken> SPtr;

		SecurityToken(void);
		virtual ~SecurityToken(void);

		void channelId(const OpcUaUInt32& channelId);
		OpcUaUInt32 channelId(void) const;
		void tokenId(const OpcUaUInt32& tokenId);
		OpcUaUInt32 tokenId(void) const;
		void createAt(const OpcUaUtcTime& createAt);
		OpcUaUtcTime createAt(void) const;
		void revisedLifetime(const OpcUaInt32& revisedLifetime);
		OpcUaInt32 revisedLifetime(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 channelId_;
		OpcUaUInt32 tokenId_;
		OpcUaUtcTime createAt_;
		OpcUaInt32 revisedLifetime_;
	};

}

#endif
