#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ifstream FileIn("taxi.txt");
    ofstream FileOut("earning_august.txt");
    
    if (!FileIn) 
	{
        cout << "Unable to open taxi.txt file";
		return EXIT_FAILURE;
    }
    
    if (!FileOut) 
	{
        cout << "Unable to open earning_august.txt file";
		return EXIT_FAILURE;
    }
    
    // Initialize cumulative variables
    double totalDistance = 0.0;
    double totalCost = 0.0;
    double longestTripDistance = 0.0;
    double leastExpensiveTripCost = 1000;
    
    int tripNumber = 1;
    int tripCounter = 0;
    
    FileOut  << setw(6) << "trip#" << setw(5) 
		     << "VIP" << setw(6) << "stops" << setw(9) 
			 << "tripDist" << setw(9) << "tripCost" << setw(9) 
			 << "totalDist" << setw(9) << "totalCost" << endl;
    
	int isVIP=99,  number_of_stops=99;
    while (FileIn>> isVIP >> number_of_stops) 
	{   
        double tripDistance = 0.0;
        double tripCost = 0.0;
        
        double first_x = 0.0;
        double first_y = 0.0;
        
        for (int count = 0; count < number_of_stops; count++) 
        {    
            double second_x=-99, second_y=-99;
			FileIn >> second_x >> second_y; 
           
            // Calculate the distance between stops
            double legDistance = sqrt(pow(first_x - second_x, 2) +
			pow(first_y - second_y, 2));
            tripDistance += legDistance;
            
            // Calculate the cost for the leg
            double legCost = legDistance * 2.60 + 15.00;
            tripCost += legCost;
            
            // Update previous coordinates
            second_x = first_x;
            second_y = first_y;
        }
        
        // Add the return trip cost
        double returnTripCost = number_of_stops * 2.60;
        tripCost += returnTripCost;
        
        // Apply VIP discount if applicable
        if (isVIP == 1) 
		{
            tripCost *= 0.75; // 25% discount
        }
        
        // Update cumulative variables
        totalDistance += tripDistance;
        totalCost += tripCost;
        longestTripDistance = max(longestTripDistance, tripDistance);
        leastExpensiveTripCost = min(leastExpensiveTripCost, tripCost);
        
        // Write to report file
        if (tripNumber <= 4 || (tripNumber - 4) % 10 == 0) 
		{
            FileOut << setw(6) << tripNumber << setw(5) << isVIP 
			<< setw(6) << number_of_stops << setw(9) << fixed 
			<< setprecision(2) << tripDistance << setw(9) << fixed 
			<< setprecision(2) << tripCost << setw(9) << fixed 
			<< setprecision(2) << totalDistance << setw(9) << fixed 
			<< setprecision(2) << totalCost << endl;
        }
        
        tripCounter++;
        tripNumber++;
    }
    
    // Write additional data to report file
    FileOut  << "Total distance traveled for the month: " 
			 << fixed << setprecision(2) << totalDistance << endl
    		 << "Total amount collected from all customers for the month: " 
			 << fixed << setprecision(2) << totalCost << endl
             << "Length of the longest trip: " << fixed 
			 << setprecision(2) << longestTripDistance << endl
             << "Cost of the least expensive trip: " << fixed 
			 << setprecision(2) << leastExpensiveTripCost << endl;
    
    // Close files
    FileIn.close();
    FileOut.close();
    
    return EXIT_SUCCESS;
}
