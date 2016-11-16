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

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CallbackParameter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename R>
      CallbackParameter0<R>::CallbackParameter0(void)
      : CallbackBase()
      {
      }

	template<typename R, typename A1>
      CallbackParameter1<R,A1>::CallbackParameter1(void)
      : CallbackBase()
      {
      }

	template<typename R, typename A1, typename A2>
      CallbackParameter2<R,A1,A2>::CallbackParameter2(void)
      : CallbackBase()
      {
      }

	template<typename R, typename A1, typename A2, typename A3>
      CallbackParameter3<R,A1,A2,A3>::CallbackParameter3(void)
      : CallbackBase()
      {
      }

	template<typename R, typename A1, typename A2, typename A3, typename A4>
      CallbackParameter4<R,A1,A2,A3,A4>::CallbackParameter4(void)
      : CallbackBase()
      {
      }
  
 
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CallbackHandler
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename R,typename F>
      CallbackHandler0<R,F>::CallbackHandler0(HANDLER handler) 
      : CallbackParameter0<R>()
      , handler_(handler)
      {
      }
    
	template<typename R,typename F, typename V1>
     CallbackHandler0_1<R,F,V1>::CallbackHandler0_1(HANDLER handler) 
    : CallbackParameter0<R>()
    , handler_(handler)
    {
    }
    
	template<typename R,typename F, typename V1, typename V2>
      CallbackHandler0_2<R,F,V1,V2>::CallbackHandler0_2(HANDLER handler) 
      : CallbackParameter0<R>()
      , handler_(handler)
      {
      }
    
	template<typename R,typename F, typename V1, typename V2, typename V3>
      CallbackHandler0_3<R,F,V1,V2,V3>::CallbackHandler0_3(HANDLER handler) 
      : CallbackParameter0<R>()
      , handler_(handler)
      {
     }
     
	template<typename R,typename F, typename V1, typename V2, typename V3, typename V4>
      CallbackHandler0_4<R,F,V1,V2,V3,V4>::CallbackHandler0_4(HANDLER handler) 
      : CallbackParameter0<R>()
      , handler_(handler)
      {
      }
  
	template<typename R, typename F, typename A1>
      CallbackHandler1<R,F,A1>::CallbackHandler1(HANDLER handler) 
      : CallbackParameter1<R,A1>()
      , handler_(handler)
      {
      }
    
	template<typename R, typename F, typename V1, typename A1>
      CallbackHandler1_1<R,F,V1,A1>::CallbackHandler1_1(HANDLER handler) 
      : CallbackParameter1<R,A1>()
      , handler_(handler)
      {
	  }
    
	template<typename R, typename F, typename V1, typename V2, typename A1>
      CallbackHandler1_2<R,F,V1,V2,A1>::CallbackHandler1_2(HANDLER handler) 
      : CallbackParameter1<R,A1>()
      , handler_(handler)
      {
      } 
    
	template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
      CallbackHandler1_3<R,F,V1,V2,V3,A1>::CallbackHandler1_3(HANDLER handler) 
      : CallbackParameter1<R,A1>()
      , handler_(handler)
      {
      }
  
	template<typename R, typename F, typename A1, typename A2>
      CallbackHandler2<R,F,A1,A2>::CallbackHandler2(HANDLER handler) 
      : CallbackParameter2<R,A1,A2>()
      , handler_(handler)
      {
      }
    
	template<typename R, typename F, typename V1, typename A1, typename A2>
      CallbackHandler2_1<R,F,V1,A1,A2>::CallbackHandler2_1(HANDLER handler) 
      : CallbackParameter2<R,A1,A2>()
      , handler_(handler)
      {
      }
    
	template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
      CallbackHandler2_2<R,F,V1,V2,A1,A2>::CallbackHandler2_2(HANDLER handler) 
      : CallbackParameter2<R,A1,A2>()
      , handler_(handler)
      {
      }
      
 	template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
      CallbackHandler2_3<R,F,V1,V2,V3,A1,A2>::CallbackHandler2_3(HANDLER handler) 
      : CallbackParameter2<R,A1,A2>()
      , handler_(handler)
      {
      }
    
	template<typename R, typename F, typename A1, typename A2, typename A3>
      CallbackHandler3<R,F,A1,A2,A3>::CallbackHandler3(HANDLER handler) 
      : CallbackParameter3<R,A1,A2,A3>()
      , handler_(handler)
      {
      }
    
	template<typename R, typename F, typename V1,typename A1, typename A2, typename A3>
      CallbackHandler3_1<R,F,V1,A1,A2,A3>::CallbackHandler3_1(HANDLER handler) 
      : CallbackParameter3<R,A1,A2,A3>()
      , handler_(handler)
	  {
      }
    
    template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
      CallbackHandler3_2<R,F,V1,V2,A1,A2,A3>::CallbackHandler3_2(HANDLER handler) 
      : CallbackParameter3<R,A1,A2,A3>()
      , handler_(handler)
      {
      }
    
	template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
      CallbackHandler4<R,F,A1,A2,A3,A4>::CallbackHandler4(HANDLER handler) 
      : CallbackParameter4<R,A1,A2,A3,A4>()
      , handler_(handler)
	  {
      }
  
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// R
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename R, typename F>
      R
      CallbackHandler0<R,F>::operator()(void) const
      {
          return handler_();
      }
    
    template<typename R, typename F, typename V1>
      R
      CallbackHandler0_1<R,F,V1>::operator()(void) const
      {
          return handler_();
      }
    
	template<typename R, typename F, typename V1, typename V2>
      R
      CallbackHandler0_2<R,F,V1,V2>::operator()(void) const
      {
          return handler_();
      }
    
	template<typename R, typename F, typename V1, typename V2, typename V3>
      R
      CallbackHandler0_3<R,F,V1,V2,V3>::operator()(void) const
      {
          return handler_();
      }
    
	template<typename R, typename F, typename V1, typename V2, typename V3, typename V4>
      R
      CallbackHandler0_4<R,F,V1,V2,V3,V4>::operator()(void) const
      {
          return handler_();
      }
  
    template<typename R, typename F, typename A1>
      R
      CallbackHandler1<R,F,A1>::operator()(A1 a1) const
      {
          return handler_(a1);
      }
    
    template<typename R, typename F, typename V1, typename A1>
      R
      CallbackHandler1_1<R,F,V1,A1>::operator()(A1 a1) const
      {
          return handler_(a1);
      }
  
    template<typename R, typename F, typename V1, typename V2, typename A1>
      R
      CallbackHandler1_2<R,F,V1,V2,A1>::operator()(A1 a1) const
      {
          return handler_(a1);
      }
    
	template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
      R
      CallbackHandler1_3<R,F,V1,V2,V3,A1>::operator()(A1 a1) const
      {
          return handler_(a1);
      }
  
	template<typename R, typename F, typename A1, typename A2>
      R
      CallbackHandler2<R,F,A1,A2>::operator()(A1 a1, A2 a2) const
      {
          return handler_(a1,a2);
      }
    
	template<typename R, typename F, typename V1, typename A1, typename A2>
      R
      CallbackHandler2_1<R,F,V1,A1,A2>::operator()(A1 a1, A2 a2) const
      {
          return handler_(a1,a2);
      }
    
	template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
      R
      CallbackHandler2_2<R,F,V1,V2,A1,A2>::operator()(A1 a1, A2 a2) const
      {
          return handler_(a1,a2);
      }
      
	template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
      R
      CallbackHandler2_3<R,F,V1,V2,V3,A1,A2>::operator()(A1 a1, A2 a2) const
      {
          return handler_(a1,a2);
      }
    
    template<typename R, typename F, typename A1, typename A2, typename A3>
      R
      CallbackHandler3<R,F,A1,A2,A3>::operator()(A1 a1, A2 a2,A3 a3) const
      {
          return handler_(a1,a2,a3);
      }
    
    template<typename R, typename F, typename V1, typename A1, typename A2, typename A3>
      R
      CallbackHandler3_1<R,F,V1,A1,A2,A3>::operator()(A1 a1, A2 a2,A3 a3) const
      {
          return handler_(a1,a2,a3);
      }
  
  	template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
      R
      CallbackHandler3_2<R,F,V1,V2,A1,A2,A3>::operator()(A1 a1, A2 a2, A3 a3) const
      {
          return handler_(a1,a2,a3);
      }
    
    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
      R
      CallbackHandler4<R,F,A1,A2,A3,A4>::operator()(A1 a1, A2 a2,A3 a3, A4 a4) const
      {
          return handler_(a1,a2,a3,a4);
      }
  
 
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Callback
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename R, typename F>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf0<R,F>,boost::_bi::list1<boost::_bi::value<F*> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0<R,F>(handler));
      }
    
	template<typename R, typename F, typename V1>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,V1>,boost::_bi::list2<boost::_bi::value<F*>,
                         boost::_bi::value<V1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_1<R,F,V1>(handler));
      }
    
	template<typename R, typename F, typename V1, typename V2>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,V2>,boost::_bi::list3<boost::_bi::value<F*>,
                         boost::_bi::value<V1>,
                         boost::_bi::value<V2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_2<R,F,V1,V2>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename V3>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,V3>,boost::_bi::list4<boost::_bi::value<F*>,
                         boost::_bi::value<V1>,
                         boost::_bi::value<V2>,
                         boost::_bi::value<V3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_3<R,F,V1,V2,V3>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename V3, typename V4>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,V4>,boost::_bi::list5<boost::_bi::value<F*>,
                         boost::_bi::value<V1>,
                         boost::_bi::value<V2>,
                         boost::_bi::value<V3>,
                         boost::_bi::value<V4> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_4<R,F,V1,V2,V3,V4>(handler));
      }

    template<typename R, typename F, typename A1>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,A1>,boost::_bi::list2<boost::_bi::value<F*>, boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1<R,F,A1>(handler));
      }
    
    template<typename R, typename F, typename V1, typename A1>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,A1>,boost::_bi::list3<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1_1<R,F,V1,A1>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename A1>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,A1>,boost::_bi::list4<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::_bi::value<V2>,
                         boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1_2<R,F,V1,V2,A1>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,A1>,boost::_bi::list5<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::_bi::value<V2>,
                         boost::_bi::value<V3>,
                         boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1_3<R,F,V1,V2,V3,A1>(handler));
      }
 
    template<typename R, typename F, typename A1, typename A2>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,A1,A2>,boost::_bi::list3<boost::_bi::value<F*>, 
                         boost::arg<1>, boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2<R,F,A1,A2>(handler));
      }
    
    template<typename R, typename F, typename V1, typename A1, typename A2>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,A1,A2>,boost::_bi::list4<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::arg<1>, 
                         boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2_1<R,F,V1,A1,A2>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,A1,A2>,boost::_bi::list5<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::_bi::value<V2>,
                         boost::arg<1>, 
                         boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2_2<R,F,V1,V2,A1,A2>(handler));
      }
      
    template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,V3,A1,A2>,boost::_bi::list6<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::_bi::value<V2>,
                         boost::_bi::value<V3>,
                         boost::arg<1>, 
                         boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2_3<R,F,V1,V2,V3,A1,A2>(handler));
      }
    
    template<typename R, typename F, typename A1, typename A2, typename A3>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,A1,A2,A3>,boost::_bi::list4<boost::_bi::value<F*>, 
                         boost::arg<1>, boost::arg<2>, boost::arg<3> > > handler)
     {
          callbackBaseSPtr_.reset(new CallbackHandler3<R,F,A1,A2,A3>(handler));
      }
    
    template<typename R, typename F, typename V1, typename A1, typename A2, typename A3>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,A1,A2,A3>,boost::_bi::list5<boost::_bi::value<F*>, 
                         boost::_bi::value<V1>,
                         boost::arg<1>, 
                         boost::arg<2>, 
                         boost::arg<3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler3_1<R,F,V1,A1,A2,A3>(handler));
      }
    
     template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,A1,A2,A3>,boost::_bi::list6<boost::_bi::value<F*>,
                         boost::_bi::value<V1>, 
                         boost::_bi::value<V2>,
                         boost::arg<1>, 
                         boost::arg<2>,
                         boost::arg<3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler3_2<R,F,V1,V2,A1,A2,A3>(handler));
      }   
    
    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
      Callback::Callback(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,A1,A2,A3,A4>,boost::_bi::list5<boost::_bi::value<F*>, 
                         boost::arg<1>, 
                         boost::arg<2>, 
                         boost::arg<3>, 
                         boost::arg<4> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler4<R,F,A1,A2,A3,A4>(handler));
      }
    

	template<typename R, typename F>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf0<R,F>,boost::_bi::list1<boost::_bi::value<F*> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0<R,F>(handler));
     }
     
	template<typename R, typename F, typename V1>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,V1>,boost::_bi::list2<boost::_bi::value<F*>,
                      boost::_bi::value<V1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_1<R,F,V1>(handler));
      }
    
	template<typename R, typename F, typename V1, typename V2>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,V2>,boost::_bi::list3<boost::_bi::value<F*>,
                      boost::_bi::value<V1>,
                      boost::_bi::value<V2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_2<R,F,V1,V2>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename V3>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,V3>,boost::_bi::list4<boost::_bi::value<F*>,
                      boost::_bi::value<V1>,
                      boost::_bi::value<V2>,
                      boost::_bi::value<V3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_3<R,F,V1,V2,V3>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename V3, typename V4>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,V4>,boost::_bi::list5<boost::_bi::value<F*>,
                      boost::_bi::value<V1>,
                      boost::_bi::value<V2>,
                      boost::_bi::value<V3>,
                      boost::_bi::value<V4> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler0_4<R,F,V1,V2,V3,V4>(handler));
      }

    template<typename R, typename F, typename A1>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf1<R,F,A1>,boost::_bi::list2<boost::_bi::value<F*>, boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1<R,F,A1>(handler));
      }
    
    template<typename R, typename F, typename V1, typename A1>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,V1,A1>,boost::_bi::list3<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1_1<R,F,V1,A1>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename A1>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,V2,A1>,boost::_bi::list4<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::_bi::value<V2>,
                      boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1_2<R,F,V1,V2,A1>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename V3, typename A1>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,V3,A1>,boost::_bi::list5<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::_bi::value<V2>,
                      boost::_bi::value<V3>,
                      boost::arg<1> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler1_3<R,F,V1,V2,V3,A1>(handler));
      }
 
    template<typename R, typename F, typename A1, typename A2>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf2<R,F,A1,A2>,boost::_bi::list3<boost::_bi::value<F*>, 
                      boost::arg<1>, 
                      boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2<R,F,A1,A2>(handler));
      }
    
    template<typename R, typename F, typename V1, typename A1, typename A2>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,V1,A1,A2>,boost::_bi::list4<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::arg<1>, 
                      boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2_1<R,F,V1,A1,A2>(handler));
      }
    
    template<typename R, typename F, typename V1, typename V2, typename A1, typename A2>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,V2,A1,A2>,boost::_bi::list5<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::_bi::value<V2>,
                      boost::arg<1>, 
                      boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2_2<R,F,V1,V2,A1,A2>(handler));
      }
      
    template<typename R, typename F, typename V1, typename V2, typename V3, typename A1, typename A2>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,V3,A1,A2>,boost::_bi::list6<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::_bi::value<V2>,
                      boost::_bi::value<V3>,
                      boost::arg<1>, 
                      boost::arg<2> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler2_3<R,F,V1,V2,V3,A1,A2>(handler));
      }
    
    template<typename R, typename F, typename A1, typename A2, typename A3>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf3<R,F,A1,A2,A3>,boost::_bi::list4<boost::_bi::value<F*>, 
                      boost::arg<1>, 
                      boost::arg<2>, 
                      boost::arg<3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler3<R,F,A1,A2,A3>(handler));
      }
    
    template<typename R, typename F, typename V1, typename A1, typename A2, typename A3>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,V1,A1,A2,A3>,boost::_bi::list5<boost::_bi::value<F*>, 
                      boost::_bi::value<V1>,
                      boost::arg<1>, 
                      boost::arg<2>, 
                      boost::arg<3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler3_1<R,F,V1,A1,A2,A3>(handler));
      }
 
     template<typename R, typename F, typename V1, typename V2, typename A1, typename A2, typename A3>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf5<R,F,V1,V2,A1,A2,A3>,boost::_bi::list6<boost::_bi::value<F*>,
                      boost::_bi::value<V1>, 
                      boost::_bi::value<V2>,
                      boost::arg<1>, 
                      boost::arg<2>,
                      boost::arg<3> > > handler)
      {
          callbackBaseSPtr_.reset(new CallbackHandler3_2<R,F,V1,V2,A1,A2,A3>(handler));
      }
    
    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
      void
      Callback::reset(boost::_bi::bind_t<R,boost::_mfi::mf4<R,F,A1,A2,A3,A4>,boost::_bi::list5<boost::_bi::value<F*>, 
                      boost::arg<1>, 
                      boost::arg<2>, 
                      boost::arg<3>, 
                      boost::arg<4> > > handler)
      {
         callbackBaseSPtr_.reset(new CallbackHandler4<R,F,A1,A2,A3,A4>(handler));
      } 
  
    template<typename R>
      R 
      Callback::operator()(void) const
      {
          CallbackParameter0<R> *callbackParameter = static_cast<CallbackParameter0<R>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(); 
      }
  
    template<typename A1>
      void
      Callback::operator()(A1 a1) const
      {
          CallbackParameter1<void,A1> *callbackParameter = static_cast<CallbackParameter1<void,A1>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1); 
      }

    template<typename R, typename A1>
      R 
      Callback::operator()(A1 a1) const
      {
          CallbackParameter1<R,A1> *callbackParameter = static_cast<CallbackParameter1<R,A1>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1); 
      }
  
    template<typename A1, typename A2>
      void 
      Callback::operator()(A1 a1,A2 a2) const
      {
          CallbackParameter2<void,A1,A2> *callbackParameter = static_cast<CallbackParameter2<void,A1,A2>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1,a2); 
      }
  
    template<typename R, typename A1, typename A2> 
      R 
      Callback::operator()(A1 a1,A2 a2) const
      {
          CallbackParameter2<R,A1,A2> *callbackParameter = static_cast<CallbackParameter2<R,A1,A2>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1,a2); 
      }
     
    template<typename A1, typename A2, typename A3>
      void
      Callback::operator()(A1 a1,A2 a2,A3 a3) const
      {
          CallbackParameter3<void,A1,A2,A3> *callbackParameter = static_cast<CallbackParameter3<void,A1,A2,A3>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1,a2,a3); 
      }
    
    template<typename R, typename A1, typename A2, typename A3>
      R 
      Callback::operator()(A1 a1,A2 a2,A3 a3) const
      {
          CallbackParameter3<R,A1,A2,A3> *callbackParameter = static_cast<CallbackParameter3<R,A1,A2,A3>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1,a2,a3); 
      }
    
    template<typename A1, typename A2, typename A3, typename A4>
      void
      Callback::operator()(A1 a1,A2 a2,A3 a3,A4 a4) const
      {
          CallbackParameter4<void,A1,A2,A3,A4> *callbackParameter = static_cast<CallbackParameter4<void,A1,A2,A3,A4>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1,a2,a3,a4); 
      }
    
    template<typename R, typename A1, typename A2, typename A3, typename A4>
      R 
      Callback::operator()(A1 a1,A2 a2,A3 a3, A4 a4) const
      {
          CallbackParameter4<R,A1,A2,A3,A4> *callbackParameter = static_cast<CallbackParameter4<R,A1,A2,A3,A4>* >(callbackBaseSPtr_.get());
          (*callbackParameter)(a1,a2,a3,a4); 
      }
	    
}