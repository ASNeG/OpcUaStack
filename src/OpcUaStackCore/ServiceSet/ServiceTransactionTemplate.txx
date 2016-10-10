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
	  , request_(constructSPtr<REQTYPE>())
	  , response_(constructSPtr<RESTYPE>())
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
		  return constructSPtr<ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID> >();
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
