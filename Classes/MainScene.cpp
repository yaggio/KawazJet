//
//  MainScene.cpp
//  KawazJet
//
//  Created by yaggio on 2015/02/19.
//
//

#include "MainScene.h"

USING_NS_CC;

// 重力を表すベクトル
const Vec2 GRAVITY_ACCELERATION = Vec2(0, -3);

Scene* MainScene::createScene()
{
  // 物理エンジンを有効にしたシーンを作成
  auto scene = Scene::createWithPhysics();
  
  // 物理空間を取り出す
  auto world = scene->getPhysicsWorld();
 
  // 重力を設定
  world->setGravity(GRAVITY_ACCELERATION);
  
  // デバッグの時
#if COCOS2D_DEBUG > 0
  // 物理空間にデバッグ用の表示を追加する
  world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
#endif
  
  // 物理空間のスピードを設定
  world->setSpeed(6.0);
  
  // レイヤーを作成
  auto layer = MainScene::create();
  scene->addChild(layer);
  
  return scene;
}

bool MainScene::init()
{
  if ( !Layer::init() ) return false;

  auto stage = Stage::create();
  this->addChild(stage);
  this->setStage(stage);
  
  this->scheduleUpdate();
  
  return true;
}

MainScene::MainScene()
: _stage(nullptr)
{
}

MainScene::~MainScene()
{
  CC_SAFE_RELEASE_NULL(_stage);
}

void MainScene::update(float dt)
{
}