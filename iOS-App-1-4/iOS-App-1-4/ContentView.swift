//
//  ContentView.swift
//  iOS-App-1-4
//  
//  Created by ushita37 on 2024/01/12
//  
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        ZStack {
            Image(.background)
            // リサイズ
                .resizable()
            // セーフエリア外まで表示
                .ignoresSafeArea()
            // 短編基準で収まるように
                .scaledToFill()
            HStack {
                // シンバル
                Button {
                    
                } label: {
                    Image(.cymbal)
                }
                
                // ギター
                Button {
                    
                } label: {
                    Image(.guitar)
                }
            }   // HStack ここまで
        }   // ZStack ここまで
    }
}

#Preview {
    ContentView()
}
