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

#ifndef __OpcUaStackServer_Attribute_h__
#define __OpcUaStackServer_Attribute_h__

#include <boost/optional.hpp>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/RolePermissionType.h"

namespace OpcUaStackServer
{

	typedef enum
	{
		AttributeModel_Mandatory,
		AttributeModel_Optional
	} AttributeModel;


	class DLLEXPORT Attribute
	{
	  public:
		Attribute(void);
		virtual ~Attribute(void);

		virtual OpcUaStackCore::OpcUaUInt32 id(void) = 0;
		virtual std::string name(void) = 0;
		virtual std::string description(void);
		virtual OpcUaStackCore::OpcUaBuildInType type(void) = 0;
		virtual bool exist(void) = 0;
		virtual void exist(bool exist) = 0;
		virtual Attribute* clone(void) = 0;
		virtual void copyTo(Attribute* attribute) = 0;
		virtual bool equal(void) = 0;

		virtual void out(std::ostream& os) const = 0;
		friend std::ostream& operator<<(std::ostream& os, const Attribute& value) {
			value.out(os);
			return os;
		}

	  private:
	};

	
	template<typename DATATYPE>
	  class DLLEXPORT AttributeData
	  : public Attribute
	  {
	    public:
		  AttributeData(void) 
		  : Attribute()
		  , data_()
		  , exist_(false)
		  {}

		  AttributeData(const DATATYPE& data)
		  : Attribute()
		  , exist_(true)
		  {
			  data_ = data;
		  }
			 
		  virtual ~AttributeData(void)
		  {}

		  void reset(void)
		  {
			  exist_ = false;
		  }

		  void data(const DATATYPE& data) {
			  exist_ = true;
			  data_ = data;
		  }

		  DATATYPE& data(void) {
			  return data_;
		  }

		  boost::optional<DATATYPE&> data_optional(void) {
			  if (!exist_) return nullptr;
			  return data_;
		  }

		  bool exist(void) {
			  return exist_;
		  }

		  void exist(bool exist) {
			  exist_ = exist;
		  }

		  virtual void out(std::ostream& os) const {
		  //  os << data_;
		  }
		  friend std::ostream& operator<<(std::ostream& os, const AttributeData& attributeData) {
			os << attributeData.data_;
			return os;
		  }

	    private:
		  bool exist_;
		  DATATYPE data_;
	  };


    template<typename DATATYPE, OpcUaStackCore::OpcUaUInt32 id_, OpcUaStackCore::OpcUaBuildInType type_>
	  class DLLEXPORT AttributeMeta
	  : public AttributeData<DATATYPE>
	  {
	    public:
			AttributeMeta(void) 
			: AttributeData<DATATYPE>()
			{}

			AttributeMeta(const DATATYPE& data)
			: AttributeData<DATATYPE>(data)
			{}

			virtual ~AttributeMeta(void) 
			{}

			OpcUaStackCore::OpcUaUInt32 id(void) {
				return id_;
			}

			std::string name(void) {
				switch (id_)
				{
					case OpcUaStackCore::AttributeId_AccessLevel: return "AccessLevel";
					case OpcUaStackCore::AttributeId_ArrayDimensions: return "ArrayDimensions";
					case OpcUaStackCore::AttributeId_BrowseName: return "BrowseName";
					case OpcUaStackCore::AttributeId_ContainsNoLoops: return "ContainsNoLoops";
					case OpcUaStackCore::AttributeId_DataType: return "DataType";
					case OpcUaStackCore::AttributeId_Description: return "Description";
					case OpcUaStackCore::AttributeId_DisplayName: return "DisplayName";
					case OpcUaStackCore::AttributeId_EventNotifier: return "EventNotifier";
					case OpcUaStackCore::AttributeId_Executable: return "Executable";
					case OpcUaStackCore::AttributeId_Historizing: return "Historizing";
					case OpcUaStackCore::AttributeId_InverseName: return "InverseName";
					case OpcUaStackCore::AttributeId_IsAbstract: return "IsAbstrace";
					case OpcUaStackCore::AttributeId_MinimumSamplingInterval: return "MinimumSamplingInterval";
					case OpcUaStackCore::AttributeId_NodeClass: return "NodeClass";
					case OpcUaStackCore::AttributeId_NodeId: return "NodeId";
					case OpcUaStackCore::AttributeId_Symmetric: return "Symmetric";
					case OpcUaStackCore::AttributeId_UserAccessLevel: return "UserAccessLevel";
					case OpcUaStackCore::AttributeId_UserExecutable: return "UserExecutable";
					case OpcUaStackCore::AttributeId_UserWriteMask: return "UserWriteMask";
					case OpcUaStackCore::AttributeId_Value: return "Value";
					case OpcUaStackCore::AttributeId_ValueRank: return "ValueRank";
					case OpcUaStackCore::AttributeId_WriteMask: return "WriteMask";
					case OpcUaStackCore::AttributeId_DataTypeDefinition: return "DataTypeDefinition";
					case OpcUaStackCore::AttributeId_RolePermissions: return "RolePermissions";
					case OpcUaStackCore::AttributeId_UserRolePermissions: return "UserRolePermissions";
					case OpcUaStackCore::AttributeId_AccessRestrictions: return "AccessRestrictions";
					case OpcUaStackCore::AttributeId_AccessLevelEx: return "AccessLevelEx";
					default: return "Unknown";
				}
			}

			OpcUaStackCore::OpcUaBuildInType type(void) {
				return type_;
			}

			Attribute* clone(void) {
				Attribute* clone = new AttributeMeta<DATATYPE, id_, type_>();
				copyTo(clone);
				return clone;
			}

			void copyTo(Attribute* attribute) {
				AttributeMeta<DATATYPE, id_, type_>* attributeMeta;
				attributeMeta = reinterpret_cast<AttributeMeta<DATATYPE, id_, type_>*>(attribute);
				if (this->exist()) attributeMeta->data(this->data());
			}

			bool equal(void) {
				// FIXME:
				return true;
			}
	  };

	  typedef AttributeMeta<OpcUaStackCore::OpcUaByte, OpcUaStackCore::AttributeId_AccessLevel, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt32> AccessLevelAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaNodeId, OpcUaStackCore::AttributeId_NodeId, OpcUaStackCore::OpcUaBuildInType_OpcUaNodeId> NodeIdAttribute;
	  typedef AttributeMeta<OpcUaStackCore::NodeClass::Enum, OpcUaStackCore::AttributeId_NodeClass, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt32> NodeClassAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaQualifiedName, OpcUaStackCore::AttributeId_BrowseName, OpcUaStackCore::OpcUaBuildInType_OpcUaQualifiedName> BrowseNameAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaLocalizedText, OpcUaStackCore::AttributeId_DisplayName, OpcUaStackCore::OpcUaBuildInType_OpcUaLocalizedText> DisplayNameAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaLocalizedText, OpcUaStackCore::AttributeId_Description, OpcUaStackCore::OpcUaBuildInType_OpcUaLocalizedText> DescriptionAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaUInt32, OpcUaStackCore::AttributeId_WriteMask, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt32> WriteMaskAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaUInt32, OpcUaStackCore::AttributeId_UserWriteMask, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt32> UserWriteMaskAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaBoolean, OpcUaStackCore::AttributeId_IsAbstract, OpcUaStackCore::OpcUaBuildInType_OpcUaBoolean> IsAbstractAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaBoolean, OpcUaStackCore::AttributeId_Symmetric, OpcUaStackCore::OpcUaBuildInType_OpcUaBoolean> SymmetricAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaLocalizedText, OpcUaStackCore::AttributeId_InverseName, OpcUaStackCore::OpcUaBuildInType_OpcUaLocalizedText> InverseNameAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaBoolean, OpcUaStackCore::AttributeId_ContainsNoLoops, OpcUaStackCore::OpcUaBuildInType_OpcUaBoolean> ContainsNoLoopsAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaByte, OpcUaStackCore::AttributeId_EventNotifier, OpcUaStackCore::OpcUaBuildInType_OpcUaByte> EventNotifierAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaDataValue, OpcUaStackCore::AttributeId_Value, OpcUaStackCore::OpcUaBuildInType_OpcUaDataValue> ValueAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaInt32, OpcUaStackCore::AttributeId_ValueRank, OpcUaStackCore::OpcUaBuildInType_OpcUaInt32> ValueRankAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaUInt32Array, OpcUaStackCore::AttributeId_ArrayDimensions, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt32> ArrayDimensionsAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaDouble, OpcUaStackCore::AttributeId_MinimumSamplingInterval, OpcUaStackCore::OpcUaBuildInType_OpcUaDouble> MinimumSamplingIntervalAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaBoolean, OpcUaStackCore::AttributeId_Historizing, OpcUaStackCore::OpcUaBuildInType_OpcUaBoolean> HistorizingAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaNodeId, OpcUaStackCore::AttributeId_DataType, OpcUaStackCore::OpcUaBuildInType_OpcUaNodeId> DataTypeAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaBoolean, OpcUaStackCore::AttributeId_Executable, OpcUaStackCore::OpcUaBuildInType_OpcUaBoolean> ExecutableAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaBoolean, OpcUaStackCore::AttributeId_UserExecutable, OpcUaStackCore::OpcUaBuildInType_OpcUaBoolean> UserExecutableAttribute;
	  typedef AttributeMeta<OpcUaStackCore::OpcUaByte, OpcUaStackCore::AttributeId_UserAccessLevel, OpcUaStackCore::OpcUaBuildInType_OpcUaByte> UserAccessLevelAttribute;
	  typedef AttributeMeta<OpcUaStackCore::DataTypeDefinition, OpcUaStackCore::AttributeId_DataTypeDefinition, OpcUaStackCore::OpcUaBuildInType_OpcUaExtensionObject> DataTypeDefinitionAttribute;
	  typedef AttributeMeta<OpcUaStackCore::RolePermissionTypeArray, OpcUaStackCore::AttributeId_RolePermissions, OpcUaStackCore::OpcUaBuildInType_OpcUaExtensionObject> RolePermissionsAttribute;
	  typedef AttributeMeta<OpcUaStackCore::RolePermissionTypeArray, OpcUaStackCore::AttributeId_UserRolePermissions, OpcUaStackCore::OpcUaBuildInType_OpcUaExtensionObject> UserRolePermissionsAttribute;
	  typedef AttributeMeta<OpcUaStackCore::AccessRestrictionType, OpcUaStackCore::AttributeId_AccessRestrictions, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt16> AccessRestrictionsAttribute;
	  typedef AttributeMeta<OpcUaStackCore::AccessLevelExType, OpcUaStackCore::AttributeId_AccessLevelEx, OpcUaStackCore::OpcUaBuildInType_OpcUaUInt32> AccessLevelExAttribute;

}

#endif
