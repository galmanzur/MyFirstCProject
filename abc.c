/* This Is A Program That Manipulate A String To Return A Shortened String */

#include <stdio.h>
#include <string.h>
#include <ctype.h> /* to use isalpha() later on */

char* shortened(char*);

#define SIZE 80 /* Size of String will be 80 MAX according to demand */

int main(void)
{
	char input_str[SIZE];
	/* Input */
	printf("[>] Please Insert String: ");
	fgets(input_str, SIZE, stdin);
	printf("\n[*] String Entered: %s\n",input_str);
	if (strlen(input_str) > 1) /* Validates that input is not empty string */
	{
		printf("[*] Shortened String is: ");
		printf("%s",shortened(input_str)); 
	}
	else
	{
		printf("[!] Invalid Input --> Please insert string next time!\n [!] Exiting...\n");
	}
	return 0;
}

char* shortened(char* str_to_manipulate)
{
	/* This func gets a string and returns the shortened one */
	int i, j, k;
	char last_char = str_to_manipulate[0]; /* Variable to compare with while looping on the string */
	for (i = 0; str_to_manipulate[i] != '\0'; ++i)
	{
	      /* enters if the character is an alphabet and the last one is too */
		if (isalpha(str_to_manipulate[i]) && isalpha(last_char));
		{
			/* enters if the character is bigger by 1 (ASCII VALUE COMPARISON) */
			if ((int)(str_to_manipulate[i]) == (int)(last_char) + 1)
			{
				last_char = str_to_manipulate[i];
				for (j = i + 1; str_to_manipulate[j] != '\0'; ++j)
				{
					/* checks again if this one is alphabet and bigger by 1, if so its a streak of at least 3 */					
					if (isalpha(str_to_manipulate[j]) && isalpha(last_char))
					{
						if ((int)(str_to_manipulate[j]) == (int)(last_char) + 1)
						{	
							/* checking if '-' already replaced to avoid running it every cycle of the for loop */
							if (str_to_manipulate[i] != '-')
							{
								str_to_manipulate[i] = '-';
							}
							/* replacing the char after the '-' beacuse its bigger by 1 than the last one */
							str_to_manipulate[i + 1] = str_to_manipulate[j];
							last_char = str_to_manipulate[j];
							if (j > i + 1)
							{	
								/* running on rest of string and brings back all chars by 1 */
								for (k = j + 1; str_to_manipulate[k] != '\0'; ++k)
								{
									str_to_manipulate[k - 1] = str_to_manipulate[k];
								}
								j = j - 1; /* j has to lower by 1 beacause the whole string got back by 1 */
							}
						}
						/* if only strak of 2 so dont go on all of the loop again .. */
						else
							break;
					}
				
				}
			}
			 
		}
		/* important to remember to set kast_char according to i values in the big for loop */
		last_char = str_to_manipulate[i];
	}
	return str_to_manipulate;
}


