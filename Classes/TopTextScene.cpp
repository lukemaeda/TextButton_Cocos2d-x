//
//  TopTextScene.cpp
//  TextButton
//
//  Created by MAEDAHAJIME on 2015/02/13.
//
//

#include "TopTextScene.h"
// UI GUI用
#include <ui/CocosGUI.h>
USING_NS_CC;     // cocos2d
using namespace ui;
using namespace std; // String*

// _/_/_/ コンストラクタ プロパティー _/_/_/
TopTextScene::TopTextScene()
{
    
}

// MainScene デストラクタで解放 メモリーリークを防ぐ
TopTextScene::~TopTextScene()
{
    
}

// createSceneはLayerをSceneに貼り付けて返すクラスメソッドです。
// 自分自身(TopTextScene)を生成し、空のSceneに貼り付けて返す簡単な処理を行っているだけです。
// これでほかのシーンからの遷移が楽に行えます。
Scene* TopTextScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = TopTextScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool TopTextScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    // ゲームスタートボタン
    createGameStartButton();
    
    return true;
}

// ゲームスタートボタン
void TopTextScene::createGameStartButton() {
    
    // 画面サイズを取得
    auto winSize = Director::getInstance()->getVisibleSize();
    
    // ボタン生成
    Button* startButton = Button::create();
    // タッチイベント True
    startButton->setTouchEnabled(true);
    // ボタンの中心位置　アーカーポンイント
    startButton->setAnchorPoint(Point(0.5, 0.5));
    // 通常状態の画像 押下状態の画像
    startButton->loadTextures("btnStart.png", "btnStartOn.png", "");
    // テキスト
    startButton->setTitleText ( "Text Button" );
    // フォント
    startButton->setTitleFontName("Arial");
    // フォントサイズ
    startButton->setTitleFontSize(60);
    // フォントカラー
    startButton->setTitleColor(Color3B::BLACK);
    // ボタンの配置
    startButton->setPosition ( Vec2 ( winSize . width  /  2.0f ,  winSize . height  /  2.0f ));
    // ボタンのイベント（Ver 3.xでは非推奨掲載）
    startButton->addTouchEventListener(this, toucheventselector(TopTextScene::touchEvent));
    // ボタンの表示
    this->addChild(startButton);

}

// タッチイベント
void TopTextScene::touchEvent(Ref* pSender, TouchEventType type) {
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            log("TOUCH_EVENT_BEGAN");
            break;
        case TOUCH_EVENT_MOVED:
            log("TOUCH_EVENT_MOVED");
            break;
        case TOUCH_EVENT_ENDED:
            log("TOUCH_EVENT_ENDED");
            break;
        case TOUCH_EVENT_CANCELED:
            log("TOUCH_EVENT_CANCELED");
            break;
        default:
            break;
    }
}
