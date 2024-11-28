#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void enterGrades(int grades[], int n);
void displayGrades(int grades[], int n);
float calculateAverage(int grades[], int n);
void determineGradeCategory(float avg);
void sortGrades(int grades[], int n);
int findHighestGrade(int grades[], int n);
int findLowestGrade(int grades[], int n);
void saveResultsToFile(int grades[], int n, float average);

int main() {
    int choice, n;
    int grades[100]; 
    float average;

    do {
        // Display menu
        printf("\n========== Grade Management System ==========\n");
        printf("1. Enter Grades\n");
        printf("2. Display Grades\n");
        printf("3. Calculate Average and Determine Grade\n");
        printf("4. Sort Grades\n");
        printf("5. Find Highest and Lowest Grades\n");
        printf("6. Save Results to File\n");
        printf("7. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of grades (max 100): ");
                scanf("%d", &n);
                if (n > 0 && n <= 100) {
                    enterGrades(grades, n);
                } else {
                    printf("Invalid number of grades. Please enter between 1 and 100.\n");
                }
                break;

            case 2:
                displayGrades(grades, n);
                break;

            case 3:
                average = calculateAverage(grades, n);
                printf("\nAverage Grade: %.2f\n", average);
                determineGradeCategory(average);
                break;

            case 4:
                sortGrades(grades, n);
                printf("Grades sorted successfully!\n");
                break;

            case 5: {
                int highest = findHighestGrade(grades, n);
                int lowest = findLowestGrade(grades, n);
                printf("Highest Grade: %d\n", highest);
                printf("Lowest Grade: %d\n", lowest);
                break;
            }

            case 6:
                average = calculateAverage(grades, n);
                saveResultsToFile(grades, n, average);
                printf("Results saved to 'results.txt'.\n");
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

void enterGrades(int grades[], int n) {
    printf("Enter %d grades:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%d", &grades[i]);
    }
    printf("Grades entered successfully.\n");
}

void displayGrades(int grades[], int n) {
    printf("Grades:\n");
    for (int i = 0; i < n; i++) {
        printf("Grade %d: %d\n", i + 1, grades[i]);
    }
}

float calculateAverage(int grades[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += grades[i];
    }
    return (float)sum / n;
}

void determineGradeCategory(float avg) {
    if (avg >= 90) {
        printf("Grade: A (Excellent)\n");
    } else if (avg >= 80) {
        printf("Grade: B (Good)\n");
    } else if (avg >= 70) {
        printf("Grade: C (Average)\n");
    } else if (avg >= 60) {
        printf("Grade: D (Below Average)\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
}

void sortGrades(int grades[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                int temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }
}

int findHighestGrade(int grades[], int n) {
    int highest = grades[0];
    for (int i = 1; i < n; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
    }
    return highest;
}

int findLowestGrade(int grades[], int n) {
    int lowest = grades[0];
    for (int i = 1; i < n; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    return lowest;
}

void saveResultsToFile(int grades[], int n, float average) {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Grades:\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "Grade %d: %d\n", i + 1, grades[i]);
    }

    fprintf(file, "\nAverage Grade: %.2f\n", average);
    if (average >= 90) {
        fprintf(file, "Grade: A (Excellent)\n");
    } else if (average >= 80) {
        fprintf(file, "Grade: B (Good)\n");
    } else if (average >= 70) {
        fprintf(file, "Grade: C (Average)\n");
    } else if (average >= 60) {
        fprintf(file, "Grade: D (Below Average)\n");
    } else {
        fprintf(file, "Grade: F (Fail)\n");
    }

    fclose(file);
    printf("Results written to 'results.txt'.\n");
}
