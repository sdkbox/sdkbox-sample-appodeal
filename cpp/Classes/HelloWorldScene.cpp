
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

    //add info
    _info = Label::createWithSystemFont("", "sans", 32);
    _info->setPosition(Vec2(winsize.width/2, 64));
    addChild(_info);

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
    
//    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad BannerCenter", "sans", 24), [](Ref*){
//        CCLOG("show ad BannerCenter");
//        sdkbox::PluginAppodeal::showAd(sdkbox::PluginAppodeal::AppodealShowStyleBannerCenter);
//    }));
    
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
    showLog("onBannerDidLoadAd");
}

void HelloWorld::onBannerDidFailToLoadAd()
{
    showLog("onBannerDidFailToLoadAd");
}

void HelloWorld::onBannerDidClick()
{
    showLog("onBannerDidClick");
}

void HelloWorld::onBannerPresent()
{
    showLog("onBannerPresent");
}
// just trigger on android
void HelloWorld::onInterstitialDidLoadAd()
{
    showLog("onInterstitialDidLoadAd");
}

void HelloWorld::onInterstitialDidFailToLoadAd()
{
    showLog("onInterstitialDidFailToLoadAd");
}

void HelloWorld::onInterstitialWillPresent()
{
    showLog("onInterstitialWillPresent");
}

void HelloWorld::onInterstitialDidDismiss()
{
    showLog("onInterstitialDidDismiss");
}

void HelloWorld::onInterstitialDidClick()
{
    showLog("onInterstitialDidClick");
}

void HelloWorld::onVideoDidLoadAd()
{
    showLog("onVideoDidLoadAd");
}

void HelloWorld::onVideoDidFailToLoadAd()
{
    showLog("onVideoDidFailToLoadAd");
}

void HelloWorld::onVideoDidPresent()
{
    showLog("onVideoDidPresent");
}

void HelloWorld::onVideoWillDismiss()
{
    showLog("onVideoWillDismiss");
}

void HelloWorld::onVideoDidFinish()
{
    showLog("onVideoDidFinish");
}

void HelloWorld::onRewardVideoDidLoadAd()
{
    showLog("onRewardVideoDidLoadAd");
}

void HelloWorld::onRewardVideoDidFailToLoadAd()
{
    showLog("onRewardVideoDidFailToLoadAd");
}

void HelloWorld::onRewardVideoDidPresent()
{
    showLog("onRewardVideoDidPresent");
}

void HelloWorld::onRewardVideoWillDismiss()
{
    showLog("onRewardVideoWillDismiss");
}

void HelloWorld::onRewardVideoDidFinish(int amount, const std::string& name)
{
    showLog("onRewardVideoDidFinish");
    CCLOG("onRewardVideoDidFinish, amount = %d, name = %s", amount, name.c_str());
}

void HelloWorld::showLog(const std::string& log) {
    std::string s = _info->getString();
    if (0 == s.length()) {
        s = log;
    } else {
        size_t pos = s.find_last_of('\n');
        if (pos != std::string::npos) {
            s = s.substr(pos);
        }
        s += '\n';
        s += log;
    }
    _info->setString(s);
    CCLOG("%s", log.c_str());
}
