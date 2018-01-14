/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BaseClass_h__
#define __OpcUaStackCore_BaseClass_h__

#include "boost/shared_ptr.hpp"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BaseClass
	{
	  public:
		typedef boost::shared_ptr<BaseClass> SPtr;

		BaseClass(void) {}
		virtual ~BaseClass(void) {}
	};

	class DLLEXPORT BaseClassArray
	: public OpcUaArray<BaseClass::SPtr, SPtrTypeCoder<BaseClass> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BaseClassArray> SPtr;
	};



}

#endif
