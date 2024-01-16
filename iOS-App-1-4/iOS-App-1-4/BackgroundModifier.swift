//
//  BackgroundModifier.swift
//  iOS-App-1-4
//  
//  Created by ushita37 on 2024/01/15
//  
//

import SwiftUI

extension Image {
    func backgroundModifier() -> some View {
        // 画像を表示するImageのインスタンス
        self
            .resizable()
            .ignoresSafeArea()
            .scaledToFill()
    }   // backgroundModifier ここまで
}
