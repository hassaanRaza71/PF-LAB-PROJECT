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

int assign_room() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i] == 0) {
            rooms[i] = 1;
            return i + 1;
        }
    }
    return -1;
}

void free_room(int room_no) {
    if (room_no > 0 && room_no <= MAX_ROOMS) {
        rooms[room_no - 1] = 0;
    }
}

void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Patient list full!\n");
        return;
    }

    Patient p;
    p.id = patient_count + 1;


printf("Enter Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    remove_newline(p.name);

    printf("Enter Gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    remove_newline(p.gender);

    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();

    printf("Enter Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    remove_newline(p.disease);

