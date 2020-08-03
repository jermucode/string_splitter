# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* This function takes a string of arbitrary length
 * and splits it into an array of strings using a delimiter
 * the return value is an array.
 */

char **splitted_string(char *string, char delimiter)
{
	
	/* spaceCounter is just the counter of the delimiter
	 * The original version of the program utilizes spaces for the delimiter
	 */
	int spaceCounter = 0;
	
	/* arrCounter tells us the size to calloc for 
	 * a single token
	 */

	size_t arrCounter = 0;
	
	/* There are a couple of pointers floating around the program
	 * this one moves along string and always the the beginning of the next token
	 */
	
	char *ptr = string;
	
	/* Here we count the amount of delimiters needed. 
	 * The array of strings gets malloc'd based on this
	 */
	
	while(*ptr)
	{
		if(*ptr == delimiter)
		{
			spaceCounter++;
		}
		ptr++;
	}

	/* Do the malloc */
	char **input_array = malloc((spaceCounter+1) * sizeof(char*));
	
	/* The logic for the increment ptr is to move up to the end of the next token
	 * That way we can count the amount needed to calloc for the size of the token
	 * We initially set it to point at the same place as ptr
	 */
	char *increment_ptr=string;
	ptr=string;
	
	/* This is another utility counter since we need to keep track of how many 
	 * tokens are behind us
	 */
	int spacers = 0;
	
	/* i indexer for strncpy into the correct slot
	 */
	int i = 0;

	/* Enter the loop to go through the string */
	while(*increment_ptr)
	{
		/*Lets us know how many characters we are moving along
		 * Also need to move increment_ptr forward by char*/
		arrCounter++;
		increment_ptr++;

		/* Hit the delimiter char*/
		if(*increment_ptr == delimiter)
		{
			/* calloc the necessary character count */
			input_array[i] = calloc((arrCounter+1), sizeof(char));
			
			/* Realized that the counters are one ahead after the first token
			 * So in order to not put the delimiter character as the first char of 
			 * the return array, we need to move ptr by one more after we get past the
			 * first token
			 */

			if(spacers == 0)
			{
				strncpy(input_array[i], ptr, arrCounter);
			}
			else
			{
				strncpy(input_array[i], (ptr+1),arrCounter);
			}
			i++;
			/* We could just add +1 to ptr over here I guess*/
			ptr = increment_ptr;
			
			/* Lets reset the array counter for the next iteration of the loop*/
			arrCounter=0;
			/*Moving spacers by one as well */
			spacers++;

			/* Could not get the last token to work any other way than
			 * by breaking the loop
			 */
			if(spacers == spaceCounter)
			{
				break;
			}

		}
		


	}

	/* Deal with the last token */
	while(*increment_ptr)
	{
		arrCounter++;
		increment_ptr++;
	}
	input_array[spaceCounter] = calloc((arrCounter+1),sizeof(char));
	strncpy(input_array[spaceCounter], (ptr+1), arrCounter);
	return (input_array);
}	




int main(void)
{
	char *string = "This is a string with spaces";
	char delimiter = ' ';
	char **input_array = splitted_string(string, delimiter);
	int delimCounter=0;

	while(*string)
	{
		if (*string == delimiter)
		{
			delimCounter++;
		}
		string++;
	}



	for(int j = 0; j <= delimCounter; j++)
	{	
		printf("%s\n",input_array[j]);
	}

	for(int k = 0; k <= delimCounter; k++)
	{	
		free(input_array[k]);
	}
	free(input_array);

	
}


