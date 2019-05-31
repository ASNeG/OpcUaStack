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

#ifndef __OpcUaStackServer_Merge_h__
#define __OpcUaStackServer_Merge_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MergeIf
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
		Merge(InformationModel::SPtr informationModel);
		~Merge(void);

		void informationModel(InformationModel::SPtr informationModel);
		bool add(InformationModel::SPtr informationModel, uint16_t namespaceIndex, MergeIf* mergeIf = NULL, uint32_t step = 10);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif
