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

#ifndef __OpcUaStackCore_DataTypeField_h__
#define __OpcUaStackCore_DataTypeField_h__

#include <boost/shared_ptr.hpp>

#include <vector>

#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackServer
{

/**
 * This function manages data type field information
 */
class DLLEXPORT DataTypeField
{
  public:
	typedef boost::shared_ptr<DataTypeField> SPtr;
	typedef std::vector<DataTypeField::SPtr> Vec;

	typedef enum {
		NumberType,				//!< number
		BuildInType,			//!< build in type
		BuildInArrayType,		//!< build in array type
		StructureType,			//!< structure type
		StructureArrayType,		//!< structure array type
		EnumerationType,		//!< enumeration type
		EnumerationArrayType,	//!< enumeration array type
	} Type;

	/**
	 * constructor
	 */
	DataTypeField(void);

	/**
	 * destructor
	 */
	~DataTypeField(void);

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
	 * @param[in] variableName			variable name
	 */
	void variableName(const std::string& variableName);

	/**
	 * Getter function
	 *
	 * @return variable name
	 */
	std::string& variableName(void);

	/**
	 * Setter function
	 *
	 * @param[in] parameterName			parameter name
	 */
	void parameterName(const std::string& parameterName);

	/**
	 * Getter function
	 *
	 * @return parameter name
	 */
	std::string& parameterName(void);

	/**
	 * Setter function
	 *
	 * @param[in] variableType			variable type
	 */
	void variableType(const std::string& variableType);

	/**
	 * Getter function
	 *
	 * @return variable type
	 */
	std::string& variableType(void);

	/**
	 * Setter function
	 *
	 * @param[in] variableTypeWithoutPtr variable type without pointer
	 */
	void variableTypeWithoutPtr(const std::string& variableTypeWithoutPtr);

	/**
	 * Getter function
	 *
	 * @return variable type without pointer
	 */
	std::string& variableTypeWithoutPtr(void);


	/**
	 * Setter function
	 *
	 * @param[in] description			variable description
	 */
	void description(const std::string& description);

	/**
	 * Getter function
	 *
	 * @return variable description
	 */
	std::string& description(void);

	/**
	 * Setter function
	 *
	 * @param[in] includePath			include path
	 */
	void includePath(const std::string& includePath);

	/**
	 * Getter function
	 *
	 * @return include path
	 */
	std::string& includePath(void);

	/**
	 * Setter function
	 *
	 * @param[in] arrayElementName		opc ua array element name
	 */
	void arrayElementName(const std::string& arrayElementName);

	/**
	 * Getter function
	 *
	 * @return opc ua array element name
	 */
	std::string& arrayElementName(void);


	/**
	 * Setter function
	 *
	 * @param[in] type					type
	 */
	void type(Type type);

	/**
	 * Getter function
	 *
	 * @return type
	 */
	Type type(void);

	/**
	 * Setter function
	 *
	 * @param[in] array					array flag
	 */
	void array(bool array);

	/**
	 * Getter function
	 *
	 * @return array flag
	 */
	bool array(void);

	/**
	 * Setter function
	 *
	 * @param[in] smartpointer			smartpointer flag
	 */
	void smartpointer(bool smartpointer);

	/**
	 * Getter function
	 *
	 * @return smartpointer flag
	 */
	bool smartpointer(void);

	/**
	 * Setter function
	 *
	 * @param[in] number				number flag
	 */
	void number(bool number);

	/**
	 * Getter function
	 *
	 * @return number flag
	 */
	bool number(void);

	/**
	 * Setter function
	 *
	 * @param[in] boolean				boolean flag
	 */
	void boolean(bool boolean);

	/**
	 * Getter function
	 *
	 * @return boolean flag
	 */
	bool boolean(void);

	/**
	 * Setter function
	 *
	 * @param[in] byte					byte flag
	 */
	void byte(bool byte);

	/**
	 * Getter function
	 *
	 * @return byte flag
	 */
	bool byte(void);

	/**
	 * Setter function
	 *
	 * @param[in] enumeration			enumeration flag
	 */
	void enumeration(bool enumeration);

	/**
	 * Getter function
	 *
	 * @return enumeration flag
	 */
	bool enumeration(void);

	/**
	 * Setter function
	 *
	 * @param[in] structure				structure flag
	 */
	void structure(bool structure);

	/**
	 * Getter function
	 *
	 * @return structure flag
	 */
	bool structure(void);

	/**
	 * Setter function
	 *
	 * @param[in] optional				optional flag
	 */
	void optional(bool optional);

	/**
	 * Getter function
	 *
	 * @return optional flag
	 */
	bool optional(void);

  private:
	std::string name_;						//!< field name
	std::string variableName_;				//!< variable name
	std::string parameterName_;				//!< parameter name
	std::string variableType_;				//!< variable type
	std::string variableTypeWithoutPtr_;	//!< variable type without pointer
	std::string description_;				//!< variable description
	std::string includePath_;				//!< include path
	std::string arrayElementName_;			//!< opc ua array element name
	Type type_;								//!< type
	bool array_;							//!< array flag
	bool smartpointer_;						//!< smartpointer flag
	bool number_;							//!< number flag
	bool boolean_;							//!< boolean flag
	bool byte_;								//!< byte flag
	bool enumeration_;						//!< enumeration flag
	bool structure_;						//!< structure flag
	bool optional_;							//!< optional flag

};

}

#endif
