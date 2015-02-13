//
//  TopTextScene.h
//  TextButton
//
//  Created by MAEDAHAJIME on 2015/02/13.
//
//

#ifndef __TextButton__TopTextScene__
#define __TextButton__TopTextScene__

#include "cocos2d.h"
#include <ui/CocosGUI.h>
USING_NS_CC;

class TopTextScene :public Layer
{
protected:
    // コンストラクタ
    TopTextScene();
    // デストラクタ
    virtual ~TopTextScene();
    // メソッド CREATE_FUNCとの連携
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    CREATE_FUNC(TopTextScene);
    // ゲームスタートボタンメソッド
    void createGameStartButton();
    // タッチイベント
    void touchEvent(Ref* pSender, cocos2d::ui::TouchEventType type);
};

#endif /* defined(__TextButton__TopTextScene__) */
