#include <stdio.h>
#include <string.h>

int main()
{
    char names[30][50];
    char readNames[30][50];
    int N, i;
    int maxLength = 0;
    int longestIndex = 0;

    FILE *fp;

    // Input number of students
    printf("Enter number of students (Max 30): ");
    scanf("%d", &N);
    getchar(); 

    if (N < 1 || N > 30)
    {
        printf("Invalid number of students!");
        return 1;
    }

    
    for (i = 0; i < N; i++)
    {
        printf("Enter name of student %d: ", i + 1);

        fgets(names[i], sizeof(names[i]), stdin);

    
        names[i][strcspn(names[i], "\n")] = '\0';
    }


    fp = fopen("student.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    
    for (i = 0; i < N; i++)
    {
        fprintf(fp, "%s\n", names[i]);
    }

    fclose(fp);

    printf("\nNames successfully saved to student.txt\n");

    
    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("Error reading file!");
        return 1;
    }

    for (i = 0; i < N; i++)
    {
        if (fgets(readNames[i], sizeof(readNames[i]), fp) == NULL)
        {
            printf("Error reading names!");
            fclose(fp);
            return 1;
        }

        readNames[i][strcspn(readNames[i], "\n")] = '\0';
    }

    fclose(fp);

    printf("\nStudent Names and Their Lengths:\n");

    for (i = 0; i < N; i++)
    {
        int length = strlen(readNames[i]);

        printf("%s - Length: %d\n", readNames[i], length);

        if (length > maxLength)
        {
            maxLength = length;
            longestIndex = i;
        }
    }
    printf("\nLongest Name: %s", readNames[longestIndex]);
    printf("\nLength of Longest Name: %d\n", maxLength);

    return 0;
}
