#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

double RandomNR()
{
    random_device nr;
		return generate_canonical<double, 10>(nr);

}

class ISensor
{
public:
	virtual double readSensor() = 0;
};

class IRoom
{
public:
	virtual void readRoom() = 0;
	virtual void updateRoom() = 0;
	virtual void createRoom() = 0;
	virtual void deleteRoom() = 0;
};






class House
{
private:
	vector<IRoom*>rooms;
public:
	void addRoom(IRoom* r)
	{
		r->createRoom();
		rooms.push_back(r);
	}
	void removeRoom(int i)
	{
		rooms.at(i)->deleteRoom();
		rooms.erase(rooms.begin() + i);
		cout << endl << "Camera " << i << " a fost stearsa." << endl;

	}
	void collectRoomData()
	{
		for (auto r : rooms)
			r->updateRoom();
	}
	void viewRoomData()
	{
		for (auto r : rooms)
			r->readRoom();
	}
};







class Temperature : public ISensor
{
    const double min = -40;
    const double max = 80;
    const double x = max - min;


	double generateTemperature()
	{
		return min + x * RandomNR();
	}

public:
	double readSensor()
	{
		return generateTemperature();
	}
};

class Pressure : public ISensor
{
    const double min = 300;
    const double max = 1100;
    const double x = max - min;

	double generatePressure()
	{
		return min + x * RandomNR();
	}

public:
	double readSensor()
	{
		return generatePressure();
	}
};

class Humidity : public ISensor
{
    const double min = 0;
    const double max = 100;
    const double x = max - min;


	double generateHumidity()
	{
		return min + x * RandomNR();
	}
public:
	double readSensor()
	{
		return generateHumidity();
	}
};








class Bedroom : public IRoom
{
private:
	vector<ISensor*>sensors;
public:
	void createRoom()
	{
		ofstream f("Bedroom.txt");
	}
	void updateRoom()
	{
		ofstream f("Bedroom.txt");
		sensors.push_back(new Temperature);
		sensors.push_back(new Pressure);
		sensors.push_back(new Humidity);

		for (auto s : sensors)
			f << s->readSensor()<<" ";
	}
	void readRoom()
	{
		ifstream f("Bedroom.txt");
		double a, b, c;
		f >> a >> b >> c;

		a+=RandomNR();
		b+=RandomNR()+1;
		c+=RandomNR()+2;

		cout <<endl<< "Bedroom --> Temp:" << a << "C , Pressure: " << b << "hPa , Humidity:" << c << "%" << endl;
	}
	void deleteRoom()
	{
		remove("Bedroom.txt");
	}


};

class Bathroom : public IRoom
{
private:
	vector<ISensor*>sensors;
public:
	void createRoom()
	{
		ofstream f("Bathroom.txt");
	}
	void updateRoom()
	{
		ofstream f("Bathroom.txt");
		sensors.push_back(new Temperature);
		sensors.push_back(new Pressure);
		sensors.push_back(new Humidity);

		for (auto s : sensors)
			f << s->readSensor() << " ";
	}
	void readRoom()
	{
		ifstream f("Bathroom.txt");
		double a, b, c;
		f >> a >> b >> c;

		a+=RandomNR()+ 2.98;
		b+=RandomNR()+97.45;
		c+=RandomNR()+ 9.23;

		cout << endl << "Bathroom --> Temp:" << a << "C , Pressure: " << b << "hPa , Humidity:" << c << "%" << endl;
	}
	void deleteRoom()
	{
		remove("Bathroom.txt");
	}

};

class Living : public IRoom
{
private:
	vector<ISensor*>sensors;
public:
	void createRoom()
	{
		ofstream f("Living.txt");
	}
	void updateRoom()
	{
		ofstream f("Living.txt");
		sensors.push_back(new Temperature);
		sensors.push_back(new Pressure);
		sensors.push_back(new Humidity);

		for (auto s : sensors)
			f << s->readSensor() << " ";
	}
	void readRoom()
	{
		ifstream f("Living.txt");
		double a, b, c;
		f >> a >> b >> c;

		a+=RandomNR()-43.98;
		b+=RandomNR()-97.45;
		c+=RandomNR()- 29.23;

		cout << endl << "Living --> Temp:" << a << "C , Pressure: " << b << "hPa , Humidity:" << c << "%" << endl;
	}
	void deleteRoom()
	{
		remove("Living.txt");
	}


};

class Kitchen : public IRoom
{
private:
	vector<ISensor*>sensors;
public:
	void createRoom()
	{
		ofstream f("Kitchen.txt");
	}
	void updateRoom()
	{
		ofstream f("Kitchen.txt");
		sensors.push_back(new Temperature);
		sensors.push_back(new Pressure);
		sensors.push_back(new Humidity);

		for (auto s : sensors)
			f << s->readSensor() << " ";
	}
	void readRoom()
	{
		ifstream f("Kitchen.txt");
		double a, b, c;
		f >> a >> b >> c;

		a+=RandomNR()-87.98;

		cout << endl << "Kitchen --> Temp:" << a << "C , Pressure: " << b << "hPa , Humidity:" << c << "%" << endl;
	}
	void deleteRoom()
	{
		remove("Kitchen.txt");
	}

};





int main()
{
	House h;
	h.addRoom(new Bedroom);
	h.addRoom(new Living);
	h.addRoom(new Kitchen);
	h.addRoom(new Bathroom);
	h.collectRoomData();
	h.viewRoomData();
	cout << endl << "-------------------------------------------------------------------------" << endl;
	h.removeRoom(1);
	cout << endl << "-------------------------------------------------------------------------" << endl;
	h.viewRoomData();
}
