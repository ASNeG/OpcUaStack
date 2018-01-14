/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Callback_h__
#define __OpcUaStackCore_Callback_h__

#include "OpcUaStackCore/Base/os.h"
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

namespace OpcUaStackCore
{

	class DLLEXPORT CallbackBase
	{
	  public:
	    CallbackBase(void);
	    virtual ~CallbackBase(void);

	    typedef boost::shared_ptr<CallbackBase> SPtr;

      private:
    };


	template<typename R>
	  class CallbackParameter0
	  : public CallbackBase
	  {
		public:
		  CallbackParameter0(void);
		  virtual R operator()(void) const = 0;
	  };


	template<typename R, typename A1>
	  class CallbackParameter1
	  : public CallbackBase
	  {
  		public:
		  CallbackParameter1(void);
  		  virtual R operator()(A1 a1) const = 0;
	  };


	template<typename R, typename A1, typename A2>
      class CallbackParameter2
      : public CallbackBase
      {
		public:
    	  CallbackParameter2(void);
          virtual R operator()(A1 a1, A2 a2) const = 0;
      };


	template<typename R, typename A1, typename A2, typename A3>
      class CallbackParameter3
      : public CallbackBase
      {
		public:
    	  CallbackParameter3(void);
          virtual R operator()(A1 a1, A2 a2, A3 a3) const = 0;
      };


	template<typename R, typename A1, typename A2, typename A3, typename A4>
      class CallbackParameter4
      : public CallbackBase
      {
        public:
    	  CallbackParameter4(void);
    	  virtual R operator()(A1 a1, A2 a2, A3 a3,A4 a4) const = 0;
      };


 
	template<typename R, typename F>
      class CallbackHandler0
      : public CallbackParameter0<R>
      {
        public:
	      typedef boost::_bi::bind_t<R,boost::_mfi::mf0<R,F>,boost::_bi::list1<boost::_bi::value<F*> > > HANDLER;
	      CallbackHandler0(HANDLER handler);
	      virtual R operator()(void) const;

		private:
	      HANDLER handler_;
	  };


	template<typename R, typename F, typename V1>
      class CallbackHandler0_1
      : public CallbackParameter0<R>
      {
        public:
  	      typedef boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,V1>,boost::_bi::list2<boost::_bi::value<F*>,
  	    		  boost::_bi::value<V1> > > HANDLER;
  	      CallbackHandler0_1(HANDLER handler);
  	      virtual R operator()(void) const;

        private:
  	      HANDLER handler_;
      };

    template<typename R, typename F, typename V1, typename V2>
      class CallbackHandler0_2
      : public CallbackParameter0<R>
      {
        public:
          typedef boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,V2>,boost::_bi::list3<boost::_bi::value<F*>,
    	      	  boost::_bi::value<V1>,
    	          boost::_bi::value<V2> > > HANDLER;
    	  CallbackHandler0_2(HANDLER handler);
    	  virtual R operator()(void) const;

        private:
    	  HANDLER handler_;
      };

    template<typename R, typename F, typename V1, typename V2, typename V3>
     class CallbackHandler0_3
     : public CallbackParameter0<R>
     {
       public:
      	 typedef boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,V3>,boost::_bi::list4<boost::_bi::value<F*>,
      	  		 boost::_bi::value<V1>,
      	  		 boost::_bi::value<V2>,
      	   	     boost::_bi::value<V3> > > HANDLER;
      	 CallbackHandler0_3(HANDLER handler);
      	 virtual R operator()(void) const;

       private:
      	 HANDLER handler_;
     };


	template<typename R, typename F, typename V1, typename V2, typename V3, typename V4>
      class CallbackHandler0_4
      : public CallbackParameter0<R>
      {
       public:
         typedef boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,V4>,boost::_bi::list5<boost::_bi::value<F*>,
       	 		 boost::_bi::value<V1>,
       	  		 boost::_bi::value<V2>,
       	   	     boost::_bi::value<V3>,
       	   	     boost::_bi::value<V4> > > HANDLER;
       	 CallbackHandler0_4(HANDLER handler);
       	 virtual R operator()(void) const;

        private:
       	 HANDLER handler_;
      };


	template<typename R, typename F, typename A1>
      class CallbackHandler1
      : public CallbackParameter1<R,A1>
      {
        public:
	      typedef boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,A1>,boost::_bi::list2<boost::_bi::value<F*>, boost::arg<1> > > HANDLER;
	      CallbackHandler1(HANDLER handler);
	      virtual R operator()(A1 a1) const;

		private:
	      HANDLER handler_;
      };


	template<typename R, typename F, typename V1, typename A1>
      class CallbackHandler1_1
      : public CallbackParameter1<R,A1>
      {
        public:
    	  typedef boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,A1>,boost::_bi::list3<boost::_bi::value<F*>,
    	 	      boost::_bi::value<V1>,
    	    	  boost::arg<1> > > HANDLER;
    	  CallbackHandler1_1(HANDLER handler);
    	  virtual R operator()(A1 a1) const;

        private:
    	  HANDLER handler_;
      };


	template<typename R, typename F, typename V1, typename V2, typename A1>
      class CallbackHandler1_2
      : public CallbackParameter1<R,A1>
      {
        public:
      	  typedef boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,A1>,boost::_bi::list4<boost::_bi::value<F*>,
      			  boost::_bi::value<V1>,
      	  		  boost::_bi::value<V2>,
      	    	  boost::arg<1> > > HANDLER;
      	  CallbackHandler1_2(HANDLER handler);
      	  virtual R operator()(A1 a1) const;

        private:
      	  HANDLER handler_;
      };


	template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
      class CallbackHandler1_3
      : public CallbackParameter1<R,A1>
      {
        public:
        	typedef boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,A1>,boost::_bi::list5<boost::_bi::value<F*>,
        			boost::_bi::value<V1>,
        	  		boost::_bi::value<V2>,
        	  		boost::_bi::value<V3>,
        	    	boost::arg<1> > > HANDLER;
        	CallbackHandler1_3(HANDLER handler);
        	virtual R operator()(A1 a1) const;

        private:
        	HANDLER handler_;
      };


	template<typename R, typename F, typename A1, typename A2>
      class CallbackHandler2
      : public CallbackParameter2<R,A1,A2>
      {
        public:
  	      typedef boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,A1,A2>,boost::_bi::list3<boost::_bi::value<F*>,
  		    	  boost::arg<1>, boost::arg<2> > > HANDLER;
  	      CallbackHandler2(HANDLER handler);
  	      virtual R operator()(A1 a1,A2 a2) const;

        private:
  	      HANDLER handler_;
      };


	template<typename R, typename F, typename V1, typename A1, typename A2>
      class CallbackHandler2_1
      : public CallbackParameter2<R,A1,A2>
      {
        public:
    	  typedef boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,A1,A2>,boost::_bi::list4<boost::_bi::value<F*>,
    	          boost::_bi::value<V1>,
    		  	  boost::arg<1>,
    		  	  boost::arg<2> > > HANDLER;
    	  CallbackHandler2_1(HANDLER handler);
    	  virtual R operator()(A1 a1,A2 a2) const;

      private:
    	HANDLER handler_;
    };


	template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
      class CallbackHandler2_2
      : public CallbackParameter2<R,A1,A2>
      {
        public:
      	  typedef boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,A1,A2>,boost::_bi::list5<boost::_bi::value<F*>,
      	          boost::_bi::value<V1>,
      	          boost::_bi::value<V2>,
      		      boost::arg<1>,
      		  	  boost::arg<2> > > HANDLER;
      	  CallbackHandler2_2(HANDLER handler);
      	  virtual R operator()(A1 a1,A2 a2) const;

        private:
      	  HANDLER handler_;
      };

	template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
      class CallbackHandler2_3
      : public CallbackParameter2<R,A1,A2>
      {
        public:
      	  typedef boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,V3,A1,A2>,boost::_bi::list6<boost::_bi::value<F*>,
      	          boost::_bi::value<V1>,
      	          boost::_bi::value<V2>,
      	          boost::_bi::value<V3>,
      		      boost::arg<1>,
      		  	  boost::arg<2> > > HANDLER;
      	  CallbackHandler2_3(HANDLER handler);
      	  virtual R operator()(A1 a1,A2 a2) const;

        private:
      	  HANDLER handler_;
      };


	template<typename R, typename F, typename A1, typename A2, typename A3>
      class CallbackHandler3
      : public CallbackParameter3<R,A1,A2,A3>
      {
        public:
          typedef boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,A1,A2,A3>,boost::_bi::list4<boost::_bi::value<F*>,
   	    	      boost::arg<1>, boost::arg<2>, boost::arg<3> > > HANDLER;
    	  CallbackHandler3(HANDLER handler);
    	  virtual R operator()(A1 a1,A2 a2,A3 a3) const;

        private:
          HANDLER handler_;
      };


	template<typename R, typename F, typename V1, typename A1, typename A2, typename A3>
      class CallbackHandler3_1
      : public CallbackParameter3<R,A1,A2,A3>
      {
        public:
         typedef boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,A1,A2,A3>,boost::_bi::list5<boost::_bi::value<F*>,
     	  	     boost::_bi::value<V1>,
    		     boost::arg<1>,
     	  	     boost::arg<2>,
     	  	     boost::arg<3> > > HANDLER;
      	  CallbackHandler3_1(HANDLER handler);
      	  virtual R operator()(A1 a1,A2 a2,A3 a3) const;

        private:
          HANDLER handler_;
      };

	template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
      class CallbackHandler3_2
      : public CallbackParameter3<R,A1,A2,A3>
      {
        public:
      	  typedef boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,A1,A2,A3>,boost::_bi::list6<boost::_bi::value<F*>,
      	          boost::_bi::value<V1>,
      	          boost::_bi::value<V2>,
      		      boost::arg<1>,
      		  	  boost::arg<2>,
      	  	  	  boost::arg<3> > > HANDLER;
      	  CallbackHandler3_2(HANDLER handler);
      	  virtual R operator()(A1 a1,A2 a2, A3 a3) const;

        private:
      	  HANDLER handler_;
      };

	template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
      class CallbackHandler4
      : public CallbackParameter4<R,A1,A2,A3,A4>
      {
        public:
          typedef boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,A1,A2,A3,A4>,boost::_bi::list5<boost::_bi::value<F*>,
     	    	  boost::arg<1>,
     	    	  boost::arg<2>,
     	    	  boost::arg<3>,
     	    	  boost::arg<4> > > HANDLER;
      	  CallbackHandler4(HANDLER handler);
      	  virtual R operator()(A1 a1,A2 a2,A3 a3,A4 a4) const;

        private:
          HANDLER handler_;
      };


	class DLLEXPORT Callback
	{
      public:
		typedef boost::shared_ptr<Callback> SPtr;

		Callback();
		template<typename R, typename F>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf0<R,F>,boost::_bi::list1<boost::_bi::value<F*> > > handler);
		template<typename R, typename F, typename V1>
	  	  Callback(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,V1>,boost::_bi::list2<boost::_bi::value<F*>,
	  	           boost::_bi::value<V1> > > handler);
		template<typename R, typename F, typename V1, typename V2>
	  	  Callback(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,V2>,boost::_bi::list3<boost::_bi::value<F*>,
	  	    	   boost::_bi::value<V1>,
	  	  	       boost::_bi::value<V2> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3>
	  	  Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,V3>,boost::_bi::list4<boost::_bi::value<F*>,
	  	  	       boost::_bi::value<V1>,
	  	  	       boost::_bi::value<V2>,
	  	  	       boost::_bi::value<V3> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3, typename V4>
	  	  Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,V4>,boost::_bi::list5<boost::_bi::value<F*>,
	  	  	       boost::_bi::value<V1>,
	  	  	       boost::_bi::value<V2>,
	  	  	       boost::_bi::value<V3>,
	  	  	       boost::_bi::value<V4> > > handler);

		template<typename R, typename F, typename A1>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,A1>,boost::_bi::list2<boost::_bi::value<F*>,
		  	       boost::arg<1> > > handler);
		template<typename R, typename F, typename V1, typename A1>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,A1>,boost::_bi::list3<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
		  	       boost::arg<1> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename A1>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,A1>,boost::_bi::list4<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	    		   boost::_bi::value<V2>,
		  	       boost::arg<1> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,A1>,boost::_bi::list5<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	    		   boost::_bi::value<V2>,
	    		   boost::_bi::value<V3>,
		  	       boost::arg<1> > > handler);

		template<typename R, typename F, typename A1, typename A2>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,A1,A2>,boost::_bi::list3<boost::_bi::value<F*>,
	  		       boost::arg<1>, boost::arg<2> > > handler);
		template<typename R, typename F, typename V1, typename A1, typename A2>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,A1,A2>,boost::_bi::list4<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	  		       boost::arg<1>,
	  		       boost::arg<2> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,A1,A2>,boost::_bi::list5<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	    		   boost::_bi::value<V2>,
	  		       boost::arg<1>,
	  		       boost::arg<2> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,V3,A1,A2>,boost::_bi::list6<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	    		   boost::_bi::value<V2>,
	    		   boost::_bi::value<V3>,
	  		       boost::arg<1>,
	  		       boost::arg<2> > > handler);

		template<typename R, typename F, typename A1, typename A2, typename A3>
		  Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,A1,A2,A3>,boost::_bi::list4<boost::_bi::value<F*>,
	  		       boost::arg<1>, boost::arg<2>, boost::arg<3> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,A1,A2,A3>,boost::_bi::list6<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	    		   boost::_bi::value<V2>,
	  		       boost::arg<1>,
	  		       boost::arg<2>,
				   boost::arg<3> > > handler);
		template<typename R, typename F, typename V1, typename A1, typename A2, typename A3>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,A1,A2,A3>,boost::_bi::list5<boost::_bi::value<F*>,
	    		   boost::_bi::value<V1>,
	  		       boost::arg<1>,
	  		       boost::arg<2>,
	  		       boost::arg<3> > > handler);

		template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
	      Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,A1,A2,A3,A4>,boost::_bi::list5<boost::_bi::value<F*>,
	  		       boost::arg<1>, boost::arg<2>, boost::arg<3>, boost::arg<4> > > handler);

		~Callback(void);

		bool exist(void);
		void reset(void);
		template<typename R, typename F>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf0<R,F>,boost::_bi::list1<boost::_bi::value<F*> > > handler);
		template<typename R, typename F, typename V1>
	  	  void reset(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,V1>,boost::_bi::list2<boost::_bi::value<F*>,
	  	             boost::_bi::value<V1> > > handler);
		template<typename R, typename F, typename V1, typename V2>
	  	  void reset(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,V2>,boost::_bi::list3<boost::_bi::value<F*>,
	  	  	         boost::_bi::value<V1>,
	  	  	         boost::_bi::value<V2> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3>
	  	  void reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,V3>,boost::_bi::list4<boost::_bi::value<F*>,
	  	    	     boost::_bi::value<V1>,
	  	  	         boost::_bi::value<V2>,
	  	  	         boost::_bi::value<V3> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3, typename V4>
	  	  void reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,V4>,boost::_bi::list5<boost::_bi::value<F*>,
	  	  	         boost::_bi::value<V1>,
	  	  	         boost::_bi::value<V2>,
	  	  	         boost::_bi::value<V3>,
	  	  	         boost::_bi::value<V4> > > handler);

		template<typename R, typename F, typename A1>
		  void reset(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,A1>,boost::_bi::list2<boost::_bi::value<F*>,
		  	         boost::arg<1> > > handler);
		template<typename R, typename F, typename V1, typename A1>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,A1>,boost::_bi::list3<boost::_bi::value<F*>,
	      		     boost::_bi::value<V1>,
		  	         boost::arg<1> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename A1>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,A1>,boost::_bi::list4<boost::_bi::value<F*>,
	    			 boost::_bi::value<V1>,
	    		     boost::_bi::value<V2>,
		  	         boost::arg<1> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,A1>,boost::_bi::list5<boost::_bi::value<F*>,
	    		     boost::_bi::value<V1>,
	    		     boost::_bi::value<V2>,
	    		     boost::_bi::value<V3>,
		  	         boost::arg<1> > > handler);

		template<typename R, typename F, typename A1, typename A2>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,A1,A2>,boost::_bi::list3<boost::_bi::value<F*>,
	  		         boost::arg<1>, boost::arg<2> > > handler);
		template<typename R, typename F, typename V1, typename A1, typename A2>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,A1,A2>,boost::_bi::list4<boost::_bi::value<F*>,
	    		     boost::_bi::value<V1>,
	  		         boost::arg<1>,
	  		         boost::arg<2> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,A1,A2>,boost::_bi::list5<boost::_bi::value<F*>,
	    		     boost::_bi::value<V1>,
	    		     boost::_bi::value<V2>,
	  		         boost::arg<1>,
	  		         boost::arg<2> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,V3,A1,A2>,boost::_bi::list6<boost::_bi::value<F*>,
	    		     boost::_bi::value<V1>,
	    		     boost::_bi::value<V2>,
	    		     boost::_bi::value<V3>,
	  		         boost::arg<1>,
	  		         boost::arg<2> > > handler);

		template<typename R, typename F, typename A1, typename A2, typename A3>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,A1,A2,A3>,boost::_bi::list4<boost::_bi::value<F*>,
	  		         boost::arg<1>, boost::arg<2>, boost::arg<3> > > handler);
		template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,A1,A2,A3>,boost::_bi::list6<boost::_bi::value<F*>,
	    		     boost::_bi::value<V1>,
					 boost::_bi::value<V2>,
	  		         boost::arg<1>,
	  		         boost::arg<2>,
	  		         boost::arg<3> > > handler);
		template<typename R, typename F, typename V1, typename A1, typename A2, typename A3>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,A1,A2,A3>,boost::_bi::list5<boost::_bi::value<F*>,
	    		     boost::_bi::value<V1>,
	  		         boost::arg<1>,
	  		         boost::arg<2>,
	  		         boost::arg<3> > > handler);

		template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
	      void reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,A1,A2,A3,A4>,boost::_bi::list5<boost::_bi::value<F*>,
	  		         boost::arg<1>, boost::arg<2>, boost::arg<3>, boost::arg<4> > > handler);


		void operator()(void) const;
		template<typename R>
	      R operator()(void) const;

		template<typename A1>
	      void operator()(A1 a1) const;
		template<typename R, typename A1>
	      R operator()(A1 a1) const;
		template<typename A1,typename A2>
	  	  void operator()(A1 a1,A2 a2) const;
		template<typename R, typename A1, typename A2>
	      R operator()(A1 a1, A2 a2) const;
		template<typename A1,typename A2,typename A3>
	  	  void operator()(A1 a1,A2 a2,A3 a3) const;
		template<typename R, typename A1, typename A2, typename A3>
	      R operator()(A1 a1, A2 a2,A3 a3) const;
		template<typename A1,typename A2,typename A3, typename A4>
	  	  void operator()(A1 a1,A2 a2,A3 a3,A4 a4) const;
		template<typename R, typename A1, typename A2, typename A3, typename A4>
	      R operator()(A1 a1, A2 a2,A3 a3,A4 a4) const;

      private:
	    CallbackBase::SPtr callbackBaseSPtr_;
    };
}

#include "OpcUaStackCore/Base/Callback.txx"

#endif
