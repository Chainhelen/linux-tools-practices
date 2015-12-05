#include <stdio.h>  
#include <dirent.h>  
int main(int argc,char *argv[])  
{  
    DIR *dirptr = NULL;  
    struct dirent *entry;  
    if((dirptr = opendir(argv[1])) == NULL)  
    {  
        printf("open dir ! \n");  
        return 1;  
    }  
    else  
    {  
        while (entry = readdir(dirptr))  
        {  
            printf("%s\n", entry->d_name);
        }  
        closedir(dirptr);  
    }  
    return 0;  
}  
