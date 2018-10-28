/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_MessageSecurityMode_h__
#define __OpcUaStackCore_MessageSecurityMode_h__


namespace OpcUaStackCore
{
	typedef enum
	{
		Invalid,				//!< The message security mode is invalid. This value is the default
								//!< value to avoid an accidental choice of no security is applied.
								//!< This choice will always be rejected.
		None,					//!< No security is applied
		Sign,					//!< All messages are signed but not encrypted
		SignAndEncrypt			//!< All messages are signed and encrypted
	} MessageSecurityMode;
}

#endif
