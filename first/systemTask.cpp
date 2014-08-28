#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct TASK_ID {
    int value;
    int index;
}taskId;


void scheduler(int task[], int n, int system_task[], int user_task[])
{
    taskId* task_id = (taskId*)malloc(sizeof(taskId) * n);
    for (int i = 0; i < n; ++i)
    {
        task_id[i].value = task[i];
        task_id[i].index = i;
    }

    for (int i = 1; i < n; ++i)
    {
        int tmpValue = task_id[i].value;
        int j = 0;
        for (j = i - 1; j >= 0 && task_id[j].value > tmpValue; j--)
        {
            task_id[j + 1] = task_id[j];
        }
        task_id[j + 1].value = tmpValue;
        task_id[j + 1].index = i;
    }

    for (int i = 0; i < n; ++i)
    {
        if (task_id[i].value < 50)
        {
            *system_task++ = task_id[i].index;
            continue;
        }

        if (task_id[i].value < 255)
        {
            *user_task++ = task_id[i].index;
            continue;
        }
    }

    *system_task = -1;
    *user_task = -1;

    free(task_id);
}


int systemTask(int argc, char* argv[])
{
    char str[1024] = {'\0'};
    int task[1024] = {0};
    int system_task[1024] = {0};
    int user_task[1024] = {0};

    fgets(str, 1024, stdin);
    int i = 0;
    char* tmpStr = strtok(str, " ");
    while (tmpStr != NULL) {
        int tmpValue = atoi(tmpStr);
        tmpStr = strtok(NULL, " ");
        if (tmpValue > 255 || tmpValue < 0)
            continue;

        task[i] = tmpValue;
        i++;
    }

    int len = i;
    scheduler(task, len, system_task, user_task);

    return 0;
}
