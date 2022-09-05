/*
   Copyright 2018-2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EnumTypeField_h__
#define __OpcUaStackCore_EnumTypeField_h__

#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackServer
{

/**
 * This function manages enum type field information
 */
class DLLEXPORT EnumTypeField
{
  public:
	typedef boost::shared_ptr<EnumTypeField> SPtr;
	typedef std::vector<EnumTypeField::SPtr> Vec;

	/**
	 * constructor
	 */
	EnumTypeField(void);

	/**
	 * destructor
	 */
	~EnumTypeField(void);

	/**
	 * Setter function
	 *
	 * @param[in] name					field name
	 */
	void name(const std::string& name);

	/**
	 * Getter function
	 *
	 * @return field name
	 */
	std::string& name(void);

	/**
	 * Setter function
	 *
	 * @param[in] value
	 */
	void value(int32_t value);

	/**
	 * Getter function
	 *
	 * @return enum value
	 */
	int32_t value(void);

	/**
	 * Setter function
	 *
	 * @param[in] description	field description
	 */
	void description(const std::string& description);

	/**
	 * Getter function
	 *
	 * @return field description
	 */
	std::string& description(void);

  private:
	std::string name_;						//!< enum field name
	int32_t value_;							//!< enum value
	std::string description_;				//!< enum description
};

}

#endif
