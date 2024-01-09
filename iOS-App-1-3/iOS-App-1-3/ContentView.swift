//
//  ContentView.swift
//  iOS-App-1-3
//
//  Created by うしたウシタ on 2024/01/05.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        // グー画像を指定
        Image(.gu)
            // モディファイア(画面に収まるよう縦横比を維持してリサイズ)
            .resizable()
            .scaledToFit()
    }
}

#Preview {
    ContentView()
}
