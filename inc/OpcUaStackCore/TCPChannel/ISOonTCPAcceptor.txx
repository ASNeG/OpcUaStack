/*
 * FILE: ISOonTCPAcceptor.cxx
 *
 * Copyright (c) 2012 Kai Huebl <kai.huebl@t-online,de>
 *
 * CHANGE LOG:
 * who  ddMmmyy  defect  description
 * ---  -------  ------  ------------------------------------------------------
 * huk  12Dec12  --      initial
 */

using namespace sps;

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// Klasse ISOonTCPAcceptor
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
template <typename HANDLER>
  void 
  ISOonTCPAcceptor::async_accept(boost::asio::ip::tcp::socket& socket, HANDLER handler)
  {
	  acceptor_.async_accept(socket,handler);
  }

/*--------[ END OF FILE ISOonTCPAcceptor.cxx ]-----------------------------*/
