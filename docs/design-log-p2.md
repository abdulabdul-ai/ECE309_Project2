# Design Log — Project 2

(500–800 words total. See spec §5 for what each section must cover.)

## Growth factor and amortized cost
In line 69 of conversation.cpp, I made the growth factor 2, and each time the capacity reaches a maximum, I multiply the current capacity by 2, so the O(1) is O(n), as n = 2,


## Rule of Five evidence
Rule of 5, because in the conversation.cpp, we needed copy semantics and move semantics, and since we needed to have these 2, we also were required to implement destructor, copy constructor, and assignment operator, and since we have this, it implies using deep-copy.

For copy constructor, in conversation.cpp, I exerted a function calling and used a new () for new Message[other.size] in line 17. 

And for each class, I also implemented exactly one deconstructor by using delete[] and freeing up the memory on the heap.

And using the complex operator =, I OVERWROTE the existing data/value in one of the objects in line 29-30. 

Then, I used the copy semantic to solely duplicate the deep copy (not the shallow one) using data pointers, and left the source object intact in lines 28-30.

And to enure the code compiles properly, I also used the move semantics as instructed and stole the resources from the old objects and zero'd the source objects in lines 46-53.

## Sentinel scanner: bounded pending_ proof
First, we use a class to check whether the sentinel is empty, and if it is, we throw an error message mentioning that it's not supposed to be empty in a conversation.

Then we check using a loop to see if individual pieces/ chunks of characters add up to be the entire sentinel message by combining the former and the latter chunks using .append() function, then we check to see if the begging of combined chunk matches our string sentinel inside the while loop and exit out the loop if we do. Otherwise, using the .substr() function, we store the largest matching string between the combined chunks and the sentinel and then combine that with latest parcels of chunk to see if that matches with the full string of the sentinel (as in the case where the sentinel is sent character by character). And then we return the text which was entered before the sentinel from the user back to the screen. 


## What I would change differently
Unfortunately, due to my father's passing away, I was disturbed and ended up starting the project late. Therefore, my PC was acting up and wouldn't let me build/compile the code and/or show my errors with where they were located. Because of which, I couldn't debug my code and fixed my errors or get help from TAs. My submission was what I managed to come up with by looking at notes and the header files, please excuse my code if it doesn't work and give me partial credit as much as possible. I will try to get started early (if not on time) from future projects and use the TAs as resources. Thank you.