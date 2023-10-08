#include<stdio.h>
#include<string.h>
#include"main.h"
#include<stdlib.h>
#include<ctype.h>
/*
Name : Dhatchaneswaran R
Date : 27/09/2023
Title : inverted search
Sample I/O :
Sample I/P :
*/

int main(int argc, char *argv[])
{
   
    int opt;

    fn_node *head = NULL;                    //it will contain file names we will pass as arguments
    main_node *hashtable[27]={NULL};         //it will store the words in dictionary manner

    
    int ret,count=0;
    fn_node *temp;

	
    if((ret=file_validate(argc,argv))== SUCCESS)          //this funtion will check the file names validate or not and exist or not
    {
	printf(">>>>>>>>>>>>>>>>>>File validation successful..!<<<<<<<<<<<<<<<<<<<<<<\n");
    }
    else
    {
	printf(">>>>>>>>>>>>>>>>>>>>>File validation failed..!<<<<<<<<<<<<<<<<<<<<<<<\n");
	return FAILURE;
    }
	printf("---------------------------------------------------------------------\n");
    	for(int i=1;i<argc;i++)
    	{
	    if(argv[i] != NULL)
	    {
	
		if( (ret = insert_at_last(&head,argv[i]))== DUPLICATE_FOUND)            //this function inserts filenames without duplicate in single list
		{
	    	    printf("DUPLICATE DETECTED ): '%s'     arg[%d]\n",argv[i],i);      
		}
		
	    }
    	}
	
    printf("\n");
    print_list(head);
    while(opt != 6)
    {
	printf("---------------------------------------------------------------------\n");
	printf("1.Create data base\n2.Display\n3.Search\n4.Update\n5.save\n6.exit\n");
	opt=0;
	printf("Enter a option :");
	scanf("%d",&opt);
	printf("---------------------------------------------------------------------\n");
	switch(opt)
	{
case 1:   //database creation
    {
    temp = head;
    FILE *fptr;
    char buff[30];
    int index=0,j=0;
    while(temp)
    {
	fptr = fopen(temp -> file_name,"r");      //opening the given files in read mode
	while(fscanf(fptr,"%s",buff) != EOF)      //fetching words one by one from the given files 
	{
            if((buff[0] >= 33 && buff[0] <= 47) || (buff[0] >= 58 && buff[0] <= 63))   //arranging and storing the words in organised manner in accordance with first letter of the word
            {
                index = 26;
            }
            else
            {
	        index = (tolower(buff[0])) % 97;
            }
	    if(create_data_base(&hashtable[index],buff, temp -> file_name) != SUCCESS)
	    {
		printf("error\n");
		return FAILURE;
	    }
	}
	temp = temp -> link;
    }
    printf("DATABASE CREATED SUCCESSFUL\n");
    break;
	    }

case 2:      //display database
{
    int count=0;

    printf("Index     word     file_count     filename     wordcount\n");
    for(int i = 0;i<27;i++)
    {
	count= count + display_data(hashtable[i],i);
    }
    if(count == 0)
    {
	printf("================>[ DATABASE IS EMPTY ]<=================\n");
    }
    break;
}

case 3:      //searching a word
{
    char word[20];
    int index;
    printf("Enter a word to search : ");
    scanf("%s",word);
    index = (tolower(word[0])) % 97;
    printf("Index     word     file_count     filename     wordcount\n");
    if(search_data(hashtable[index],index,word)!= SUCCESS)
    {
	printf("-----------------**[WORD NOT FOUND]**<------------------\n");
    }
    break;
}
case 4:     //update the data from backup file to database
{   char file[50];
    printf("\nEnter the file name for update :");
    scanf("%s",file);
    if(update_validation(file,hashtable)== SUCCESS)	// update the database
    {
	printf("\nINFO : Updation Successful !!\n");
    }
    break;
}
case 5:    //saving the data from database to back.txt file
{
    int ret;
    ret=save(hashtable);
    if(ret == FAILURE)
    {
	printf("\t================>[ DATABASE IS EMPTY ]<=================\n");
    }
    else
    {
	printf("\t=============>[ DATA SAVED SUCCESSFULLY ]<===============\n");
    }
    break;

}


}
}
}

