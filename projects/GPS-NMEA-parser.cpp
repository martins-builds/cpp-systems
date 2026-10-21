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

    valid = true;

    hours = std::stoi(fields[1].substr(0, 2));
    minutes = std::stoi(fields[1].substr(2, 2));
    seconds = std::stoi(fields[1].substr(4, 2));

    double lat_deg = std::stod(fields[3].substr(0, 2));
    double lat_min = std::stod(fields[3].substr(2));
    latitude = lat_deg + (lat_min / 60.0);

    double lon_deg = std::stod(fields[5].substr(0, 3));
    double lon_min = std::stod(fields[5].substr(3));
    longitude = lon_deg + (lon_min / 60.0);

    if (fields[4] == "S"){
        latitude = -latitude;
    }
    if (fields[6] == "W"){
        longitude = -longitude;
    }

    return true;
}

int main(){
    GPSFix gps;

    // Test Case 1: A perfectly valid $GPRMC sentence
    // Time: 12:35:19 UTC | Valid (A) | Lat: 4807.038 N | Lon: 01131.000 E
    std::string valid_sentence = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    
    std::cout << "--- Testing Valid Sentence ---" << std::endl;
    if (gps.parse(valid_sentence)) {
        std::cout << "Parse Successful!" << std::endl;
        std::cout << "Time: " << gps.getHours() << ":" << gps.getMinutes() << ":" << gps.getSeconds() << " UTC" << std::endl;
        std::cout << "Latitude: " << gps.getLatitude() << "°" << std::endl;
        std::cout << "Longitude: " << gps.getLongitude() << "°" << std::endl;
        std::cout << "Is Valid Flag: " << (gps.isValid() ? "True" : "False") << std::endl;
    } else {
        std::cout << "Parse Failed (Unexpected)!" << std::endl;
    }

    std::cout << "\n----------------------------------------\n" << std::endl;

    // Test Case 2: An invalid sentence (Status is 'V' for Void/Receiver Warning)
    // Your short-circuit check 'fields[2] != "A"' should catch this and return false
    std::string invalid_status_sentence = "$GPRMC,123519,V,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    
    std::cout << "--- Testing Invalid Status ('V') Sentence ---" << std::endl;
    if (gps.parse(invalid_status_sentence)) {
        std::cout << "Parse Successful (Unexpected behavior)!" << std::endl;
    } else {
        std::cout << "Parse Failed as expected (Sentence is marked Void/Invalid)." << std::endl;
    }

    std::cout << "\n----------------------------------------\n" << std::endl;

    // Test Case 3: A truncated/malformed sentence
    // Your short-circuit check 'fields.size() < 7' will catch this and exit instantly,
    // protecting your code from an out-of-bounds crash on missing indices!
    std::string broken_sentence = "$GPRMC,123519,A,4807.038,N";
    
    std::cout << "--- Testing Truncated Sentence ---" << std::endl;
    if (gps.parse(broken_sentence)) {
        std::cout << "Parse Successful (Unexpected behavior)!" << std::endl;
    } else {
        std::cout << "Parse Failed as expected (Sentence was safely rejected due to small size)." << std::endl;
    }

    return 0;
}