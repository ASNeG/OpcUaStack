#ifndef __OpcUaStackCore_OpcUaArray_h__
#define __OpcUaStackCore_OpcUaArray_h__


#include "boost/shared_ptr.hpp"
#include <stdint.h>
#include <iostream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/ByteOrder.h"

namespace OpcUaStackCore
{

	template <typename T>
	class NumberTypeCoder
	{
	  public:
		  static void opcUaBinaryEncode(std::ostream& os, T& value) 
		  {
			  ByteOrder<T>::opcUaBinaryEncodeNumber(os, value);
		  }

		  static void opcUaBinaryDecode(std::istream& is, T& value) 
		  {
			  ByteOrder<T>::opcUaBinaryDecodeNumber(is, value);
		  }

		  static T copy(T& sourceValue, T& destValue)
		  {
			  destValue = sourceValue;
			  return sourceValue;
		  }
	};

	template <typename T>
	class ClassTypeCoder
	{
	  public:
		  static void opcUaBinaryEncode(std::ostream& os, T& value) 
		  {
			  value.opcUaBinaryEncode(os);
		  }

		  static void opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  value.opcUaBinaryDecode(is);
		  }

		  static T& copy(T& sourceValue, T& destValue)
		  {
			  sourceValue.copyTo(destValue);
			  return destValue;
		  }
	};

	template <typename T>
	class EnumTypeCoder
	{
	  public:
		  static void opcUaBinaryEncode(std::ostream& os, T& value) 
		  {
			  int32_t v = value;
			  ByteOrder<int32_t>::opcUaBinaryEncodeNumber(os, v);
		  }

		  static void opcUaBinaryDecode(std::istream& is, T& value)
		  {
			  int32_t v = 0;
			  ByteOrder<int32_t>::opcUaBinaryDecodeNumber(is, v);
			  value = (T)v;
		  }

		  static T copy(T& sourceValue, T& destValue)
		  {
			  destValue = sourceValue;
			  return sourceValue;
		  }
	};

	template <typename T>
	class SPtrTypeCoder
	{
	  public:
		  static void opcUaBinaryEncode(std::ostream& os, boost::shared_ptr<T>& value) 
		  {
			  value->opcUaBinaryEncode(os);
		  }

		  static void opcUaBinaryDecode(std::istream& is, boost::shared_ptr<T>& value)
		  {
			  value = T::construct();
			  value->opcUaBinaryDecode(is);
		  }

		  static boost::shared_ptr<T> copy( boost::shared_ptr<T>& sourceValue, boost::shared_ptr<T>& destValue)
		  {
			  destValue = T::construct();
			  sourceValue->copyTo(*destValue);
			  return destValue;
		  }
	};


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class OpcUaArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename T, typename CODER = ClassTypeCoder<T> >
	class OpcUaArray 
	{
	  public:
		OpcUaArray(uint32_t maxArrayLen = 1);
		~OpcUaArray(void); 

		void resize(uint32_t maxArrayLen);
		uint32_t size(void);
		uint32_t maxSize(void);
		void clear(void);

		bool set(uint32_t pos, const T& value);
		bool set(const T& value);
		bool push_back(const T& value);
		bool get(uint32_t pos, T& value);
		bool get(T& value);

		void copyTo(OpcUaArray<T, CODER>& array);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		void initArray(void);
		void clearArray(void);

		uint32_t maxArrayLen_;
		uint32_t actArrayLen_;

		T* valueArray_;
		T value_;
	};

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::OpcUaArray(uint32_t maxArrayLen)
	: maxArrayLen_(maxArrayLen)
	, actArrayLen_(0)
	{
		initArray();
	}

	template<typename T, typename CODER>
	OpcUaArray<T, CODER>::~OpcUaArray(void)
	{
		clearArray();
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::initArray(void)
	{
		if (maxArrayLen_ == 1) {
			valueArray_ = &value_;
		}
		else {
			valueArray_ = new T[maxArrayLen_];
		}
		actArrayLen_ = 0;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::clearArray(void)
	{
		if (maxArrayLen_ != 1) {
			delete [] valueArray_;
		}
		valueArray_ = NULL;

		actArrayLen_ = 0;
		maxArrayLen_ = 1;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::resize(uint32_t maxArrayLen)
	{
		clearArray();
		maxArrayLen_ = maxArrayLen;
		initArray();
	}

	template<typename T, typename CODER>
	uint32_t
	OpcUaArray<T, CODER>::size(void)
	{
		return actArrayLen_;
	}

	template<typename T, typename CODER>
	uint32_t
	OpcUaArray<T, CODER>::maxSize(void)
	{
		return maxArrayLen_;
	}

	template<typename T, typename CODER>
	void
	OpcUaArray<T, CODER>::clear(void)
	{
		clearArray();
		initArray();
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::set(uint32_t pos, const T& value)
	{
		if (pos >= maxArrayLen_) {
			return false;
		}
		valueArray_[pos] = value;

		if (pos+1 > actArrayLen_) {
			actArrayLen_ = pos + 1;
		}
		return true;
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::set(const T& value)
	{
		return set(0, value);
	}

	template<typename T, typename CODER>
	bool
	OpcUaArray<T, CODER>::push_back(const T& value)
	{
		return set(actArrayLen_, value);
	}

	template<typename T, typename CODER>
	bool 
	OpcUaArray<T, CODER>::get(uint32_t pos, T& value)
	{
		if (pos >= actArrayLen_) {
			return false;
		}

		value = valueArray_[pos];
		return true;
	}

	template<typename T, typename CODER>
	bool 
	OpcUaArray<T, CODER>::get(T& value)
	{
		return get(0, value);
	}

	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::copyTo(OpcUaArray<T, CODER>& array)
	{
		if (actArrayLen_ == 0) return;
		array.resize(actArrayLen_);
		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			T destValue;
			CODER::copy(valueArray_[idx], destValue);
			array.set(idx, destValue);
		}
	}
		
	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::opcUaBinaryEncode(std::ostream& os) const
	{
		ByteOrder<uint32_t>::opcUaBinaryEncodeNumber(os, actArrayLen_);
		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			CODER::opcUaBinaryEncode(os, valueArray_[idx]);
		}
	}
	
	template<typename T, typename CODER>
	void 
	OpcUaArray<T, CODER>::opcUaBinaryDecode(std::istream& is)
	{
		int32_t arrayLength = 0;
		ByteOrder<int32_t>::opcUaBinaryDecodeNumber(is, arrayLength);
		if (arrayLength <= 0) {
			return;
		}

		resize(arrayLength);
		for (int32_t idx=0; idx<arrayLength; idx++) {
			T value;
			CODER::opcUaBinaryDecode(is, value);
			push_back(value);
		}
	}

}

#endif
