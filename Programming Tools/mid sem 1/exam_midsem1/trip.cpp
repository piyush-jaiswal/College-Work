#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int arPos;  // storing the position of ar which takes one line of input at a time from file.

struct flightDetails
{
    int flightNo;
    int depCity;
    int arrCity;
    int depTime;
    int arrTime;
};


// Calculates time between a and b in mins
int calTimeInMins(int a, int b)
{
    int ahrs, amin, bhrs, bmin;   
    
    ahrs = a / 100;
    bhrs = b / 100;
    
    amin = a % 100;
    bmin = b % 100;
    
    return (bhrs - ahrs)*60 + (bmin - amin);
}


// searches the flight which leaves from a destination
int searchFlightNo(flightDetails** flight, int noOfFlights, int dep)
{
    int i;
    
    for(i = 0; i < noOfFlights; i++)
    {
        if(flight[i] -> depCity == dep)
            return i;
    }
    
    return -1;
}


// searches for relevant flights
void searchforFlights(flightDetails** flight, int noOfFlights, int qDep, int qArr, int qT1, int qT2)
{
    int i = searchFlightNo(flight, noOfFlights, qDep);
    
    int a = flight[i] -> arrCity;
    int dt = flight[i] -> depTime;
    int ar = flight[i] -> arrTime;
    
    if(qArr == a && dt > qT1 && ar < qT2)
    {
        cout << calTimeInMins(dt, ar)/60 << " ";
        cout << flight[i] -> depCity << " " << flight[i] -> flightNo << endl;
        return;
    }
    
    cout << "-1" << endl;
}


// get a string delimeted by space or at the end
int getDetail(char *ar)
{
    int i = arPos, pos = 0;
    char temp[50], c;
    
    while(true)
    {
        c = ar[i];
        
        if(c == ' ' || c == '\0')
        {
            temp[pos] = '\0';
            arPos = i+1;
            return atoi(temp);
        }
        else
        {
            temp[pos++] = c;
            i++;
        }
    }
}


void trip()
{
    int noOfCities, noOfFlights, i, noOfQuery, qDep, qArr, qT1, qT2;
    char ar[100];
    ifstream inf;
    inf.open("flight_detail.txt");
    
    inf.get(ar, 100, '\n');
    inf.get();  // for skipping the '\n' of the input file
    noOfCities = atoi(ar);
    inf.get(ar, 100, '\n');
    inf.get();
    noOfFlights = atoi(ar);
    
    flightDetails** flight = new flightDetails*[noOfFlights];
    for(i=0; i<noOfFlights; i++)
        flight[i] = new flightDetails;
    
    // Inputting the flight schedules
    for(i = 0; i < noOfFlights; i++)
    {
        arPos = 0;
        inf.get(ar, 100, '\n');
        inf.get();
        
        flight[i] -> flightNo = getDetail(ar);
        flight[i] -> depCity = getDetail(ar);
        flight[i] -> arrCity = getDetail(ar);
        flight[i] -> depTime = getDetail(ar);
        flight[i] -> arrTime = getDetail(ar);
    }
    
    arPos = 0;
    inf.get(ar, 100, '\n');
    inf.get();
    noOfQuery = getDetail(ar);
    
    // Inputting the query
    for(i = 0; i < noOfQuery; i++)
    {
        arPos = 0;
        inf.get(ar, 100, '\n');
        inf.get();
        
        
        qDep = getDetail(ar);
        qArr = getDetail(ar);
        qT1 = getDetail(ar);
        qT2 = getDetail(ar);
        
        
        // searching relevant flights
        searchforFlights(flight, noOfFlights, qDep, qArr, qT1, qT2);
    }
    
    inf.close();
}
