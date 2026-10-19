class GPSFix{
private:
    double latitude;    // Decimal degrees
    double longitude;   // Decimal degrees
    int hours;          // UTC time: hours (0-23)
    int minutes;        // UTC time: minutes (0-59)
    int seconds;        // UTC time: seconds (0-59)
    bool valid;         // Status flag: true if fix is valid, false otherwise

public:
    GPSFix();

    double getLatitude() const;
};

GPSFix::GPSFix(){
    latitude = 0.0;
    longitude = 0.0;
    hours = 0;
    minutes = 0;
    seconds = 0;
    valid = 0;
}

#include <iostream>
using namespace std;

int main(){

}