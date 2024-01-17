#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int priority;
} Task;

void addTask(Task **tasks, int *numTasks)
{
    Task newTask;

    printf("Enter task name: ");
    scanf("%s", newTask.name);

    printf("Enter task date (YYYY-MM-DD): ");
    scanf("%s", newTask.date);

    printf("Enter priority (1-10): ");
    scanf("%d", &newTask.priority);

    (*numTasks)++;
    *tasks = realloc(*tasks, (*numTasks) * sizeof(Task));
    (*tasks)[*numTasks - 1] = newTask;

    printf("Task added successfully!\n");
}

void displayTasks(Task *tasks, int numTasks)
{
    if (numTasks == 0)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\nTasks:\n");
    for (int i = 0; i < numTasks; i++)
    {
        printf("Name: %s, Date: %s, Priority: %d\n", tasks[i].name, tasks[i].date, tasks[i].priority);
    }
}

int main()
{
    Task *tasks = NULL;
    int numTasks = 0;
    int choice;

    do
    {
        printf("\nTask Manager Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask(&tasks, &numTasks);
            break;
        case 2:
            displayTasks(tasks, numTasks);
            break;
        case 3:
            free(tasks);
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
