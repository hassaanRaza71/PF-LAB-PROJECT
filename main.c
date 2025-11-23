#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_ROOMS 10

typedef struct {
    int id;
    char name[50];
    char gender[10];
    int age;
    char disease[50];
    int room_no;
} Patient;

Patient patients[MAX_PATIENTS];
int patient_count = 0;

int rooms[MAX_ROOMS];


void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void show_rooms() {
    printf("\n--- Room Status ---\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i] == 0)
            printf("Room %d: Free\n", i + 1);
        else
            printf("Room %d: Occupied\n", i + 1);
    }
}

