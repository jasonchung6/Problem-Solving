#include<iostream>
using namespace std;

int main(){
    int h, m ,s, hh, mm, ss, hhh, mmm, sss;
    int hx = 0, mx = 0;
    scanf("%d:%d:%d", &h, &m, &s);
    scanf("%d:%d:%d", &hh, &mm, &ss);

    if (ss >= s)
        sss = ss - s;
    else{
        sss = 60 + ss - s;
        mx++;
    }
    
    if (mm > m)
        mmm = mm - m - mx;
    else if (mm < m){
        mmm = 60 + mm - m - mx;
        hx++;
    }
    else{
        if(mx == 0)
            mmm = 0;
        else{
            mmm = 59;
            hx++;
        }
    }
    
    if (hh > h)
        hhh = hh - h - hx;
    else if (hh < h){
        hhh = 24 + hh - h - hx;
    }
    else{
        if(hx == 0)
            hhh = 0;
        else{
            hhh = 23;
        }
    }
    
    printf("%02d:%02d:%02d", hhh, mmm, sss);
}