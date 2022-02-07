#include <stdio.h>

int main(){
    int n ;
    scanf("%d",&n);
    int x ,y;
    x= y= 1;
    getchar();
    
    char in;
    for(int i = 0 ; i < n ;i++){
        scanf("%c",&in);
        getchar();
        if(
           (x <= 1 && in =='L') || (y<= 1 && in=='U')
           ||(x >= n && in == 'R' ) || (y >= n && in=='D')){
               i--;
               continue;
           }
        switch (in) {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            default:
                break;
        }
        
    }
    printf("%d %d\n",x,y);
}
