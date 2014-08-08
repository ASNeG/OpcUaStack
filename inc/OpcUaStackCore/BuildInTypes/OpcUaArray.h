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
		bool set(const T& valueSPtr);
		bool push_back(const T& value);
		bool get(uint32_t pos, T& value);
		bool get(T& value);

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

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// class OpcUaArray
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	template<typename T>
	class OpcUaArray<boost::shared_ptr<T> >
	{
	  public:
		OpcUaArray(uint32_t maxArrayLen = 1);
		~OpcUaArray(void); 

		void resize(uint32_t maxArrayLen);
		uint32_t size(void);
		uint32_t maxSize(void);
		void clear(void);

		bool set(uint32_t pos, const boost::shared_ptr<T> value);
		bool set(const boost::shared_ptr<T> valueSPtr);
		bool push_back(const boost::shared_ptr<T> value);
		bool get(uint32_t pos, boost::shared_ptr<T>& value);
		bool get(boost::shared_ptr<T>& value);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		void initArray(void);
		void clearArray(void);

		uint32_t maxArrayLen_;
		uint32_t actArrayLen_;

		typename boost::shared_ptr<T>* valueArray_;
		typename boost::shared_ptr<T> value_;
	};

	template<typename T>
	OpcUaArray<boost::shared_ptr<T> >::OpcUaArray(uint32_t maxArrayLen)
	: maxArrayLen_(maxArrayLen)
	, actArrayLen_(0)
	{
		initArray();
	}

	template<typename T>
	OpcUaArray<boost::shared_ptr<T> >::~OpcUaArray(void)
	{
		clearArray();
	}

	template<typename T>
	void
	OpcUaArray<boost::shared_ptr<T> >::initArray(void)
	{
		if (maxArrayLen_ == 1) {
			valueArray_ = &value_;
		}
		else {
			valueArray_ = new boost::shared_ptr<T>[maxArrayLen_];
		}
		actArrayLen_ = 0;
	}

	template<typename T>
	void
	OpcUaArray<boost::shared_ptr<T> >::clearArray(void)
	{
		if (maxArrayLen_ != 1) {
			delete [] valueArray_;
		}
		valueArray_ = NULL;

		actArrayLen_ = 0;
		maxArrayLen_ = 1;
	}

	template<typename T>
	void
	OpcUaArray<boost::shared_ptr<T> >::resize(uint32_t maxArrayLen)
	{
		clearArray();
		maxArrayLen_ = maxArrayLen;
		initArray();
	}

	template<typename T>
	uint32_t
	OpcUaArray<boost::shared_ptr<T> >::size(void)
	{
		return actArrayLen_;
	}

	template<typename T>
	uint32_t
	OpcUaArray<boost::shared_ptr<T> >::maxSize(void)
	{
		return maxArrayLen_;
	}

	template<typename T>
	void
	OpcUaArray<boost::shared_ptr<T> >::clear(void)
	{
		clearArray();
		initArray();
	}

	template<typename T>
	bool
	OpcUaArray<boost::shared_ptr<T> >::set(uint32_t pos, const boost::shared_ptr<T> value)
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

	template<typename T>
	bool
	OpcUaArray<boost::shared_ptr<T> >::set(const boost::shared_ptr<T> value)
	{
		return set(0, value);
	}

	template<typename T>
	bool
	OpcUaArray<boost::shared_ptr<T> >::push_back(const boost::shared_ptr<T> value)
	{
		return set(actArrayLen_, value);
	}

	template<typename T>
	bool 
	OpcUaArray<boost::shared_ptr<T> >::get(uint32_t pos, boost::shared_ptr<T>& value)
	{
		if (pos >= actArrayLen_) {
			return false;
		}

		value = valueArray_[pos];
		return true;
	}

	template<typename T>
	bool 
	OpcUaArray<boost::shared_ptr<T> >::get(boost::shared_ptr<T>& value)
	{
		return get(0, value);
	}
		
	template<typename T>
	void 
	OpcUaArray<boost::shared_ptr<T> >::opcUaBinaryEncode(std::ostream& os) const
	{
		int32_t actArrayLen;
		actArrayLen = actArrayLen_;
		ByteOrder<uint32_t>::opcUaBinaryEncodeNumber(os, actArrayLen_);

		if (actArrayLen_ <= 0) {
			return;
		}

		for (uint32_t idx=0; idx<actArrayLen_; idx++) {
			valueArray_[idx]->opcUaBinaryEncode(os);
		}
	}
	
	template<typename T>
	void 
	OpcUaArray<boost::shared_ptr<T> >::opcUaBinaryDecode(std::istream& is)
	{
		int32_t arrayLength = 0;
		ByteOrder<uint32_t>::opcUaBinaryDecodeNumber(is, arrayLength);
		if (arrayLength <= 0) {
			return;
		}

		resize(arrayLength);
		for (int32_t idx=0; idx<arrayLength; idx++) {
			boost::shared_ptr<T> value;
			value = T::construct();
			value->opcUaBinaryDecode(is);
			push_back(value);
		}
	}

}

#endif
