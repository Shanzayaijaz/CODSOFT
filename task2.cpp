#include <iostream>
using namespace std;
int main(){
	cout<<"Enter the first number: ";
	double a,b;
	cin>>a;
	cout<<"Enter the second number: ";
	cin>>b;
	int option;
do{
cout<<"Enter the operation you want to perform \n1.Addition 2.Subraction 3.Multiplication 4.Division -1.Exit ";
	cin>>option;
	switch(option){
		case 1:
			cout<<"The sum of "<<a<<" and "<<b<<" is "<<a+b<<endl;
			break;
		case 2:
		  	cout<<"The differnce between "<<a<<" and "<<b<<" is "<<a-b<<endl;
			break;	
		case 3:
			cout<<"The product of "<<a<<" and "<<b<<" is "<<a*b<<endl;
			break;
		case 4:
			if(b!=0){
			cout<<"The quotient when "<<a<<" is divided by "<<b<<" is "<<a/b<<endl;}
			else
			cout<<"The number cannot be divided by a zero"<<endl;
			break;
		case -1:
            cout << "Exiting the program." << endl;
            break;
		default:
			cout<<"Enter a valid number"<<endl;
	}	} 	while(option!=-1);
}
