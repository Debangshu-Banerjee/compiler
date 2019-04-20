#include<bits/stdc++.h>

using namespace std;

int main(){

double id;

string name;

double salary;

ifstream fp("Employee");

string a12b;

while (getline(fp,a12b)){

	stringstream check1(a12b);
	string intermediate;
	getline(check1, intermediate, ',');
	cout<<intermediate;


	getline(check1, intermediate, ',');
	cout<<","<<intermediate;


	getline(check1, intermediate, ',');
	cout<<","<<intermediate;


cout<<endl;

}
fp.close();

}
