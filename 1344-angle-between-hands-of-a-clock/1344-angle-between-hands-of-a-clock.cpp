class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleminutes=6*(minutes%60);
        double anglehour=30*(hour%12)+(angleminutes/360)*30;
        double d=max(anglehour,angleminutes)-min(anglehour,angleminutes);
        return min(d,360-d);
    }
};