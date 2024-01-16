//
//  MapView.swift
//  iOS-App-1-5
//  
//  Created by ushita37 on 2024/01/16
//  
//

import SwiftUI
import MapKit

struct MapView: View {
    // 検索キーワード
    let searchKey: String
    // キーワードから取得した緯度経度
    @State var targetCoordinate = CLLocationCoordinate2D()
    var body: some View {
        Map(){
            
        }
        // 検索キーワードの変更を検知
        .onChange(of: searchKey, initial: true) { oldValue, newValue
            in
            // 入力されたキーワードをデバッグエリアに表示
            print("検索キーワード: \(newValue)")
            
            // 検索クエリの作成
            let request = MKLocalSearch.Request()
            // クエリにキーワードの設定
            request.naturalLanguageQuery = newValue
            // MKLocalSearchの初期化
            let search = MKLocalSearch(request: request)
            
            // 検索の開始
            search.start{ response, error in
                // 結果が存在するときは、1件目を取り出す
                if let mapItems = response?.mapItems,
                   let mapItem = mapItems.first {
                    
                    // 緯度経度をtargetCoordinateに取り出す
                    targetCoordinate = mapItem.placemark.coordinate
                    
                    // 緯度経度をデバッグエリアに表示
                    print("緯度経度: \(targetCoordinate)")
                }
                
            }
        }// onChangeここまで
    }
}

#Preview {
    MapView(searchKey: "東京駅")
}
