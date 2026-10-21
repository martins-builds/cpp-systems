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
    std::stringstream ss(sentence);
    std::string field;
    std::vector<std::string> fields;

    while(std::getline(ss, field, ',')){
        fields.push_back(field);
    }

    if(fields.size() < 7 || fields[0] != "$GPRMC" || fields[2] != "A"){
        return false;
    }

    hours = std::stoi(fields[1].substr(0, 2));
    minutes = std::stoi(fields[1].substr(2, 2));
    seconds = std::stoi(fields[1].substr(4, 2));

    double lat_deg = std::stod(fields[3].substr(0, 2));
    double lat_min = std::stod(fields[3].substr(2));
    double final_latitude = lat_deg + (lat_min / 60.0);

    double lon_deg = std::stod(fields[5].substr(0, 3));
    double lon_min = std::stod(fields[5].substr(3));
    double final_longitude = lon_deg + (lon_min / 60.0);

    if (fields[4] == "S"){
        final_latitude = -final_latitude;
    }
    if (fields[6] == "W"){
        final_longitude = -final_longitude;
    }

    return false;
}

int main(){

}