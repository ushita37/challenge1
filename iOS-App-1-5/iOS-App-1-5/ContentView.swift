//
//  ContentView.swift
//  iOS-App-1-5
//  
//  Created by ushita37 on 2024/01/15
//  
//

import SwiftUI

struct ContentView: View {
    // 入力中の文字列を保持する状態変数
    @State var inputText: String = ""
    // 検索キーワードを保持する状態変数、初期値は"東京駅"
    @State var displaySearchKey: String = "東京駅"
    
    var body: some View {
        VStack{
            
            TextField("キーワード", text: $inputText, prompt:
                Text("キーワードを入力してください"))
            //入力が完了された時
            .onSubmit {
                displaySearchKey = inputText
            }
            // 余白を追加
            .padding()
            
            //マップを表示
            MapView(searchKey: displaySearchKey)
        }   // VStack ここまで
    }
}

#Preview {
    ContentView()
}
