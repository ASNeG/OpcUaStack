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

#ifndef __CDAMESSAGE_H__
#define __CDAMESSAGE_H__

#include <string>
#include "Application/CDA/Coder.h"

class CDAMessage
{
  public:
	typedef boost::shared_ptr<CDAMessage> SPtr;

	typedef enum
	{
		MSG_READ_REQUEST,
		MSG_READ_RESPONSE,
		MSG_WRITE_REQUEST,
		MSG_WRITE_RESPONSE,
		MSG_SUBSCRIBE_REQUEST,
		MSG_SUBSCRIBE_RESPONSE,
		MSG_CHANGEVALUE_NOTIFY,
		MSG_RESET_REQUEST,
		MSG_RESET_RESPONSE
	} MessageType;
	MessageType messageType_;

	virtual std::ostream& encode(std::ostream& os) = 0;
	virtual std::istream& decode(std::istream& is) = 0;

	friend std::ostream& operator<<(std::ostream& os, CDAMessage& cdaMessage) {
		return cdaMessage.encode(os);
	}

	friend std::istream& operator>>(std::istream& is, CDAMessage& cdaMessage) {
		return cdaMessage.decode(is);
	}

	friend std::ostream& operator<<(std::ostream& os, CDAMessage* cdaMessage) {
		return cdaMessage->encode(os);
	}

	friend std::istream& operator>>(std::istream& is, CDAMessage* cdaMessage) {
		return cdaMessage->decode(is);
	}
};

template<typename T>
  class CDAMessageTmpl : public CDAMessage
  {
    public:
	  typedef boost::shared_ptr<T> SPtr;
  };

class CDAReadRequest : public CDAMessageTmpl<CDAReadRequest>
{
  public:
	CDAReadRequest(void);

    std::string name_;
	DataValue::Type type_;

	virtual std::ostream& encode(std::ostream& os);
    virtual std::istream& decode(std::istream& is);
};

class CDAReadResponse : public CDAMessageTmpl<CDAReadResponse>
{
  public:
	CDAReadResponse(void);

	std::string name_;
	DataValue::Type type_;
	DataValue::VecSPtr dataValueVecSPtr_;
	uint32_t state_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDAWriteRequest : public CDAMessageTmpl<CDAWriteRequest>
{
  public:
	CDAWriteRequest(void);

	std::string name_;
	DataValue::Type type_;
	DataValue::VecSPtr dataValueVecSPtr_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDAWriteResponse : public CDAMessageTmpl<CDAWriteResponse>
{
  public:
	CDAWriteResponse(void);

	std::string name_;
	DataValue::Type type_;
	uint32_t state_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDASubscribeRequest : public CDAMessageTmpl<CDASubscribeRequest>
{
  public:
	CDASubscribeRequest(void);

	std::string name_;
	DataValue::Type type_;
	bool switch_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDASubscribeResponse : public CDAMessageTmpl<CDASubscribeResponse>
{
  public:
	CDASubscribeResponse(void);

	std::string name_;
	DataValue::Type type_;
	bool switch_;
	uint32_t state_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDAResetRequest : public CDAMessageTmpl<CDAResetRequest>
{
  public:
	CDAResetRequest(void);

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDAResetResponse : public CDAMessageTmpl<CDAResetResponse>
{
  public:
	CDAResetResponse(void);

	uint32_t state_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDAValueChangeNotify : public CDAMessageTmpl<CDAValueChangeNotify>
{
  public:
    CDAValueChangeNotify(void);

	std::string name_;
	DataValue::Type type_;
	DataValue::VecSPtr dataValueVecSPtr_;
	uint32_t state_;

	virtual std::ostream& encode(std::ostream& os);
	virtual std::istream& decode(std::istream& is);
};

class CDAMessageFactory
{
  public:
    static CDAMessage::SPtr createMessage(CDAMessage::MessageType messageType) {
		CDAMessage::SPtr cdaMessageSPtr;
		switch (messageType) 
		{
			case CDAMessage::MSG_READ_REQUEST: 
				cdaMessageSPtr.reset(new CDAReadRequest); 
				break;
			case CDAMessage::MSG_READ_RESPONSE:
				cdaMessageSPtr.reset(new CDAReadResponse());
				break;
			case CDAMessage::MSG_WRITE_REQUEST:
				cdaMessageSPtr.reset(new CDAWriteRequest());
				break;
			case CDAMessage::MSG_WRITE_RESPONSE:
				cdaMessageSPtr.reset(new CDAWriteResponse());
				break;
			case CDAMessage::MSG_SUBSCRIBE_REQUEST:
				cdaMessageSPtr.reset(new CDASubscribeRequest());
				break;
			case CDAMessage::MSG_SUBSCRIBE_RESPONSE:
				cdaMessageSPtr.reset(new CDASubscribeResponse());
				break;
			case CDAMessage::MSG_CHANGEVALUE_NOTIFY:
				cdaMessageSPtr.reset(new CDAValueChangeNotify());
				break;
			case CDAMessage::MSG_RESET_REQUEST:
				cdaMessageSPtr.reset(new CDAResetRequest());
				break;
			case CDAMessage::MSG_RESET_RESPONSE:
				cdaMessageSPtr.reset(new CDAResetResponse());
				break;
			default:
				break;
		}
		return cdaMessageSPtr;
	}
};

#endif
