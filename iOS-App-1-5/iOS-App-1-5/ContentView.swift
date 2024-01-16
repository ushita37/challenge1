//
//  ContentView.swift
//  iOS-App-1-5
//  
//  Created by ushita37 on 2024/01/15
//  
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack{
            MapView(searchKey: "羽田空港")
        }
    }
}

#Preview {
    ContentView()
}
