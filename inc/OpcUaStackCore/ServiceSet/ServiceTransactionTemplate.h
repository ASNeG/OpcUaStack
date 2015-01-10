#ifndef __OpcUaStackCore_ServiceTransactionTemplate_h__
#define __OpcUaStackCore_ServiceTransactionTemplate_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"

namespace OpcUaStackCore
{
	
	template<typename REQTYPE, typename RESTYPE, uint32_t REQID, uint32_t RESID>
	  class ServiceTransactionTemplate 
			: public ObjectPool<ServiceTransactionTemplate<REQTYPE, RESTYPE, REQID, RESID> >
			, public ServiceTransaction
	  {
	    public:
		  typedef boost::shared_ptr<ServiceTransactionTemplate> SPtr;

		  static void name(const std::string& name);
		  static std::string name(void);

		  ServiceTransactionTemplate(void);
		  ~ServiceTransactionTemplate(void);

		  ServiceTransaction::SPtr constructTransaction(void);

		  typename REQTYPE::SPtr request(void);
		  typename RESTYPE::SPtr response(void);

		  std::string requestName(void);
		  std::string responseName(void); 

		  void opcUaBinaryEncodeRequest(std::ostream& os) const;
		  void opcUaBinaryEncodeResponse(std::ostream& os) const;
		  void opcUaBinaryDecodeRequest(std::istream& is);
		  void opcUaBinaryDecodeResponse(std::istream& is);

	    private:
		  typename REQTYPE::SPtr request_;
		  typename RESTYPE::SPtr response_;

		  static std::string name_;
	  };

}

#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.txx"

#endif