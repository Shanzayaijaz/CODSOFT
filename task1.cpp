#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int generateRandomNum(){
    int randomNum = rand() % 10 + 1;
    return randomNum;
}

int main(){
int guess;
cout<<"Welcome to the number guessing game"<<endl<<endl;
cout<<"Think of a number between 1 and 10"<<endl;
cout<<"Enter your guess: ";
cin>>guess;
srand(time(0));
int random=generateRandomNum();
cout<<"Random number: "<<random<<endl;
if(guess==random){
    cout<<"Congratulations, you guessed the number "<<endl;
}
else{
    if(random<guess){
    	cout<<"Your guess is higher than the random number"<<endl;
    	
	}
	if(random>guess){
		cout<<"Your guess is lower than the random number"<<endl;
	}
}

}
