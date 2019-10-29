#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int input;
    printf("(1)上下反転、(2)左右反転、(3)180°回転、(4)90°回転、(5)270°回転\nどれにしますか(1〜5)? ");
    scanf("%d", &input);

    char str[100];
    int img1[1024][1024];  // 画像バッファ
    int img2[1024][1024];
    int w,h;             // 画像の大きさ
    int d;               // 画像の階調
    int x,y;             // 横縦のインデックス
    FILE *fp1, *fp2;

    if( (fp1 = fopen(argv[1], "r") ) == NULL){
	perror(argv[1]);
	exit(1);
    }
    if( (fp2 = fopen(argv[2], "w") ) == NULL){
	perror(argv[2]);
	exit(1);
    }

    // ヘッダの読み込み
    fscanf( fp1, "%s", &str );        // マジックナンバー
    fscanf( fp1, "%d %d", &w, &h );   // 画像の大きさ
    fscanf( fp1, "%d", &d );          // 画像の階調


    // 画像本体
    for(y = 0; y < h; y++){
	for(x = 0; x < w; x++){
	    fscanf(fp1, "%d", &(img1[x][y]));
	}
    }

    switch(input){
    case 1: {
	for(y = 0; y < h; y++){
	    for(x = 0; x < w; x++){
		img2[x][h-y-1] = img1[x][y];
	    }
	}
	break;}
    case 2: {
	for(y = 0; y < h; y++){
	    for(x = 0; x < w; x++){
		img2[w-x-1][y] = img1[x][y];
	    }
	}
	break;}
    case 3: {
	for(y = 0; y < h; y++){
	    for(x = 0; x < w; x++){
		img2[w-x-1][h-y-1] = img1[x][y];
	    }
	}
	break;}
    case 4: {
	for(y = 0; y < h; y++){
	    for(x = 0; x < w; x++){
		img2[h-y-1][x] = img1[x][y];
	    }
	}
	break;}
    case 5: {
	for(y = 0; y < h; y++){
	    for(x = 0; x < w; x++){
		img2[y][w-x-1] = img1[x][y];
	    }
	}
	break;}
    }
    switch(input){
    case 1:
    case 2:
    case 3:{
	fprintf(fp2, "%s\n%d %d\n%d\n", str, w, h, d);
	for(y = 0; y < h; y++){
	    for(x = 0; x < w; x++){
		fprintf(fp2, "%d ", img2[x][y]);
	    }
	    fprintf(fp2, "\n");
	}
	break;
    }
    case 4:
    case 5:{
	fprintf(fp2, "%s\n%d %d\n%d\n", str, h, w, d);
	for(y = 0; y < w; y++){
	    for(x = 0; x < h; x++){
		fprintf(fp2, "%d ", img2[x][y]);
	    }
	    fprintf(fp2, "\n");
	}
	break;
    }
    }
    return 0;
}
