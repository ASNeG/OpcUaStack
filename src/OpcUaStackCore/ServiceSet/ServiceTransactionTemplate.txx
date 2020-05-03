/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServiceTransactionTemplate (static)
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  std::string ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::name_ = "";

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::name(const std::string& name) 
	  { 
	      name_ = name; 
	  }
	
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  std::string 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::name(void) 
	  { 
	      return name_; 
	  }


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServiceTransactionTemplate
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::ServiceTransactionTemplate(void)
	  : ServiceTransaction(REQID, RESID)
	  , request_(boost::make_shared<REQTYPE>())
	  , response_(boost::make_shared<RESTYPE>())
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
		  return boost::make_shared<ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID> >();
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
	  std::string 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::requestName(void) 
	  { 
	      return name() + std::string("Request"); 
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  std::string 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::responseName(void) 
	  { 
	      return name() + std::string("Response"); 
	  } 
	  
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::resultHandler(const ResultHandler& resultHandler)
	  {
	  	  resultHandler_ = resultHandler;
	  }
		  
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
      typename ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::ResultHandler& 
      ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::resultHandler(void)
      {
          return resultHandler_;
      }
      
    template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  void 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::resultHandlerStrand(const boost::shared_ptr<boost::asio::io_service::strand>& resultHandlerStrand)
	  {
	  	  resultHandlerStrand_ = resultHandlerStrand;
	  }
		  
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
      boost::shared_ptr<boost::asio::io_service::strand>& 
      ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::resultHandlerStrand(void)
      {
          return resultHandlerStrand_;
      }
	  
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  bool 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryEncodeRequest(std::ostream& os) const
	  {
		  return request_->opcUaBinaryEncode(os);
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  bool 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryEncodeResponse(std::ostream& os) const
	  {
		  return response_->opcUaBinaryEncode(os);
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  bool 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryDecodeRequest(std::istream& is)
	  {
		  return request_->opcUaBinaryDecode(is);
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  bool 
	  ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::opcUaBinaryDecodeResponse(std::istream& is)
	  {
		  return response_->opcUaBinaryDecode(is);
	  }
}
