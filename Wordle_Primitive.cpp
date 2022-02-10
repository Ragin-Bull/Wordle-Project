#include<bits/stdc++.h>
#include <fstream>
#include <stdio.h>  
#include <stdlib.h>     
#include <time.h>       
using namespace std;

int main(){
    vector<string> collection{};
    collection.reserve(10000);

    /*Import the file and the store all the words in a vector called collection*/

    ifstream file("test.txt");
    if(file.is_open())
    {

        for(int i = 0; i < 5756; ++i)
        {
            string x;
            file >> x;
            collection.push_back(x);
        }
    file.close();
    } 
    /*Random Number Generator*/
    int randomNumber;
    srand(time(NULL));
    randomNumber = rand()%5757 + 1;

    cout<<"*************** WORDLE TIME ***************"<<endl;
    cout<<"Don't lie you know the rules, so lets begin!!"<<endl;
    string word = collection[randomNumber];
    string guess;
    int i=0;
    cout<<"Enter your word: ";
    while(i<6){
        cin>>guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (guess.length()==5){

            if(guess==word){
                cout<<"Wordle "<<i+1<<"/6"<<endl;
                cout<<"Congratulations!! you got this right. "<<guess<<" is the word."<<endl;
                break;
            }
            else{
                for(int j=0; j<5; j++){
                    if (guess[j]==word[j])
                        cout<<guess[j]<<" in green  ";
                    else if (word.find(guess[j])==0 || word.find(guess[j])==1 || word.find(guess[j])==2 || word.find(guess[j])==3 || word.find(guess[j])==4){
                        cout<<guess[j]<<" in yellow  ";
                    }
                    else{
                        cout<<guess[j]<<" in black  ";
                    }
                }
            }
            cout<<"\n";
            i++;
        }
        else{
            cout<<"ENTER A 5-LETTER WORD DAMMN IT!!"<<"\n";
            continue;
        }
    }
    if(i==6)
        cout<<"\n"<<"You failed to guess the right word, better luck next time!! By the way the correct word was "<<word<<endl;

    return 0;

}