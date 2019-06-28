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

#ifndef __OpcUaStackCore_OpcUaExtensibleParameter_h__
#define __OpcUaStackCore_OpcUaExtensibleParameter_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaExtensibleParameter
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensibleParameter> SPtr;

		OpcUaExtensibleParameter(void);
		~OpcUaExtensibleParameter(void);

		void clear(void);
		OpcUaNodeId& parameterTypeId(void);
		ExtensionObjectBase::SPtr& eoSPtr(void);
		bool exist(void) const;

        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
		virtual std::string namespaceName(void) override;
		virtual std::string typeName(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual void opcUaBinaryEncode(std::ostream& os) const override;
        virtual void opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        virtual bool isNull(void) const override;
        //- ExtensionObjectBase -----------------------------------------------

        void reset(void);
        void copyTo(OpcUaExtensibleParameter& value);
        bool operator==(const OpcUaExtensibleParameter& value) const;
        bool operator!=(const OpcUaExtensibleParameter& value) const;
        OpcUaExtensibleParameter& operator=(const OpcUaExtensibleParameter& value);

		template<typename T>
		   typename T::SPtr parameter(OpcUaUInt32 parameterTypeId) {
				parameterTypeId_.set(parameterTypeId);
				return parameter<T>();
			}
		template<typename T>
		   typename T::SPtr parameter(const OpcUaNodeId& typeNodeId) {
				parameterTypeId_ = typeNodeId;
				return parameter<T>();
			}
		template<typename T>
		   typename T::SPtr parameter(void) {
			   if (eoSPtr_.get() != NULL) {
				   return boost::static_pointer_cast<T>(eoSPtr_);
			   }

			   eoSPtr_ = OpcUaExtensionObject::findElement(parameterTypeId_);
			   if (eoSPtr_.get() == NULL) {
				   typename T::SPtr epSPtr;
				   return epSPtr;
			   }

			   typename T::SPtr epSPtr = constructSPtr<T>();
			   eoSPtr_ = epSPtr;
			   return epSPtr;
		   }

	  protected:
	      bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
	      bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		OpcUaExtensibleParameter(const OpcUaExtensibleParameter& value);

		OpcUaNodeId parameterTypeId_;
		ExtensionObjectBase::SPtr eoSPtr_;
	};

	class DLLEXPORT OpcUaExtensibleParameterArray
	: public OpcUaArray<OpcUaExtensibleParameter::SPtr, SPtrTypeCoder<OpcUaExtensibleParameter> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaExtensibleParameterArray> SPtr;
	};

}

#endif
