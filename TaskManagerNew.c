#include <stdio.h>
#include <string.h>

// Function to add a task
void addTask(char taskNames[50][10], int taskPriorities[10], int *taskCount)
{
    if (*taskCount < MAX_TASKS)
    {
        printf("Enter task name: ");
        // Use fgets to read input with spaces
        fgets(taskNames[*taskCount], 50, stdin);
        // Remove newline character from the end
        taskNames[*taskCount][strcspn(taskNames[*taskCount], "\n")] = '\0';

        printf("Enter task priority (1-10): ");
        scanf("%d", &taskPriorities[*taskCount]);

        (*taskCount)++;

        printf("Task added successfully!\n");
    }
    else
    {
        printf("Task manager is full. Cannot add more tasks.\n");
    }
}

// Function to display tasks
void displayTasks(char taskNames[10][50], int taskPriorities[10], int taskCount)
{
    if (taskCount > 0)
    {
        printf("Task Name\tPriority\n");
        for (int i = 0; i < taskCount; ++i)
        {
            printf("%s\t\t%d\n", taskNames[i], taskPriorities[i]);
        }
    }
    else
    {
        printf("No tasks available.\n");
    }
}

int main()
{
    char taskNames[10][50];
    int taskPriorities[10];
    int taskCount = 0;
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
            getchar(); // Consume the newline character left by scanf
            addTask(taskNames, taskPriorities, &taskCount);
            break;
        case 2:
            displayTasks(taskNames, taskPriorities, taskCount);
            break;
        case 3:
            printf("Exiting Task Manager.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
