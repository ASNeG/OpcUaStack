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

#ifndef __OpcUaStackCore_ServiceTransactionTemplate_h__
#define __OpcUaStackCore_ServiceTransactionTemplate_h__

#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"

namespace OpcUaStackCore
{
	
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  class ServiceTransactionTemplate
	  : public ServiceTransaction
	  {
	    public:
		  typedef boost::shared_ptr<ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID> > SPtr;
		  typedef std::function<void(SPtr& handler)> ResultHandler;

		  static void name(const std::string& name);
		  static std::string name(void);

		  ServiceTransactionTemplate(void);
		  virtual ~ServiceTransactionTemplate(void);

		  ServiceTransaction::SPtr constructTransaction(void);

		  typename REQTYPE::SPtr request(void);
		  typename RESTYPE::SPtr response(void);

		  std::string requestName(void);
		  std::string responseName(void); 

		  void resultHandler(const ResultHandler& resultHandler);
		  ResultHandler& resultHandler(void);

		  bool opcUaBinaryEncodeRequest(std::ostream& os) const;
		  bool opcUaBinaryEncodeResponse(std::ostream& os) const;
		  bool opcUaBinaryDecodeRequest(std::istream& is);
		  bool opcUaBinaryDecodeResponse(std::istream& is);

	    private:
		  ResultHandler resultHandler_;
		  ResponseHeader::SPtr responseHeader_;
		  typename REQTYPE::SPtr request_;
		  typename RESTYPE::SPtr response_;

		  static std::string name_;
	  };

}

#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.txx"

#endif
