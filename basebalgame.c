#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 

int main() {
    printf("Hello BaseBall Game!\n");
    srand((unsigned int)time(NULL));
    int answerArr[3], i, sub_i, inputArr[3],j ;
    for(i=0; i< 3; i++){
        answerArr[i] = rand()%9;
        for (sub_i = 0;sub_i<i;sub_i++){
            if(answerArr[i]== answerArr[sub_i]){
                i--;
                break;
            }
        }
    }

    printf("0~9 까지의 정수 중 3개의 정수를 중복 없이 입력하세요.\n");
    printf("10회 시도를 하거나 스트라이크가 3회 나오면 게임은 종료 됩니다.\n");
    printf("(각 정수 사이는 띄어쓰기로 입력합니다. 예. 1 2 3)\n");

    
    int retry, strike,ball;
    for(retry=0;retry<10&&strike<3; retry++){
        bool test1=true, test2=true;
        printf("%d번째 시도! ", retry +1);
        scanf("%d%d%d", &inputArr[0],&inputArr[1],&inputArr[2]);
        for(i=0;i<2;i++){
            if(inputArr[i]==inputArr[i+1]){
                test1=false;
                break;
            }
        }
        for(i=0;i<3; i++){
            if(inputArr[i]>9){
                test2=false;
                break;
            }
        }
        strike = ball = 0;
        if(test1==true && test2==true){
            for(i=0;i<3;i++){
                for (j=0; j<3;j++){
                    if(answerArr[i]==inputArr[j]){
                        if(i==j) strike++;
                        else ball++;
                    }
                }
            }
            printf("%d Strike, %d Ball \n", strike,ball);
        }
        else {
            printf("숫자가 잘 못 입력 되었습니다. 다시 입력 하세요.\n");
            retry--;
        }
    }

    if(strike==3 && retry ==1 ) printf("HOMERUN!! %d %d %d 정답입니다. ", answerArr[0],answerArr[1],answerArr[2]);
    if(strike==3) printf("%d %d %d 정답입니다. ", answerArr[0],answerArr[1],answerArr[2]);
    else printf("Game Over! 정답은 %d %d %d 입니다.", answerArr[0],answerArr[1],answerArr[2]);    
}

