<!--

---
layout: default
title: Project Setup
permalink: /en-US/win8/samples/HelloBlinky.htm
lang: en-US
---

 !! I propose we add this to the existing "setup your PC" steps instead of including them in the hello blinky example. !!
 
 
 END COMMENT
 -->

##Create a new Project
Open Visual Studio. Select File -> New Project and Select Templates -> Visual C++ -> Windows for IoT -> Galileo Wiring app
![AppCreate]({{site.baseurl}}/images/Nuget_AppCreate.png) <!-- TODO IMAGE -->


##Develop
Complete one of the many samples on the 'Develop' section of this section, or build your own project!

##Build and deploy
Press F5 to build and deploy your project.

You may be prompted for credentials. Enter:

~~~
  Username: minwinpc\Administrator
  Password: p@ssw0rd
~~~

![]({{site.baseurl}}/images/VSDeployCred.png) <!-- TODO IMAGE -->

if you have renamed your Raspberry pi to something else besides 'minwinpc' use that name in the login box instead.

## Failed to deploy?
Under certain network conditions, deploy by name might fail. In this case, it would be best to deploy by IP.

Copy the IP address from IoTCore Watcher, by right clicking on the RPi instance and select Copy IP Address:

![Copy IP Address]({{site.baseurl}}/images/Deploy_CopyIP.png) <!-- TODO IMAGE -->

Open the project properties by right clicking on the project in Solution Explorer.

Paste the copied IP address into the 'Remote Server Name' field on the debugging tab in Visual Studio:

![Paste IP Address]({{site.baseurl}}/images/Deploy_PasteIP.png)  <!-- TODO IMAGE -->
<!-- TODO NO AUTHENTICATION STEP -->