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

#ifndef __OpcUaStackCore_Core_h__
#define __OpcUaStackCore_Core_h__

#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Core
	{
	  public:
		Core(void);
		~Core(void);

		void config(Config& config);
		Config& config(void);

		bool init(void);
		void cleanup(void);

	  private:
		void initExtensionObject(void);
		void cleanupExtensionObject(void);

		static bool init_;
		Config* config_;
	};

}

#endif
