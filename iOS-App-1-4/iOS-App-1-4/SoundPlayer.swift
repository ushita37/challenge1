//
//  SoundPlayer.swift
//  iOS-App-1-4
//  
//  Created by ushita37 on 2024/01/13
//  
//

import UIKit
import AVFoundation

class SoundPlayer: NSObject {
    // シンバルの音源データを読み込み
    let cymbalData = NSDataAsset(name: "cymbalSound")!.data
    
    // シンバル用プレイヤーの変数
    var cymbalPlayer: AVAudioPlayer!
    
    // ギターの音源
    let guitarData = NSDataAsset(name: "guitarSound")!.data
    
    // ギター用プレイヤー
    var guitarPlayer: AVAudioPlayer!
    
    func cymbalPlay(){
        do {
            // シンバル用のプレイヤーに、音源データを指定
            cymbalPlayer = try AVAudioPlayer(data: cymbalData)
            
            cymbalPlayer.play()
        } catch {
            print("シンバルでエラー")
        }
        
    }
    
    func guitarPlay(){
        do {
            guitarPlayer = try AVAudioPlayer(data: guitarData)
            guitarPlayer.play()
        } catch {
            print("ギターでエラー")
        }
    }

}
