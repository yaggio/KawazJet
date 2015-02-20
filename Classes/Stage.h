//
//  Stage.h
//  KawazJet
//
//  Created by Yaggio on 2015/02/20.
//
//

#ifndef __KawazJet__Stage__
#define __KawazJet__Stage__

#include "cocos2d.h"

class Stage : public cocos2d::Layer
{
protected:
  Stage();
  virtual ~Stage();
  bool init() override;
 
public:
  void update(float dt) override;
  
  // タイルマップ
  CC_SYNTHESIZE_RETAIN(cocos2d::TMXTiledMap *, _tiledMap, TiledMap);
  CREATE_FUNC(Stage);
private:
  /** 指定のレイヤーの特定位置のタイルに剛体を設置します
   *  指定座標にタイルがなかった場合はnullptrを返します
   *  @param layer 対象のレイヤー
   *  @param coordinate 対象タイルのあるマップ上の座標
   *  @return タイルのスプライト、またはnullptr
   */
  cocos2d::Sprite* addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2&coordinate);
  
};

#endif /* defined(__KawazJet__Stage__) */
