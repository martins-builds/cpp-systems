#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

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
    double getLongitude() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool isValid() const;
    bool parse(const std::string& sentence);
};

GPSFix::GPSFix(){
    latitude = 0.0;
    longitude = 0.0;
    hours = 0;
    minutes = 0;
    seconds = 0;
    valid = 0;
}

double GPSFix::getLatitude() const{
    return latitude;
}

double GPSFix::getLongitude() const{
    return longitude;
}
int GPSFix::getHours() const{
    return hours;
}
int GPSFix::getMinutes() const{
    return minutes;
}
int GPSFix::getSeconds() const{
    return seconds;
}
bool GPSFix::isValid() const{
    return valid;
}
bool GPSFix::parse(const std::string& sentence){

}

int main(){

}