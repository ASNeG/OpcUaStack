#ifndef __OpcUaServerApplicationDemo_DemoLibrary_h__
#define __OpcUaServerApplicationDemo_DemoLibrary_h__

#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServerApplicationDemo
{

	class DemoLibrary
	: public ApplicationIf
	{
	  public:
		DemoLibrary(void);
		virtual ~DemoLibrary(void);

		//- ApplicationIf -----------------------------------------------------
		virtual bool startup(void);
		virtual bool shutdown(void);
		//- ApplicationIf -----------------------------------------------------

	  private:
		bool getNamespaceInfo(void);
		void readValue(ApplicationReadContext& applicationReadContext);
		void writeValue(void);

		OpcUaDataValue::SPtr createDataValue(void);
		bool createValueMap(void);

		uint32_t namespaceIndex_;
		Callback readCallback_;
		Callback writeCallback_;

		typedef std::map<OpcUaNodeId,OpcUaDataValue::SPtr> ValueMap;
		ValueMap valueMap_;
	};

}

#endif
