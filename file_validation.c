#include<stdio.h>
#include<string.h>
#include"main.h"
int file_validate(int argc, char *argv[])
{
    FILE *fptr;
    
	printf("---------------------------------------------------------------------\n");
    if(argc > 1)     //checking conditon for command line arguments more than one 
    {
	for(int i=1;i<argc;i++)
	{
	    if(strstr(argv[i],".txt")==0)   //file is .txt file or not
	    {
		printf("[ %s ] is not a [.txt] file      arg[%d]\n\n",argv[i],i);
		argv[i] = NULL;
	    }

	    if(argv[i] != NULL)
	    {
	        fptr=fopen(argv[i],"r"); 
	        if(fptr == NULL)          //file exist or not
	        {
		    printf("FILE NOT EXIST    >>>    [ %s ]    arg[%d]\n\n",argv[i],i);
		    argv[i] = NULL ;
	        }
	        else if(fptr != NULL)
	        {
	            fseek(fptr,0,SEEK_END);
	            if(ftell(fptr)==0)    //file empty or not
	            {
	 	        printf("Empty file    >>>    [ %s ]    arg[%d]\n\n",argv[i],i);
		        argv[i]= NULL;
	            } 
	        }
	    }
	    
	}
	printf("---------------------------------------------------------------------\n");
	return SUCCESS;
    }
    else
        printf("Atleast one more argument is needed\n");
	return FAILURE;
}
