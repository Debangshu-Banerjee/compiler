#include<bits/stdc++.h>

using namespace std;

int main(){

double id;

string name;

double salary;

ifstream fp("Employee");

string a12b;


getline(fp,a12b);

cout<<a12b<<endl;
while (getline(fp,a12b)){

	stringstream check1(a12b);
	string intermediate;


	getline(check1, intermediate, ',');
	id = stod(intermediate);


	getline(check1, intermediate, ',');
	name = intermediate;


	getline(check1, intermediate, ',');
	salary = stod(intermediate);


	if((salary<200&&name=="John")||(id>3)){
		cout<<a12b<<endl;
	}

}
fp.close();

}
