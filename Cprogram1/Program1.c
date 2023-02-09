#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12



float calculateMonthlyAverage(const float *sales) {
    float totalSales, averageSales;
    for (int i = 0; i < MONTHS; ++i) {
        totalSales += sales[i];
    }
    averageSales = totalSales/MONTHS;
    return averageSales;
}

//Read input txt
float* read_data_from(char *file_name) {
    float* month_sales_data = (float*)malloc(sizeof(float) * MONTHS);
    FILE *fp = fopen(file_name, "r+");

    for (int i = 0; i < MONTHS; ++i) {
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }

    return month_sales_data;
}


void print_monthly_sales(const char *months[], const float *sales) {
    //MONTHLY SALES REPORT SECTION
    printf("\nMonthly sales report for 2023:\n");
    printf("Month      Sales\n");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%-10s $%-10.2f\n", months[i], sales[i]);
    }


   
}

void print_moving_averages(const char *months[], const float *sales) {
    //SIX MONTH MOVING AVERAGE SECTION
    printf("\nSix-Month Moving Average Report:\n");
    float sixMonthTotal;
    for (int i = 0; i < MONTHS/2 + 1; ++i) {
        sixMonthTotal = sales[i] + sales[i+1] + sales[i+2] + sales[i+3] + sales[i+4] + sales[i+5];
        printf("%-10s - %-10s $%-10.2f\n", months[i], months[i+5], sixMonthTotal/6);
    }
}



// MIN/MAX SALES SUMMARY SECTION
void print_min_max_sales(const char *months[], const float *sales) {

    printf("\nSales summary:\n");
    float minimum = sales[0], maximum = sales[0];
    int savedMinimumIndex = 0,savedMaximumIndex = 0;
    for (int i = 0; i < MONTHS; ++i) {
        if (sales[i] < minimum) {
            minimum = sales[i];
            savedMinimumIndex = i;
        }
        if (sales[i] > maximum) {
            maximum = sales[i];
            savedMaximumIndex = i;
        }
        if (i == MONTHS-1) {
            printf("Minimum sales: $%.2f  (%s)\n", minimum, months[savedMinimumIndex]);
            printf("Maximum sales: $%.2f  (%s)\n", maximum, months[savedMaximumIndex]);
            printf("Average sales: $%.2f\n", calculateMonthlyAverage(sales));
        }
    }
}


//Bubble sort section
void swap_float(float * one, float *two) {
    float temp = *one;
    *one = *two;
    *two = temp;
}

void swap_char(char ** one, char **two) {
    char* temp = *one;
    *one = *two;
    *two = temp;
}



//HIGHEST TO LOWEST SECTION
void print_highest_to_lowest(const char *months[], const float* sales) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month      Sales\n");
    
    float* sales_copy = (float*)malloc(sizeof(float) * MONTHS);
    for(int i = 0; i < MONTHS; ++i) {
        sales_copy[i] = sales[i];
    }

    char *months_copy[MONTHS];
    for(int i = 0; i < MONTHS; ++i) {
        char* month_copy = (char*)malloc(sizeof(char) * sizeof(months[i] + 1));
        strcpy(month_copy, months[i]);
        months_copy[i] = month_copy;
    }

    for(int i = 0; i < MONTHS; ++i) {
        for(int j = i; j < MONTHS; ++j) {
            if(sales_copy[j] > sales_copy[i]) {
                swap_float(&sales_copy[j] , &sales_copy[i]);
                swap_char(&months_copy[j],&months_copy[i]);
            }
        }
    }

    for(int i = 0; i < MONTHS; ++i) {
        printf("%-10s %-10.2f\n", months_copy[i], sales_copy[i]);
    }
}


int main() {
    float* sales = read_data_from("data.txt");
    const char *months[] = {"January","February","March", "April","May","June","July","August","September","October", "November","December"};
    
    print_monthly_sales(months, sales);
    print_min_max_sales(months,sales);
    print_moving_averages(months,sales);
    print_highest_to_lowest(months, sales);
    return 0;
}