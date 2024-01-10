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
            
            // 数字が0だったら
            if jankenNumber == 0 {
                Text("これからじゃんけんをします！")
            } else if jankenNumber == 1 {
                // 数字が1だったらグー
                // グー画像を指定
                Image(.gu)
                // モディファイア(画面に収まるよう縦横比を維持してリサイズ)
                    .resizable()
                    .scaledToFit()
                Text("グー")
            } else if jankenNumber == 2 {
                // 数字が2だったらチョキ
                Image(.choki)
                    .resizable()
                    .scaledToFit()
                Text("チョキ")
            } else {
                // パー
                Image(.pa)
                    .resizable()
                    .scaledToFit()
                Text("パー")
                
            }
            

            
            Button(action: {
                // 次のじゃんけんへ
                jankenNumber = jankenNumber + 1
            }, label: {
                
                Text("じゃんけんをする！")
            })
        }
    }
}

#Preview {
    ContentView()
}
