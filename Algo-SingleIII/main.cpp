//
//  main.cpp
//  Algo-SingleIII
//
//  Created by Chaojun Xue on 1/7/16.
//  Copyright © 2016 Chaojun Xue. All rights reserved.
//

/*
 https://leetcode.com/problems/single-number-iii/
 
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 
 For example:
 
 Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 
 Note:
 The order of the result is not important. So in the above example, [5, 3] is also correct.
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */

#include <iostream>
#include <vector>
#include <map>


bool Greater(int a, int b)
{
    return a<=b;
}

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::vector<int> result;
        std::map<int, int> rbTree;
        //RBTree rbTree;
        
        for(auto num : nums){
            if(rbTree.find(num) != rbTree.end()){
                rbTree.erase(num);
            }
            else{
                rbTree.insert(std::pair<int,int>(num,100));
            }
        }

        for(auto num : rbTree){
            result.push_back(num.first);
        }
        return result;
    }
    
    std::vector<int> singleNumber1(std::vector<int>& nums) {
        std::vector<int> result;
        
        //std::sort(nums.begin(), nums.end(), Greater);
        std::sort(nums.begin(), nums.end(), [](int a, int b)->bool{
            
            return (a < b);//Note: a>=b doesn't work
        });
        
        int firstOne = -1;
        bool first = true;
        for(int num : nums){
            if(first){
                firstOne = num;
                first = false;
            }
            else{
                if(num != firstOne){
                    result.push_back(firstOne);
                    firstOne = num;
                }
                else{
                    first = true;
                }
            }
        }
        
        if(first == false){
            result.push_back(firstOne);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::vector<int> nums  = {
    
        433454163,-1016282006,-239848547,468592701,433454163,-818856676,-1177621849,-1253893784,1204788121,-345704316,1514788203,-659286982,67293606,1119109788,349759943,551190842,-1644795989,1375986005,-1392723021,-40635766,-1770461237,-1634650831,-1871923121,131496832,951832201,-1773140305,-1175759511,503717170,994802911,-1871923121,-338844886,-818856676,-1728447056,-1442255096,-1826061812,-396488066,451284129,-845695283,-1392723021,-152241559,150060458,-810390432,-40635766,829027879,348611243,67293606,-1450543069,-1253893784,-2090516819,-69229522,836158527,-1619296933,-45504116,-544866340,-28974294,-798651450,1489893747,-1175759511,1502763710,-761428389,1535167002,-240456056,468592701,-1044460230,836158527,551190842,829027879,-659286982,505864933,1535167002,-1439989581,-845695283,-1619296933,-1442255096,-152241559,-951077628,-2026992557,-207332528,-24993198,-1826061812,-69229522,131496832,-276581318,-1439989581,2041037916,-798651450,-1644795989,-810390432,181811079,-338844886,907346347,505864933,907346347,442791728,519347845,349759943,442791728,-276581318,1861998837,-240456056,-2026992557,-345704316,552131941,-2090516819,-1728447056,1761003708,1502763710,1761003708,-2088121358,1204788121,994802911,-239848547,-1045648256,-1078168040,-951077628,-24993198,-1773140305,305272990,1536226367,348611243,1536226367,1017340544,-1078168040,150060458,1489893747,82220798,-45504116,-1045648256,-207332528,-761428389,47247395,-1450543069,2041037916,1375986005,951832201,519347845,398985324,398985324,1017340544,202997739,-28974294,-1723060468,503717170,-1723060468,-1016282006,-1770461237,181811079,-396488066,1514788203,-535334876,202997739,-535334876,552131941,451284129,-1177621849,82220798,-1044460230,-1634650831,-2088121358,47247395,1861998837,-544866340
         };
    //int input[] = {-1, 0};
    
    //std::sort(std::begin(input), std::end(input));
    
    /*for(int i = 0; i < sizeof(input)/sizeof(input[0]); i++){
        nums.push_back(input[i]);
    }*/

    
    std::vector<int> results = solution.singleNumber(nums);
    
    std::for_each(results.begin(), results.end(), [](int num){
        printf("%d ", num);
    });
    printf("\n");
    
    return 0;
}
