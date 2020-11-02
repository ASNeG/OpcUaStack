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

#ifndef __OpcUaStackCore_ForwardTransactionTemplate_h__
#define __OpcUaStackCore_ForwardTransactionTemplate_h__

#include "OpcUaStackServer/Forward/ForwardTransaction.h"

namespace OpcUaStackServer
{
	
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  class ForwardTransactionTemplate
	  : public ForwardTransaction
	  {
	    public:
		  using SPtr = boost::shared_ptr<ForwardTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID> >;

		  ForwardTransactionTemplate(void);
		  virtual ~ForwardTransactionTemplate(void);

		  typename REQTYPE::SPtr request(void);
		  typename RESTYPE::SPtr response(void);

	    private:
		  typename REQTYPE::SPtr request_;
		  typename RESTYPE::SPtr response_;

		  static std::string name_;
	  };

}

#include "OpcUaStackServer/Forward/ForwardTransactionTemplate.txx"

#endif
