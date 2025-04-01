#include<stdio.h>
struct cube{
    char c[7][3][3];
    int a;
};
struct cube s1[4],s;
char cube[7][3][3];

// solvers:
void Solve();
void previous(int,int);
void layer_1_solver();
void layer_2_solver();
void layer_3_solver();

int layer_1();
int layer_1_s1(int base);
int layer_1_s2();
int layer_1_s3();
void layer_1_s4();
void layer_1_2();
int layer_1_small(int,int);

void layer_2();
void layer_2_s1(int,int);
void layer_2_1(int);

void layer_3(char,int);

void turn_1(int);
void move(char p,int k,char c,int a);
void up(int);
void down(int);
void left(int);
void right(int);
void face(int);
void back(int);
// colours handling :
void input_handling(char [7]);
void input(int);
void view(int);

int main(){
    s.a=0;  // ybwrygrybgwgyryrgrwbbrwgyowygoroboryoorwgyoogbwbbbogww
    char s[7];  // leaving first 2d array and using other 6 2d arrays in 3d array...
    int i,j,k,a,a1[6];
    for(k=1;k<7;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cube[k][i][j]=' ';
            }
        }
        a1[k-1]=0;
    }
    cube[1][1][1]='g'; cube[2][1][1]='o'; cube[3][1][1]='y'; cube[4][1][1]='r'; cube[5][1][1]='w'; cube[6][1][1]='b';
    printf("\n-------------------- CUBE SOLVER ---------------------\n\n");
    printf("enter which colour you want to solve: ");
    scanf(" %[^\n]",s); 
//    printf("\nM.U.K.H.Y.A.A.M.S.A.A.L.U:-\nWHILE ENTERING INPUTS :-\n\n");
    printf("\nWHILE ENTERING INPUTS :-\n\n");
    input_handling(s);
    for(k=1;k<7;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(cube[k][i][j]=='g')   a1[0]++;
                if(cube[k][i][j]=='o')   a1[1]++;
                if(cube[k][i][j]=='y')   a1[2]++;
                if(cube[k][i][j]=='r')   a1[3]++;
                if(cube[k][i][j]=='w')   a1[4]++;
                if(cube[k][i][j]=='b')   a1[5]++;
            }
        }
    }
    for(k=0;k<6;k++){
        if(a1[k]!=9)    printf("\nits wrong input\n");
    }
    Solve();
}
void input_handling(char s[7]){
    if(s[0]=='g' || s[0]=='G'){
        s[1]='g';   s[2]='o';   s[3]='y';   s[4]='r';   s[5]='w';   s[6]='b';
        printf("TAKE GREEN COLOUR AS TOP AND BLUE COLOUR AS BOTTOM :\nFOR GREEN CENTER TAKE ORANGE AS BOTTOM :\nFOR BLUE CENTER TAKE ORANGE AS TOP :");
        printf("\n\nwhile solving take orange as face\ngreen as top");
    }
    else if(s[0]=='b' || s[0]=='B'){
        s[1]='b';   s[2]='o';   s[3]='w';   s[4]='r';   s[5]='y';   s[6]='g';
        printf("TAKE BLUE COLOUR AS TOP AND GREEN COLOUR AS BOTTOM :\nFOR BLUE CENTER TAKE ORANGE AS BOTTOM :\nFOR GREEN CENTER TAKE ORANGE AS TOP :");
        printf("\n\nwhile solving take orange as face\nblue as top");
    }
    else if(s[0]=='o' || s[0]=='O'){
        s[1]='o';   s[2]='w';   s[3]='b';   s[4]='y';   s[5]='g';   s[6]='r';
        printf("TAKE ORANGE COLOUR AS TOP AND RED COLOUR AS BOTTOM :\nFOR ORANGE CENTER TAKE WHITE AS BOTTOM :\nFOR RED CENTER TAKE WHITE AS TOP :");
        printf("\n\nwhile solving take white as face\norange as top");
    }
    else if(s[0]=='y' || s[0]=='Y'){
        s[1]='y';   s[2]='o';   s[3]='b';   s[4]='r';   s[5]='g';   s[6]='w';
        printf("TAKE YELLOW COLOUR AS TOP AND white COLOUR AS BOTTOM :\nFOR YELLOW CENTER TAKE ORANGE AS BOTTOM :\nFOR WHITE CENTER TAKE ORANGE AS TOP :");
        printf("\n\nwhile solving take orange as face\nyellow as top");
    }
    else if(s[0]=='r' || s[0]=='R'){
        s[1]='r';   s[2]='y';   s[3]='b';   s[4]='w';   s[5]='g';   s[6]='o';
        printf("TAKE RED COLOUR AS TOP AND ORANGE COLOUR AS BOTTOM :\nFOR RED CENTER TAKE YELLOW AS BOTTOM :\nFOR ORANGE CENTER TAKE YELLOW AS TOP :");
        printf("\n\nwhile solving take yellow as face\nred as top");
    }
    else if(s[0]=='w' || s[0]=='W'){
        s[1]='w';   s[2]='r';   s[3]='b';   s[4]='o';   s[5]='g';   s[6]='y';   
        printf("TAKE WHITE COLOUR AS TOP AND YELLOW COLOUR AS BOTTOM :\nFOR WHITE CENTER TAKE RED AS BOTTOM :\nFOR YELLOW CENTER TAKE RED AS TOP :");
        printf("\n\nwhile solving take red as face\nwhite as top");
    }
//    printf("\n\nGamaninchagalaru!!!\n\n");
    printf("\n\n");
    cube[3][1][1]=s[3];  cube[4][1][1]=s[4];  cube[5][1][1]=s[5];  cube[2][1][1]=s[2];  cube[1][1][1]=s[1];  cube[6][1][1]=s[6];
    input(3);  cube[3][1][1]=s[3];   view(3);
    input(4);  cube[4][1][1]=s[4];   view(4);
    input(5);  cube[5][1][1]=s[5];   view(5);
    input(2);  cube[2][1][1]=s[2];   view(2);
    input(1);  cube[1][1][1]=s[1];   view(1);
    input(6);  cube[6][1][1]=s[6];   view(6);
}
void Solve(){
    printf("\n ---------");
    printf("\n| layer_1 |");
    printf("\n ---------\n");
    layer_1_solver();
    printf("\n\nTOTAL MOVES : %d\n",s.a);
    printf("\n -----------------------------------------");
    printf("\n| layer_2                                 |");
    printf("\n| NOW ROTATE YOUR CUBE UPSIDE DOWN..      |\n| WITHOUT CHANGING FACE but TOP AS BOTTOM |\n");
    printf(" -----------------------------------------\n");
    layer_2_solver();
    printf("\nTOTAL MOVES : %d\n",s.a);
    printf("\n ---------");
    printf("\n| layer_3 |");
    printf("\n ---------\n\n");
    layer_3_solver();
    printf("\n\n -------------------");
    printf("\n| TOTAL MOVES : %d |\n",s.a);
    printf(" -------------------\n");
    view(1);   
    view(2);   view(3);   view(4);   view(5);
    view(6);
}
// layer solvers...
void layer_1_solver(){
    printf("\n");
    int i,j;
    for(i=0;i<3;i++){ 
        for(j=0;j<3;j++){
            if(cube[1][i][j]!=cube[1][1][1]){
                layer_1();
                i=-1; break;
            }
        }
    }
    layer_1_s4();
    for(i=0;i<=2;i++){
        for(j=2;j<=5;j++){
            if(cube[j][0][i]!=cube[j][1][1]){
                layer_1_s3();
                i=-1; break;
            }  
        }
    }
}
void layer_2_solver(){
    printf("\n");
    int i,j;
    for(i=1;i<=2;i++){
        for(j=1;j<=6;j++){
            turn_1(j);
        }
    }
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            cube[1][i][j]=cube[1][i][j]+cube[6][i][j]-(cube[6][i][j]=cube[1][i][j]);
            cube[3][i][j]=cube[3][i][j]+cube[5][i][j]-(cube[5][i][j]=cube[3][i][j]);
        }
    }
    for(i=2;i<=5;i++){
        if(cube[i][1][2]!=cube[i][1][1] || cube[i][1][0]!=cube[i][1][1]){
            layer_2(),i=1;
            printf("\n");
        }
    }
}
void layer_3_solver(){
    int i,j,a,b,c;
    for(i=0;i<=3;i++){
        s1[i].a=0;
        previous(1,i);
        layer_3('n',i);
        previous(2,i);
        up(3);
    }
    for(i=1,j=0;i<=3;i++){
        if  ( i!=2 && s1[i]. a < s1[j].a - 1 )    j=i,previous(2,j);
        else if(i==2 && s1[i]. a < s1[j].a - 2 )  j=i,previous(2,j),s1[j].a++;
    }
    printf(j==1 ? "U' " : j==2 ? "U2 " : j==3 ? "U  " : 0);
    layer_3('p',0);
}
// layer_1:
int layer_1(){
    int i=0,j,a=0,b=0,c=0,m,k,n,count=0;
    i=layer_1_s1(20);
   // special cases
    if(i){
        for(j=0;j<=4;j++,i++){   // down
            if(cube[i][1][1]==cube[i][2][1]){         // if green is in cube[6]---blue
                printf(count==1 ? "D  " : count==2 ? "D2 " : count==3 ? "D' " : "");
                (count==1 || count==3) ? s.a++ : count==2 ? s.a+=2 : 0;
                if(i==2){
                    face(2);     printf("F2 ");
                }
                else if(i==3){
                    right(2);    printf("R2 ");
                }
                else if(i==4){
                    back(2);     printf("B2 ");
                }
                else{
                    left(2);     printf("L2 ");
                }
                s.a+=2;
                return 0;
            }
            else{
                down(1);    count++;
            }
            if(i==5)    i=1;
        }
    }
    printf("\n");
    for(c=2,b=0;c<=5;c++){
        if(cube[c][1][0]==cube[1][1][1]){  // if green is in faces (orange,yellow,red,white)
            m=1,n=2;    b=1;
            break;
        }
        if(cube[c][1][2]==cube[1][1][1]){
            m=1,n=0;    b=2;
            break;
        }
        if(cube[c][2][1]==cube[1][1][1]){
            c==2 ? (m=0,n=1) : c==3 ? (m=1,n=2) : c==4 ? (m=2,n=1) : (m=1,n=0);
            b=4;    break;
        }
        if(cube[c][0][1]==cube[1][1][1]){
            c==2 ? (m=2,n=1) : c==3 ? (m=1,n=2) : c==4 ? (m=0,n=1) : (m=1,n=0);
            b=3;    break;
        }

    }
    i=c+1,j=c-1;    // right--i left--j face--c back--(else)
    (i==6) ? i=2 : (j==1) ? j=5 : 0;
    if(c!=6){
        if(cube[c][1][0]==cube[1][1][1] && b==1){  //b=2
            if(cube[j][m][n]==cube[c][1][1]){
                move('p',c,'u',1);   move('p',c,'l',3);
                move('p',c,'u',3);
            }
            else if(cube[j][m][n]==cube[i][1][1]){
                move('p',c,'f',2);  move('p',c,'r',1);
            }
            else{
                move('p',c,'u',3);  move('p',c,'l',3);
                move('p',c,'u',1); 
            }
        }
        else if(cube[c][1][2]==cube[1][1][1] && b==2){ //b=3
            if(cube[i][m][n]==cube[c][1][1]){
                move('p',c,'u',3);  move('p',c,'r',1);
                move('p',c,'u',1);
            }
            else if(cube[i][m][n]==cube[j][1][1]){
                move('p',c,'f',2);  move('p',c,'l',3);
            }
            else{
                move('p',c,'u',1);  move('p',c,'r',1);
                move('p',c,'u',3);
            }
        }
        else if(cube[c][0][1]==cube[1][1][1] && b==3){  //b=1
            if(cube[1][m][n]==cube[c][1][1]){
                move('p',c,'u',1);  move('p',c,'l',1);
                move('p',c,'u',3);  move('p',c,'f',1);
            }
            else{
                move('p',c,'u',3);  move('p',c,'r',1);
                move('p',c,'u',1);  move('p',c,'b',1);
            }
        }
        else if(cube[c][2][1]==cube[1][1][1] && b==4){ //b=4
            if(cube[6][m][n]==cube[c][1][1]){
                move('p',c,'f',1);  move('p',c,'u',1);
                move('p',c,'l',3);  move('p',c,'u',3);
            }
            else{
                move('p',c,'d',1);  move('p',c,'r',3);
                move('p',c,'b',1);
            }
        }
    }
    layer_1_s2();
    // upto here plus completed...
    for(i=0,n=1,c=2;i<3;i++){
        for(j=0;j<3;j++){
            if((i+j)%2==1){
                if(!(cube[1][i][j]==cube[1][1][1] && cube[c][0][1]==cube[c][1][1]))  n=0;    // checking plus is completed or not...
                c++;
            }
        }
    }
    if(n){
        for(i=2;i<=5;i++){
            for(j=0;j<3;j++){
                if(j%2==0 && cube[i][2][j]==cube[1][1][1]){
                    layer_1_2(); i=1; break;
                }
            }
        }
        for(k=1;k<=4;k++){
            k==1 ? (i=0,j=0) : k==2 ? (i=0,j=2) : k==3 ? (i=2,j=0) : (i=2,j=2);
            if(cube[6][i][j]==cube[1][1][1]){
                for(c=2;c<=5;c++){
                    if(cube[c][0][0]==cube[1][1][1]){
                        c==2 ? (i=0,j=0) : c==3 ? (i=0,j=1) : c==4 ? (i=2,j=2) : (i=2,j=0);
                    }
                    else if(cube[c][0][2]==cube[1][1][1]){
                        c==5 ? (i=0,j=0) : c==2 ? (i=0,j=1) : c==3 ? (i=2,j=2) : (i=2,j=0);
                    }
                    if(cube[c][0][0]==cube[1][1][1] || cube[c][0][2]==cube[1][1][1]){
                        for(n=0;n<3;n++){
                            if(cube[6][i][j]==cube[1][1][1])   break;
                            down(1);
                        }
                        printf(n==1 ? "D  " : n==2 ? "D2 " : n==3 ? "D' " : 0);
                        (n==1 || n==3) ? s.a++ : n==2 ? s.a+=2 : 1;
                        break;
                    }
                }
                if(c!=6){
                    if(cube[c][0][0]==cube[1][1][1]){
                        move('p',c,'l',1);  move('p',c,'d',3);  move('p',c,'l',3);
                    }
                    else{
                        move('p',c,'r',3);  move('p',c,'d',1);  move('p',c,'r',1);
                    }
                    break;
                }
                else{
                    for(c=2;c<=5;c++){
                        c==2 ? (i=2,j=2) : c==3 ? (i=0,j=2) : c==4 ? (i=0,j=0) : (i=2,j=0);
                        if(cube[1][i][j]!=cube[1][1][1]){
                            i==0 ? i=2 : i=0;
                            for(n=0;n<3;n++){
                                if(cube[6][i][j]==cube[1][1][1])   break;
                                down(1);
                            }
                            printf(n==1 ? "D  " : n==2 ? "D2 " : n==3 ? "D' " : 0);
                            (n==1 || n==3) ? s.a++ : n==2 ? s.a+=2 : 1;
                            break;
                        }
                    }
                    move('p',c,'r',3);  move('p',c,'d',1);  move('p',c,'r',1);
                }
            }
        }
        if(k==5){
            for(c=2;c<=5;c++){
                i=c-1,j=c+1;
                c==2 ? i=5 : c==5 ? j=2 : 0;
                if(cube[c][0][0]==cube[1][1][1]){
                    if(cube[i][0][2]==cube[i][1][1] || cube[i][0][2]==cube[c][1][1]){
                        move('p',c,'l',1);  move('p',c,'d',3);  move('p',c,'l',3);  break;
                    }
                    else{
                        move('p',c,'f',3);  move('p',c,'d',3);  move('p',c,'f',1);  break;
                    }
                }
                else if(cube[c][0][2]==cube[1][1][1]){
                    if(cube[j][0][0]==cube[j][1][1] || cube[j][0][0]==cube[c][1][1]){
                        move('p',c,'r',3);  move('p',c,'d',1);  move('p',c,'r',1);  break;
                    }
                    else{
                        move('p',c,'f',1);  move('p',c,'d',1);  move('p',c,'f',3);  break;
                    }
                }
            }
        }
    }
    return 0;
}
void layer_1_2(){
    int a,b,c,i,j,k;
    for(c=2,b=0;c<=5;c++){
        i=c+1,j=c-1;
        c>3 ? k=c-2 : k=c+2;
        j==1 ? j=5 : i==6 ? i=2 : 0;
        if(cube[c][2][0]==cube[1][1][1]){
            if(cube[j][2][2]==cube[c][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=1;
            if(cube[j][2][2]==cube[i][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=2;
            if(cube[j][2][2]==cube[j][1][1])  a=c,b=3;
            if(cube[j][2][2]==cube[k][1][1])  a=c,b=4;
        }
        else if(cube[c][2][2]==cube[1][1][1]){
            if(cube[i][2][0]==cube[i][1][1])  a=c,b=5;
            if(cube[i][2][0]==cube[k][1][1])  a=c,b=6;
            if(cube[i][2][0]==cube[c][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=7;
            if(cube[i][2][0]==cube[j][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=8;
        }
    }
    i=a+1,j=a-1;
    a>3 ? k=a-2 : k=a+2;
    j==1 ? j=5 : i==6 ? i=2 : 0;
    if(b){
        if(b==1){
            move('p',a,'d',1);  move('p',a,'r',3);  move('p',a,'d',3);  move('p',a,'r',1);
        }
        else if(b==2){
            move('p',k,'d',3);  move('p',k,'l',1);  move('p',k,'d',3);  move('p',k,'l',3);
        }
        else if(b==3){
            move('p',j,'r',3);  move('p',j,'d',3);  move('p',j,'r',1);
        }
        else if(b==4){
            move('p',j,'l',1);  move('p',j,'d',3);  move('p',j,'l',3);
        }
        else if(b==5){
            move('p',a,'f',1);  move('p',a,'d',1);  move('p',a,'f',3);
        }
        else if(b==6){
            move('p',i ,'r',3);  move('p',i,'d',1);  move('p',i,'r',1);
        }
        else if(b==7){
            move('p',a,'d',3);  move('p',a,'l',1);  move('p',a,'d',1);  move('p',a,'l',3);
        }
        else if(b==8){
            move('p',k,'d',1);  move('p',k,'r',3);  move('p',k,'d',1);  move('p',k,'r',1);
        }
    }
}
int layer_1_s1(int base){
    if(base<=1) return 0;
    int a=0,i,j,m,n=0,c=0,count;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                if((i+j)%2!=0 && cube[1][i][j]==cube[1][1][1]) c++;
        for(i=1;i<=4;i++){
            count=0;
            if(cube[1][2][1]==cube[1][1][1] && cube[2][0][1]==cube[2][1][1]) a=i,count++;
            if(cube[1][1][2]==cube[1][1][1] && cube[3][0][1]==cube[3][1][1]) a=i,count++;
            if(cube[1][0][1]==cube[1][1][1] && cube[4][0][1]==cube[4][1][1]) a=i,count++;
            if(cube[1][1][0]==cube[1][1][1] && cube[5][0][1]==cube[5][1][1]) a=i,count++;
            if((c>2 && count<2) || (c==1 && count!=1))
                up(1),n++;
            else  break;
        }
        if(i==5 && a){
            if(a!=1)   a==4 ? move('p',2,'u',1) : move('p',2,'u',a);
        }
        else  printf(n==1 ? "U  " : n==2 ? "U2 " : n==3 ? "U' " : 0);
        (n==1 || n==3) ? s.a++ : n==3 ? s.a+=2 : 0;

    for(a=2;a<=5;a++){
        i=a+1,j=a-1;    
        (i==6) ? i=2 : (j==1) ? j=5 : 0;

        if(cube[a][1][0]==cube[1][1][1] && cube[j][1][2]==cube[j][1][1]){
            move('p',a,'l',3);  layer_1_s1(base-1);  
        }
        if(cube[a][1][2]==cube[1][1][1] && cube[i][1][0]==cube[i][1][1]){
            move('p',a,'r',1);  layer_1_s1(base-1);
        }
    }

    for(a=2;a<=5;a++){
        i=a+1,j=a-1;    
        (i==6) ? i=2 : (j==1) ? j=5 : 0;
        
        a==2 ? m=2 : a==3 ? m=1 : a==4 ? m=0 : m=1;
        a==2 ? n=1 : a==3 ? n=2 : a==4 ? n=1 : n=0;
        if(cube[a][0][1]==cube[1][1][1] && cube[1][m][n]==cube[i][1][1]){
            move('p',a,'f',1);  move('p',a,'r',1);  layer_1_s1(base-1);
        }
        if(cube[a][0][1]==cube[1][1][1] && cube[1][m][n]==cube[j][1][1]){
            move('p',a,'f',3);  move('p',a,'l',3);  layer_1_s1(base-1);
        }

        a==2 ? m=0 : a==3 ? m=1 : a==4 ? m=2 : m=1;
        a==2 ? n=1 : a==3 ? n=2 : a==4 ? n=1 : n=0;
        if(cube[a][2][1]==cube[1][1][1] && cube[6][m][n]==cube[i][1][1]){
            move('p',a,'f',3);  move('p',a,'r',1);  layer_1_s1(base-1);
        }
        if(cube[a][2][1]==cube[1][1][1] && cube[6][m][n]==cube[j][1][1]){
            move('p',a,'f',1);  move('p',a,'l',3);  layer_1_s1(base-1);
        }
    }
    
    i=0;
    if(cube[6][0][1]==cube[1][1][1]){      // if green edges are in blue face
        i=2;
        if(cube[2][1][1]==cube[2][2][1])  a=1;
    }   
    if(cube[6][1][2]==cube[1][1][1]){
        if(a!=1)    i=3;
        if(cube[3][1][1]==cube[3][2][1])  a=1;
    }   
    if(cube[6][2][1]==cube[1][1][1]){
        if(a!=1)    i=4;
        if(cube[4][1][1]==cube[4][2][1])  a=1;
    }
    if(cube[6][1][0]==cube[1][1][1]){
        if(a!=1)    i=5;
        if(cube[5][1][1]==cube[5][2][1])  a=1;
    }
    if(a!=1){
        if(cube[6][0][1]==cube[1][1][1] && cube[6][1][2]==cube[1][1][1]){
            if(cube[2][2][1]==cube[3][1][1] && cube[3][2][1]==cube[4][1][1])  i=2;}
        if(cube[6][1][2]==cube[1][1][1] && cube[6][2][1]==cube[1][1][1]){
            if(cube[3][2][1]==cube[4][1][1] && cube[4][2][1]==cube[5][1][1])  i=3;}
        if(cube[6][2][1]==cube[1][1][1] && cube[6][1][0]==cube[1][1][1]){
            if(cube[4][2][1]==cube[5][1][1] && cube[5][2][1]==cube[2][1][1])  i=4;}
    }
    return i;
}
int layer_1_s2(){
    int i=0,j,n,count,a,c;
    if(cube[1][0][1]==cube[1][1][1] && cube[1][1][0]==cube[1][1][1] && cube[1][1][2]==cube[1][1][1] && cube[1][2][1]==cube[1][1][1]){
        for(i=2;i<=5;i++)
            if(cube[i][0][1]!=cube[i][1][1])  break;      // if all green edges are set...
        count=0;
        if(i!=6){
            n=0;
            for(j=1;j<=4;j++){
                count=0;
                for(a=2;a<=5;a++){
                    if(cube[a][0][1]==cube[a][1][1])  count++;
                    else    i=c,c=a;
                }
                if(count>=2)  continue;
                else{
                    up(1);   n++;
                }   
            }
            printf(n==1 ? "U  " : n==2 ? "U2 " : n==3 ? "U' " : 0);
            (n==1 || n==3) ? s.a++ : n==3 ? s.a+=2 : 0;
        }
        if(count==2){
            if((c+i)%2==0){
                move('p',c,'u',2);  move('p',c,'f',1);  move('p',c,'b',1);
                move('p',c,'u',2);  move('p',c,'f',3);  move('p',c,'b',3);
            }
            else{
                if(c==5 && i==2)    c=2;
                move('p',c,'f',2);  move('p',c,'d',3);  move('p',c,'l',2);
                move('p',c,'d',1);  move('p',c,'f',2);
            }
        }
    }
    return 0;
}
int layer_1_s3(){
    int i,j,b,c;
    char d;
    for(c=2;c<=5;c++){
        if((d=cube[c][0][1])!=cube[c][1][1])  break;
    }
    if(c!=6){
        layer_1_small(c,1);
        while(1){
            c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : c==5 ? (i=2,j=4) : 0;
            if(d==cube[j][1][1]){
                d=cube[j][0][1];
                move('p',c,'d',1);  layer_1_small(j,1);
                c=j;
            }
            else if(d==cube[i][1][1]){ 
                d=cube[i][0][1];
                move('p',c,'d',3);  layer_1_small(i,1);
                c=i;
            }
            else{
                c>3 ? i=c-2 : i=c+2;
                d=cube[i][0][1];    layer_1_small(i,1);
                c=i;
            }
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(cube[1][i][j]!=cube[1][1][1])   break;
                }
                if(j!=3)    break;
            }
            if(i==3)    break;
        }
    }
    else{
        for(c=2;c<=5;c++){
            for(i=0;i<=2;i+=2){
                if(cube[c][0][i]!=cube[c][1][1])  break;
            }
            if(i!=4)    break;
        }
        c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : (i=2,j=4);
        if(c==6)    return 1;
        else if(cube[c][0][2]!=cube[c][1][1]){
            if(cube[c][0][2]==cube[i][1][1]){
                move('p',i,'l',1);  move('p',i,'d',1);  move('p',i,'l',3);
            }
            else {
                move('p',c,'r',3);  move('p',c,'d',3);  move('p',c,'r',1);
            }
        }
        else{
            if(cube[c][0][0]==cube[i][1][1]){
                move('p',c,'l',1);  move('p',c,'d',1);  move('p',c,'l',3);
            }
            else {
                move('p',j,'r',3);  move('p',j,'d',3);  move('p',j,'r',1);
            }
        }
        for(i=0;i<=2;i+=2){
            for(j=0;j<=2;j+=2){
                if(cube[1][i][j]!=cube[1][1][1]){
                    layer_1_2();
                    i=-2; break;
                }
            }
        }
    }
    return 0;
}
void layer_1_s4(){
    int i,count,a=0,c;
    for(i=1;i<=3;i++){
        count=0;
        for(c=2;c<=5;c++){
            if(cube[c][0][1]==cube[c][1][1])  count++;
        }
        if(count<2){
            a++;
            up(1);
        }
        else    break;
    }
    printf(a==3 ? "U' " : a==2 ? "U2 " : a==1 ? "U  " : 0);
    (a==1 || a==3) ? s.a++ : a==3 ? s.a+=2 : 0;
}
int layer_1_small(int c,int a){
    printf("coming here");
    move('p',c,'r',1);  move('p',c,'l',3);  move('p',c,'f',a);
    move('p',c,'r',3);  move('p',c,'l',1);
    printf("\n");
    return 0;
}
// layer_2:
void layer_2(){
    int i,j,m,n,a=0,b=0,c,k;
    for(c=2;c<=5;c++){
        if(cube[c][0][1]!=cube[1][1][1]){
            c==2 ? (m=2,n=1) : c==3 ? (m=1,n=2) : c==4 ? (m=0,n=1) : (m=1,n=0); // to check blue face..
            if(cube[1][m][n]!=cube[1][1][1]){
                c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : (i=2,j=4);
                c>3 ? k=c-2 : k=c+2;
                if(a==0){
                    b=c;
                    if(cube[c][0][1]==cube[c][1][1] || cube[c][0][1]==cube[k][1][1])   a++;
                }
                else{
                    if(cube[c][0][1]==cube[j][1][1] && cube[1][m][n]==cube[k][1][1]){
                        b=c;
                        break;
                    }
                    else if(cube[c][0][1]==cube[i][1][1] && cube[1][m][n]==cube[k][1][1]){
                        b=c;
                        break;
                    }
                }
            }
            else continue;
        }
    }
    if(b)   layer_2_1(b);
    else{
        for(c=2,a=0;c<=5;c++){
            c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : (i=2,j=4);
            if(cube[c][1][2]==cube[c][1][1] && cube[i][1][0]!=cube[i][1][1]){
                b=c , a=1;  break;
            }
            if(cube[c][1][0]==cube[c][1][1] && cube[j][1][2]!=cube[j][1][1]){
                b=c , a=2;  break;
            }
            if(cube[c][1][2]!=cube[c][1][1])    b=c,a=1;
            if(cube[c][1][0]!=cube[c][1][1])    b=c,a=2;
        }
        if(a==1){
            layer_2_s1(1,b);    move('p',b,'u',3);  move('p',b,'f',3);  move('p',b,'u',1);  move('p',b,'f',1);
        }
        else if(a==2){
            layer_2_s1(2,b);    move('p',b,'u',1);  move('p',b,'f',1);  move('p',b,'u',3);  move('p',b,'f',3);
        }
    }
}
void layer_2_s1(int a,int c){
    if(a==1){
        move('p',c,'r',1);  move('p',c,'u',3);  move('p',c,'r',3);
    }
    else{
        move('p',c,'l',3);  move('p',c,'u',1);  move('p',c,'l',1);
    }
}
void layer_2_1(int c){
    int a=0,i,j,m,n,k;
    while(a<=3){

        c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : (i=2,j=4);
        c==2 ? (m=2,n=1) : c==3 ? (m=1,n=2) : c==4 ? (m=0,n=1) : (m=1,n=0);
        c>3 ? k=c-2 : k=c+2;

        if((cube[c][0][1]==cube[i][1][1] && cube[1][m][n]==cube[k][1][1])){
            printf(a==1 ? "U' " : a==2 ? "U2 " : a==3 ? "U  " : 0);
            layer_2_s1(1,i);    move('p',c,'u',3);  layer_2_s1(2,k);
            (a==1 || a==3) ? s.a++ : a==2 ? s.a+=2 : 1;
            break;
        }
        else if((cube[c][0][1]==cube[j][1][1] && cube[1][m][n]==cube[k][1][1])){
            printf(a==1 ? "U' " : a==2 ? "U2 " : a==3 ? "U  " : 0);
            layer_2_s1(2,j);    move('p',c,'u',1);  layer_2_s1(1,k);
            (a==1 || a==3) ? s.a++ : a==2 ? s.a+=2 : 1;
            break;
        }
        else{
            up(3) ,a++ ,c++;
            c==6 ? c=2 : 0;
        }
    }
}
// layer_3:
void layer_3(char p,int z){
    s1[z].a=0;
    int i,j,k,a=0,b=0,c,count=0,m;
    // first formula
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if((i+j)%2==1 && cube[1][i][j]==cube[1][1][1]){
                count++;
                (i==0 && j==1) ? c=4 : (i==1 && j==0) ? c=5 : (i==1 && j==2) ? c=3 : c=2;
                a==0 ? a=c : b==0 ? b=c : 0;
            }
        }
    }
    if(!count){
        move(p,2,'f',1);  move(p,2,'r',1);  move(p,2,'u',1);  s1[z].a+=6;
        move(p,2,'r',3);  move(p,2,'u',3);  move(p,2,'f',3);  a=3,b=2;
    }
    if(count!=4){
        (a>b ? (a!=5 ? (b=a+b-(a=b)) : 1) : 1) && b<5 ? c=b+1 : c=2;
        move(p,c,'f',1);  move(p,c,'r',1);  move(p,c,'u',1);
        move(p,c,'r',3);  move(p,c,'u',3);  s1[z].a+=5;
        if((a+b)%2!=0){
            move(p,c,'r',1);  move(p,c,'u',1);
            move(p,c,'r',3);  move(p,c,'u',3);  s1[z].a+=4;
        }
        move(p,c,'f',3);    s1[z].a++;
    }
    if(p=='p')  printf("\n");
    // second formula
    for(i=1,j=0;i<=4;i++){
        count=a=b=0;
        for(c=2;c<=5;c++){
            if(cube[c][0][1]==cube[c][1][1]){
                count++;
                a==0 ? a=c : b==0 ? b=c : 0;
            }
        }
        if(count<2){
            up(3);j++;
        }
        else break;
    }
    p=='p' ? printf(j==1 ? "U' " : j==2 ? "U2 " : j==3 ? "U  " : 0) : 1;
    (j==3 || j==1) ? (p=='p' ? s.a++ : s1[z].a++) : j==2 ? (p=='p' ? s.a++ : s1[z].a+=2) : 0;
    if(count!=4){
        ((a==2 && b==5) ? a=a+b-(b=a) : 1) && a>2 ? c=a-1 : c=5;
        if((a+b)%2==0){
            move(p,a,'r',1);  move(p,a,'u',1);  move(p,a,'r',3);  move(p,a,'u',1);
            move(p,a,'r',1);  move(p,a,'u',2);  move(p,a,'r',3);  s1[z].a+=8;
        }
        move(p,c,'r',1);  move(p,c,'u',1);  move(p,c,'r',3);  move(p,c,'u',1);
        move(p,c,'r',1);  move(p,c,'u',2);  move(p,c,'r',3);  move(p,c,'u',1);  s1[z].a+=9;
        if(p=='p')  printf("\n");
    }
    // third formula
    char temp[3];
    while(1){
        for(c=2,a=2,b=0;c<=5;c++){
            c==2 ? (i=2,j=2) : c==3 ? (i=0,j=2) : c==4 ? (i=0,j=0) : (i=2,j=0);
            c<5 ? k=c+1 : k=2;
            temp[0]=cube[1][i][j],temp[1]=cube[c][0][2],temp[2]=cube[k][0][0];
            for(i=0,count=0;i<3;i++){
                if(cube[c][1][1]==temp[i])       count++;
                else if(cube[k][1][1]==temp[i])  count++;
                else if(cube[1][1][1]==temp[i])  count++;
            }
            count==3 ? (a=c,b++) : 1;
        }
        if(b!=4){
            move(p,a,'l',3);    move(p,a,'u',1);    move(p,a,'r',1);    move(p,a,'u',3);
            move(p,a,'l',1);    move(p,a,'u',1);    move(p,a,'r',3);    move(p,a,'u',3);    s1[z].a+=8;
        }
        else break;
    }
    if(p=='p')  printf("\n");
    // fourth formula
    for(c=2,a=0,b=0,count=0;c<=5;c++){
        if(cube[c][0][2]!=cube[c][1][1]){
            a==0 ? a=c : b=(a+c)/2;
            c==5 && a==2 ? (count==2 ? (cube[3][1][1]!=cube[3][0][2] ? b=2 : b=5) : (count==1 ? b=5 : 0)) : 0;
            count++;
        }
    }
    for(c=1;c<=count;c++){
        b<5 ? a=b+1 : a=2;
        a==2 ? (i=2,j=2) : a==3 ? (i=0,j=2) : a==4 ? (i=0,j=0) : (i=2,j=0); 
        if(cube[a][0][2]==cube[1][1][1]){
            move(p,b,'r',1);    move(p,b,'d',1);    move(p,b,'r',3);    move(p,b,'d',3);
            move(p,b,'r',1);    move(p,b,'d',1);    move(p,b,'r',3);    move(p,b,'d',3);
            s1[z].a+=8;
        }
        else if(cube[1][1][1]!=cube[1][i][j]){
            move(p,b,'d',1);    move(p,b,'r',1);    move(p,b,'d',3);    move(p,b,'r',3);
            move(p,b,'d',1);    move(p,b,'r',1);    move(p,b,'d',3);    move(p,b,'r',3);
            s1[z].a+=8;
        }
        else c--;
        if(c<count) move(p,b,'u',3),s1[z].a++;
        if(p=='p')  printf("\n");
    }
    c=0;
    while(1){
        if(cube[2][0][1]!=cube[2][1][1])  up(1),c++;
        else    break;
    }
    if(p=='p') printf(c==1 ? "U  " : c==2 ? "U2 " : c==3 ? "U' " : 0);
    (c==3 || c==1) ? (p=='p' ? s.a++ : s1[z].a++) : c==2 ? (p=='p' ? s.a+=2 : s1[z].a+=2) : 0;
}
// solving handling..
void previous(int a,int b){
    int i,j,k;
    for(k=1;k<=6;k++){
        for(i=0;i<=2;i++){
            for(j=0;j<=2;j++){
                if(a==1)        s1[b].c[k][i][j]=cube[k][i][j];
                else            cube[k][i][j]=s1[b].c[k][i][j];
            }
        }
    }
}
void move(char p,int k,char c,int a){
    int i,j;
    char b;
    for(i=1;i<=a;i++){
        if((c=='f' && k==2) || (c=='l' && k==3) || (c=='b' && k==4) || (c=='r' && k==5)){
            face(1);    b='F';
        }
        else if((c=='r' && k==2) || (c=='f' && k==3) || (c=='l' && k==4) || (c=='b' && k==5)){
            right(1);    b='R';
        }
        else if((c=='b' && k==2) || (c=='r' && k==3) || (c=='f' && k==4) || (c=='l' && k==5)){
            back(1);    b='B';
        }
        else if((c=='l' && k==2) || (c=='b' && k==3) || (c=='r' && k==4) || (c=='f' && k==5)){
            left(1);    b='L';
        }
        if(c=='u'){
            up(1);    b='U';
        }
        if(c=='d'){
            down(1);    b='D';
        }
    }
    if(p=='p'){
        printf("%c",b);
        printf(a==1 ? "  " : a==2 ? "2 " : "' ");
        (a==1 || a==3) ? s.a++ : a==2 ? s.a+=2 : 0;
    }
}
void input(int a){
    int i,j;
    view(a);
    for(i=0;i<3;i++){
        printf("enter %d row: ",i+1);
        scanf(" %c %c %c",&cube[a][i][0],&cube[a][i][1],&cube[a][i][2]);
    }
}
void view(int a){
    int i,j;
    printf("\n-------------\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)    printf("| %c ",cube[a][i][j]);
        printf("|\n-------------\n");
    }
}
// mov3s ar3 noth!ng but ju5t sw@pp!ng...
void down(int k){
    int i,j;
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            cube[2][2][i] = cube[5][2][i] + cube[2][2][i] - ( cube[5][2][i] = cube[2][2][i] );
            cube[5][2][i] = cube[4][2][i] + cube[5][2][i] - ( cube[4][2][i] = cube[5][2][i] );
            cube[4][2][i] = cube[3][2][i] + cube[4][2][i] - ( cube[3][2][i] = cube[4][2][i] );
        }
        turn_1(6);
    }
}
void up(int k){
    int i,j;
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            cube[2][0][i] = cube[3][0][i] + cube[2][0][i] - ( cube[3][0][i] = cube[2][0][i] );
            cube[3][0][i] = cube[4][0][i] + cube[3][0][i] - ( cube[4][0][i] = cube[3][0][i] );
            cube[4][0][i] = cube[5][0][i] + cube[4][0][i] - ( cube[5][0][i] = cube[4][0][i] );
        }
        turn_1(1);
    }
}
void right(int k){
    int i,j;
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            cube[2][i][2] = cube[6][i][2] + cube[2][i][2] - ( cube[6][i][2] = cube[2][i][2] );
            cube[6][i][2] = cube[4][2-i][0] + cube[6][i][2] - ( cube[4][2-i][0] = cube[6][i][2] );
            cube[4][2-i][0] = cube[1][i][2] + cube[4][2-i][0] - ( cube[1][i][2] = cube[4][2-i][0] );
        }
        turn_1(3);
    }
}
void left(int k){
    int i,j;
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            cube[2][i][0] = cube[1][i][0] + cube[2][i][0] - ( cube[1][i][0] = cube[2][i][0] );
            cube[1][i][0] = cube[4][2-i][2] + cube[1][i][0] - ( cube[4][2-i][2] = cube[1][i][0] );
            cube[4][2-i][2] = cube[6][i][0] + cube[4][2-i][2] - ( cube[6][i][0] = cube[4][2-i][2] );
        }
        turn_1(5);
    }
}
void face(int k){
    int i,j;
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            cube[1][2][2-i] = cube[5][i][2] + cube[1][2][2-i] - ( cube[5][i][2] = cube[1][2][2-i] );
            cube[5][i][2] = cube[6][0][i] + cube[5][i][2] - ( cube[6][0][i] = cube[5][i][2] );
            cube[6][0][i] = cube[3][2-i][0] + cube[6][0][i] - ( cube[3][2-i][0] = cube[6][0][i] );
        }
        turn_1(2);
    }
}
void back(int k){
    int i,j;
    for(j=0;j<k;j++){
        for(i=0;i<3;i++){
            cube[1][0][i] = cube[3][i][2] + cube[1][0][i] - ( cube[3][i][2] = cube[1][0][i] );
            cube[3][i][2] = cube[6][2][2-i] + cube[3][i][2] - ( cube[6][2][2-i] = cube[3][i][2] );
            cube[6][2][2-i] = cube[5][2-i][0] + cube[6][2][2-i] - ( cube[5][2-i][0] = cube[6][2][2-i] );
        }
        turn_1(4);
    }
}
void turn_1(int b){
    int i,j,k;
    char a[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j]=cube[b][2-j][i];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cube[b][i][j]=a[i][j];
}

// Sample cube states:
// wwrgyyoryyoygrrobbrorgwwobwbyrgooobggybwgbwrgbywobwyrg
// WWRGYYORYYOYGRROBBRORGWWOBWBYRGOOOBGGYBWGBWRGBYWOBWYRG
// wwrwywgywybgbrybowworrwyoryggrgogbgoorbygoyrgooywbbbbr
// wwrwywoyyybrbrbbwgbyrowyoybgorgogwgywrbbgoyggorgobrwro
// bgwoyrowwggggrrbyoyyywwywwybrwoobbwyrorbgyrbooggbbogrr 1
// gybyygybgwwwrrgobbgrywwgwrbbbroogobgrorygorwyyrowbooyw
// ggbyyywrgwrobrowogbwbbwgyoorbrworwrbybrogyywygwoybgogr 1
// ygbgyorwywrywroorooowgwybryobroorgbwbbrbgygybrwgybgwwg
// owwwyoororowwrbwwrgbyowybrgobbgobrgyrybyggbrwyogybgyrg
// yrwbyyorgbogbrwyybrorgwrrbygobwoorygwwogggyyobgwwbbwro 
// wwbbyrrygworyrworrgoorwggooyborooybyygrygggybbwbwbgwbw 1
// ybwrygrybgwgyryrgrwbbrwgyowygoroboryoorwgyoogbwbbbogww
// rrwwyyyyybbobrobyygbybwogwwbygworbogwworggrgwrgogborro   1
// gorbyyyobwrggrworbwwwowyrryboybowgbboggggyogorrrwbbwyy
// yyywywyorbrwbrbwrybwwrwobbroooworgorogrggggggwygybboyb
// oyyoywbbybrrbrobrgwwwywyryboogbowwwwggrgggggyorrrboybo
// owwoyobbogbgwrogbwyrbgwygrrybbroybywryrwggorwygrgboowy
// goroybwrryybrrbgygowbowwrobybyrowrgowgbgggowowrgybyybw 8
// yyywywyorbrwbrbwrybwwrwobbroooworgorogrggggggwygybboyb
// yywryrbwrorgbrbyoyrwwowybryrooboyrbowgggggbggbwwwbooyg
// yoobybwwrwwwyrbgogroyrwyrwygybroorrobrbyggogobgggbbyww
// yybryrwyrwrrwryybbwwwowwobroooooybbbggrggggggyworbbyog
// U set...
// gygwybwobrobyryyrwwroowboroywrworyborgwgggggybogybwbbr
// yoobyboobyybyrbwrrrrywwwwowrwbroorygygggggggogrwybwbbo   
// gybwyboobrrbyrowrryoybwwwowrworobryyogygggggwgrgybwbbo
// rybbyboobroworbwryrwowwwbowgryroyryybgygggwgggrgybwobo
// gwboyyowgwrworboywbybowwrbgrorrowyybogrgggygyoryrbbgbw
// bowbyyowgrrborwrywywyowwryygywroorrgogbgggogobbwrbbgby
// brooywowrwwgorywrwroyowygrygyybobgbbwgbgggogrrrywbboyb
// wybbywoorowgbrowworryywbgbyrogoorrybwgwgggggobryybwyrb
// yyyryybrwrrwbrobbbowrywbywbwoowowooogggggggggybwobyrrr
// yyybywrrrrrwbrybwbowrowywbywooroobobgggggggggowwybbory
// ryowyrbwbyrrbrrrbbwwwywywwyooyooobbrgggggggggoyyrbboow
// green is already set..
// worst case layer-2
// yyyoyrbww rrryrwbyb wwwrwowob ooowoyorr ggggggggg ybybbbobr
// yyyoyrbrw rrryrwobo wwwrwoyob ooowoyrbr ggggggggg wyybbbbwb
// yyyryybyb rrrrrbwww wwwowbbwb oooyoworr ggggggggg ybyoborbo
// yyyyyboworrrrrrbybwwwwwwyowoooooobrbgggggggggryybbbrbw
// without using layer 1 formula...
// yrwbyyorgbogbrwyybrorgwrrbygobwoorygwwogggyyobgwwbbwro
// yyyyyyoyb rrrrrrrbo wwwwwwbrr oooooobbb ggggggggg ywybbbwow
// yyyyyyybrrrrrrrwbywwwwwwrbwooooooobogggggggggbrbobwbyb
// yyyyyyrybrrrrrrorrwwwwwwbwooooooobobgggggggggwbwbbbyby
// yyyyyyybbrrrrrrybbwwwwwwwbboooooorbogggggggggwrbobwoyr
// yyyyyyrbbrrrrrrwbbwwwwwwobyoooooorbbgggggggggbwwyboyro
// rybbyboobroworbwryrwowwwbowgryroyryybgygggwgggrgybwobo
// oyrbyrowrbgogrwgbggobgwgyryrrbyorgybwowwgbyywroywbboow
// yyyyyyoborrrrrrybrwwwwwwwbyoooooorbwgggggggggbobybrbwb
// yyyyyybbbrrrrrrrbywwwwwwrboooooooybogggggggggbwwobrbyw
// yyyyyyyyyrrrrrrrrrwwwwwwwwwooooooooogggggggggbbbbbbbbb
// wwgwyowyb yrbgrrwrg rywwwoyoo ryrbooygo ygrbgbbgg bwgybrobo
// yyyyyyoyrrrrrrrbrbwwwwwwrwooooooobobgggggggggwbybbbwby