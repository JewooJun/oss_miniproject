typedef struct{
char name[20]; // 제품명
char content[256]; // 설명
char weight[256]; // 중량
int price; // 판매가격
int ship; // 배송방법
} Product; 

int selectMenu();

void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
void readProduct(Product p); // 하나의 제품 출력 함수
int selectDataNo(Product *p, int count); // 제품번호 검색 함수

int createProduct(Product *p); // 제품을 추가하는 함수

void searchProduct(Product *p, int count); // 제품이름 검색
void searchPrice(Product *p, int count); // 제품 가격 검색
void searchWeight(Product *p, int count); // 제품 중량 검색

int updateProduct(Product *p); // 제품 수정
int deleteProduct(Product *p); // 제품 삭제

int loadData(Product *p); // File에서 데이터 불러오기
void saveData(Product *p, int count); // File 저장
