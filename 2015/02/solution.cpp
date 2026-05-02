#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include<vector>

std::vector<int> split(std::string& s, const char delim){
    std::vector<int> result;
    std::stringstream ss (s);
    std::string item;

    while (std::getline(ss, item, delim)){
        result.push_back(std::stoi(item));
    }
    return result;
}

int get_area(std::vector<int> dims){
    int curr_area=0;
    int l=dims[0], w=dims[1], h=dims[2];
    std::vector<int> areas={l*w, w*h, l*h};
    int min_area=areas[0];

    for (int area:areas){
        if (area<min_area){
            min_area=area;
        }
        curr_area += 2*area;
    }
    return curr_area + min_area;
}

int get_ribbon(std::vector<int> dims){
    int l=dims[0], w=dims[1], h=dims[2];
    std::vector<int> perims={2*(l+w), 2*(w+h), 2*(l+h)};
    int min_perim=perims[0];

    for (int perim:perims){
        if (perim<min_perim){
            min_perim=perim;
        }
    }
    return min_perim + (l*w*h);
}

int main(){
    std::ifstream file("input.txt");
    int ribbon_length=0,sheet_area=0;
    std::string line;
    std::vector<int> dimensions;
    while (std::getline(file, line)){
        dimensions = split(line, 'x');
        sheet_area += get_area(dimensions);
        ribbon_length += get_ribbon(dimensions);
    }
    std::cout<<"Part 1: Required wrapping sheet area= "<<sheet_area<<std::endl;
    std::cout<<"Part 2: Required ribbon length= "<<ribbon_length<<std::endl;
}
