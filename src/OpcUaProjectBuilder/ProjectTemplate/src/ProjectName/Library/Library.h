/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __ProjectName_Library_h__
#define __ProjectName_Library_h__

#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace ProjectName
{

	class Library
	: public OpcUaStackServer::ApplicationIf
	{
	  public:
		Library(void);
		virtual ~Library(void);

		//- ApplicationIf -----------------------------------------------------
		bool startup(void) override;
		bool shutdown(void) override;
		std::string version(void) override;
		std::string gitCommit(void) override;
		std::string gitBranch(void) override;
		//- ApplicationIf -----------------------------------------------------

	  private:
	};

}

#endif
