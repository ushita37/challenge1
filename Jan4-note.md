# 関数を引数として別の関数に渡す
こんにちは。ウシタです。1日にリポジトリ作成と`README`コミット、2日に`scanf`や`strtok`関連のコミット、3日にCLionのデバッグに関するコミットをしましたが、そろそろネタがなくなってきました。どうしましょう。


## 関数に渡せる引数は、整数値や実数値、文字だけではない
私がとある計算をしていた時、ある関数を別の関数で使いたいと思ったことがある。以下にC言語で書かれたプログラムの例を示す。
```
#define A 0.0 // 積分区間の先頭
#define B 1.0 // 積分区間の最後

double func1(double x) {
    return 4.0 * sqrt(1 - x * x);
}

double func2(double x) {
    return 4.0 / (1.0 + x * x);
}

double gauss (double x) {
    // 積分区間は実数全体、最後に積分値を2乗して円周率を得る
    return exp(-x * x);
}

void simpson (double (*f)(double), const double a, const double b, const int n, double *pre_err){
    // 省略
}

int main(void) {
    // 省略
        simpson(func1, a, b, n, &pre_err);
}
```
シンプソン則という、定積分の計算をする方法がある。今回は、この定積分を行う関数`simpson`を使って、様々な定積分の計算をさせることを考える。

定積分をするには、`simpson`以外にも被積分関数が必要だ。今、円周率を積分によって求めようとしているが、そのような被積分関数は複数ある。そのため、シンプソン則を用いるときに簡単に被積分関数を切り替えられるように、`simpson`の定義では特定の関数を使わずにある関数`double (*f)(double)`を用いて宣言する。

このとき、main関数で`simpson`を呼び出すときに、関数`func1`や`func2`、`gauss`を引数とする。なお、これらの関数名は「関数のメモリ番地」を表しているので、`simpson`を定義するときは第一引数に~~`double f(double)`ではなく~~`double (*f)(double)`と記述し、関数ポインタとする必要がある。


## 今日の一言
VSCode使っているときに間違えて`Command`+`R`, `Command`+`K`を押したら、[MacOSのキーボードショートカット](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf) が出てきてびっくりしてます。偶然ってすごいですね。

数学が苦手なので、定積分により円周率を求める公式を探したり考えたりするのに苦労しました。情報系だけじゃなくて数学の勉強もしましょう。Try Harder.