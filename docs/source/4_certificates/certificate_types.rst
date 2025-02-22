Certificate Types
===========================

Self Signed Certificate
-------------------------

The simplest type are self signed certificates. Self signed certificates are not 
signed by a public certification authority. Self Signed Zerts are generated by 
the OPC UA server itself. For this reason, external or public OPC UA applications 
should not trust these certificates. However, these certificates are sufficient 
for the test or in an internal environment.

CA Certificate
----------------

CA certificates are issued by a public certification authority. CA certificates
are used to sign Application certificates and Intermdiate Certificates and are 
combined into a Cert chain. If a CA certificate is trusted, all derived 
certificates are also trusted.

Application Certificate
-------------------------

An Application certificate is used for the encryption and signature of 
OPC UA communication connections for an application. An application certificate 
can be self-signed, signed by a CA certificate or signed by an intermediate 
certificate. 

Intermediate Certificate
--------------------------

Intermediate certificates are used to group application certificates. A
intermediate certificate is signed by a CA certificates or a other 
intermediate certificate. If a intermediate certificate is trusted, 
all derived certificates are also trusted.
