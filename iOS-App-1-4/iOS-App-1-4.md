# 楽器アプリ
『iPhoneアプリ開発集中講座』を読み進めています。これからは楽器アプリを作ります。

## 1/12
Xcodeでプロジェクトを作成すると、`ContentView.swift`などのファイルに自動でコメントアウトが生成される。このコメントアウトには、ファイル名やプロジェクト名、作成日などが含まれるが、アカウントによっては開発者の本名が載る場合がある。
本名が載ると不都合が生じる場合があるのでこれを別の名前(ハンドルネーム)で置き換えたい、と言う場合には、`~/Library/Developer/Xcode/UserData/IDETemplateMacros.plist`を編集すれば良い。

[参考にした記事](https://qiita.com/yudwig/items/855847f0254a13dfb0cc)

以下のコードで、`Created by ushita37 on ___DATE___`と表示されている場所を変更した。`ushita37`という文字列は私が設定したものだが、ここが`___DATE___`になっていると、Apple IDで設定した名前が表示されてしまう。
GitHubなどでコードを公開する時は注意が必要だ。

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>FILEHEADER</key>
    <string>
//  ___FILENAME___
//  ___TARGETNAME___
//  
//  Created by ushita37 on ___DATE___
//  ___COPYRIGHT___
//</string>
</dict>
</plist>

```


## 1/13のコメント
p.188 ギターの音を鳴らすところまで

iOSアプリを作る時に用いるXcodeの他にも、FPGAのプログラミングで用いるVivadoなどの(用途がある程度決まっている)IDEを使う時に気を付けるべきことがある。
今回のアプリの例では、`SoundPlayer.swift`を編集し、ここで定義されたクラスを`ContentView.swift`で実体化して用いている。言い換えれば、2つのファイルに依存関係がある、ということである。
競技プログラミングでは大抵の場合、一つの`.c` `.cpp` `.py`ファイルを作れば事足りるが、実際の開発をする場面でのプログラミングでは、複数のファイルを扱うことになる。そのため、自分が使っている関数・メソッド・クラスはどこで定義されているのか、に注意する必要がある。