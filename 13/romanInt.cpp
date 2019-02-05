#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
    public:
	int romanToInt(string s) {
	    int count=0;
	    if( s.length() ==0)
		return 0;
	    int length = s.length();
	    for(int i=0; i < length; i++){

		if( s.at(i) == 'M'){
		    count+=1000;                
		}
		else if( s.at(i) == 'C'){
		    if( i < length - 1){

			if( i < length && s.at(i+1) == 'M'){
			    count+=900;
			    i++;
			}
			else if( i < length && s.at(i +1) == 'D'){
			    count+=400;
			    i++;
			}
		    }
		    else
		    count+=100;   
		}
		else if( s.at(i) == 'D'){
		    count+=500;
		}
		else if(s.at(i) == 'L'){
		    count+=50;            
		}
		else if( s.at(i) =='X'){
		    if( i < length-1){
			if( s.at(i + 1) == 'L'){
			    count+=40;
			    i++;
			}
			else if( s.at(i+1) == 'C'){
			    count+=90;
			    i++;
			}
		    }
		    else
		    count+=10;
		}
		else if( s.at(i)=='V')
		    count+=5;
		else if( s.at(i) == 'I'){
		    if( i < length -1){

			if(s.at(i+1)=='V'){
			    count+=4;
			    i++;
			}
			else if(s.at(i+1)=='X'){
			    count+=9;
			    i++;
			}
		    }
		    else
		    count++;
		}
	    }
	    return count;    
	}
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
	char currentChar = input[i];
	if (input[i] == '\\') {
	    char nextChar = input[i+1];
	    switch (nextChar) {
		case '\"': result.push_back('\"'); break;
		case '/' : result.push_back('/'); break;
		case '\\': result.push_back('\\'); break;
		case 'b' : result.push_back('\b'); break;
		case 'f' : result.push_back('\f'); break;
		case 'r' : result.push_back('\r'); break;
		case 'n' : result.push_back('\n'); break;
		case 't' : result.push_back('\t'); break;
		default: break;
	    }
	    i++;
	} else {
	    result.push_back(currentChar);
	}
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {

	int ret = Solution().romanToInt("MCMXCIV");

	string out = to_string(ret);
	cout << out << endl;
    }
    return 0;
}
