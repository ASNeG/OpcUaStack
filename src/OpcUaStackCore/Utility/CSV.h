/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaOpcUaStackCore_CSV_h__
#define __OpcUaOpcUaStackCore_CSV_h__

#include <boost/shared_ptr.hpp>
#include <vector>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaOpcUaStackCore
{

	class DLLEXPORT CSV
	{
	  public:
		typedef boost::shared_ptr<CSV> SPtr;
		typedef std::vector<std::string> Line;

		typedef enum
		{
			M_Read,
			M_Write
		} Mode;

		typedef enum
		{
			S_Ok,
			S_Error,
			S_EndOfFile
		} State;

		CSV(void);
		~CSV(void);

		void delimiter(const std::string& delimiter);
		bool open(const std::string& fileName, Mode mode);
		bool close(void);
		CSV::State readLine(Line& line);
		CSV::State writeLine(Line& line);
		uint32_t lineNumber(void);

	  private:
		uint32_t lineNumber_;

		std::string delimiter_;
		std::string fileName_;

		std::ifstream ifFile_;
		std::ofstream ofFile_;

	};

}

#endif
