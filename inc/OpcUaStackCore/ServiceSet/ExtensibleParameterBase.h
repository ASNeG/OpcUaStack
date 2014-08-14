#ifndef __OpcUaStackCore_ExtensibleParameterBase_h__
#define __OpcUaStackCore_ExtensibleParameterBase_h__

namespace OpcUaStackCore
{

  class DLLEXPORT ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ExtensibleParameterBase> SPtr;

		virtual SPtr factory(void) = 0;
		virtual void opcUaBinaryEncode(std::ostream& os) const = 0;
		virtual void opcUaBinaryDecode(std::istream& is) = 0;
	};

}

#endif