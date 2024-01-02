# 行ごとに長さが変わる文字列からなるテキストファイルを、入力としてを受け取る
昨日1/1に`README.me`で書いた通り、何をするか、今後の方針をどうするかは未だ決まっていません。とりあえず今日1/2は、プログラミングをしていて気になった、C言語の入力について扱います。

## 「綺麗でない」入力の例
以下のような入力があったとする。
```
node,S,4,neighbor,A,3,B,5,C,9
node,A,1,neighbor,S,3,D,4
node,B,1,neighbor,S,5,D,12
node,C,2,neighbor,S,9,H,18,F,2
node,D,10,neighbor,A,4,B,12,F,3,H,4
node,E,4,neighbor,F,3
node,F,3,neighbor,C,2,D,3,E,3,G,4
node,G,1,neighbor,F,4,H,5
node,H,2,neighbor,C,18,D,4,G,5
```
これは、ある単純連結無向グラフを表したものである。`S,A,B,C,D,E,F,G,H`は節点(node)であり、それぞれが`4,1,1,2,10,4,3,1,2`というコストを持っている。
また、例えば1行目であれば`neighbor,`という文字列の後に、`A,3`というアルファベットと数字の組みがあるが、これは1行目が表すノード`S`について、`A`との間に辺が1本あって、そのコストは`3`である、ということを表す。

グラフのある点から別の点までの最短経路をダイクストラ法で探す、いわば乗換案内のような問題を念頭に、この入力を眺めてみる。すると、入力には不要な文字(列)が多く含まれており、他方で(必須ではないが)あると望ましい情報が欠けていることがわかる。例えば、
- `node` `neighbor`という文字列は、実際の処理では使わない
- `,`は各要素を区切る文字として使われている
- `A,3`のような、隣接する点とその点までのコストの組がいくつあるのかわからない、つまりそれぞれの点の次数が入力例から直接読み取れない
といったことが分かる。

これらの特徴により、難易度が低めの競技プログラミングで用いるような「綺麗な」入力例を扱う上では発生しない、以下の問題が発生する。
- 不要な部分はスキップしながら行を読み込まなければいけない
- 区切り文字がスペース` `あるいは`\n`ではないので面倒
- 要素の数がいくつあるか、格納するまで分からないので、`scanf`などの関数を何回繰り返し用いればよいか分からない

## ファイルを開いて1行読み込み、その行を文字列変数に格納する
コマンドライン引数は、`./a.out topology1.txt true S D`というような形式となる。入力ファイル名は`topology1.txt`であり、(0から数えて)1番目のコマンドライン引数である。これをCプログラムの中で用いて、ファイルを読み込む。
```
FILE *fp = fopen(argv[1], "r");
if (fp == NULL) {
    printf("File not found!\n");
    return 1;
}
char buf[MAX_SIZE];

while (fgets(buf, MAX_SIZE, fp) != NULL) {
```
`fopen`の引数に、ファイル名を表す`argv[1]`を渡して、`while`ループの中で`fgets`を用いて`buf`にファイルの中身を1行ずつ格納している。ここまでは簡単。

## フォーマットと各変数への格納
例えば、`node,S,4,neighbor,A,3,B,5,C,9`という行について、`S`を`char`型配列のある要素として、`4`を`int`型配列のある要素として格納し、`node`や`neighbor`といった文字列は読み飛ばしたいとする。このとき、
```
sscanf(buf, "%*[^,],%c,%d,%*[^\n]", &node_ids[node_num], &nodes[node_num].node_cost);
```
のようなコードを書いてみた。
[scanfの解説サイト](https://cplusplus.com/reference/cstdio/scanf/)が示すように、`*`や`[^]`でを用いて一部の文字列を読み飛ばすことができる。

また、文字を検索する`strchr`を使って、
```
char *p = buf;
// neighbor,の後ろまでをスキップ(頭から数えて、4つ目の,までスキップ)
for(int i = 0; i < 4; i++) {
    p = strchr(p, ',');
    p++;
}
```
というコードを書いてポインタ`p`を移動させる。その上で、`strtok`と区切り文字の`,`を上手く使って文字列をトークンに分割し、
```
int token_num = 0;
p = strtok(p, ",");
sscanf(p, "%c", &(nodes[node_num].neighbors[token_num]));
p = strtok(NULL, ",");
sscanf(p, "%d", &(nodes[node_num].link_costs[token_num]));

while (p != NULL) {
    token_num++;
    p = strtok(NULL, ",");
    if(p == NULL) break;
    sscanf(p, "%c", &(nodes[node_num].neighbors[token_num]));
    p = strtok(NULL, ",");
    if(p == NULL) break;
    sscanf(p, "%d", &(nodes[node_num].link_costs[token_num]));
}
```
のようにして、いくつデータ(`A,3`のような組)が続くか分からない時でも、`char`型や`int`型に変換して格納できる。
この例では、`while`ループで複数回`strtok`を用いてポインタを動かしているので、途中で`NULL`かどうかの判定を挟まないとエラーを起こす。

[strtokの解説サイト](http://www9.plala.or.jp/sgwr-t/lib/strtok.html)

## 今日の一言
(この部分は後から付け足したのでJSTで1/3のコミットになってますが、1/2の分ということにしてください...)
スキルアップのために何をすればいいか模索している段階ですが、とにかくがんばります。Try Harder.