//
//  Stage.cpp
//  KawazJet
//
//  Created by Yaggio on 2015/02/20.
//
//

#include "Stage.h"

USING_NS_CC;

Stage::Stage()
: _tiledMap(nullptr)
{
}

Stage::~Stage()
{
  CC_SAFE_RELEASE_NULL(_tiledMap);
}

bool Stage::init()
{
  if ( !Layer::init() ) return false;

  // マップファイルからノードを作成
  auto map = TMXTiledMap::create("map/stage1.tmx");
  this->addChild(map);
  this->setTiledMap(map);
  
  // 地形レイヤー
  auto terrainLayer = map->getLayer("Terrain");
  // オブジェクトレイヤー
  auto objectLayer = map->getLayer("Object");
  
  // マップのサイズ
  auto mapSize = map->getMapSize();
  for (int x=0; x<mapSize.width; ++x) {
    for (int y=0; y<mapSize.height; ++y) {
      auto coordinate = Vec2(x, y);
      this->addPhysicsBody(terrainLayer, coordinate);
      this->addPhysicsBody(objectLayer, coordinate);
    }
  }
  
  this->scheduleUpdate();
  return true;
}

void Stage::update(float dt)
{
}

Sprite* Stage::addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2 &coordinate)
{
  // タイルのスプライトを取り出す
  auto sprite = layer->getTileAt(coordinate);
  if (sprite) {
    // 剛体用のマテリアルを作成
    auto material = PhysicsMaterial();
    // ひっかからないように摩擦を0にする
    material.friction = 0;
    // 剛体を設置
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), material);
    // 剛体を固定
    physicsBody->setDynamic(false);
    // 剛体をつけるSpriteのアンカーポイントを中心にする
    sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    // 剛体にSpriteをつける
    sprite->setPhysicsBody(physicsBody);
    return sprite;
  }
    
  
}