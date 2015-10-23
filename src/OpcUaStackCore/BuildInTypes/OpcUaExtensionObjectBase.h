/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ExtensionObjectBase_h__
#define __OpcUaStackCore_ExtensionObjectBase_h__

namespace OpcUaStackCore
{

    class DLLEXPORT ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<ExtensionObjectBase> BSPtr;

		ExtensionObjectBase(void) {}
		virtual ~ExtensionObjectBase(void) {}

		virtual BSPtr factory(void) = 0;
		virtual void opcUaBinaryEncode(std::ostream& os) const = 0;
		virtual void opcUaBinaryDecode(std::istream& is) = 0;
		virtual void copyTo(ExtensionObjectBase& extensionObjectBase) = 0;
		virtual bool equal(ExtensionObjectBase& extensionObjectBase) const = 0;
		virtual void out(std::ostream& os) = 0;
	};

}

#endif
