#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_GROUP_SIZE 3
#define MAX_NUM_GROUPS 100

int main() {
    char names[MAX_NUM_GROUPS][MAX_GROUP_SIZE][MAX_NAME_LENGTH];
    int num_groups = 0;
    int num_names = 0;

    while (1) {
        char name[MAX_NAME_LENGTH];
        printf("Enter a name (or 'q' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break;
        }
        strcpy(names[num_groups][num_names], name);
        num_names++;
        if (num_names == MAX_GROUP_SIZE) {
            num_groups++;
            num_names = 0;
            if (num_groups == MAX_NUM_GROUPS) {
                printf("Max number of groups reached.\n");
                break;
            }
        }
    }

    // print out the groups
    printf("Groups:\n");
    for (int i = 0; i < num_groups; i++) {
        printf("%s, %s, %s\n", names[i][0], names[i][1], names[i][2]);
    }

    return 0;
}

