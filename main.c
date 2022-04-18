#include <stdio.h>
#include "manager.h"

int main(void){
#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif
    Product plist[256];
    int index = 0;
    int count = 0;
    int menu;
    count = loadData(plist);
    index = count;
    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4)
            if(count == 0) continue;
        if(menu == 1) listProduct(plist, count);
        else if(menu == 2){
            count += createProduct(&plist[index++]);
        }
        else if(menu == 3){
            int no = selectDataNo(plist, index);
            if(no == 0){
                printf("취소됨!\n");
                continue;
            }
            int isupd = updateProduct(&plist[no-1]);
            if(isupd == 1) printf("=> 수정성공!\n");
        }
        else if(menu == 4){
            int no = selectDataNo(plist, count);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1) ");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&plist[no-1])){
                    printf("=> 삭제됨!\n");
                }
            }
        }
        else if(menu == 5) saveData(plist, count);
        else if(menu == 6) searchProduct(plist, count);
        else if(menu == 7) searchPrice(plist, count);
        else if(menu == 8) searchWeight(plist, count);
    }
    printf("종료됨!\n");
    return 0;
}
