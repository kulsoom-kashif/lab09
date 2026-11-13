#include <stdio.h>
#include <string.h>

int main(){
	char firstname[10], lastname[10], regID[8], fullname[20] , depname[20], profile[5], *ptr;
	
	//1. taking name input
	printf("Enter the first name: ");
	fgets(firstname, 10, stdin);
	firstname[strcspn(firstname, "\n")] = '\0';
	
	printf("Enter the last name: ");
	fgets(lastname, 10, stdin);
	lastname[strcspn(lastname, "\n")]='\0';
	
	printf("Enter the department name: ");
	fgets(depname, 20, stdin);
	
	printf("Enter the registration id: ");
	fgets(regID, 8, stdin);
	
	//2.calculating and display no of char 
	printf("lenght of firstname is :%u ", strlen(firstname)); 
	printf("lenght of lastname is :%u ", strlen(lastname));
	
	//3. 
	strcpy(fullname, firstname);
	
	//4 merge first and last name
	strcat(fullname, " ");
	strcat(fullname, lastname);
	
	//5.
	strncpy(profile, depname, 4);
    profile[4] = '\0';
    //6
        if (strcmp(depname, "Computer Science") == 0)
    {
        printf("\nStudent belongs to Computer Science department.");
    }
    else
    {
        printf("\nStudent does not belong to Computer Science department.");
    }

	//7.
	if (strncmp(regID, "26k-", 4) == 0)
	{
        printf("\nRegistration ID starts with 26k-.");
    }
    else
    {
        printf("\nRegistration ID does not start with 26k-.");
    }
    
    // 8. Find first occurrence of 'a'
    ptr = strchr(fullname, 'a');

    if (ptr != NULL)
    {
        printf("\nFirst occurrence of 'a' is at position: %ld",
               (long)(ptr - fullname));
    }
    else
    {
        printf("\nCharacter 'a' not found.");
    }

    // 9. Search for Science in department
    if (strstr(depname, "Science") != NULL)
    {
        printf("\nThe word Science exists in department name.");
    }
    else
    {
        printf("\nThe word Science does not exist in department name.");
    }
	
	return 0;
}