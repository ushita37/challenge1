//
//  ContentView.swift
//  iOS-App-1-3
//
//  Created by うしたウシタ on 2024/01/05.
//

import SwiftUI

struct ContentView: View {
    
    // じゃんけんの結果を格納する変数
    @State var jankenNumber = 0
    
    var body: some View {
        
        VStack {
            // スペースを追加
            Spacer()
            
            // 数字が0だったら
            if jankenNumber == 0 {
                Text("これからじゃんけんをします！")
                    .padding(.bottom)
            } else if jankenNumber == 1 {
                // 数字が1だったらグー
                // グー画像を指定
                Image(.gu)
                // モディファイア(画面に収まるよう縦横比を維持してリサイズ)
                    .resizable()
                    .scaledToFit()
                Spacer()
                Text("グー")
                    .padding(.bottom)
            } else if jankenNumber == 2 {
                // 数字が2だったらチョキ
                Image(.choki)
                    .resizable()
                    .scaledToFit()
                Spacer()
                Text("チョキ")
                    .padding(.bottom)
            } else {
                // パー
                Image(.pa)
                    .resizable()
                    .scaledToFit()
                Spacer()
                Text("パー")
                    .padding(.bottom)
            }
            

            
            Button(action: {
                // 次のじゃんけんへ
                jankenNumber = Int.random(in: 1...3)
                // 新しいじゃんけんの結果
                var newJankenNumber = 0
                
                // 前回の結果と異なる場合のみ採用
                repeat {
                    newJankenNumber = Int.random(in: 1...3)
                    // 前回と同じ結果の時は、再度ランダムに数値を出す
                } while jankenNumber == newJankenNumber
                
                // 新しいじゃんけんの結果を格納
                jankenNumber = newJankenNumber
            }, label: {
                
                Text("じゃんけんをする！")
                    .frame(maxWidth: /*@START_MENU_TOKEN@*/.infinity/*@END_MENU_TOKEN@*/)
                    .frame(height: 100)
                    .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                    .background(.pink)
                    .foregroundColor(.white)
            })
        }
    }
}

#Preview {
    ContentView()
}
