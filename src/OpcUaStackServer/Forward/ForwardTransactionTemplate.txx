/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

namespace OpcUaServer
{

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  ForwardTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::ForwardTransactionTemplate(void)
	  : ServiceTransaction(REQID, RESID)
	  , request_(boost::make_shared<REQTYPE>())
	  , response_(boost::make_shared<RESTYPE>())
	  {
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  ForwardTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::~ForwardTransactionTemplate(void)
	  {
	  }

	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	typename REQTYPE::SPtr 
	  ForwardTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::request(void)
	  {
		  return request_;
	  }
		
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  typename RESTYPE::SPtr 
	  ForwardTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID>::response(void)
	  {
		  return response_;
	  }

}
