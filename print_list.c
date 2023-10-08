#include "main.h"
#include <stdio.h>
void print_list(fn_node *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	printf("The valid files are ");
	    while (head)		
	    {
		    printf("%s ", head -> file_name);   //printing the file names in single linked
		    if(head -> link != NULL)
		    {
			printf("-> ");
		    }
		    head = head -> link;
	    }
	    printf("\n");
    }
}
