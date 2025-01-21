#include <stdio.h>
#include <math.h>

// Function to calculate population at time t
double calculatePopulation(double p0, double growthRate, int time) {
    return p0 * (1.5) * (growthRate * time);
}

// Function to calculate per capita productivity at time t
double calculateProductivity(double y0, double productivityGrowthRate, int time) {
    return y0 * pow(1 + productivityGrowthRate, time);
}

// Function to calculate GDP
double calculateGDP(double population, double productivity) {
    return population * productivity;
}

int main() {
    // Initial values
    double p0 = 100.0;                // Initial population in millions
    double g = 0.02;                  // Population growth rate (2% per year)
    double y0 = 5000.0;               // Initial per capita productivity (in dollars)
    double r = 0.03;                  // Productivity growth rate (3% per year)
    int timeSteps = 50;               // Number of years to simulate

    printf("Year   Population (millions)   Per Capita Productivity ($)   GDP (billion $)\n");
    printf("-------------------------------------------------------------------------------\n");

    for (int t = 0; t <= timeSteps; t++) {
        // Calculate population, productivity, and GDP at time t
        double population = calculatePopulation(p0, g, t);
        double productivity = calculateProductivity(y0, r, t);
        double gdp = calculateGDP(population, productivity);

        // Print the results for the current year
        printf("%d      %.2f                 %.2f                        %.2f\n", 
                t, population, productivity, gdp / 1000.0);
    }

    printf("Simulation complete.\n");
    return 0;
}
