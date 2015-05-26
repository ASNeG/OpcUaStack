#ifndef __OpcUaStackServer_Merge_h__
#define __OpcUaStackServer_Merge_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class MergeIf
	{
	  public:
		MergeIf(void) {}
		virtual ~MergeIf(void) {}

		virtual void handleMerge(uint32_t maxCount, uint32_t actCount) = 0;
	};

	class DLLEXPORT Merge
	{
	  public:
		typedef boost::shared_ptr<Merge> SPtr;

		Merge(void);
		~Merge(void);

		void informationModel(InformationModel::SPtr informationModel);
		bool add(InformationModel::SPtr informationModel, uint16_t namespaceIndex, MergeIf* mergeIf = NULL, uint32_t step = 10);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif
