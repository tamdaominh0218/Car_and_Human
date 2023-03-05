#include <iostream>
#include <map>
#include <vector>
using namespace std;

class car {
protected:
	static double seri_num;
	double seri;
	float power;
	float speed;
public:
	double getseri() const {
		return seri;
	}
	car(float po, float sp) {
		power = po;
		speed = sp;
		seri = seri_num;

		//getseri();
		seri_num++;
	}
	virtual void showinfo() = 0;
};
double car::seri_num = 0;
class normal : public car {
public:
	normal(float po, float sp) : car(po, sp) {}
	void showinfo() {
		cout << "Engine power of normal car is: " << power << endl;
		cout << "Engine speed of normal car is: " << speed << endl;
	}
};
class perfomance : public car {
protected:
	bool turbo_charger;
	float longitude, latitude;
public:
	perfomance(float po, float sp) : car(po, sp) {}
	void showinfo() {
		cout << "Engine power of perfomance car is: " << power << endl;
		cout << "Engine speed of perfomance car is: " << speed << endl;
	}
	void check_turbo() {
		if (turbo_charger == true)
		{
			speed += speed / 10;
		}
	}
	void navigating(float lon, float lat) {
		longitude = lon;
		latitude = lat;
	}
	double getlongtitude() {
		return longitude;
	}
	double getlatitude() {
		return latitude;
	}
};

class person {
public:
	virtual void drive() = 0;
	virtual void getcarInfo(car* car) = 0;
};
class engineer : public person {
public:
	void drive() {
		cout << "Driving car" << endl;
	}
	void getcarInfo(car* car) {
		cout << "Serial number is " << car->getseri() << endl;
		car->showinfo();
	}
	void program_navig(perfomance* car, float lon, float lat) {
		car->navigating(lon, lat);
		cout << "Navigating of the car: " << car->getlongtitude() << ", " << car->getlatitude() << endl;
	}
};
class user :public person {
public:
	void drive() {
		cout << "Driving a car: " << endl;
	}
	void getcarInfo(car* car) {
		car->showinfo();
	}
	void position(perfomance* car) {
		cout << "Position of the car: " << car->getlongtitude() << ", " << car->getlatitude() << endl;
	}
	void rent_car() {
		
	}
	void return_car() {}
};


int main() {

	engineer engi;
	user us;


	perfomance performanceCar(450, 100);
	normal normalCar(300, 200);
	normal normalCar2(150, 80);
	
	engi.getcarInfo(&performanceCar);
	engi.program_navig(&performanceCar, 11.2, 13.1);
	engi.getcarInfo(&normalCar);
	engi.getcarInfo(&normalCar2);

	return 0;

}