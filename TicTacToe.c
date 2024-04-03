#include<stdio.h>
#include<conio.h>
#include<windows.h>
int check_x(int Caro[20][20],int x,int y){
    if(x<0||y<0) return 0;
    else if(Caro[x][y]==0){
        Caro[x][y]=1;
        return 1;
    } else return 0;
}
int check_o(int Caro[20][20],int x,int y){
    if(x<0||y<0) return 0;
    else if(Caro[x][y]==0){
        Caro[x][y]=2;
        return 1;
    } else return 0;
}
int matrix(int Caro[20][20]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("      0");
    for(int i=1;i<10;i++) printf("   %i",i);
    for(int i=10;i<20;i++) printf("  %i",i);
    printf("\n");
    printf("    %c%c%c%c",218,196,196,196);
    for(int i=1;i<20;i++) printf("%c%c%c%c",194,196,196,196);
    printf("%c\n",191);
    for(int i=0;i<19;i++){
        printf("%4i",i);
        for(int j=0;j<20;j++) {
            printf("%c ",179);
            if (Caro[i][j] == 0) {
                printf("  ");
            } else if (Caro[i][j] == 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                printf("X ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("O ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        printf("%c\n",179);
        printf("    %c",195);
        for(int i=1;i<20;i++) printf("%c%c%c%c",196,196,196,197);
        printf("%c%c%c%c\n",196,196,196,180);
    }
    printf("%4i",19);
    for(int j=0;j<20;j++) {
        printf("%c ",179);
        if (Caro[19][j] == 0) {
            printf("  ");
        } else if (Caro[19][j] == 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("X ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("O ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
    printf("%c\n",179);
    printf("    %c",192);
    for(int i=1;i<20;i++) printf("%c%c%c%c",196,196,196,193);
    printf("%c%c%c%c\n",196,196,196,217);
}
int win_check_horizontal(int Caro[20][20],int x,int y){
    int count=0;
    for(int i=y-1;i>=0&&Caro[x][i]==Caro[x][y];i--) count++;
    for(int i=y+1;i<20&&Caro[x][i]==Caro[x][y];i++) count++;
    if(count>=4) return 1;
    else return 0;
}
int win_check_vertical(int Caro[20][20],int x,int y){
    int count=0;
    for(int i=x-1;i>=0&&Caro[i][y]==Caro[x][y];i--) count++;
    for(int i=x+1;i<20&&Caro[i][y]==Caro[x][y];i++) count++;
    if(count>=4) return 1;
    else return 0;
}
int win_check_diagonal(int Caro[20][20],int x,int y){
    int count=0;
    for(int i=x-1,j=y-1;i>=0&&j>=0&&Caro[i][j]==Caro[x][y];i--,j--) count++;
    for(int i=x+1,j=y+1;i<20&&j<20&&Caro[i][j]==Caro[x][y];i++,j++) count++;
    if(count>=4) return 1;
    count=0;
    for(int i=x-1,j=y+1;i>=0&&j<20&&Caro[i][j]==Caro[x][y];i--,j++) count++;
    for(int i=x+1,j=y-1;i<20&&j>=0&&Caro[i][j]==Caro[x][y];i++,j--) count++;
    if(count>=4) return 1;
    else return 0;
}
int check(int Caro[20][20],int x,int y){
    if(win_check_horizontal(Caro,x,y)) return 1;
    else if(win_check_vertical(Caro,x,y)) return 1;
    else if(win_check_diagonal(Caro,x,y)) return 1;
    else return 0;
}
int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int Caro[20][20],t1,t2,x_win=0,o_win=0;
    for(int i=0;i<20;i++) for(int j=0;j<20;j++) Caro[i][j]=0;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
    printf("--------------------CO CARO--------------------\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    printf("*HUONG DAN*:\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("-Bat dau tro choi phe X danh truoc, sau do phe O danh.\n");
    printf("-Nhap o minh muon danh theo dinh dang x:y\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    while(1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("\nPhe X danh : ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%i:%i",&t1,&t2);
        while(!check_x(Caro,t1,t2)){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Loi! Phe X danh lai : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            scanf("%i:%i",&t1,&t2);
        }
        system("cls");
        matrix(Caro);
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(Caro[i][j]){
                    if(check(Caro,i,j)){
                        x_win=1;
                        break;
                    }
                }
            }
            if(x_win) break;
        }
        if(x_win){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("\nX thang cuoc.");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            getch();
            break;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("\nPhe O danh : ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        scanf("%i:%i",&t1,&t2);
        while(!check_o(Caro,t1,t2)){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Loi! Phe O danh lai : ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            scanf("%i:%i",&t1,&t2);
        }
        system("cls");
        matrix(Caro);
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(Caro[i][j]){
                    if(check(Caro,i,j)){
                        o_win=1;
                        break;
                    }
                }
            }
            if(o_win) break;
        }
        if(o_win){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("\nO thang cuoc.");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            getch();
            break;
        }
    }
}