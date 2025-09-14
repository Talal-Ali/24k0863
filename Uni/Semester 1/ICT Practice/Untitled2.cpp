#include<iostream>
#include<string>

using namespace std;

class Employee
{
	protected:
		string name;
		int id;
		int salary;
	public:
		Employee(string n, int i, int sal): name(n), id(i), salary(sal){}
		
		virtual string getDetails()
		{
			return "ID: "+to_string(id) + "name: "+ name; 
		}
		virtual int calSalary() const
		{
			return salary;
		}
	//	virtual ~Employee() {}
};

class FullTimeEmployee: public Employee
{
	public:
		FullTimeEmployee(string n, int i, int sal): Employee(n, i, sal){}
		string getDetails()
		{
			return "ID: "+ to_string(id) + " name: "+ name + " Salary: " + to_string(salary);
		}
		
};

class PartTimeEmployee: public Employee
{
	protected:
		float rate;
		int hours;
	public:
		PartTimeEmployee(string n, int i, int s, float r, int h): Employee(n, i, (int)r*h), rate(r), hours(h){}
		string getDetails()
		{
			return "ID: "+to_string(id) + " name: "+ name + "Rate: "+ to_string(rate) + "Hours: " + to_string(hours);
		}
		
		int calSalary() const override {
    			return hours * rate;
		}

};

class ContractEmployee: Employee
{
	private:
		int projComp;
		
		
};
int main()
{
	FullTimeEmployee fte("John Doe", 1234, 4000);
	cout<< fte.getDetails()<<endl;
}