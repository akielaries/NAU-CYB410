# Assignment 1

When messing with malware on your machine I figured I would either want to run it in a VM
or make sure none of thge prerequisites are enabled on the machine itself. This is where 
malware written in C or C++ thrive as languages like Python and Java need the runtime and
interpreter already installed to meet that prerequisite. For this assignment I decided to take
a look at the Zeus trojan malware pkg that initially gaining traction in the late 2000s when used
to streal info from the US DoT. Trojans are known to be malware that behaves as legitimate programs.
The bot would go on to infecting millions of computers and spawning any variants. 
The bot is aimed to target windows machines to extract banking informations using keystroke
logging. This form of attack is a common example of a man-in-the-middle attack. The malware pkg
performs infection via phishing schemes or drive-by downloads and infected some of the largest companies
such as Bank of America, Oracle, Cisco, Amazon, etc. The trojan violates just about every principle in the
CIA triad. Since confidential banking information was taken as well as money, confidentially and integrity
are both violated while availability remains in questions. Patches to the malware offered from
cybersecurity consultants is known to eradicate it from the infected machine, however strains of the virus
were spawned remaining a constant battle. 

I was able to find several versions of the "leaked" banking trojan but check out the version I had found from here!

https://github.com/Visgean/Zeus

