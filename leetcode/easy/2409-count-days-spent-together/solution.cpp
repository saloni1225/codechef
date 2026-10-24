class Solution {
public:
int findDaysofYear(string date , vector<int>&sumDays){
    int month=stoi(date.substr(0,2));
    int days=stoi(date.substr(3));

    return sumDays[month-1]+days;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthDays={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>sumDays(13,0);
        sumDays[1]=31;
        for(int i=2;i<=12;i++){
            sumDays[i]=monthDays[i-1] + sumDays[i-1];
        }
        int arrAD=findDaysofYear(arriveAlice,sumDays);
        int levAD=findDaysofYear(leaveAlice,sumDays);
        int arrBD=findDaysofYear(arriveBob,sumDays);
        int levBD=findDaysofYear(leaveBob,sumDays);

        int overlapDays=min(levAD,levBD)-max(arrAD,arrBD)+1;

        return overlapDays <0?0:overlapDays;
    }
};