/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_XmlnsGuard_h__
#define __OpcUaStackCore_XmlnsGuard_h__

#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <map>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"

namespace OpcUaStackCore
{

	class DLLEXPORT XmlnsGuard
	{
	  public:
		/**
		 * Encoder
		 *
		 * @parameter[in] nodeSetElement			node set element with namespace information
		 * @parameter[in] xmlns						actual namespace info
		 */
		XmlnsGuard(boost::property_tree::ptree& nodeSetElement, Xmlns& xmlns);

		/**
		 * Decoder
		 */
		~XmlnsGuard(void);

	  private:
		Xmlns* xmlnsAct_;
		Xmlns xmlnsCopy_;
	};
}

#endif
