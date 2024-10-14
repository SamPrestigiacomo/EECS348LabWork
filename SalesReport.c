#include <stdio.h>

#define NUM_MONTHS 12

// Function declarations
void printMonthlySalesReport(double sales[]);
void printSalesSummaryReport(double sales[]);
void printSixMonthMovingAverage(double sales[]);
void printSalesReportHighestToLowest(double sales[]);

// Define months
const char* months[] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

int main() {
    // Sample data
    double sales[NUM_MONTHS] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
    };

    // Generate reports
    printMonthlySalesReport(sales);
    printSalesSummaryReport(sales);
    printSixMonthMovingAverage(sales);
    printSalesReportHighestToLowest(sales);

    return 0;
}

void printMonthlySalesReport(double sales[]) {
    printf("Monthly Sales Report for 2024\n");
    printf("Month     Sales\n");
    // Iterate through each month
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s: %.2f\n", months[i], sales[i]);
    }
    printf("\n");
}
void printSalesSummaryReport(double sales[]) {
    double min = sales[0], max = sales[0], total = 0;
    int minMonth = 0, maxMonth = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }
    printf("Sales Summary Report:\n");
    printf("Minimum sales: %.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: %.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: %.2f\n", total/12);
    printf("\n");
}
void printSixMonthMovingAverage(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= 12 - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s: %.2f\n", months[i], months[i +5], sum / 6);

    }
    printf("\n");
}
void printSalesReportHighestToLowest(double sales[]) {
    double sortedSales[12];
    int sortedMonths[12];

    for (int i = 0; i < 12; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = i;
    }

    // Sort sales in descending order
    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - 1 - i; j++) {
            if (sortedSales[j] < sortedSales[j+1]) {
                // Swap sales
                double tempSales = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = tempSales;

                // Swap months
                int tempMonth = sortedMonths[j];
                sortedMonths[j] = sortedMonths[j + 1];
                sortedMonths[j + 1] = tempMonth;
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month     Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s: %.2f\n", months[sortedMonths[i]], sortedSales[i]);
    }
    printf("\n");
}