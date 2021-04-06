#include<stdio.h>
#include<stdlib.h>
void empty(char matrix[3][3]);//initialize matrixe with ' '.
void display(char matrix[3][3]);
char check(char matrix[3][3]);//will return x if player won, O if pc one, ' ' for no result . 
void get_comp(char matrix[3][3]);
void get_player(char matrix[3][3]);
int main()
{   char done,matrix[3][3],r='y';
    do{
    printf("welcome to the game of Tik--Tak--Toe\n");
    printf("you(X) will be playing against the computer(O)\n");
    printf("good luck\n");
    empty(matrix);
    display(matrix);
    do
    { 
      get_player(matrix);
      done=check(matrix);
      if(done!=' ') break;
      display(matrix);
      printf("\ncomputers move\n");
      get_comp(matrix);
      done=check(matrix);
      if(done!=' ') break;
      display(matrix);
        
    }while (done==' ');

    display(matrix);
    if(done=='X'){ 
      printf("congrats you won!!!:)\nDo you want to play again? (Y/y)\n");
      scanf("%c",&r);
      scanf("%c",&r);
      }
    else if (done=='O'){ printf("you lose\n want to play again? press (Y/y)\n");
      scanf("%c",&r);
      scanf("%c",&r);}
    }while(r=='Y'||r=='y');
}

void empty(char matrix[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    matrix[i][j]=' ';

}

void display(char matrix[3][3])
{
    int i,j;
    printf("\n");
    for(i=0;i<3;i++)
    {printf(" %c | %c | %c \n",matrix[i][0],matrix[i][1],matrix[i][2]);
    if(i<2)
    printf("---|---|---\n");
    }
    printf("\n");
}

void get_comp(char matrix[3][3])
{
    int i,j;
    for(i=0;i<3;i++){
    for(j=0;j<3;j++)
    if(matrix[i][j]==' ') break;
    if(matrix[i][j]==' ') break;
    }
    if(i*j==6)
    {printf("ITS A DRAW\n");
     exit(0);
    }
    else 
    matrix[i][j]='O';
    
}

void get_player(char matrix[3][3]){
    int i,j;
    printf("enter the coordinates of your move{(1,1)->(3,3)} // seperate with commas\n");
    scanf("%d,%d",&i,&j);
    printf("%d,%d",i,j);
    if(i>3||j>3){
        printf("invalid coordinates enter again\n");
        get_player(matrix);
    }
    else if(matrix[i-1][j-1]!=' '){ 
    printf("\nspace not empty\n");
    printf("enter again\n");
    get_player(matrix);
    }
    matrix[--i][--j]='X';
}

char check(char matrix[3][3]){
    int i,j;
    char cmp;
    for(i=0;i<3;i++){
        cmp=matrix[i][0];
        if((matrix[i][0]==matrix[i][1])&&(matrix[i][2]==matrix[i][1])) return cmp;
    }
    for(j=0;j<3;j++){
        cmp=matrix[0][j];
        if((matrix[0][j]==matrix[1][j])&&(matrix[2][j]==matrix[1][j])) return cmp;
    }
    cmp=matrix[0][0];
    for(i=0,j=0;i<3,j<3;i++,j++){
    if(matrix[i][j]!=cmp) break;
    }
    if(i*j==9)
    return cmp;

    cmp=matrix[0][2];
    for(i=0,j=2;i<3,j>=0;i++,j--)
    if(matrix[i][j]!=cmp) break;
    
    if(i==3)
    return cmp;

    return ' ';
}
