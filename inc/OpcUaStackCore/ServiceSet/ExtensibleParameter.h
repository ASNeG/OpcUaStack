#ifndef __OpcUaStackCore_ExtensibleParameter_h__
#define __OpcUaStackCore_ExtensibleParameter_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ExtensibleParameterBase> SPtr;

		virtual SPtr factory(void) = 0;
		virtual void opcUaBinaryEncode(std::ostream& os) const = 0;
		virtual void opcUaBinaryDecode(std::istream& is) = 0;
	};

	class DLLEXPORT AnonymousIdentityToken : public  ObjectPool<AnonymousIdentityToken>, public ExtensibleParameterBase
	{
	  public:
		AnonymousIdentityToken(void);
		~AnonymousIdentityToken(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaString policyId_;
	};

	class DLLEXPORT UserNameIdentityToken : public  ObjectPool<UserNameIdentityToken>, public ExtensibleParameterBase
	{
	  public:
		UserNameIdentityToken(void);
		~UserNameIdentityToken(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;
		void userName(const std::string& userName);
		std::string userName(void) const;
		void password(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void password(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void encryptionAlgorithm(const std::string& encryptionAlgorithm);
		std::string encryptionAlgorithm(void) const;

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaString policyId_;
		OpcUaString userName_;
		OpcUaByteString password_;
		OpcUaString encryptionAlgorithm_;
	};

	class DLLEXPORT ExtensibleParameter : public  ObjectPool<ExtensibleParameter>
	{
	  public:
		ExtensibleParameter(void);
		~ExtensibleParameter(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		static bool init_;
		OpcUaNodeId parameterTypeId_;
	};

}

#endif