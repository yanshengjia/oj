// HDOJ #1039 Easier Done Than Said?
// 3 rules:
// (1)It must contain at least one vowel.
// (2)It cannot contain three consecutive vowels or three consecutive consonants.
// (3)It cannot contain two consecutive occurrences of the same letter, except for 'ee' or 'oo'.
//
// created by yanshengjia
// @2016-2-27

//#define LOCAL

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	#ifdef LOCAL
    freopen("1.txt","r",stdin);
    #endif
    
    std::ios::sync_with_stdio(false);   
    
    string str;
    int length;
    int vowel_counter;
    int consonant_counter;
    int repeat_counter;
    bool flag1;         // flag1 = true ------ satisfy rule 1
    bool flag2;         // flag2 = true ------ satisfy rule 2
    bool flag3;         // flag3 = true ------ satisfy rule 3
    bool flag_vowel;    // whether the char is a vowel or not
    
    while(cin>>str && str != "end")
    {
        vowel_counter = 0;
        consonant_counter = 0;
        repeat_counter = 0;
        length = str.size();
        flag1 = false;
        flag2 = true;
        flag3 = true;
        
        
        // scan str
        for(int i=0; i<length; i++)
        {
            flag_vowel = false;
            // judge rule 1
            
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            {
                flag1 = true;
                flag_vowel = true;
            }
            

            // judge rule 2
            if(flag_vowel == true)
            {
                // current char is a vowel
                vowel_counter++;
                consonant_counter = 0;
            }
            else
            {
                // current char is a consonant
                consonant_counter++;
                vowel_counter = 0; 
            }
            
            if(vowel_counter == 3 || consonant_counter == 3)
            {
                flag2 = false;
            }
            
            
            // judge rule 3
            if(i<length-1 && str[i]==str[i+1])
            {
                if(str[i]!='e' && str[i]!='o')
                {
                    flag3 = false;
                }
            }
        }
        
        
        if(flag1 && flag2 && flag3)
        {
            cout<<"<"<<str<<"> is acceptable."<<endl;
        }
        else
        {
            cout<<"<"<<str<<"> is not acceptable."<<endl;
        }
    }
    
    return 0;
}