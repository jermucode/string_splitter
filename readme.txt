

This is my C implementation for splitting a string according to a delimiter character without using strtok.
I do not particularly like strtok and for some reason I can never get it to work.

I did not add the terminating NULL character to the ends of the strings, my use case has no need for them. 
However, if you find some use for the program, I strongly urge you to put in the terminating null character.

The return value is an array of strings (array of arrays)
