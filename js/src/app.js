
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginAppodeal.init();
        sdkbox.PluginAppodeal.setListener({
            onBannerDidLoadAd: function() {
                cc.log("onBannerDidLoadAd");
            },
            onBannerDidFailToLoadAd: function() {
                cc.log("onBannerDidFailToLoadAd");
            },
            onBannerDidClick: function() {
                cc.log("onBannerDidClick");
            },
            onBannerPresent: function() {
                cc.log("onBannerPresent");
            },
            onInterstitialDidLoadAd: function() {
                cc.log("onInterstitialDidLoadAd");
            },
            onInterstitialDidFailToLoadAd: function() {
                cc.log("onInterstitialDidFailToLoadAd");
            },
            onInterstitialWillPresent: function() {
                cc.log("onInterstitialWillPresent");
            },
            onInterstitialDidDismiss: function() {
                cc.log("onInterstitialDidDismiss");
            },
            onInterstitialDidClick: function() {
                cc.log("onInterstitialDidClick");
            },
            onVideoDidLoadAd: function() {
                cc.log("onVideoDidLoadAd");
            },
            onVideoDidFailToLoadAd: function() {
                cc.log("onVideoDidFailToLoadAd");
            },
            onVideoDidPresent: function() {
                cc.log("onVideoDidPresent");
            },
            onVideoWillDismiss: function() {
                cc.log("onVideoWillDismiss");
            },
            onVideoDidFinish: function() {
                cc.log("onVideoDidFinish");
            }
        });

        var menu = new cc.Menu();

        var AppodealShowStyleInterstitial = 1;
        var AppodealShowStyleSkippableVideo = 2;
        var AppodealShowStyleVideoOrInterstitial = 3;
        var AppodealShowStyleBannerTop = 4;
        var AppodealShowStyleBannerCenter = 5;
        var AppodealShowStyleBannerBottom = 6;
        var AppodealShowStyleRewardedVideo = 7;
        var AppodealShowStyleVideo = AppodealShowStyleSkippableVideo; // deprecated use AppodealShowStyleSkippableVideo
        var AppodealShowStyleNonSkippableVideo = AppodealShowStyleRewardedVideo;

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad Interstitial", "sans", 24), function() {
            cc.log("show ad Interstitial");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleInterstitial);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad SkippableVideo", "sans", 24), function() {
            cc.log("show ad SkippableVideo");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleSkippableVideo);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad VideoOrInterstitial", "sans", 24), function() {
            cc.log("show ad VideoOrInterstitial");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleVideoOrInterstitial);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad BannerTop", "sans", 24), function() {
            cc.log("show ad BannerTop");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerTop);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad BannerCenter", "sans", 24), function() {
            cc.log("show ad BannerCenter");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerCenter);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad BannerBottom", "sans", 24), function() {
            cc.log("show ad BannerBottom");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerBottom);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad RewardedVideo", "sans", 24), function() {
            cc.log("show ad RewardedVideo");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleRewardedVideo);
        }));

        menu.addChild(cc.MenuItemLabel.create(cc.Label.createWithSystemFont("show ad NonSkippableVideo", "sans", 24), function() {
            cc.log("show ad NonSkippableVideo");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleNonSkippableVideo);
        }));

        var winsize = cc.winSize;
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

