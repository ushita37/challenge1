#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 65536
#define MAX_INT 2147483647
#define MAX_NODE_NUM 10

struct node {
    char id;
    int node_cost;
    int d; // スタートノードからの距離
    char prep;  // 直前のノード
    int neighbor_num;
    char neighbors[MAX_NODE_NUM];
    int link_costs[MAX_NODE_NUM];
};



int main(int argc, char** argv) {
    // コマンドライン引数: ./a.out topology1.txt true S D
    bool node_cost_flag = !strcmp(argv[2],"true");  // もしtrueなら、ノードコストも考慮する
    char startID = argv[3][0];
    char destinationID = argv[4][0];
    char node_ids[MAX_NODE_NUM] = {0};   // 構造体の初期化
    struct node nodes[MAX_NODE_NUM]; // 構造体の初期化

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }
    char buf[MAX_SIZE];
    int node_num = 0;   // node_numは入力の行数をも表す

    while (fgets(buf, MAX_SIZE, fp) != NULL) {
        // ここでノードの情報の初期化も行う
        nodes[node_num].id = 0;
        nodes[node_num].node_cost = MAX_INT;
        nodes[node_num].d = MAX_INT;
        nodes[node_num].prep = 0;
        nodes[node_num].neighbor_num = 0;
        for(int i = 0; i < MAX_NODE_NUM; i++) {
            nodes[node_num].neighbors[i] = 0;
            nodes[node_num].link_costs[i] = MAX_INT;
        }

        // 入力例のうち、1行はこんな感じ: node,S,1,neighbor,A,7,B 9,C,14
        for (int i = 0; i < MAX_SIZE; i++) {
            if (buf[i] == '\n' || buf[i] == '\r') { // CRLFの改行もヌル文字に置き換える
                buf[i] = '\0';
                break;
            }
        }

        sscanf(buf, "%*[^,],%c,%d,%*[^\n]", &node_ids[node_num], &nodes[node_num].node_cost);
        nodes[node_num].id = node_ids[node_num];
        if (node_ids[node_num] == startID) nodes[node_num].d = 0;

        char *p = buf;
        // ,を区切りに文字列を抽出

        // neighbor,の後ろまでをスキップ(頭から数えて、4つ目の,までスキップ)
        for(int i = 0; i < 4; i++) {
            p = strchr(p, ',');
            p++;
        }

        int token_num = 0;
        p = strtok(p, ",");
        sscanf(p, "%c", &(nodes[node_num].neighbors[token_num]));
        p = strtok(NULL, ",");
        sscanf(p, "%d", &(nodes[node_num].link_costs[token_num]));

        while (p != NULL) {
            token_num++;
            p = strtok(NULL, ",");
            if(p == NULL) break;    // 全ての隣接ノードを格納したら、ここでbreak
            sscanf(p, "%c", &(nodes[node_num].neighbors[token_num]));
            p = strtok(NULL, ",");
            if(p == NULL) break;
            sscanf(p, "%d", &(nodes[node_num].link_costs[token_num]));
        }
        nodes[node_num].neighbor_num = token_num;
        node_num++;
    }
    fclose(fp);
    return 0;
}
