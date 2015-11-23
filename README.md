# Banker-s-Algo

# Most Recent Update! (from Jason)

Guys, 

The safety algorithm is now fully implemented. The implementation is in
"safe.c" and the header, "safe.h" contains the prototype for the "safe()"
function. When you need to call "safe()," be sure to include this 
file!

The other change I made was to reorganize how the "extern" declarations 
appear in each source file. This improved the readability of the code
and reduced some redundancy. I would put these declarations in a header,
but I'm not sure about how that would affect the interpretation of the 
compiler. This has to do with the order of declarations, which I don't 
want to worry about, so I'm not going to! It's not really a problem, 
anyway.

All we have left to do is implement an initial randomized allocation
function that legally allocates resources to processes before they 
start running. Then, we have to test the safety of this new system
state, re-allocating until we get a safe state. 

Once a safe state is achieved, we start a thread for each row
in the allocation matrix, and let our system run until the user says 
stop! This should be an adequate demonstration of the Banker's Algorithm! 

We're cooking with gas now! We should have everything implemented and 
in working order soon!

- Jason
