#include<fstream>
#include<iostream>
#include<string>

int main(){
    int inp_counter=0; // declare counter for the inputs
    int soln2=0,soln1=0; // declare initial values of solutions
    std::string str; // variable to read each input line
    std::ifstream file("input.txt");

    while (getline(file, str)){
        for (const char c : str){
            if (c=='('){
                soln1++;
            }
            else if (c==')'){
                soln1--;
            }
            inp_counter++;
            if (soln1==-1 && soln2==0){
                soln2=inp_counter;
            }
        }
    }
    std::cout<<"Santa's final floor: "<<soln1<<std::endl;
    std::cout<<"First time Santa reaches the basement: "<<soln2<<std::endl;
}