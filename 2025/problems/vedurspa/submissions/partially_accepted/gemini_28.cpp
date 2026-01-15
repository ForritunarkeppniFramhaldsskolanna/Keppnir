#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    double latitude, longitude, height;
    string initial_date, initial_time;
    cin >> latitude >> longitude >> height >> initial_date >> initial_time;

    vector<double> temperatures;
    vector<int> wind_directions;
    vector<double> wind_speeds;
    vector<int> humidities;

    for (int i = 0; i < n; ++i) {
        string temp_str, wind_dir_str, wind_speed_str, humidity_str;
        cin >> temp_str >> wind_dir_str >> wind_speed_str >> humidity_str;

        if (temp_str != "-") {
            temperatures.push_back(stod(temp_str));
        } else {
            temperatures.push_back(1000.0); // Use a sentinel value
        }

        if (wind_dir_str != "-") {
            wind_directions.push_back(stoi(wind_dir_str));
        } else {
             wind_directions.push_back(-1); //Sentinel value
        }

        if (wind_speed_str != "-") {
            wind_speeds.push_back(stod(wind_speed_str));
        } else {
            wind_speeds.push_back(1000.0);
        }
        
        if (humidity_str != "-") {
            humidities.push_back(stoi(humidity_str));
        } else {
            humidities.push_back(-1);
        }
    }

    for (int i = 0; i < m; ++i) {
        // Simple prediction: Use the last valid value.  If no valid values, output "-".

        double predicted_temp = (temperatures.back() != 1000.0) ? temperatures.back() : -1000.0;
        int predicted_wind_dir = (wind_directions.back() != -1) ? wind_directions.back() : -2;
        double predicted_wind_speed = (wind_speeds.back() != 1000.0) ? wind_speeds.back() : -1000.0;
        int predicted_humidity = (humidities.back() != -1) ? humidities.back() : -2;

        
        if (predicted_temp != -1000.0)
        {
            if(predicted_temp > 50.0)
                cout << fixed << setprecision(1) << 50.0 << " ";
            else if(predicted_temp < -50.0)
                cout << fixed << setprecision(1) << -50.0 << " ";
            else
                cout << fixed << setprecision(1) << predicted_temp << " ";
        }
        else
        {
            cout << "-" << " ";
        }
            
        if (predicted_wind_dir != -2)
        {
            if(predicted_wind_dir > 360)
                cout << 360 << " ";
            else if (predicted_wind_dir < 0)
                cout << 0 << " ";
            else
                cout << predicted_wind_dir << " ";
        }
        else
        {
            cout << "-" << " ";
        }

        if (predicted_wind_speed != -1000.0)
        {
            if(predicted_wind_speed > 80.0)
               cout << fixed << setprecision(1) << 80.0 << " ";
            else if (predicted_wind_speed < 0.0)
                cout << fixed << setprecision(1) << 0.0 << " ";
            else
                cout << fixed << setprecision(1) << predicted_wind_speed << " ";
        }
        else
        {
            cout << "-" << " ";
        }

        if (predicted_humidity != -2)
        {
            if(predicted_humidity > 110)
               cout << 110 << endl;
            else if(predicted_humidity < 0)
                cout << 0 << endl;
            else
                cout << predicted_humidity << endl;
        }
        else
        {
            cout << "-" << endl;
        }

        //Update values to use as last known.
        temperatures.push_back(predicted_temp);
        wind_directions.push_back(predicted_wind_dir);
        wind_speeds.push_back(predicted_wind_speed);
        humidities.push_back(predicted_humidity);
    }

    return 0;
}
