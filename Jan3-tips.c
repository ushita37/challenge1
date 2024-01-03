struct student {
    int id;
    char name[32];
    int score;
};
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct avl_node {
    datatype data;
    struct avl_node *left, *right;
    int height;
};