/*
Given a time in 24 hour format, calculate the angle between the hour and minute hands
*/

/*
solution: math
O(1) time, O(1) space
*/

#include<cassert>
#include<iostream>
using namespace std;

/*

Input:  time format in 24 hour: hour and minute
Output: the angle between the hour and minute hands

*/
int calulateAngle(int hour, int minute)
{
    assert(hour >= 0 && hour < 24);
    assert(minute >= 0 && minute < 60);
 
    int minutedegree = 360 * minute / 60;
    int hourdegree = 360 * (hour % 12) / 12 + 30 * minute / 60;  //30 degree per hour
 
    return abs(hourdegree - minutedegree);
}

int main(){
    
    int hour1 = 12, minute1 = 0;
    int hour2 = 18, minute2 = 0;
    int hour3 = 12, minute3 = 30;    
    cout<<calAngle(hour1,minute1)<<endl;
    cout<<calAngle(hour2,minute2)<<endl;
    cout<<calAngle(hour3,minute3)<<endl;
    return 0;

}
