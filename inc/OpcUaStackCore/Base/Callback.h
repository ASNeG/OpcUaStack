#ifndef __OpcUaStackCore_Callback_h__
#define __OpcUaStackCore_Callback_h__

namespace OpcUaStackCore
{

	class CallbackDataBase
	{
      public:
        CallbackDataBase( void ); 
        virtual ~CallbackDataBase( void );
    };


	class CallbackDataBaseP0 : public CallbackDataBase
	{
      public:
        CallbackDataBaseP0( void );
        virtual ~CallbackDataBaseP0( void );

        virtual void run( void ) = 0;
        void operator()( void ); 
    };

	template<class P1>
      class CallbackDataBaseP1 : public CallbackDataBase
	  {
		public:
          CallbackDataBaseP1( void );
          virtual ~CallbackDataBaseP1( void );

          virtual void run( P1 ) = 0;
          void operator()( P1 p1 ); 
      };

    template<class P1, class P2>
      class CallbackDataBaseP2 : public CallbackDataBase
      {
        public:
          CallbackDataBaseP2( void );
          virtual ~CallbackDataBaseP2( void );

          virtual void run( P1, P2 ) = 0;
          void operator()( P1 p1, P2 p2 ); 
      };

    template<class Client>
      class CallbackDataBase0 : public CallbackDataBaseP0
      {
        public:
          typedef void (Client::*Function)( void );

          CallbackDataBase0( Client *client, Function function );       
          ~CallbackDataBase0( void );
 
          void run( void );

        private:
          Client *client_;
          Function function_; 
      };


    template<class Client, class P1>
      class CallbackDataBase1 : public CallbackDataBaseP1<P1>
      {
        public:
          typedef void (Client::*Function)( P1 );

          CallbackDataBase1( Client *client, Function function );
          ~CallbackDataBase1( void );

          void run( P1 p1 );

	    private:
          Client *client_;
          Function function_; 
      };

 
    template<class Client, class P1, class P2>
      class CallbackDataBase2 : public CallbackDataBaseP2<P1, P2>
      {
        public:
          typedef void (Client::*Function)( P1, P2 );

          CallbackDataBase2( Client *client, Function function );
          ~CallbackDataBase2( void );

          void run( P1 p1, P2 p2 );

        private:
          Client *client_;
          Function function_;
      };

 
    class Callback
    {
      public:
        Callback(void);
        template<class Client>
          Callback( Client *client, void (Client::*function)( void )); 
        template<class Client, class P1>
          Callback( Client *client, void (Client::*function)( P1 p1 ));
        template<class Client, class P1, class P2>
          Callback( Client *client, void (Client::*function)( P1 p1, P2 p2 ));
        ~Callback( void ); 

        template<class Client>
          void set( Client *client, void (Client::*function)( void ) );
        template<class Client, class P1>
          void set( Client *client, void (Client::*function)( P1 p1 ) );
        template<class Client, class P1, class P2>
          void set( Client *client, void (Client::*function)( P1 p1, P2 p2 ) );

        void operator()( void );
        template<class P1>
          void operator()( P1 p1 );
        template<class P1, class P2>
          void operator()( P1 p1, P2 p2 );
      
      private:
        CallbackDataBase *callbackDataBase_;
    };


}

#endif