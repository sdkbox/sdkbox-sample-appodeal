
#include "HelloWorldScene.h"
#include "PluginAppodeal/PluginAppodeal.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginAppodeal::setListener(this);
    
    auto menu = Menu::create();
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad Interstitial", "sans", 24), [](Ref*){
        CCLOG("show ad Interstitial");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleInterstitial);
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad SkippableVideo", "sans", 24), [](Ref*){
        CCLOG("show ad SkippableVideo");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleSkippableVideo);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad VideoOrInterstitial", "sans", 24), [](Ref*){
        CCLOG("show ad VideoOrInterstitial");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleVideoOrInterstitial);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad BannerTop", "sans", 24), [](Ref*){
        CCLOG("show ad BannerTop");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleBannerTop);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad BannerCenter", "sans", 24), [](Ref*){
        CCLOG("show ad BannerCenter");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleBannerCenter);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad BannerBottom", "sans", 24), [](Ref*){
        CCLOG("show ad BannerBottom");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleBannerBottom);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad RewardedVideo", "sans", 24), [](Ref*){
        CCLOG("show ad RewardedVideo");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleRewardedVideo);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad NonSkippableVideo", "sans", 24), [](Ref*){
        CCLOG("show ad NonSkippableVideo");
        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleNonSkippableVideo);
    }));
    
    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::onBannerDidLoadAd()
{
    CCLOG("onBannerDidLoadAd");
}

void HelloWorld::onBannerDidFailToLoadAd()
{
    CCLOG("onBannerDidFailToLoadAd");
}

void HelloWorld::onBannerDidClick()
{
    CCLOG("onBannerDidClick");
}

void HelloWorld::onBannerPresent()
{
    CCLOG("onBannerPresent");
}
// just trigger on android
void HelloWorld::onInterstitialDidLoadAd()
{
    CCLOG("onInterstitialDidLoadAd");
}

void HelloWorld::onInterstitialDidFailToLoadAd()
{
    CCLOG("onInterstitialDidFailToLoadAd");
}

void HelloWorld::onInterstitialWillPresent()
{
    CCLOG("onInterstitialWillPresent");
}

void HelloWorld::onInterstitialDidDismiss()
{
    CCLOG("onInterstitialDidDismiss");
}

void HelloWorld::onInterstitialDidClick()
{
    CCLOG("onInterstitialDidClick");
}

void HelloWorld::onVideoDidLoadAd()
{
    CCLOG("onVideoDidLoadAd");
}

void HelloWorld::onVideoDidFailToLoadAd()
{
    CCLOG("onVideoDidFailToLoadAd");
}

void HelloWorld::onVideoDidPresent()
{
    CCLOG("onVideoDidPresent");
}

void HelloWorld::onVideoWillDismiss()
{
    CCLOG("onVideoWillDismiss");
}

void HelloWorld::onVideoDidFinish()
{
    CCLOG("onVideoDidFinish");
}

void HelloWorld::onRewardVideoDidLoadAd()
{
    CCLOG("onRewardVideoDidLoadAd");
}

void HelloWorld::onRewardVideoDidFailToLoadAd()
{
    CCLOG("onRewardVideoDidFailToLoadAd");
}

void HelloWorld::onRewardVideoDidPresent()
{
    CCLOG("onRewardVideoDidPresent");
}

void HelloWorld::onRewardVideoWillDismiss()
{
    CCLOG("onRewardVideoWillDismiss");
}

void HelloWorld::onRewardVideoDidFinish(int amount, const std::string& name)
{
    CCLOG("onRewardVideoDidFinish, amount = %d, name = %s", amount, name.c_str());
}
