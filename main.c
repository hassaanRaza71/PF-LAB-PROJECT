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

  p.room_no = assign_room();
    if (p.room_no == -1) {
        printf("No rooms available. Cannot admit patient.\n");
        return;
    }

    patients[patient_count] = p;
    patient_count++;

    printf("Patient added! Assigned Room: %d\n", p.room_no);
}

void list_patients() {
    if (patient_count == 0) {
        printf("No patients available.\n");
        return;
    }

    printf("\n--- Patient List ---\n");
    for (int i = 0; i < patient_count; i++) {
        printf("ID: %d\nName: %s\nGender: %s\nAge: %d\nDisease: %s\nRoom: %d\n\n",
               patients[i].id,
               patients[i].name,
               patients[i].gender,
               patients[i].age,
               patients[i].disease,
               patients[i].room_no);
    }
}
void search_patient() {
    char buffer[20];
    int id;

    printf("Enter patient ID to search: ");
    fgets(buffer, sizeof(buffer), stdin);
    id = to_int(buffer);

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("\nPatient Found:\n");
            printf("ID: %d\nName: %s\nGender: %s\nAge: %d\nDisease: %s\nRoom: %d\n",
                   patients[i].id,
                   patients[i].name,
                   patients[i].gender,
                   patients[i].age,
                   patients[i].disease,
                   patients[i].room_no);
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
}

void delete_patient() {
    char buffer[20];
    int id;

    printf("Enter patient ID to delete: ");
    fgets(buffer, sizeof(buffer), stdin);
    id = to_int(buffer);

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            free_room(patients[i].room_no);

            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }

            patient_count--;
            printf("Patient deleted and room freed!\n");
            return;
        }
    }

    printf("Patient with ID %d not found.\n", id);
}





int main() {
    char buffer[10];
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. List Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Show Rooms\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        fgets(buffer, sizeof(buffer), stdin);
        choice = to_int(buffer);

        if (choice == 1) add_patient();
        else if (choice == 2) list_patients();
        else if (choice == 3) search_patient();
        else if (choice == 4) delete_patient();
        else if (choice == 5) show_rooms();
        else if (choice == 6) break;
        else printf("Invalid choice!\n");
    }
