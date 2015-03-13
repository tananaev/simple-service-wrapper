# [Simple Service Wrapper](https://github.com/tananaev/simple-service-wrapper)

## Contacts

Author - Anton Tananaev ([anton.tananaev@gmail.com](mailto:anton.tananaev@gmail.com))

## Overview

A service wrapper enabling arbitrary programs to be installed and run as Windows Services, programs that run in the background, rather than under the direct control of a user. They are often automatically started at boot time.

It is especially important for Java programs, as Java itself doesn't support creating system services.

## Usage

1. Download and unpack files

2. Install service:

        sc.exe create NAME binPath= "C:\test\service.exe \"java -jar C:\test\application.jar\"" type= own start= auto error= ignore
 
3. Run service from "Control Panel" or "Computer Management"

4. Uninstall service:

        sc.exe delete NAME

## License

    Apache License, Version 2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

