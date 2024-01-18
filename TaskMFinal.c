#include <stdio.h>
#include <stdlib.h>

// Function to add a task
void addTask(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int *taskCount);

// Function to display tasks
void displayTasks(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int taskCount);

// Function to sort the task by priority level
void sortByPriority(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int taskCount);

// Function to sort the task by the earliest date
void sortByDate(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int taskCount);

// Function used by sortbypripriority and sortbydate functions to change the array placements.
void swaptask(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int index1, int index2);

int main()
{
    // Initialised all data
    char taskNames[10][50];
    int taskPriorities[10];
    char taskDates[10][6];
    int taskCount = 0;
    int choice;

    do
    {
        printf("\nTask Manager Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Sort by Date\n");
        printf("4. Sort by Priority\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getchar(); // Remove the newline character left by fgets
            addTask(taskNames, taskPriorities, taskDates, &taskCount);
            break;
        case 2:
            displayTasks(taskNames, taskPriorities, taskDates, taskCount);
            break;
        case 3:
            sortByDate(taskNames, taskPriorities, taskDates, taskCount);
            printf("Tasks sorted by date.\n");
            break;
        case 4:
            sortByPriority(taskNames, taskPriorities, taskDates, taskCount);
            printf("Tasks sorted by priority.\n");
            break;
        case 5:
            printf("Exiting Task Manager.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // to loop the function and end the task when user ask for it

    return 0;
}
// funtion to add task
void addTask(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int *taskCount)
{
    if (*taskCount < 10)
    {
        printf("Enter task name: ");
        // Use fgets to read input with spaces
        fgets(taskNames[*taskCount], 50, stdin);
        // Remove newline character from the end
        char *newlinePos = strchr(taskNames[*taskCount], '\n');
        if (newlinePos != NULL)
        {
            *newlinePos = '\0';
        }
        printf("Enter task priority (1-10): ");
        scanf("%d", &taskPriorities[*taskCount]);

        printf("Enter task date (DD/MM): ");
        scanf("%5s", taskDates[*taskCount]);

        (*taskCount)++;

        printf("Task added successfully!\n");
    }
    else
    {
        printf("Task manager is full. Cannot add more tasks.\n");
    }
}

void displayTasks(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int taskCount)
{
    if (taskCount > 0)
    {
        printf("\n\n%-30s %-10s %-10s\n", "Task Name", "Priority", "Date");
        printf("------------------------------------------------\n");
        for (int i = 0; i < taskCount; ++i)
        {
            printf("%-30s %-10d %-10s\n", taskNames[i], taskPriorities[i], taskDates[i]);
        }
    }
    else
    {
        printf("No tasks available.\n");
    }
}

void sortByPriority(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int taskCount)
{
    for (int i = 0; i < taskCount - 1; i++)
    {
        for (int j = 0; j < taskCount - i - 1; j++)
        {
            // Compare priorities
            if (taskPriorities[j] < taskPriorities[j + 1])
            {
                // Swap tasks if needed
                swaptask(taskNames, taskPriorities, taskDates, j, j + 1);
            }
        }
    }
}

void sortByDate(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int taskCount)
{
    for (int i = 0; i < taskCount - 1; i++)
    {
        for (int j = 0; j < taskCount - i - 1; j++)
        {
            // Extract day, month, and year from dates
            int day1, month1;
            sscanf(taskDates[j], "%d/%d", &day1, &month1);

            int day2, month2;
            sscanf(taskDates[j + 1], "%d/%d", &day2, &month2);

            // Convert to a comparable integer representation (e.g., YYYYMMDD)
            int date1 = month1 * 100 + day1;
            int date2 = month2 * 100 + day2;

            // Compare dates numerically
            if (date1 > date2)
            {
                // Swap tasks if needed
                swaptask(taskNames, taskPriorities, taskDates, j, j + 1);
            }
        }
    }
}

void swaptask(char taskNames[10][50], int taskPriorities[10], char taskDates[10][6], int index1, int index2)
{
    for (int i = 0; i < 50; i++)
    {
        char temp = taskNames[index1][i];
        taskNames[index1][i] = taskNames[index2][i];
        taskNames[index2][i] = temp;
    }

    // Swap taskPriorities
    int tempPriority = taskPriorities[index1];
    taskPriorities[index1] = taskPriorities[index2];
    taskPriorities[index2] = tempPriority;

    // Swap taskDates
    for (int i = 0; i < 6; i++)
    {
        char temp = taskDates[index1][i];
        taskDates[index1][i] = taskDates[index2][i];
        taskDates[index2][i] = temp;
    }
}