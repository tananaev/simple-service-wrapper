Simple Service Wrapper

==========

Install service

sc.exe create NAME binPath= "C:\test\service.exe \"java -jar C:\test\application.jar\"" type= own start= auto error= ignore DisplayName= NAME

==========

Uninstall service

sc.exe delete NAME
