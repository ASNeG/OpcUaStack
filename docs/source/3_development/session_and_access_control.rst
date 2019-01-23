Session and Access Control
==========================

In this section we'll learn how to implement authentication and authorization
functionality in your application with ASNeG OPC UA Stack.

Overview
--------

After an OPC UA client has got :term:`Endpoint`\ s of the server by
using :ref:`discovery_process` and opened a :term:`Secure Channel` with suitable
:ref:`security_policy` and :ref:`security_mode`, it should create and activate
:term:`Session` with the server to access to the OPC UA application's data with
During the session activation the client authenticates itself by *userIdentityToken*
that allows the application to correspond the activated :term:`Session` with
its user profile. Then the client finishes
communication with the server it should close :term:`Session` by calling
:term:`Service` *CloseSession* or it is closed by the timeout.

ASNeG OPC UA Stack provides a callback mechanism to notify the user application
about activating\\closing session and accessing to the data during the current
session so that a developer can builtin authentication and authorization in its
OPC UA applications.

.. TODO: Insert a diagram



Authentication
--------------

Authorization
--------------

Close Session
--------------

References
---------

* :ref:`security`
* :ref:`discovery_process`
* `Example <https://github.com/ASNeG/ASNeG-Demo/blob/master/src/ASNeG-Demo/Library/Authentication.cpp>`_

OPC UA Specification
--------------------

* Part 4 Services, 5.6 Session Service Set.
