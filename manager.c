#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "manager.h"

// 메뉴판 출력하기
int selectMenu(){
    int menu;
    printf("\n*** 제품 검색창 ***\n");
    printf("1. 제품 조회\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 수정\n");
    printf("4. 제품 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 제품 이름 검색\n");
    printf("7. 제품 가격 검색\n");
    printf("8. 제품 중량 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 전체 등록된 제품 리스트 출력하기
void listProduct(Product *p, int count){
    int i = 0;
    printf("No. 제품명 설명 중량 판매가격 배송방법(1:새벽배송 /2:택배배송)\n");
    printf("---------------------------------------------------\n");
    for (i = 0; i < count; i++){
        if (p[i].price == -1) continue;
        printf("%d ", i + 1);
        readProduct(p[i]);
    }
    printf("\n");
}

// 하나의 제품 출력 함수
void readProduct(Product p){
    printf("%s %s %s %d %d\n", p.name, p.content, p.weight, p.price, p.ship);
}

int selectDataNo(Product* p, int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

// 제품을 추가하는 함수
int createProduct(Product *p){
    printf("제품의 이름은? ");
    scanf(" %[^\n]", p->name);
    printf("제품의 설명은? ");
    scanf(" %[^\n]", p->content);
    printf("제품의 중량은? ");
    scanf(" %[^\n]", p->weight);
    printf("제품의 가격은? ");
    scanf(" %d", &p->price);
    printf("제품의 배송방법은? (1:새벽배송 / 2:택배배송)");
    scanf(" %d", &p->ship);
    return 1;
}

// 제품이름 검색하기
void searchProduct(Product *p, int count){
    char sname[20];
    int scnt = 0;
    printf("검색할 제품 이름? ");
    scanf(" %s",sname);
    printf("No. 제품명 설명 중량 판매가격 배송방법(1:새벽배송 /2:택배배송)\n");
    printf("---------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, sname)){
            printf("%2d ",i + 1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

// 제품 가격 검색
void searchPrice(Product *p, int count){
    int searchp;
    int scnt = 0;
    printf("검색할 제품 가격? ");
    scanf("%d", &searchp);
    printf("No. 제품명 설명 중량 판매가격 배송방법(1:새벽배송 /2:택배배송)\n");
    printf("---------------------------------------------------\n");
    for(int i = 0; i<count; i++){
        if(p[i].price == -1) continue;
        if(p[i].price == searchp){
            printf("%2d ",i + 1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

// 제품 중량 검색
void searchWeight(Product *p, int count){
    char wname[20];
    int scnt = 0;
    printf("검색할 제품 중량? ");
    scanf(" %s",wname);
    printf("No. 제품명 설명 중량 판매가격 배송방법(1:새벽배송 /2:택배배송)\n");
    printf("---------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].weight, wname)){
            printf("%2d ",i + 1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

// 제품 수정
int updateProduct(Product *p){
    printf("새로운 제품의 이름은? ");
    scanf(" %[^\n]", p->name); 
    printf("새로운 제품의 설명은? ");
    scanf(" %[^\n]", p->content);
    printf("새로운 제품의 중량은? ");
    scanf(" %[^\n]", p->weight);
    printf("새로운 제품의 판매가격은? ");
    scanf(" %d", &p->price);
    printf("새로운 제품의 배송방법은? (1:새벽배송 /2:택배배송) "); 
    scanf(" %d", &p->ship);
    return 1;
}

// 제품 삭제하기
int deleteProduct(Product *p){
    p->price = -1;
    return 1;
}

// 파일에서 데이터 불러오기
int loadData(Product *p){
    FILE *fp;
    fp = fopen("product.txt","rt");
    int i = 0;
    if(fp == NULL){
        printf("=>파일 없음\n");
    }
    else{
        for(; i < 256; i++){
            fscanf(fp," %[^,], %[^,], %[^,] %d %d ", p[i].name, p[i].content, p[i].weight, &p[i].price, &p[i].ship);
            if (feof(fp)) break;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    }
    return i;
}

// 파일 저장
void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("product.txt","wt");
    for(int i=0; i < count; i++){
        if(p[i].price == -1) continue;
        fprintf(fp,"%s %s %s %d %d\n", p[i].name, p[i].content, p[i].weight, p[i].price, p[i].ship);
    }
    fclose(fp);
    printf("저장됨!\n");
}
