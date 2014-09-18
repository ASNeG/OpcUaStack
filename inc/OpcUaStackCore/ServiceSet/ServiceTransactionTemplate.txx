
namespace OpcUaStackCore
{

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::ServiceTransactionTemplate(void)
	  : ServiceTransaction(REQID, RESID)
	  , request_(typename REQTYPE::construct())
	  , response_(typename RESTYPE::construct())
	  {
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::~ServiceTransactionTemplate(void)
	  {
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  ServiceTransaction::SPtr 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::constructTransaction(void) 
	  {
		  return ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::construct();
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	typename REQTYPE::SPtr 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::request(void)
	  {
		  return request_;
	  }
		
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  typename RESTYPE::SPtr 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::response(void)
	  {
		  return response_;
	  }
	  
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryEncodeRequest(std::ostream& os) const
	  {
		  request_->opcUaBinaryEncode(os);
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryEncodeResponse(std::ostream& os) const
	  {
		  response_->opcUaBinaryEncode(os);
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryDecodeRequest(std::istream& is)
	  {
		  request_->opcUaBinaryDecode(is);
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryDecodeResponse(std::istream& is)
	  {
		  response_->opcUaBinaryDecode(is);
	  }

}