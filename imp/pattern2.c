#include <stdio.h>
int main(){
    char s = 'G';
    
    for(char i=s;i>='A';i--){
        for(char j=s;j>i;j--){
            printf(" ");
        }
        for(char k=i;k>='A';k--){
            printf("%c",k);
        }
        printf("\n");
    }
    return 0;
}

// G F E D C B A  
//   F E D C B A  
//     E D C B A  
//       D C B A  
//         C B A  
//           B A  
//             A  
