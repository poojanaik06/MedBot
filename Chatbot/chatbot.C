#include <stdio.h>
#include <string.h>
void displayMenu() {
    printf("Welcome to the Medbot!\n");
    printf("Please select an option:\n");
    printf("1. General Health Advice\n");
    printf("2. Symptoms Check\n");
    printf("3. Schedule an Appointment\n");
    printf("4. Exit\n");
}
void generalAdvice() {
    printf("General Health Advice:\n");
    printf("- Eat a balanced diet.\n");
    printf("- Exercise regularly.\n");
    printf("- Get enough sleep (7-8 hours).\n");
    printf("- Stay hydrated by drinking plenty of water.\n");
}
void symptomsCheck() {
    char symptom[100];

    printf("What symptom are you experiencing? (e.g., fever, headache, cough)\n");
    scanf("%s", symptom);

    if (strcmp(symptom, "fever") == 0) {
        printf("You may have an infection. Please rest, stay hydrated, and monitor your temperature. Consider consulting a doctor if your fever persists.\n");
    } else if (strcmp(symptom, "headache") == 0) {
        printf("It could be due to stress, dehydration, or other causes. Drink water, take a break, and if it continues, consult a healthcare professional.\n");
    } else if (strcmp(symptom, "cough") == 0) {
        printf("A cough could be a sign of a cold or allergy. Drink warm fluids, and if it persists for more than a week, consult a doctor.\n");
    } else {
        printf("I'm not familiar with that symptom. Please consult a healthcare professional for further advice.\n");
    }
}


void scheduleAppointment() {
    char name[100];
    char date[20];
    char doc[50];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Enter the date you would like to schedule (e.g., 2024-09-10): ");
    scanf("%s", date);
    printf("enter the specialist with whom your appointment has to be confirmed :");
    scanf("%s",doc);
    printf("Thank you, %s. Your appointment has been scheduled for %s.\n", name, date);
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generalAdvice();
                break;
            case 2:
                symptomsCheck();
                break;
            case 3:
                scheduleAppointment();
                break;
            case 4:
                printf("Thank you for using the Medbot... Stay healthy!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
