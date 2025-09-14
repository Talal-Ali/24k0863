#include <iostream>
using namespace std;

template <typename T>
class WeatherData{
    private:
    T temperature;
    T humidity;
    T air_pressure;
    public:
    WeatherData(T temp, T hum, T press): temperature(temp), humidity(hum), air_pressure(press){}

    void print_data(){
        cout<<"Temperature: "<<temperature<<" C"<<endl;
        cout<<"Humidity: "<<humidity<<" %"<<endl;
        cout<<"Air Pressure: "<<air_pressure<<" kPa"<<endl;
    }
};

int main(){
    WeatherData<double> data1(25.6, 70.2, 101.3);
    data1.print_data();
    cout<<"-----------------------------------------"<<endl;
    WeatherData<int> data2(20, 65, 100);
    data2.print_data();
    return 0;
 
}