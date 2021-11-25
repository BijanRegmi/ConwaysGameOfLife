#include "patterns.hpp"
#include <iostream>

namespace Parser{

pattern_array parse_string(std::string str){
	std::cout << "String: " << str << std::endl;
    int current_count = 1;

	std::vector<bool> row_arr;
	pattern_array p_arr;

    for (int i=0, j=str.size(); i<j; i++){
        int num = getNum(i, str);
        if (num == -1){
            if (str[i] == 'o'){
				while(current_count){
					row_arr.push_back(1);
					current_count--;
				}
			} else if (str[i] == 'b'){
				while(current_count){
					row_arr.push_back(0);
					current_count--;
				}
			} else if (str[i] == '$'){
				p_arr.push_back(row_arr);
				row_arr.clear();
			} else if (str[i] == '!'){
				int r = p_arr[0].size();
				int c = p_arr.back().size();
				row_arr.insert(row_arr.end(), r-c, 0);
				p_arr.push_back(row_arr);
			}
            current_count = 1;
        }
        else{
            i += digitCount(num)-1;
            current_count = num;
        }
    }
	for (auto x: p_arr){
		for (auto y: x)
			std::cout << y;
		std::cout << std::endl;
	}
	return p_arr;
}

int digitCount(int n){
    int c = 0;
    while (n){
        n/=10;
        c++;
    }
    return c;
}

int getNum(int i, std::string str){
    int num = str[i]-'0';
    if (num>=0 && num<=9){
        int gotNum = getNum(i+1, str);
        if (gotNum != -1) num = num*10+gotNum;
        return num;
    } else return -1;
}

}
