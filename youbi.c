#include <stdio.h>

int main(int argc, char *argv[]){

    // 曜日
    char date[7][100] = {"土", "日", "月", "火", "水", "木", "金"};

    int d = atoi(argv[3]);
    int m = atoi(argv[2]);
    int y = atoi(argv[1]);

    // 1月と2月は前年の13月14月として扱う
    if( m==1 || m==2 ) { 
        m += 12;
        y--;
    }
    
    // ツェラーの公式
    int c = y/100;
    int F = c*(-2) + (c/4);
    int Y = y % 100;

    int h = ( d + ( (26*(m+1))/10 ) + Y + (Y/4) + F) % 7;

    printf("%s曜日\n", date[h]);

    return 0;
}