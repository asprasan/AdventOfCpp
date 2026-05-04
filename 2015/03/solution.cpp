#include <iostream>
#include <fstream>
#include <set>
#include <tuple>

std::tuple<int, int> next_house(std::tuple<int, int> house, const char c){
    // Compute the next house visited by Santa/robot for delivering gifts
    // If < move Left
    // If > move Right
    // If ^ move Up
    // If v move Down
    if (c=='<'){
        std::get<0>(house)--;
    }
    else if (c=='>'){
        std::get<0>(house)++;
    }
    else if (c=='^'){
        std::get<1>(house)++;
    }
    else if (c=='v'){
        std::get<1>(house)--;
    }
    return house;
}

int main(){
    std::ifstream file("input.txt");
    std::string line;
    
    std::set<std::tuple <int, int>> house_grid1, house_grid2; //define the grid of visited homes
    std::tuple<int, int> house={0,0}; // define the santa's location for part 1
    std::tuple<int, int> santa_house={0,0}, robo_house={0,0}; //define the santa's or robot's location for part 2
    
    int soln1=1, soln2=1; // start counter at 1 because gift already delivered at origin
    int counter = 0;
    
    house_grid1.insert(house);
    house_grid2.insert(santa_house);

    while (std::getline(file, line)){
        for (const char c: line){
            // solution for part 1
            house=next_house(house, c);
            if (!house_grid1.count(house)){
                soln1++;
                house_grid1.insert(house);
            }
            // solution for part 2
            if (counter%2==0){
                // logic for santa's movements
                santa_house=next_house(santa_house, c);
                if (!house_grid2.count(santa_house)){
                    soln2++;
                    house_grid2.insert(santa_house);
                }
            }
            else if (counter%2==1){
                // logic for robot's movements
                robo_house = next_house(robo_house, c);
                if (!house_grid2.count(robo_house)){
                    soln2++;
                    house_grid2.insert(robo_house);
                }
            }
            counter++;
            }
        }
    std::cout<<"Solution for part 1: "<<soln1<<std::endl;
    std::cout<<"Solution for part 2: "<<soln2<<std::endl;
}
