
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
            },
            onRewardVideoDidLoadAd: function() {
                cc.log("onRewardVideoDidLoadAd");
            },
            onRewardVideoDidFailToLoadAd: function() {
                cc.log("onRewardVideoDidFailToLoadAd");
            },
            onRewardVideoDidPresent: function() {
                cc.log("onRewardVideoDidPresent");
            },
            onRewardVideoWillDismiss: function() {
                cc.log("onRewardVideoWillDismiss");
            },
            onRewardVideoDidFinish: function(amount, name) {
                cc.log("onRewardVideoDidFinish");
            },
            onSkippableVideoDidLoadAd: function() {
                cc.log("onSkippableVideoDidLoadAd");
            },
            onSkippableVideoDidFailToLoadAd: function() {
                cc.log("onSkippableVideoDidFailToLoadAd");
            },
            onSkippableVideoDidPresent: function() {
                cc.log("onSkippableVideoDidPresent");
            },
            onSkippableVideoWillDismiss: function() {
                cc.log("onSkippableVideoWillDismiss");
            },
            onSkippableVideoDidFinish: function() {
                cc.log("onSkippableVideoDidFinish");
            },
            onSkippableVideoDidClick: function() {
                cc.log("onSkippableVideoDidClick");
            },
            onNonSkippableVideoDidLoadAd: function() {
                cc.log("onNonSkippableVideoDidLoadAd");
            },
            onNonSkippableVideoDidFailToLoadAd: function() {
                cc.log("onNonSkippableVideoDidFailToLoadAd");
            },
            onNonSkippableVideoDidPresent: function() {
                cc.log("onNonSkippableVideoDidPresent");
            },
            onNonSkippableVideoWillDismiss: function() {
                cc.log("onNonSkippableVideoWillDismiss");
            },
            onNonSkippableVideoDidFinish: function() {
                cc.log("onNonSkippableVideoDidFinish");
            },
            onNonSkippableVideoDidClick: function() {
                cc.log("onNonSkippableVideoDidClick");
            }
        });

        var menu = new cc.Menu();

        var AppodealShowStyleInterstitial = 1;
        var AppodealShowStyleBannerTop = 4;
        var AppodealShowStyleBannerBottom = 8;
        var AppodealShowStyleRewardedVideo = 16;
        var AppodealShowStyleNonSkippableVideo = 32;

        //deprecated
        var AppodealShowStyleSkippableVideo = AppodealShowStyleInterstitial;
        var AppodealShowStyleVideoOrInterstitial = AppodealShowStyleInterstitial;
        var AppodealShowStyleBannerCenter = AppodealShowStyleBannerBottom;
        var AppodealShowStyleVideo = AppodealShowStyleSkippableVideo;

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad Interstitial", "sans", 28), function() {
            cc.log("show ad Interstitial");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleInterstitial);
        }));

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad SkippableVideo", "sans", 24), function() {
            cc.log("show ad SkippableVideo");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleSkippableVideo);
        }));

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad VideoOrInterstitial", "sans", 24), function() {
            cc.log("show ad VideoOrInterstitial");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleVideoOrInterstitial);
        }));

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad BannerTop", "sans", 24), function() {
            cc.log("show ad BannerTop");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerTop);
        }));

        // menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad BannerCenter", "sans", 24), function() {
        //     cc.log("show ad BannerCenter");
        //     sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerCenter);
        // }));

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad BannerBottom", "sans", 24), function() {
            cc.log("show ad BannerBottom");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerBottom);
        }));

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad RewardedVideo", "sans", 24), function() {
            cc.log("show ad RewardedVideo");
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleRewardedVideo);
        }));

        menu.addChild(new cc.MenuItemLabel(cc.Label.createWithSystemFont("show ad NonSkippableVideo", "sans", 24), function() {
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

