
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginAppodeal:init()
    sdkbox.PluginAppodeal:setListener(function(args)
        dump(args)
    end)

    local menu = cc.Menu:create()

    local AppodealShowStyleInterstitial = 1
    local AppodealShowStyleSkippableVideo = 2
    local AppodealShowStyleVideoOrInterstitial = 3
    local AppodealShowStyleBannerTop = 4
    local AppodealShowStyleBannerCenter = 5
    local AppodealShowStyleBannerBottom = 6
    local AppodealShowStyleRewardedVideo = 7
    local AppodealShowStyleVideo = AppodealShowStyleSkippableVideo -- deprecated use AppodealShowStyleSkippableVideo
    local AppodealShowStyleNonSkippableVideo = AppodealShowStyleRewardedVideo

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad Interstitial", "sans", 24)):onClicked(function()
        print("show ad Interstitial")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleInterstitial)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad SkippableVideo", "sans", 24)):onClicked(function()
        print("show ad SkippableVideo")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleSkippableVideo)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad VideoOrInterstitial", "sans", 24)):onClicked(function()
        print("show ad VideoOrInterstitial")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleVideoOrInterstitial)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad BannerTop", "sans", 24)):onClicked(function()
        print("show ad BannerTop")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleBannerTop)
    end))

    -- menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad BannerCenter", "sans", 24)):onClicked(function()
    --     print("show ad BannerCenter")
    --     sdkbox.PluginAppodeal:showAd(AppodealShowStyleBannerCenter)
    -- end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad BannerBottom", "sans", 24)):onClicked(function()
        print("show ad BannerBottom")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleBannerBottom)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad RewardedVideo", "sans", 24)):onClicked(function()
        print("show ad RewardedVideo")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleRewardedVideo)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("show ad NonSkippableVideo", "sans", 24)):onClicked(function()
        print("show ad NonSkippableVideo")
        sdkbox.PluginAppodeal:showAd(AppodealShowStyleNonSkippableVideo)
    end))

    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
