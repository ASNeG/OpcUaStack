#include "Application/CDA/CDAMessage.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// CDAReadRequest
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAReadRequest::CDAReadRequest(void)
: CDAMessageTmpl<CDAReadRequest>()
{
	messageType_ = CDAMessage::MSG_READ_REQUEST;
}

std::ostream& 
CDAReadRequest::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	return os;
}

std::istream& 
CDAReadRequest::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	return is;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAReadResponse
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAReadResponse::CDAReadResponse(void)
: CDAMessageTmpl<CDAReadResponse>()
{
	messageType_ = CDAMessage::MSG_READ_RESPONSE;
}

std::ostream& 
CDAReadResponse::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	CDAEncoder::encode(os, dataValueVecSPtr_);
	CDAEncoder::encode(os, state_);
	return os;
}

std::istream& 
CDAReadResponse::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	CDADecoder::decode(is, dataValueVecSPtr_);
	CDADecoder::decode(is, state_);
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAWriteRequest
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAWriteRequest::CDAWriteRequest(void)
: CDAMessageTmpl<CDAWriteRequest>()
{
	messageType_ = CDAMessage::MSG_WRITE_REQUEST;
}

std::ostream& 
CDAWriteRequest::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	CDAEncoder::encode(os, dataValueVecSPtr_); 
	return os;
}

std::istream& 
CDAWriteRequest::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	CDADecoder::decode(is, dataValueVecSPtr_);
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAWriteResponse
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAWriteResponse::CDAWriteResponse(void)
: CDAMessageTmpl<CDAWriteResponse>()
{
	messageType_ = CDAMessage::MSG_WRITE_RESPONSE;
}

std::ostream& 
CDAWriteResponse::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	CDAEncoder::encode(os, state_);
	return os;
}

std::istream& 
CDAWriteResponse::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	CDADecoder::decode(is, state_);
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDASubscribeRequest
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDASubscribeRequest::CDASubscribeRequest(void)
: CDAMessageTmpl<CDASubscribeRequest>()
{
	messageType_ = CDAMessage::MSG_SUBSCRIBE_REQUEST;
}

std::ostream& 
CDASubscribeRequest::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	CDAEncoder::encode(os, switch_);
	return os;
}

std::istream& 
CDASubscribeRequest::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	CDADecoder::decode(is, switch_);
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDASubscribeResponse
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDASubscribeResponse::CDASubscribeResponse(void)
: CDAMessageTmpl<CDASubscribeResponse>()
{
	messageType_ = CDAMessage::MSG_SUBSCRIBE_RESPONSE;
}

std::ostream& 
CDASubscribeResponse::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	CDAEncoder::encode(os, switch_);
	CDAEncoder::encode(os, state_);
	return os;
}

std::istream& 
CDASubscribeResponse::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	CDADecoder::decode(is, switch_);
	CDADecoder::decode(is, state_);
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAValueChangeNotify
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAValueChangeNotify::CDAValueChangeNotify(void)
: CDAMessageTmpl<CDAValueChangeNotify>()
{
	messageType_ = CDAMessage::MSG_CHANGEVALUE_NOTIFY;
}

std::ostream& 
CDAValueChangeNotify::encode(std::ostream& os)
{
	CDAEncoder::encode(os, name_);
	CDAEncoder::encode(os, type_);
	CDAEncoder::encode(os, dataValueVecSPtr_);
	CDAEncoder::encode(os, state_);
	return os;
}

std::istream& 
CDAValueChangeNotify::decode(std::istream& is)
{
	CDADecoder::decode(is, name_);
	CDADecoder::decode(is, type_);
	CDADecoder::decode(is, dataValueVecSPtr_);
	CDADecoder::decode(is, state_);
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAResetRequest
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAResetRequest::CDAResetRequest(void)
: CDAMessageTmpl<CDAResetRequest>()
{
	messageType_ = CDAMessage::MSG_RESET_REQUEST;
}

std::ostream& 
CDAResetRequest::encode(std::ostream& os)
{
	return os;
}

std::istream& 
CDAResetRequest::decode(std::istream& is)
{
    return is;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//  
// CDAResetResponse
//  
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
CDAResetResponse::CDAResetResponse(void)
: CDAMessageTmpl<CDAResetResponse>()
{
	messageType_ = CDAMessage::MSG_RESET_RESPONSE;
}

std::ostream& 
CDAResetResponse::encode(std::ostream& os)
{
	CDAEncoder::encode(os, state_);
	return os;
}

std::istream& 
CDAResetResponse::decode(std::istream& is)
{
	CDADecoder::decode(is, state_);
    return is;
}
