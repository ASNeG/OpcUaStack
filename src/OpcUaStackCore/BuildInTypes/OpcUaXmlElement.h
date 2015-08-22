#ifndef __OpcUaStackCore_OpcUaXmlElement_h__
#define __OpcUaStackCore_OpcUaXmlElement_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaXmlElement : public ObjectPool<OpcUaXmlElement>
	{
	  public:
		typedef boost::shared_ptr<OpcUaXmlElement> SPtr;

	    OpcUaXmlElement(void);
		~OpcUaXmlElement(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);

	  private:
		
	};

	class OpcUaXmlElementArray
	: public OpcUaArray<OpcUaXmlElement::SPtr, SPtrTypeCoder<OpcUaXmlElement> >
	, public ObjectPool<OpcUaXmlElementArray>
	{
	  public:
		typedef boost::shared_ptr<OpcUaXmlElementArray> SPtr;
	};

}

#endif
