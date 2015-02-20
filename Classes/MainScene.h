//
//  MainScene.h
//  KawazJet
//
//  Created by Yaggio on 2015/02/19.
//
//

#ifndef __KawazJet__MainScene__
#define __KawazJet__MainScene__

#include "cocos2d.h"
#include "Stage.h"

class MainScene : public cocos2d::Layer
{
protected:
  MainScene();
  virtual ~MainScene();
  bool init() override;
  
public:
  static cocos2d::Scene* createScene();
  void update(float dt) override;
  // ステージ
  CC_SYNTHESIZE_RETAIN(Stage *, _stage, Stage);
  CREATE_FUNC(MainScene);
};

#endif /* defined(__KawazJet__MainScene__) */
