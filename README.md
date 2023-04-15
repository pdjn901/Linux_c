# Linux_c
linux c programs for own refrence


15-04-2023
1) Linux c programs have been classified as the 1) Linux internals,  2) Linux Network programming, 3) 


agk_int:- 

embedded c 
1) bitwise operation;
	a) convert binary to oct,hex
	
2) timer 
	a) get_clock(); function?
	
3) linked list usd evr?

4) queueue
	a) how many input and outputs

5) simple c 
	a) c program for a^b?







out telephonic int 
1) device drivers ------------usb(device reg, and de-regi),ex: wi-fi ,wlan,camera dirver 
2) yocto	
3) bsp	(inner layer of yocto umbrella) -------->buildroot,openil,yocto(build and os for stm32,beagle bone black,nxp);
4) basic c and python.---logic,linux networking,ipc,internals, signals, small script.








===========refreneces==========================

==================================================================
---------------------------------------------------
ex:- usb ddriver

static struct usb_driver skel_driver = {
        .name        = "skeleton",
        .probe       = skel_probe,
        .disconnect  = skel_disconnect,
        .suspend     = skel_suspend,
        .resume      = skel_resume,
        .pre_reset   = skel_pre_reset,
        .post_reset  = skel_post_reset,
        .id_table    = skel_table,
        .supports_autosuspend = 1,
};
-----------------------------------------------
https://docs.kernel.org/driver-api/usb/writing_usb_driver.html
--------------------------------------------------------------------------
https://www.oreilly.com/library/view/linux-device-drivers/0596005903/ch13.html
====================================================================



